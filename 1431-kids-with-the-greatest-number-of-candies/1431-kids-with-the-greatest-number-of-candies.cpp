class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(), candies.end());

        vector<bool> ans;
        for (int x : candies){
            bool val = x + extraCandies >= max;
            ans.push_back(val);
        }
        return ans;
    }
};