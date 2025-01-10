#include <bits/stdc++.h>
using namespace std;


// c++ Solution
// Knuth-Morris-Pratt algorithm
class Solution {
    vector<int> buildlps(string& pat) {
        int sz = (int)pat.size();
        vector<int> lps(sz, 0);
        int len = 0;
        lps[0] = 0;
        for (int i = 1; i < sz; ++i) {
            if (pat[i] == pat[len]) {
                lps[i] = ++len;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                    --i;
                } else {
                    lps[i] = 0;
                }
            }
        }
        return lps;
    }
    bool KMP(string &s, string& pat) {
        vector<int> lps = buildlps(pat);
        int i = 0, j = 0;
        while (i < (int)s.size()) {
            if (s[i] == pat[j]) {
                j++;
                i++;
                if (j == (int)pat.size()) return true;
            }
            else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < (int)words.size(); ++i) {
            for (int j = 0; j < (int)words.size(); ++j) {
                if (i == j) continue;
                if (KMP(words[j], words[i])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}