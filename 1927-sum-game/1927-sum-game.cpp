class Solution {
public:
    bool sumGame(string s) {
        int n = s.size();
        int sum = 0, q = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '?')
                q += (i < n/2 ? 1 : -1);
            else
                sum += (i < n/2 ? 1 : -1) * (s[i] - '0');
        }

        return 2 * sum + 9 * q != 0;
    }
};