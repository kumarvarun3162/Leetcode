class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1] + 1){
                sum += nums[i];
            }
            else { break; }
        }

        int x = sum;

        while(true){
            bool found = false;

            for (int j : nums){
                if ( j == x){
                    found = true;
                    break;
                }
            }
            if (!found){
                return x;
            }
            x ++;
        }

    }
};