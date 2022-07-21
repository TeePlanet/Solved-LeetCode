/* 	Rotate Image
*	Problem description on https://leetcode.com/problems/rotate-image/ and codesignal.com
*	Solved by John Huynh


Example

For n x n 2D matrix representing an image:
a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]

The output should be:
solution(a) =
    [[7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]] */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int halfSize = matrix.size() / 2;
        int innerSquare_left = 0;
        for (int i = 0; i < halfSize; i++) {
            innerSquare_left = i;
            innerSquare_right = matrix[i].size() - i - 1;
            for (int j = innerSquare_left; j < innerSquare_right; j++) {
                swap(matrix[i][j], matrix[matrix.size() - j - 1][i]); // swap(up, down)
                swap(matrix[matrix.size() - j - 1][i], matrix[matrix.size() - i - 1][matrix.size() - j - 1]); // swap(left, right)
                swap(matrix[matrix.size() - i - 1][matrix.size() - j - 1], matrix[j][matrix.size() - i - 1]); // swap(down, up)
            }
        }

    }
};
