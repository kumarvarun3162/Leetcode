class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;

        int i = 0; int j = 0;
        while( i < word1.length() || j < word2.length()){
            if (i < word1.size()){
                ans += word1[i++];
            }
            if ( j < word2.size()){
                ans += word2[j++];
            }
        }
        
        return ans;
    }
};