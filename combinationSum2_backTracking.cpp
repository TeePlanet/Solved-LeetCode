/* 	Combination Sum II
*	Problem description on https://leetcode.com/problems/combination-sum-ii/.
*	Solved by John Huynh
*   Problem:     Find all unique combinations of elements in an array "candidates" with each 
                 combination's elements summing to a "target" number. 
    Constraints: Each number in candidates is used once in the combination.
                 No duplicate combination.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 
*/

class Solution {
public:
    void backTrack(vector<int>& candidates, int target, vector<vector<int>> & result, vector<int> & temp, int index) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        if (target < 0 || index >= candidates.size()) {
            return;
        }
        
        temp.push_back(candidates[index]);
        backTrack(candidates, target - candidates[index], result, temp, index + 1);        
        temp.pop_back();
        while (index + 1 < candidates.size() && candidates[index + 1] == candidates[index]) {
            index += 1;
        }
        backTrack(candidates, target, result, temp, index + 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, target, result, temp,  0);
        return result;
    }
};