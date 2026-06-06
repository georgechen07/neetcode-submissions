class Solution {
private:
    int ways[46] = {0};

public: Solution() {
    ways[1] = 1;
    ways[2] = 2;
}

public:
    int climbStairs(int n) {       
        if (n == 0 || ways[n] != 0) {
            return ways[n];
        }

        ways[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return ways[n];
    }
};
