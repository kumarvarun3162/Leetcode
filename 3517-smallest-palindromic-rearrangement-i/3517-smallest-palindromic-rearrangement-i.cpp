class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);

        for (char c : s){
            freq[c - 'a']++;
        }

        string left = "";
        string mid = "";

        for (int i = 0; i < 26; i++){
            if (freq[i] == 0) continue;

            char c = 'a' + i;
            left.append(freq[i]/2, c);

            if (freq[i] % 2 != 0){
                mid = c;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;

    }
};