class Solution {
public:
    int maxArea(vector<int>& height) {
                
    if(height.size() == 0) 
        return 0;
        
    int water = 0, l = 0, r = height.size()-1;
    while(l < r) {
        int h = min(height[l], height[r]);
        water = max(water, (r - l) * h);
        while(l < r && height[l] <= h) l++;
        while(l < r && height[r] <= h) r--;
    }
    return water;
    }
};