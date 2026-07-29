class Solution {
    // Computes unique permutations of multi-set capped at k to prevent overflow
    long long countWays(const vector<int>& half, int totalLen, long long cap) {
        long long res = 1;
        int currentTotal = 1;
        
        for (int cnt : half) {
            for (int i = 1; i <= cnt; ++i) {
                res = (res * currentTotal) / i;
                currentTotal++;
                if (res > cap) return cap + 1; // Cap to avoid integer overflow
            }
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int oddCount = 0;
        char mid = 0;
        vector<int> half(26, 0);
        int halfLen = 0;

        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                oddCount++;
                mid = 'a' + i;
            }
            half[i] = freq[i] / 2;
            halfLen += half[i];
        }

        // More than one odd frequency character cannot form a palindrome
        if (oddCount > 1) return "";

        // Check if total valid permutations are less than k
        if (countWays(half, halfLen, k) < k) return "";

        string left = "";

        // Construct the left half greedily
        for (int i = 0; i < halfLen; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half[c] == 0) continue;

                half[c]--; // Try using character 'c'
                long long ways = countWays(half, halfLen - i - 1, k);

                if (k <= ways) {
                    left += (char)('a' + c);
                    break; // 'c' is the correct choice
                } else {
                    k -= ways; // Skip these permutations
                    half[c]++; // Restore character
                }
            }
        }

        // Construct full palindrome
        string right = left;
        reverse(right.begin(), right.end());

        return oddCount ? left + mid + right : left + right;
    }
};