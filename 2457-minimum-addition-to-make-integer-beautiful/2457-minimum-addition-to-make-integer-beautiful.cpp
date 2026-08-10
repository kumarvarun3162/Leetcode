class Solution {
public:
    long long sum_digit(long long n) {
        long long digit_sum = 0;

        while (n > 0) {
            digit_sum += n % 10;
            n /= 10;
        }

        return digit_sum;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long ans = 0;
        long long place = 1;

        while (sum_digit(n) > target) {
            long long digit = (n / place) % 10;

            if (digit != 0) {
                long long add = (10 - digit) * place;

                n += add;
                ans += add;
            }

            place *= 10;
        }

        return ans;
    }
};