class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        int l = 0;
        int xr = 0;

        for (int r = 0; r < nums.size(); r++) {
            xr ^= nums[r];

            if (xr != 0) {
                ans = max(ans, r - l + 1);
            }
        }

        if (xr == 0) {
            for (int x : nums) {
                if (x != 0) {
                    return nums.size() - 1;
                }
            }
            return 0;
        }

        return ans;
    }
};