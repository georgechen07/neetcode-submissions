class Solution {
public:
    bool isHappy(int n) {
        int m = n;
        while (true) {
            int temp = 0;
            while (n > 0) {
                temp += pow((n % 10), 2);
                n /= 10;
            }
            n = temp;

            temp = 0;
            while (m > 0) {
                temp += pow((m % 10), 2);
                m /= 10;
            }
            m = temp;
            temp = 0;
            while (m > 0) {
                temp += pow((m % 10), 2);
                m /= 10;
            }
            m = temp;

            if (n == 1 || m == 1) {
                return true;
            } else if (m == n) {
                return false;
            }
        }

        return false;
    }
};
