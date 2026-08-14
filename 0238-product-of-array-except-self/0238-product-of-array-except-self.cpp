class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> suffix_prd(n);
        vector<int> prefix_prd(n);

        prefix_prd[0] = 1;
        for (int i = 1; i < n; i++ ){
            prefix_prd[i] = prefix_prd[i - 1] * nums[i - 1];
        }
        suffix_prd[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--){
            suffix_prd[i] = suffix_prd[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i ++){
            ans[i] = prefix_prd[i] * suffix_prd[i];
        }
        return ans;


    }
};