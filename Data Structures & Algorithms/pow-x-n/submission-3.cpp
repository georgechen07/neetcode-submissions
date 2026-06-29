class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1 || x == 0) {
            return x;
        }
        if (n == 0) {
            return 1;
        }
        return recurse(x, n, x, 1);
    }

    double recurse(double const x, int const n, double curr, double currPow) {
        cout << "called with" << '\n' << "curr = " << curr << '\n' << "currPow = " << currPow << '\n';
        if (n == currPow) {
            return x;
        }

        if (n < 0) {
            return 1 / recurse(x, -n, curr, currPow);
        }

        if (currPow != 1 && (currPow <= n / 2 || 2 * currPow - n < n - currPow - 1)) {
            return curr * recurse(x, n, curr * curr, currPow * 2);
        } else if (n > currPow) {
            // 2 * call
            //  currPow = 2, curr = 2, n = 4
            // 
            return x * recurse(x, n, curr * x, currPow + 1);
        } else {
            currPow--;
            return recurse(x, n, curr / x, currPow) / x;
        }
    }
};
