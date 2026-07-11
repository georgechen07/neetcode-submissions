class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> areas;
        auto rights = vector<int>(heights.size());
        auto lefts = vector<int>(heights.size());
        for (int i = 0; i < heights.size(); ++i) {
            if (areas.empty() || heights[i] > heights[areas.top()]) {
                areas.push(i);
            } else {
                while (!areas.empty() && heights[i] < heights[areas.top()]) {
                    rights[areas.top()] = i;
                    areas.pop();
                }
                areas.push(i);
            }
        }
        while (!areas.empty()) {
            rights[areas.top()] = heights.size();
            areas.pop();
        }

        for (int i = heights.size() - 1; i >= 0; --i) {
            if (areas.empty() || heights[i] > heights[areas.top()]) {
                areas.push(i);
            } else {
                while (!areas.empty() && heights[i] < heights[areas.top()]) {
                    lefts[areas.top()] = i + 1;
                    areas.pop();
                }
                areas.push(i);
            }
        }
        while (!areas.empty()) {
            lefts[areas.top()] = 0;
            areas.pop();
        }

        int max_area = 0;
        for (int i = 0; i < rights.size(); ++i) {
            cout << "i = " << i << ", height = " << heights[i] << ", width = " << rights[i] - lefts[i] << '\n';
            cout << "right = " << rights[i] << ", left = " << lefts[i] << '\n';
            int curr_area = heights[i] * (rights[i] - lefts[i]);
            max_area = max(max_area, curr_area);
        }

        return max_area;
    }
};
