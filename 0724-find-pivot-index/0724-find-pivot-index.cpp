class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);

        for (int idx = 0; idx < n; idx++) {
            int right = sum - nums[idx] - left;
            if (left == right)
                return idx;
            left += nums[idx];
        }

        return -1;
    }
};