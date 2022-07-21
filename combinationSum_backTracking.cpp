/*
*	39. Combination Sum
*	Solved by John Huynh
Medium

11267

242

Add to List

Share
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500
Accepted
1.1M
Submissions
1.7M
*/

/*
class Solution {
public:
    void backTrack(vector<int>& candidates, int target, vector<vector<int>> & result, vector<int> temp, int sum, int index) {        
        temp.push_back(candidates[index]);
        sum += candidates[index];
        
        if (sum == target) {
            result.push_back(temp);
            return;
        }        
        else if (sum > target) {
            return;
        }
        
        backTrack(candidates, target, result, temp, sum, index);
        
        for (int i = index + 1; i < candidates.size(); i++) {
            backTrack(candidates, target, result, temp, sum, i);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int sum = 0;
        for (int i = 0; i < candidates.size(); i++) {
            sum = 0;
            backTrack(candidates, target, result, temp, sum, i);            
        }
        return result;
    }
};
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
        backTrack(candidates, target - candidates[index], result, temp, index);
        temp.pop_back();
        backTrack(candidates, target, result, temp, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        backTrack(candidates, target, result, temp,  0);
        return result;
    }
};
