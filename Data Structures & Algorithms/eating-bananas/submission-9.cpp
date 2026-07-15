class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int k;
        int upper = piles[piles.size() - 1];
        int lower = 1;

        while (upper != lower) {
            k = (upper + lower) / 2;
            cout << "current speed = " << k << '\n';
            int time = 0;
            for (auto const& pile : piles) {
                time += ceil(1.0 * pile / k);
            }
            cout << "current time = " << time << '\n';

            if (time > h) {
                lower = k + 1;
            } else {
                upper = k;
            }
        }

        int time = 0;
        for (auto const& pile : piles) {
            time += ceil(1.0 * pile / upper);
        }
        if (time <= h) {
            return upper;
        }

        return k;
    }
};
