/* 468. Validate IP Address
*	Problem description can be found on https://leetcode.com/problems/validate-ip-address/ 
*	Solved by John Huynh
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string checkIPv4 (string ip) {
        string x = "";
        int num = 0;
        int countDot = 0; // count number of dots.
        int countNum = 0; // count number of x strings with each x between two dots.
        for (int i = 0; i < ip.size(); i++) {
            if (ip[i] == '.') {
                if (x.size() > 1 && x[0] == '0') {
                    return "Neither";
                }
                if (i + 1 < ip.size() && ip[i + 1] == '.') {
                    return "Neither";
                }
                if (num > 255 || num < 0) {
                    return "Neither";
                }
                countDot += 1;
                countNum += 1;
                x = "";
                num = 0;
            }
            else {
                if (ip[i] - '0' > 9 || ip[i] - '0' < 0) { // can use isdigit.
                    return "Neither";
                }
                x += ip[i];
                num = num * 10 + (ip[i] - '0');
                if (x.size() > 3) {
                    return "Neither";
                }
            }
        }
        if (x.size() > 0) {
            if (x.size() > 1 && x[0] == '0') {
                return "Neither";
            }
            if (x.size() > 3) {
                return "Neither";
            }
            if (num > 255 || num < 0) {
                return "Neither";
            }
            countNum += 1;
        }
        if (countDot != 3) {
            return "Neither";
        }
        if (countNum != 4) {
            return "Neither";
        }
        return "IPv4";
    }
    
    string checkIPv6 (string ip) {
        string x = "";
        int countColon = 0; // count number of colons.
        int countNum = 0; // count number of x strings with each x between two colons.
        for (int i = 0; i < ip.size(); i++) {
            if (ip[i] == ':') {
                
                if (i + 1 < ip.size() && ip[i + 1] == ':') {
                    return "Neither";
                }
                countColon += 1;
                countNum += 1;
                x = "";
            }
            else {
                // can use isxdigit to check hexadecimal number.
                if (ip[i] > 102 || (ip[i] < 97 && ip[i] > 70) || (ip[i] < 65 && ip[i] > 57) || ip[i] < 48) { 
                    return "Neither";
                }
                x += ip[i];
                if (x.size() > 4) {
                    return "Neither";
                }
            }
        }
        if (x.size() > 0) {
            if (x.size() > 4) {
                return "Neither";
            }
            countNum += 1;
        }
        if (countColon != 7) {
            return "Neither";
        }
        if (countNum != 8) {
            return "Neither";
        }
        return "IPv6";
    }
    
    string validIPAddress(string queryIP) { 
        if (queryIP.find('.') != std::string::npos) {
            return checkIPv4(queryIP);
        }
        else if (queryIP.find(':') != std::string::npos) {
            return checkIPv6(queryIP);
        }
        else {
            return "Neither";
        }        
    }
};

int main() {
    //string queryIP = "50AA:RE44:3333:0:0:5B2C:2345:6833";
    //string queryIP = "50AA:E44:3333:0:0:5B2C:2345:6833";
    string queryIP = "192.168.10.100";
    Solution solve;
    cout << solve.validIPAddress(queryIP) << endl;
    return 0;
}