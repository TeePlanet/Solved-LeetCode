/* 	139. Word Break
*   	Problem description can be found on https://leetcode.com/problems/word-break/ 
* 	Solved by John Huynh
*/


class Solution {
public:    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, vector<int> > startEnd;
        vector<bool> dp(s.size(), false); // record the reachable characters from the beginning of string s using wordDict strings
        int temp = 0;
        for (int i = 0; i < wordDict.size(); i++) {
            temp = s.find(wordDict[i]);
            while (temp != std::string::npos) {
                startEnd[temp].push_back(wordDict[i].size() - 1 + temp);
                temp = s.find(wordDict[i], temp + 1);
            }
        }
        for (auto const & element : startEnd[0]) {
            dp[element] = true;
        }
        for (int i = 1; i < s.size(); i++) {
            if (dp[i - 1] == true) {
                for (auto const & element : startEnd[i]) {
                    dp[element] = true;
                }
            }
        }
        return dp[s.size() - 1];
    }
};