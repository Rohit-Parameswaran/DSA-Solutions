class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1, maxArea = 0;
        while (l < r) {
            maxArea = max(maxArea, (r - l) * min(height[l], height[r]));
            if (height[l] > height[r])
                r--;
            else
                l++;
        }
        return maxArea;
    }
};
