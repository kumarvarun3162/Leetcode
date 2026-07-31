class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0; unordered_map<int, int> f ;
        int res = 0;
        f[0] = 1;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int ques = sum - k;
            if (f.count(ques))
                res += f[ques];
            f[sum]++;
         }
        return res;
    }
};