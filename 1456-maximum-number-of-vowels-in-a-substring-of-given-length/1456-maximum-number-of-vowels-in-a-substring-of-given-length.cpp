class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int maxcount = 0;

        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' ||
                   ch == 'o' || ch == 'u';
        };

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        maxcount = count;

        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i])) {
                count++;
            }

            if (isVowel(s[i - k])) {
                count--;
            }

            maxcount = max(count, maxcount);
        }

        return maxcount;
    }
};