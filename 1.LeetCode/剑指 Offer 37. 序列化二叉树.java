//
// Created by raven on 2021/7/30.
//


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        preOrderTraverse(root, sb);
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    int cur_idx = 0;
    public TreeNode deserialize(String data) {
        cur_idx = 0;
        String[] inputs = data.split(",");
        return createTreeNode(inputs);
    }

    private void preOrderTraverse(TreeNode node, StringBuilder sb) {
        if (node == null) {
            sb.append("#,");
            return;
        }
        sb.append(node.val).append(",");
        preOrderTraverse(node.left, sb);
        preOrderTraverse(node.right, sb);
    }

    private TreeNode createTreeNode(String[] inputs) {
        assert (cur_idx < inputs.length);
        if (inputs[cur_idx].equals("#")) {
            cur_idx++;
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(inputs[cur_idx]));
        cur_idx++;
        if (cur_idx == inputs.length) return node;
        node.left = createTreeNode(inputs);
        node.right = createTreeNode(inputs);
        return node;
    }
}
