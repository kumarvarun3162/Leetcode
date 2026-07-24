class Solution {
public:
    bool fun(vector<int> &have, vector<int> &need) {
        for (int i = 0; i < 256; i++) {
            if (have[i] < need[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> have(256, 0);
        vector<int> need(256, 0);

        if (n < m)
            return "";

        for (int i = 0; i < m; i++) {
            need[t[i]]++;
        }

        int left = 0;
        int res = INT_MAX;
        int start = -1;

        for (int right = 0; right < n; right++) {
            have[s[right]]++;

            while (fun(have, need)) {
                int len = right - left + 1;

                if (res > len) {
                    res = len;
                    start = left;
                }

                have[s[left]]--;
                left++;
            }
        }

        if (res == INT_MAX)
            return "";

        return s.substr(start, res);
    }
};