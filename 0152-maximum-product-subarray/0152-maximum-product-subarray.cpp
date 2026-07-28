class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxending = nums[0];
        int minending = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++){
            int v1 = nums[i];
            int v2 = nums[i] * maxending;
            int v3 = nums[i] * minending; 

            maxending = max(v1, max(v2, v3));
            minending = min(v1, min(v2, v3));
            ans = max(ans, max(maxending, minending));
        }
        return ans;
    }
};