/* 	Text Justification
* 	Problem description can be found on https://leetcode.com/problems/text-justification/
*	Solved by John Huynh
*/

vector<string> solution(vector<string> words, int l) {
    int start = 0;
    int end = 0;
    int numSpaces = 0;
    int numOfCharsInLine = 0;
    int lineSize = 0;
    string s = "";
    vector<string> strs;
    int between = 0;
    int extra = 0;
    int spacesBetween = 0;
    int numOfWordsInLine = 0;
    if (words[0] == s) {
        s.append(l, ' ');
        strs.push_back(s);
        return strs;
    }
    for (int i = 0; i < words.size(); i++) {
        lineSize = numOfCharsInLine;
        numOfCharsInLine += words[i].size();
        end = i;
        between = end - start;

        if (numOfCharsInLine + between > l) {
            between -= 1;
            numSpaces = l - lineSize;
            if (between > 0) {
                extra = numSpaces % between;
            }
            numOfWordsInLine = between + 1;
            if (extra == 0 || between == 0) {
                if (between > 0) {
                    spacesBetween = floor(numSpaces / between);
                }
                else {
                    spacesBetween = 0;
                }
                while (numOfWordsInLine > 0) {
                    s += words[start];
                    cout << "s: " << s << endl;
                    if (numOfWordsInLine > 1) {
                        s.append(spacesBetween, ' ');
                    }
                    start += 1;
                    numOfWordsInLine -= 1;
                }
            }
            else if (extra > 0) {
                if (between > 0) {
                    spacesBetween = floor((numSpaces - extra) / between);
                }
                else {
                    spacesBetween = 0;
                }
                s += words[start];
                s.append(spacesBetween, ' ');
                s.append(1, ' ');
                extra -= 1;
                start += 1;
                numOfWordsInLine -= 1;
                while (numOfWordsInLine > 0) {
                    s += words[start];
                    if (numOfWordsInLine > 1) {
                        s.append(spacesBetween, ' ');
                        if (extra > 0) {
                            s.append(1, ' ');
                            extra -= 1;
                        }
                    }
                    start += 1;
                    numOfWordsInLine -= 1;
                }
            }
            if (l - s.size() > 0) {
                s.append(l - s.size(), ' ');
            }

            strs.push_back(s);
            start = i;
            end = i;
            s = "";
            extra = 0;
            spacesBetween = 0;
            numOfWordsInLine = 0;
            numOfCharsInLine = words[i].size();
        }
    }
    lineSize = numOfCharsInLine;
    between = end - start;
    int remaining = 0;
    if (between > 0) {
        numOfWordsInLine = between + 1;
        while (numOfWordsInLine > 0) {
            s += words[start];
            if (numOfWordsInLine > 1) {
                s.append(1, ' ');
            }
            start += 1;
            numOfWordsInLine -= 1;
        }
        remaining = l - s.size();
        if (remaining > 0) {
            s.append(remaining, ' ');
        }
        strs.push_back(s);
    }
    else if (numOfCharsInLine > 0) {
        s = words[words.size() - 1];
        s.append(l - s.size(), ' ');
        strs.push_back(s);
    }
    return strs;
}
