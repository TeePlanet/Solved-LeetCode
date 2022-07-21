/*  91. Decode Ways
*    Problem description can be found on https://leetcode.com/problems/decode-ways/
*	Solved by John Huynh
    Both two approaches below passed all test cases. 
    The first approach uses multiplications when interupted by constraints and 
        fibonacci for un-interupted groups of numbers.
    The second approach uses dynamic programming and "carry-over" numbers when interupted by constraints. (More elegant)
    
*/

// First approach (Slower: 3ms): 
// Example: "1 2 2 0 2 2 3 2 2"
//           1 2     1 2 3 1 2
//             2 x       3 x 2 = 12
class Solution {
public:
    int numDecodings(string s) {
        //cout << "string: " << s << endl;
        //cout << "string size: " << s.size() << endl;
        if (s.size() > 0 && s[0] == '0') {
            return 0;
        }

        vector<long long unsigned> fibonacci(s.size() + 3, 0);
        int start = 0;
        int end = 0;
        string twoDigits = "";
        int isAlphabet = 0;
        long long unsigned total = 1;

        fibonacci[0] = 1;
        fibonacci[1] = 1;
        fibonacci[2] = 2;
        fibonacci[3] = 3;
        unordered_set<string> numbers;
        for (int i = 1; i <= 26; i++) {
            numbers.insert(to_string(i));
        }
        for (int i = 1; i < s.size(); i++) {
            if (i > 2) {
                fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
            }
            //twoDigits = s.substr(i - 1, 2);
            twoDigits = string() + s[i - 1] + s[i];
            isAlphabet = numbers.count(twoDigits);
            if (isAlphabet == 0 && s[i] == '0') {
                return 0;
            }
            else if (isAlphabet == 0 && s[i - 1] != '0') {
                //cout << "twoDigits: " << twoDigits << endl;
                end = i - 1;
                //cout << "start1: " << start << endl;
                //cout << "end1: " << end << endl;
                total *= fibonacci[end - start + 1];
                start = i;
                end = i;
            }
            else if (isAlphabet == 1 && s[i] == '0') {
                end = i - 2;
                //cout << "start2: " << start << endl;
                //cout << "end2: " << end << endl;
                total *= fibonacci[end - start + 1];
                start = i + 1;
                end = i + 1;
            }

        }

        //cout << "Start: " << start << endl;
        //cout << "End: " << end << endl;
        end = s.size() - 1;
        //cout << "End: " << end << endl;
        if (end - start - 1 >= 0) {
            fibonacci[end - start + 1] = fibonacci[end - start + 1 - 2] + fibonacci[end - start + 1 - 1];
        }

        //cout << "fibonacci of string size: " << fibonacci[end - start + 1] << endl;
        if (end >= start) {
            total *= fibonacci[end - start + 1];
        }

        return total;
    }
};

// Second approach (Faster: 0ms):
// Example: "1 2 2 0 2 2 3 2 2"
//           1 2 0 2 2 4 6 6 12
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() > 0 && s[0] == '0') {
            return 0;
        }
        vector<long long unsigned> fibonacci(s.size() + 3, 0);
        int start = 0;
        int end = 0;
        string twoDigits = "";
        int isAlphabet = 0;
        long long unsigned total = 1;
        fibonacci[0] = 1;
        fibonacci[1] = 1;
        unordered_set<string> numbers;
        for (int i = 1; i <= 26; i++) {
            numbers.insert(to_string(i));
        }

        if (s.size() == 2) {
            twoDigits = string() + s[0] + s[1];
            isAlphabet = numbers.count(twoDigits);
            if (isAlphabet == 1 && s[1] == '0') {
                return 1;
            }
        }
        int temp = 0;
        for (int i = 1; i < s.size() + 1; i++) {
            twoDigits = string() + s[i - 1] + s[i];
            isAlphabet = numbers.count(twoDigits);
            if (isAlphabet == 0 && s[i] == '0') {
                return 0;
            }
            else if (isAlphabet == 1 && s[i] == '0' && i - 1 >= 0) {
                if (i - 2 < 0) {
                    temp = 1;
                    fibonacci[i] = temp;
                }
                else {
                    fibonacci[i] = fibonacci[i - 2];
                }
            }
            else if (isAlphabet == 0 && i - 1 >= 0) {
                fibonacci[i] = fibonacci[i - 1];
            }
            else if (i - 1 >= 0 && i + 1 <= s.size() && s[i + 1] != '0') {
                if (i - 2 < 0) {
                    temp = 1;
                    fibonacci[i] = temp + fibonacci[i - 1];
                }
                else {
                    fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
                }
            }
        }
        return fibonacci[s.size()];
    }
};

/*
* 
"123122"
"1231222"
"12312222"
"123122222"
"122022322"
"10011"
"11111111111111111111111111111"
*/