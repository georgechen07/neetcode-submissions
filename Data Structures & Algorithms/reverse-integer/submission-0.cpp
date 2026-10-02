class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int max = INT_MAX / 10;
        int min = INT_MIN / 10;
        while (x != 0) {
            if (res > max || res < min) {
                return 0;
            }
            res *= 10;
            res += (x % 10);
            x /= 10;
        }

        return res;
    }
};
