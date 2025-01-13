#include <bits/stdc++.h>
using namespace std;


// c++ Solution
class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
            if (freq[c - 'a'] == 3) {
                freq[c - 'a'] -= 2;
            }
        }
        int sz = 0;
        for (auto f : freq) {
            sz += f;
        }
        return sz;
    }
};

int main() {

    return 0;
}