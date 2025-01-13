#include <bits/stdc++.h>
using namespace std;


// c++ Solution
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = (int)s.size();
        vector<int> firstAppear(26, 0);
        unordered_map<char, pair<int, int>> occurrences;
        for (int i = 0; i < n; ++i) {
            firstAppear[s[i] - 'a']++;
            if (firstAppear[s[i] - 'a'] == 1) {
                occurrences[s[i] - 'a'].first = i;
            } else {
                occurrences[s[i] - 'a'].second = i;
            }
        }
        int uniquePalindromes = 0;
        for (auto [f, l] : occurrences) {
            unordered_set<char> feElnos;
            for (int i = l.first + 1; i < l.second; ++i) {
                feElnos.insert(s[i]);
            }
            uniquePalindromes += (int)feElnos.size();
        }
        return uniquePalindromes;
    }
};

int main() {

    return 0;
}