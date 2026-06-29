class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1 || x == 0) {
            return x;
        }
        if (n == 0) {
            return 1;
        }
        if (n > 0) {
            return x * myPow(x, n - 1);
        } else {
            return myPow(x, n + 1) / x;
        }
    }
};
