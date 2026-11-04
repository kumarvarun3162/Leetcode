class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

         int n = intervals.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (intervals[j][0] <= intervals[i][1]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};