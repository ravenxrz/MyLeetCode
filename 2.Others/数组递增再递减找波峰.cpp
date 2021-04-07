class Solution {
   public:
    int findMaxValue(const vector<int>& nums) {
        if (nums.empty())
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (mid == 0) {
                return nums[left] > nums[right] ? nums[left] : nums[right];
            }
            if (mid == right) {
                return nums[right];
            }
            // 检查在上升期还是下降期
            if (nums[mid - 1] <= nums[mid] && nums[mid] >= nums[mid + 1]) {
                return nums[mid];
            } else if (nums[mid - 1] <= nums[mid] &&
                       nums[mid] <= nums[mid + 1]) {
                left = mid + 1;
            } else if (nums[mid - 1] >= nums[mid] &&
                       nums[mid] >= nums[mid + 1]) {
                right = mid - 1;
            }
        }
        return -1;
    }
};
