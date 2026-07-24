class Solution {
public:
    int trap(vector<int>& height) {
        auto l = height.begin();
        auto r = height.end() - 1;

        while (*l == 0 && l != r) {
            ++l;
        }

        while (*r == 0 && r != l) {
            --r;
        }

        int curr_height = min(*l, *r);
        int area = (r - l + 1) * curr_height;

        while (l <= r) {
            cout << "l at " << *l << " and r at " << *r << " area = " << area << '\n';
            if (*l <= *r) {
                if (curr_height >= *l) {
                    area -= *l;
                }
                ++l;
                if (l == height.end()) {
                    break;
                }
            } else {
                if (curr_height >= *r) {
                    area -= *r;
                }
                --r;
            }
            int prev_height = curr_height;
            curr_height = max(min(*l, *r), curr_height);

            if (prev_height != curr_height) {
                area += (curr_height - prev_height) * (r - l + 1);
            }
        }

        return area;
    }
};
