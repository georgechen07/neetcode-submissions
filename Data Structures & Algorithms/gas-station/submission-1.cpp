class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
        }

        if (total_cost > total_gas) {
            return -1;
        }

        int total = 0;
        int res = 0;
        for (int j = 0; j < gas.size(); ++j) {
            total += gas[j] - cost[j];
            if (total < 0) {
                total = 0;
                res = j + 1; 
            }
        }

        return res;
    }
};
