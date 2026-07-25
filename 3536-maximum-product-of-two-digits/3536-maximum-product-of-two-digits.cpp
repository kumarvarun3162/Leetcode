class Solution {
public:
    int maxProduct(int n) {
        int mx = 0, second = 0;

       while (n > 0){
            int d = n % 10;

            if (d >= mx){
                second = mx;
                mx = d;
            }
            else if ( d > second){
                second = d;
            }
            n /= 10;
       }

       return mx * second;
    }
};