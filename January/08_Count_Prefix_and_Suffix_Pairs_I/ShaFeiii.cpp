#include <bits/stdc++.h>
using namespace std;


// c++ Solution
class Solution {
    bool isPrefixAndSuffix(string &s1, string &s2) {
        if ((int)s1.size() > (int)s2.size()) return false;
        for (int i = 0, j = 0; i < (int)s1.size(); ++i, ++j) {
            if (s1[i] != s2[j]) return false;
        }
        for (int i = (int)s1.size() - 1, j = (int)s2.size() - 1; i >= 0; --i, --j) {
            if (s1[i] != s2[j]) return false;
        }
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for (int i = 0; i < (int)words.size(); ++i) {
            for (int j = i + 1; j < (int)words.size(); ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) cnt++;
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}