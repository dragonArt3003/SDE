class Solution {
public:
    int maxArea(vector<int>& height) {
        int lheight, rheight;
        int l, r;
        l = 0, r = height.size() - 1;
        int area, maxArea;
        maxArea = INT_MIN;
        while (l < r){
            lheight = height[l];
            rheight = height[r];
            area = min(lheight, rheight) * (r - l);
            maxArea = std::max(maxArea, area);
            if (lheight < rheight)
                l++;
            else
                r--;
        }
        return maxArea;
    }
};
