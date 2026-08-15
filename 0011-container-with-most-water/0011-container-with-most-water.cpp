class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; int r = height.size() - 1;
        int area = 0;
        while(l < r){
            int side =min(height[l],height[r]);
            int p = side * (r - l);
            area = max(area,p);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }

        
        }
        return area;
    }
};