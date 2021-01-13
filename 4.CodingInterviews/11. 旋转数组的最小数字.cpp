/**
 *  把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 *  例如，数组[3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1.
    示例 1：
    输入：[3,4,5,1,2]
    输出：1
    
    示例 2：
    输入：[2,2,2,0,1]
    输出：0
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minArray(vector<int> &numbers)
    {
        if(numbers.empty()){
            return 0;
        }
        
        int start = 0;
        int end = numbers.size() - 1;
        int mid = start;
        while(numbers[start] >= numbers[end]){
            if(start+1 == end){
                mid = end;break;
            }
            mid = (start + end) >> 1;
            if(numbers[start] == numbers[mid] && numbers[mid] == numbers[end]){
                // 顺序查找
                int ans = numbers[start];
                for(int i = start;i<=end;i++){
                    if(ans > numbers[i])  ans = numbers[i];
                }
                return ans;
            }
            
            if(numbers[mid] >= numbers[start]){
                start = mid;
            }else if(numbers[mid] <= numbers[end]){
                end = mid;
            }
        }
        return numbers[mid];
    }
};


int main()
{
    Solution sol;
    // empty test
    {
        vector<int> nums{};
        cout << sol.minArray(nums) << endl;
    }
    // only one element
    {
        vector<int> nums{1};
        cout << sol.minArray(nums) << endl;
    }
    //  2
    {
        vector<int> nums{2, 1};
        cout << sol.minArray(nums) << endl;
    }
    // multiple nums
    {
        vector<int> nums{3, 4, 5, 1, 2};
        cout << sol.minArray(nums) << endl;
    }
    {
        vector<int> nums{2, 2, 2, 0, 1};
        cout << sol.minArray(nums) << endl;
    }
    
    // 不移动
    {
        vector<int> nums{1, 3, 4, 5};
        cout << sol.minArray(nums) << endl;
    }
    {
        vector<int> nums{3, 1, 1};
        cout << sol.minArray(nums) << endl;
    }
    {
        vector<int> nums{3, 1};
        cout << sol.minArray(nums) << endl;
    }
    {
        vector<int> nums{1, 3, 3};
        cout << sol.minArray(nums) << endl;
    }
    {
        vector<int> nums{3, 1, 3};
        cout << sol.minArray(nums) << endl;
    }
    return 0;
}
