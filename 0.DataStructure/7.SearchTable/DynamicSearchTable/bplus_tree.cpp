#include <bits/stdc++.h>
using namespace std;

static int order = 1000; /* order: 一个节点有多少个指向children的指针 */

class BPTree;
class Node;

class Node {
    bool is_leaf; /* 是否是叶子节点 */
    // TODO: max_size // 修改为全局变量即可，没必要每个节点都存一份
    const int max_size;     /* 最多多少个key */
    Node* parent;           /* 父亲节点 */
    vector<int> key;        /* key数组, 长度为max_size */
    vector<Node*> children; /* children数组，长度为max_size+1 */

    Node() : is_leaf(false), max_size(order - 1), parent(nullptr) {}

    friend class BPTree;
};

/**
 * @brief BPTree， 注意不能插入重复的key，如果插入重复key，则视为无效插入
 *
 */
class BPTree {
   public:
    BPTree() : root_(new Node) {
        root_->is_leaf = true;
        root_->parent = nullptr;
    }
    /**
     * @brief 查找key是否在B+树中
     *
     * @param key
     * @return true key存在
     * @return false key 不存在
     */
    bool search(int key) const;

    /**
     * @brief 插入key
     *
     * @param key
     */
    void insert(int key);

    /**
     * @brief 在B+树中移除key
     *
     * @param key
     * @return true 移除成功
     * @return false 移除失败
     */
    bool remove(int key);

    /**
     * @brief 打印整棵树
     *
     */
    void print_tree();

    /**
     * @brief 取得树的高度
     * 
     */
    int height();

    /**
     * @brief 树是否为空
     * 
     * @return true 树空
     * @return false 树非空
     */
    bool empty();

   private: /* function */
    /**
     * @brief insert操作核心函数
     *
     * @param node 当前遍历到的node
     * @param key 需要插入的key
     */
    void do_insert(Node* node, int key);

    /**
     * @brief 分裂leaf node
     *
     * @param node 需要分裂的叶子node
     * @note node->size == max_size + 1, 也即node已经overflow
     * 另外本函数只负责split "node", 如果split后,
     * node->parent也溢出了，并不负责处理parent node
     * 的split，这个交由上层调用接口去处理
     */
    void split_leaf(Node* node);

    /**
     * @brief 分裂non-leaf node
     *
     * @param node 需要分裂的非叶子节点
     * @note node->size == max_size + 1, 也即node已经overflow
     * 另外本函数只负责split "node", 如果split后,
     * node->parent也溢出了，并不负责处理parent node
     * 的split，这个交由上层调用接口去处理
     */
    void split_non_leaf(Node* node);

    /* TODO:delete opeartion */

    /**
     * @brief 打印node节点
     *
     * @param node
     */
    void print_one_node(const Node* node) const;

   private: /* member */
    Node* root_;
};

bool BPTree::search(int key) const {
    Node* cur = root_;
    /* 使用binary search定位到第一个大于等于key的 */
    while (!cur->is_leaf) {
        auto iter = std::lower_bound(cur->key.begin(), cur->key.end(), key);
        int idx = iter - cur->key.begin();
        if (iter == cur->key.end()) { /* 节点内所有key都比传入"key"小 */
            cur = cur->children[idx];
        } else { /* 找到有key >= 传入key */
            if (*iter == key) {
                /* go to right  */
                cur = cur->children[idx + 1];
            } else {
                /* go to left */
                cur = cur->children[idx];
            }
        }
    }
    /* 现在，cur是leaf node，再次使用binary search得到结果 */
    auto iter = std::lower_bound(cur->key.begin(), cur->key.end(), key);
    return iter == cur->key.end() ? false : *iter == key;
}

void BPTree::insert(int key) {
    do_insert(root_, key);
}

void BPTree::do_insert(Node* node, int key) {
    assert(node);
    if (node->is_leaf) {
        /* 找到合适的位置，尝试插入key */
        auto iter = std::lower_bound(node->key.begin(), node->key.end(), key);
        if (iter != node->key.end() && *iter == key)
            return; /* 不支持重复key的插入 */
        node->key.insert(iter, key);
        /* 检查node->key的size， 如果达到max_size, 需要分裂 */
        if (node->key.size() == node->max_size + 1) {
            split_leaf(node);
        }
        return;
    } else { /* 非叶子节点 */
        /* 找到合适的位置 */
        auto iter = std::lower_bound(node->key.begin(), node->key.end(), key);
        int idx = iter - node->key.begin();
        if (iter == node->key.end()) {
            do_insert(node->children[idx], key);
        } else {
            if (key == *iter) {
                do_insert(node->children[idx + 1], key);
            } else {
                do_insert(node->children[idx], key);
            }
        }
        /* 检查本节点是否需要分裂 */
        if (node->key.size() == node->max_size + 1) {
            split_non_leaf(node);
        }
        return;
    }
}

bool BPTree::remove(int key) {
    return false;
}

void BPTree::split_leaf(Node* node) {
    assert(node->key.size() == node->max_size + 1);
    /* 拆分后，左节点还有会有多个key */
    int left_num = node->key.size() / 2;
    int right_num = node->key.size() - left_num;

    /* 执行拆分 */
    Node* left_node = node;
    /* 新节点 */
    Node* right_node = new Node;
    right_node->is_leaf = true;
    right_node->parent = node->parent;
    right_node->key.resize(right_num, 0);
    /* 拆分数据 */
    int i, j;
    for (i = 0, j = left_num; j < node->key.size(); i++, j++) {
        right_node->key[i] = node->key[j];
    }
    /* 移除node中从[left_num, end)的所有key */
    node->key.erase(node->key.begin() + left_num, node->key.end());
    assert(left_node->key.size() == left_num);
    assert(right_node->key.size() == right_num);

    /* 将right_node中的第一个节点移动到parent node中 */
    int val = right_node->key[0];
    if (node->parent == nullptr) { /* node是root节点 */
        Node* parent_node = new Node;
        parent_node->is_leaf = false;
        parent_node->key.push_back(val);
        parent_node->children.push_back(left_node);
        parent_node->children.push_back(right_node);
        /* 设置parent指针 */
        left_node->parent = parent_node;
        right_node->parent = parent_node;
        /* 更新root节点 */
        root_ = parent_node;
    } else { /* 不是root节点 */
        Node* cur = node->parent;
        int idx = std::upper_bound(cur->key.begin(), cur->key.end(), val) -
                  cur->key.begin();
        cur->key.insert(cur->key.begin() + idx, val);
        cur->children.insert(cur->children.begin() + idx + 1, right_node);
    }
}

void BPTree::split_non_leaf(Node* node) {
    assert(node->key.size() == node->max_size + 1);
    /* 拆分后，左节点还会有多少个key */
    int left_num = node->key.size() / 2;
    int right_num = node->key.size() - left_num -
                    1; /* 这里要多减一，因为非叶子节点无需保存所有key */

    /* 执行拆分 */
    Node* left_node = node;
    Node* right_node = new Node;
    int val = node->key[left_num];
    right_node->is_leaf = false;
    right_node->parent = left_node->parent;
    right_node->key.resize(right_num, 0);
    right_node->children.resize(right_num + 1, 0);

    /* 拆分key */
    int i, j;
    for (i = 0, j = left_num + 1; j < node->key.size(); i++, j++) {
        right_node->key[i] = left_node->key[j];
    }
    /* 移除node中从[left, end)中所有key */
    node->key.erase(node->key.begin() + left_num, node->key.end());
    assert(left_node->key.size() == left_num);
    assert(right_node->key.size() == right_num);

    /* 拆分ptrs */
    for (i = 0, j = left_num + 1; j < node->children.size(); i++, j++) {
        right_node->children[i] = left_node->children[j];
    }
    /* 移除node中从[left+1, end)中所有ptrs */
    node->children.erase(node->children.begin() + left_num + 1,
                         node->children.end());
    assert(left_node->children.size() == left_num + 1);
    assert(right_node->children.size() == right_num + 1);

    /* val插入到父亲节点 */
    if (node->parent == nullptr) {
        Node* parent_node = new Node;
        parent_node->is_leaf = false;
        parent_node->parent = nullptr;
        parent_node->key.push_back(val);
        parent_node->children.push_back(left_node);
        parent_node->children.push_back(right_node);
        /* 更新子节点parent指针 */
        left_node->parent = parent_node;
        right_node->parent = parent_node;
        /* 更新root节点 */
        root_ = parent_node;
    } else {
        Node* cur = node->parent;
        int idx = std::upper_bound(cur->key.begin(), cur->key.end(), val) -
                  cur->key.begin();
        cur->key.insert(cur->key.begin() + idx, val);
        cur->children.insert(cur->children.begin() + idx + 1, right_node);
    }

    /* 由于node节点拆分为了两个节点，所以要更新原node节点的孩子节点的parent指针
     */
    for (auto child : left_node->children) {
        child->parent = left_node;
    }
    for (auto child : right_node->children) {
        child->parent = right_node;
    }
}

void BPTree::print_tree() {
    queue<Node*> qe;
    qe.push(root_);
    int cur_level_num = 1;
    int next_level_num = 0;

    while (!qe.empty()) {
        const Node* cur = qe.front();
        qe.pop();
        print_one_node(cur);
        cur_level_num--;

        for (auto child : cur->children) {
            qe.push(child);
            next_level_num++;
        }

        if (cur_level_num == 0) {
            cout << '\n';
            cur_level_num = next_level_num;
            next_level_num = 0;
        }
    }
}

void BPTree::print_one_node(const Node* node) const {
    string node_str = "[";
    for (auto key : node->key) {
        node_str.append(" " + to_string(key) + " |");
    }
    node_str.pop_back();
    cout << node_str << "]";
}

int BPTree::height()
{
    if(empty()) return 0;
    int level = 1;
    Node *cur = root_;
    while(!cur->is_leaf){
        cur = cur->children[0];
        level++;
    }
    return level;
}

bool BPTree::empty()
{
    return root_->is_leaf && root_->key.empty();
}

int main() {
    BPTree bptree;

    /* 插入1w个值 */
    srand(time(NULL));
    for (int i = 0; i < 1000 * 1000; i++) {
        bptree.insert(rand());
    }
    bptree.print_tree();
    cout << bptree.height() << endl;

    return 0;
}