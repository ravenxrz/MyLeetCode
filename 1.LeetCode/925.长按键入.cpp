//你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。 
//
// 你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。 
//
// 
//
// 示例 1： 
//
// 输入：name = "alex", typed = "aaleex"
//输出：true
//解释：'alex' 中的 'a' 和 'e' 被长按。
// 
//
// 示例 2： 
//
// 输入：name = "saeed", typed = "ssaaedd"
//输出：false
//解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
// 
//
// 示例 3： 
//
// 输入：name = "leelee", typed = "lleeelee"
//输出：true
// 
//
// 示例 4： 
//
// 输入：name = "laiden", typed = "laiden"
//输出：true
//解释：长按名字中的字符并不是必要的。
// 
//
// 
//
// 提示： 
//
// 
// name.length <= 1000 
// typed.length <= 1000 
// name 和 typed 的字符都是小写字母。 
// 
//
// 
//
// 
// Related Topics 双指针 字符串 
// 👍 140 👎 0

#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        if(typed.size() < name.size())
            return false;

        int i = 0;  // pointer for name
        int j = 0; // pointer for typed

        while(i < name.size() && j < typed.size()){
            if(name[i] == typed[j]){
                j++;
                if(i + 1 < name.size() && name[i+1] != name[i]){
                    // name中当前字符是最后一个字符, 跳过typed中的所有 name[i]
                    while (typed[j] == typed[j - 1]){
                        j++;
                    }
                }
                 i++; // 下一个字符
            }else{
                // 一旦不相等,直接false
                return false;
            }
        }

        if(i != name.size())
            return false;
        
        while(j<typed.size()){
            if(typed[j] == typed[j-1])
                j++;
            else
                return false;
        }

        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution sol;
    cout << sol.isLongPressedName("saeed","ssaaedd");
    return 0;
}