#include <bits/stdc++.h>
using namespace std;


// c++ Solution
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = (int)s.size();
        if (n & 1) return false;
        stack<int> opened, unlocked;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                unlocked.push(i);
            }
            else if (s[i] == '(') {
                opened.push(i);
            } else {
                if (!opened.empty()) {
                    opened.pop();
                } else if (!unlocked.empty()) {
                    unlocked.pop();
                } else {
                    opened.push(10);
                    goto soz;
                }
            }
        }
        while (!unlocked.empty() and !opened.empty() and unlocked.top() > opened.top()) {
            opened.pop();
            unlocked.pop();
        }
        soz:
        return opened.empty();
    }
};

int main() {

    return 0;
}