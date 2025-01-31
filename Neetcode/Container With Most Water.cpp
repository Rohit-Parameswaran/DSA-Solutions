class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size(), l=0, r=n-1;
        int ans = 0, lh;
        while(l<r) {
            lh = min(heights[l], heights[r]);
            ans = max(ans, lh*(r-l));
            if(lh == heights[l]) ++l;
            else --r;
        }
        return ans;        
    }
};
