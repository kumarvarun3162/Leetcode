class Solution {
public:
    string reverseVowels(string s) {
        int l = 0; int r = s.size() - 1;
        auto isVowel = [](char c){
            return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                   c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        while (l < r){
            while ( l < r && !isVowel(s[l])) l++;
            while ( l < r && !isVowel(s[r])) r--;
            
            swap(s[l], s[r]);
            l++; r--;
        }

        return s;


        
    }
};