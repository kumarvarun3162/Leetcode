class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0; int n = nums.size() ;int window = 0;
        int ans = 0;

        for (int right = 0; right < n ; right ++)
        {
            window += nums[right];
            while (window + k < right - left + 1)
            {
                window -= nums[left++];
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};