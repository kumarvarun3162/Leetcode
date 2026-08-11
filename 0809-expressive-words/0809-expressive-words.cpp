class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;

        for (string word : words) {

            int i = 0;
            int j = 0;
            bool valid = true;

            while (i < s.size() && j < word.size()) {

                if (s[i] != word[j]) {
                    valid = false;
                    break;
                }

                int startS = i;

                while (i < s.size() && s[i] == s[startS]) {
                    i++;
                }

                int countS = i - startS;

                int startW = j;

                while (j < word.size() && word[j] == word[startW]) {
                    j++;
                }

                int countW = j - startW;

                if (countS < countW) {
                    valid = false;
                    break;
                }

                if (countS != countW && countS < 3) {
                    valid = false;
                    break;
                }
            }
            if (i != s.size() || j != word.size()) {
                valid = false;
            }

            if (valid) {
                ans++;
            }
        }

        return ans;
    }
};