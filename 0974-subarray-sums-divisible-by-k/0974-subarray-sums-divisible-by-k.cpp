class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0; unordered_map <int, int> f;
        int ans = 0;
        f[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int rem = ((sum % k) + k ) % k;
            if (f.count(rem))
                ans += f[rem];
            f[rem]++;
        }
        return ans;
    }
};