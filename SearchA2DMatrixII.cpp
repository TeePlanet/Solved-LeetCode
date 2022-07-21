/* 	240. Search a 2D Matrix II
*  	Problem description on https://leetcode.com/problems/search-a-2d-matrix-ii/
* 	Solved by John Huynh
* Given a matrix m x n with integers in each row sorted in ascending order from left to right
*                       and integers in each column sorted in ascending order from top to bottom,
*                       search for an integer "target" in this matrix,
                        return true if it is in the matrix, else return false.
*  The method used to solve this problem is to divide the matrix into 4 regions
    based on the mid point. If target > mid value or target < mid value, rule out 
    one region and search for it in the remaining three regions.


Constraints:
m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
Accepted
605K
Submissions
1.2M
*/

class Solution {
public:
    bool search(vector<vector<int>>& matrix, int target, int left, int right, int top, int bottom) {
        bool ans = false;      
        int rowMid = left + (right - left) / 2;
        int colMid = top + (bottom - top) / 2;
        if (left == right && top == bottom) {
            if (matrix[colMid][rowMid] == target) { 
                return true;
            }
            else {
                return false;
            }
        }
        else if (left < right && top < bottom) { 
            if (matrix[colMid][rowMid] == target) {
                return true;
            }
            else if (matrix[colMid][rowMid] > target) {
                ans = search(matrix, target, left, rowMid, top, colMid) || search(matrix, target, rowMid + 1, right, top, colMid) || search(matrix, target, left, rowMid, colMid + 1, bottom);
            }
            else if (matrix[colMid][rowMid] < target) {                
                ans = search(matrix, target, rowMid + 1, right, top, colMid) || search(matrix, target, rowMid + 1, right, colMid + 1, bottom) || search(matrix, target, left, rowMid, colMid + 1, bottom);
            }
        }
        else if (left < right && top == bottom) { 
            if (matrix[colMid][rowMid] == target) {
                return true;
            }
            else if (matrix[colMid][rowMid] > target) {
                ans = search(matrix, target, left, rowMid - 1, top, bottom);
            }
            else if (matrix[colMid][rowMid] < target) {
                ans = search(matrix, target, rowMid + 1, right, top, bottom);
            }
        }
        else if (left == right && top < bottom) { 
            if (matrix[colMid][rowMid] == target) {
                return true;
            }
            else if (matrix[colMid][rowMid] > target) {                
                ans = search(matrix, target, left, right, top, colMid - 1);
            }
            else if (matrix[colMid][rowMid] < target) {
                ans = search(matrix, target, left, right, colMid + 1, bottom);
            }
        }
        
        return ans;
    }
        
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, target, 0, matrix[0].size() - 1, 0, matrix.size() - 1);
    }
};