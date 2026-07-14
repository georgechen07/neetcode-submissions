class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int currY = 0;
        int currX = 0;

        while (matrix[currY][currX] < target) {
            if (currY + 1 < matrix.size() && matrix[currY + 1][currX] <= target) {
                currY++;
            } else {
                currX++;
            }

            if (currX >= matrix[0].size() || currY >= matrix.size()) {
                return false;
            }
        }

        return matrix[currY][currX] == target;
    }
};
