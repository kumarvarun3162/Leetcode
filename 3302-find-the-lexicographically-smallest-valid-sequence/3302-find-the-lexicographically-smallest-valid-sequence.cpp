class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suff(m, -1);

        int j = m - 1;

        for (int i = n - 1; i >= 0 && j >= 0; --i) {
            if (word1[i] == word2[j]) {
                suff[j] = i;
                --j;
            }
        }

        vector<int> ans;
        ans.reserve(m);

        int p = 0;
        bool usedMismatch = false;

        for (int i = 0; i < n && p < m; ++i) {

            // Exact match
            if (word1[i] == word2[p]) {
                ans.push_back(i);
                ++p;
                continue;
            }

            if (!usedMismatch) {
                if (p == m - 1 ||
                    (suff[p + 1] != -1 && i < suff[p + 1])) {

                    ans.push_back(i);
                    ++p;
                    usedMismatch = true;
                }
            }
        }

        if (p == m)
            return ans;

        return {};
    }
};