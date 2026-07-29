class Solution {
public:
    int kadane(vector<int> &nums){
        int MaxSum = nums[0];
        int current_sum = nums[0];
        for (int i = 1; i < nums.size(); i++){
            current_sum = max(nums[i], current_sum + nums[i]);
            MaxSum = max(MaxSum, current_sum);
        }
        return MaxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int max_normal = kadane(nums);
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> neg_nums(nums.size());
        for (int i = 1; i < nums.size(); i++){
            neg_nums[i] = -nums[i];
        }
        int min_subarray = kadane(neg_nums);
        int max_circular = total_sum + min_subarray;

        return max(max_normal, max_circular);

    }
};