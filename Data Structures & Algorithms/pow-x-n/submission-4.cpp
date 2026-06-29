class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1 || x == 0) {
            return x;
        }
        if (n == 0) {
            return 1;
        }
        return recurse(x, n);
    }

    double recurse(double const x, int n) {
        if (n == 1) {
            return x;
        }

        if (n < 0) {
            return 1 / recurse(x, -n);
        }

        if (n % 2 != 0) {
            return x * recurse(x, n - 1);
        } else {
            auto curr = recurse(x, n / 2);
            return curr * curr;
        }
    }
};
