class Solution {
private: int totalCost[101] = {0};

public:
    Solution() {
        totalCost[0] = 0;
        totalCost[1] = 0;
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        return recurse(cost.size(), cost);
    }

    int recurse(int floor, vector<int>& cost) {
        if (floor == 0 || floor == 1 || totalCost[floor] != 0) {
            return totalCost[floor];
        }
        
        totalCost[floor] = min(recurse(floor - 1, cost) + cost[floor - 1], recurse(floor - 2, cost) + cost[floor - 2]);
        
        // cout << "floor: " << floor << " " << recurse(floor - 1, cost) + cost[floor - 1] << '\n';
        // cout << "floor: " << floor << " " << recurse(floor - 2, cost) + cost[floor - 2] << '\n';
        return totalCost[floor];
    }
};
