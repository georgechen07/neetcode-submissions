class Solution {
public:
    int maxArea(vector<int>& heights) {
        auto areas = vector<int>();
        
        int l = 0;
        int r = heights.size() - 1;

        int currMax = 0;

        while (r > l) {
            int area = (r - l) * min(heights[l], heights[r]);
            if (area > currMax) {
                currMax = area;
            }
            if (heights[l] < heights[r]) {
                l++;
            } else if (heights[l] > heights[r]) {
                r--;
            } else {
                if (heights[l + 1] > heights[r - 1]) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        return currMax;
    }
};
