/*  62. Unique Paths
*   Problem description can be found on https://leetcode.com/problems/unique-paths/
*   Solved by John Huynh
*   Topic: Dynamic Programming.
*   Problem: Find the total number of all possible unique paths that a robot can take from the top-left corner.
    to the bottom-right corner.
*   Input: integers m and n representing m x n grid.
    Output: the total number of all unique paths from grid[0][0] to grid[m-1][n-1].

*/

#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:    
    int uniquePaths(int m, int n) {
        int grid[m][n];
        grid[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i != 0 && j != 0) {
                    grid[i][j] = grid[i][j-1] + grid[i-1][j];
                }
                else if (i == 0 && j != 0) {
                    grid[i][j] = grid[i][j-1];
                }
                else if (i != 0 && j == 0) {
                    grid[i][j] = grid[i-1][j];
                }
            }
        }
        return grid[m-1][n-1];
    }
};
int main() {
    int m = 2;
    int n = 3;
    Solution solve;
    cout << solve.uniquePaths(m, n) << endl;
}