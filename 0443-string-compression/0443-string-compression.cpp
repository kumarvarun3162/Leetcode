class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int i = 0;

        while (i < chars.size()) {
            char ch = chars[i];
            int j = i;

            while (j < chars.size() && chars[j] == ch) {
                j++;
            }

            int count = j - i;

            chars[write++] = ch;

            if (count > 1) {
                string s = to_string(count);

                for (char c : s) {
                    chars[write++] = c;
                }
            }

            i = j;
        }

        return write;
    }
};