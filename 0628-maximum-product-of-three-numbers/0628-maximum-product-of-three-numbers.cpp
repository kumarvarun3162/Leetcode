class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;

        int min1 = INT_MAX, min2 = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= mx) {
                third = second;
                second = mx;
                mx = nums[i];
            }
            else if (nums[i] > second) {
                third = second;
                second = nums[i];
            }
            else if (nums[i] > third){
                third = nums[i];
            }

            if (nums[i] <= min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if (nums[i] <= min2){
                min2 = nums[i];
            }
        }

        return max(mx * second * third, min1 * min2 * mx);
    }
};