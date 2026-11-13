
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        // Step 1: Find Next Greater Element
        vector<int> nxt(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nxt[i] = st.top();
            }

            st.push(i);
        }

        // Step 2: Binary lifting
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, n));
        vector<vector<long long>> cost(LOG, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];

            cost[0][i] =
                1LL * nums[i] * (nxt[i] - i)
                - (pref[nxt[i]] - pref[i]);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = up[j - 1][i];

                if (mid != n) {
                    up[j][i] = up[j - 1][mid];

                    cost[j][i] =
                        cost[j - 1][i] + cost[j - 1][mid];
                }
                else {
                    up[j][i] = n;
                    cost[j][i] = cost[j - 1][i];
                }
            }
        }

        // Step 3: Calculate operations for [l, r]
        auto getCost = [&](int l, int r) -> long long {
            long long total = 0;
            int cur = l;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][cur] <= r) {
                    total += cost[j][cur];
                    cur = up[j][cur];
                }
            }

            total += 1LL * nums[cur] * (r - cur + 1)
                     - (pref[r + 1] - pref[cur]);

            return total;
        };

        // Step 4: Binary search for each right endpoint
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int low = 0;
            int high = r;

            while (low < high) {
                int mid = low + (high - low) / 2;

                if (getCost(mid, r) <= k) {
                    high = mid;
                }
                else {
                    low = mid + 1;
                }
            }

            ans += r - low + 1;
        }

        return ans;
    }
};
