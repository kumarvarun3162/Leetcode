class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current_avg = 0;
        int total = 0;

        for (int i = 0; i < k; i++) {
            total += nums[i];
        }

        current_avg = (double)total / k;
        double maxx = current_avg;

        for (int i = 1; i <= nums.size() - k; i++) {
            current_avg = current_avg
                        - (double)nums[i - 1] / k
                        + (double)nums[i + k - 1] / k;

            maxx = max(maxx, current_avg);
        }

        return maxx;
    }
};
