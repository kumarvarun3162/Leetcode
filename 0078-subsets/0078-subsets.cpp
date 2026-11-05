
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};

        for (int i : nums) {
            vector<vector<int>> curr = {};

            for (auto j : ans) {
                j.push_back(i);
                curr.push_back(j);
            }

            ans.insert(ans.end(), curr.begin(), curr.end());
        }

        return ans;
    }
};
