#include <bits/stdc++.h>
using namespace std;


// c++ Solution
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int sz = (int)words.size();
        vector<int> vowelsSoFar(sz, 0);
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        auto isVowel = [&](string& s) {
            return vowels.count(s.front()) and vowels.count(s.back());
        };
        int i = 0;
        for (string& word : words) {
            if (i) {
                vowelsSoFar[i] = (isVowel(word) ? vowelsSoFar[i - 1] + 1 : vowelsSoFar[i - 1]);
            } else {
                vowelsSoFar[i] = isVowel(word);
            }
            ++i;
        }
        vector<int> ans;
        for (auto& query : queries) {
            int l = query[0], r = query[1];
            if (l) {
                ans.push_back(vowelsSoFar[r] - vowelsSoFar[l - 1]);
            } else {
                ans.push_back(vowelsSoFar[r]);
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}