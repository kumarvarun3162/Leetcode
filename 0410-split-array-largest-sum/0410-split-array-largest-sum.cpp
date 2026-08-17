class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = 0;
        long long high = 0;

        for (int x : nums) {
            low = max(low, (long long)x);
            high += x;
        }

        while (low < high) {

            long long mid = low + (high - low) / 2;

            int parts = 1;
            long long sum = 0;

            for (int x : nums) {

                if (sum + x > mid) {
                    parts++;
                    sum = x;
                }
                else {
                    sum += x;
                }
            }

            if (parts <= k) {
                // mid is possible
                high = mid;
            }
            else {
                // mid is too small
                low = mid + 1;
            }
        }

        return low;
    }
};