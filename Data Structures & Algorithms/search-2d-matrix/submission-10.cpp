class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int currY = matrix.size() / 2;
        int currX = matrix[0].size() / 2;

        int rightYBound = matrix.size();
        int leftYBound = 0;
        int rightXBound = matrix[0].size();
        int leftXBound = 0;

        if (target > matrix[matrix.size() - 1][matrix[0].size() - 1] || target < matrix[0][0]) {
            return false;
        }

        while (leftYBound != rightYBound) {
            if (leftYBound == currY) {
                break;
            } else if (matrix[currY][0] < target) {
                leftYBound = currY;
            } else if (matrix[currY][0] > target) {
                rightYBound = currY;
            } else {
                return true;
            }
            currY = (leftYBound + rightYBound) / 2;
        }

        while (leftXBound != rightXBound) {
            if (currX == leftXBound) {
                return matrix[currY][currX] == target;
            } else if (matrix[currY][currX] < target) {
                leftXBound = currX;
            } else if (matrix[currY][currX] > target) {
                rightXBound = currX;
            } else {
                return true;
            }
            currX = (leftXBound + rightXBound) / 2;
        }

        return false;
    }
};
