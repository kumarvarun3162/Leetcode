class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long res = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long L = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    L = lcm(L, coins[i]);
                    bits++;
                    if (L > x) break;
                }
            }

            if (L > x) continue;

            if (bits % 2)
                res += x / L;
            else
                res -= x / L;
        }

        return res;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {
        long long l = 1, r = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (l < r) {
            long long mid = (l + r) / 2;

            if (count(mid, coins) >= k)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};