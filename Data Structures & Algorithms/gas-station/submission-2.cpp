class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_ = 0;
        int total = 0;
        int res = 0;
        for (int j = 0; j < gas.size(); ++j) {
            total += gas[j] - cost[j];
            total_ += gas[j] - cost[j];
            if (total < 0) {
                total = 0;
                res = j + 1; 
            }
        }

        if (total_ < 0) {
            return -1;
        }
        return res;
    }
};
