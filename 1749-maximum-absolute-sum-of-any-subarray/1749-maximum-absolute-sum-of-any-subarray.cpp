class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMax = 0, MaxSum = 0;
        int currMin = 0, MinSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currMax = max(currMax + nums[i], nums[i]);
            MaxSum = max(MaxSum, currMax);

            currMin = min(currMin + nums[i], nums[i]);
            MinSum = min(MinSum, currMin);
        }

        return max(MaxSum, -MinSum);
    }
};