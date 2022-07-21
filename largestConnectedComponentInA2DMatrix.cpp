/*
*	This problem is similar to Max Area of Island on https://leetcode.com/problems/max-area-of-island/
* 	Solved by John Huynh
*	Given a 2D matrix, return the size of the largest connected component.
	Recursion method for connected components.

* Example: 	
1.	11111
	10110
	10010
	01100
Answer: 10
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::unordered_set;
using std::max;

void recursion(vector<vector<int> > & matrix, vector<vector<int> > & visited, int & num,
	int row, int col) {
        if (row >= matrix.size() || col >= matrix[row].size()) {
            return;
        }
        visited[row][col] = 1;
        if (matrix[row][col] == 1) {
            num++;            
        }
        if (row - 1 >= 0 && matrix[row - 1][col] == matrix[row][col]
            && visited[row - 1][col] == 0) {
            visited[row - 1][col] = 1;
            recursion(matrix, visited, num, row - 1, col);
        }
        if (col - 1 >= 0 && matrix[row][col - 1] == matrix[row][col] 
            && visited[row][col - 1] == 0) {
            visited[row][col - 1] = 1;
            recursion(matrix, visited, num, row, col - 1);
        }
        if (row + 1 < matrix.size() && matrix[row + 1][col] == matrix[row][col]
            && visited[row + 1][col] == 0) {
            visited[row + 1][col] = 1;
            recursion(matrix, visited, num, row + 1, col);
        }
        if (col + 1 < matrix[row].size() && matrix[row][col + 1] == matrix[row][col]
            && visited[row][col + 1] == 0) {
            visited[row][col + 1] = 1;
            recursion(matrix, visited, num, row, col + 1);
        }
    }

int main() {
	/*
	Example 1:	
		11111
		10110
		10010
		01100
		Answer : 10
	* /
	/*
	vector<vector<int> > matrix(4, vector<int>(5, 0));
	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[0][2] = 1;
	matrix[0][3] = 1;
	matrix[0][4] = 1;
	matrix[1][0] = 1;
	matrix[1][2] = 1;
	matrix[1][3] = 1;
	matrix[2][0] = 1;
	matrix[2][3] = 1;
	matrix[3][1] = 1;
	matrix[3][2] = 1;
	vector<vector<int> > visited(4, vector<int>(5, 0));
	*/
	/*
	Example 2:
		00011
		10110
		10010
		01100
		Answer : 6
	*/
	/*
	vector<vector<int> > matrix(4, vector<int>(5, 0));
	matrix[0][3] = 1;
	matrix[0][4] = 1;
	matrix[1][0] = 1;
	matrix[1][2] = 1;
	matrix[1][3] = 1;
	matrix[2][0] = 1;
	matrix[2][3] = 1;
	matrix[3][1] = 1;
	matrix[3][2] = 1;
	vector<vector<int> > visited(4, vector<int>(5, 0));
	*/
	/*
	Example 3:
		14444331
		21143311
		32112321
		33212222
		31311444
		11311444
		Answer : 9
	*/
	vector<vector<int> > matrix(6, vector<int>(8, 1));
	matrix[0][1] = 4;
	matrix[0][2] = 4;
	matrix[0][3] = 4;
	matrix[0][4] = 4;
	matrix[0][5] = 3;
	matrix[0][6] = 3;
	matrix[1][0] = 2;
	matrix[1][3] = 4;
	matrix[1][4] = 3;
	matrix[1][5] = 3;
	matrix[2][0] = 3;
	matrix[2][1] = 2;
	matrix[2][4] = 2;
	matrix[2][5] = 3;
	matrix[2][6] = 2;
	matrix[3][0] = 3;
	matrix[3][1] = 3;
	matrix[3][2] = 2;
	matrix[3][4] = 2;
	matrix[3][5] = 2;
	matrix[3][6] = 2;
	matrix[3][7] = 2;
	matrix[4][0] = 3;
	matrix[4][2] = 3;
	matrix[4][5] = 4;
	matrix[4][6] = 4;
	matrix[4][7] = 4;
	matrix[5][2] = 3;
	matrix[5][5] = 4;
	matrix[5][6] = 4;
	matrix[5][7] = 4;

	vector<vector<int> > visited(6, vector<int>(8, 0));
	int num = 0;
	int maxNum = 0;
	int row = 0;
	int col = 0;

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			num = 0;
			if (visited[i][j] == 0) {
				recursion(matrix, visited, num, i, j);
			}
			maxNum = max(maxNum, num);
		}
	}
	cout << "Result: " << maxNum << endl;

	return 0;
}