class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        sort(arr2.begin(), arr2.end());

        int count = 0;

        for(int i = 0; i < arr1.size(); i++) {

            int x = arr1[i];

            int pos = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();

            bool valid = true;

            // Check right side
            if(pos < arr2.size() && abs(arr2[pos] - x) <= d) {
                valid = false;
            }

            // Check left side
            if(pos > 0 && abs(arr2[pos - 1] - x) <= d) {
                valid = false;
            }

            if(valid == true) {
                count++;
            }
        }

        return count;
    }
};