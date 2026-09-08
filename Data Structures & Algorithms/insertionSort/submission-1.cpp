// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> sol;
        if (pairs.empty()) {
            return sol;
        }
        
        for (int i = 0; i < pairs.size(); ++i) {
            auto curr = pairs[i];
            int j = i;
            while (j > 0 && pairs[j - 1].key > curr.key) {
                pairs[j] = pairs[j - 1];
                --j;
            }
            pairs[j] = curr;

            sol.push_back(pairs);
        }

        return sol;
    }
};
