/*
*	74. Search a 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix/
*	Solved by John Huynh

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mn = matrix.size() * matrix[0].size();
        int left = 1;
        int right = mn;
        int mid = left + (right - left)/2;
        int row = 0;
        int col = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        while (true) {
            mid = left + (right - left)/2;
            if (mid > cols) {
                if (cols > 1) {
                    if (mid % cols == 0) {
                        row = floor(mid/cols);
                        col = cols;
                    }
                    else {                
                        row = floor(mid/cols) + 1;
                        col = mid % cols;                        
                    }
                }
                else {
                    row = mid;
                    col = 1;
                }
            }
            else if (mid <= cols) {
                row = 1;
                col = mid;
            }
            if (matrix[row-1][col-1] == target) {
                return true;
            }
            else if (matrix[row-1][col-1] > target) {
                if (col - 1 > 0 && matrix[row-1][col-2] < target) {
                    return false;
                }
                else if (col - 1 == 0 && row - 1 > 0 && matrix[row-2][cols-1] < target) {
                    return false;
                }
                else if (col - 1 == 0 && row - 1 == 0) {
                    return false;
                }
                right = mid - 1;
            }
            else if (matrix[row-1][col-1] < target) {
                if (col + 1 <= cols && matrix[row-1][col] > target) {
                    return false;
                }
                else if (col + 1 > cols && row + 1 <= rows && matrix[row][0] > target) {
                    return false;
                }
                else if (col + 1 > cols && row + 1 > rows) {
                    return false;
                }
                left = mid + 1;
            }
            else {
                return false;
            }
        }
        return true;
    }
};