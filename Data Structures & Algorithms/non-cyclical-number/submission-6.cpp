class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> m;
        while (!m.contains(n)) {
            m[n] = true;
            int temp = 0;
            while (n > 0) {
                temp += pow((n % 10), 2);
                n /= 10;
            }
            n = temp;
            if (n == 1) {
                return true;
            }
        }

        return false;
    }
};
