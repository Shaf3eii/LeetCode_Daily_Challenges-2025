#include <bits/stdc++.h>
using namespace std;


// c++ Solution
class Solution {
public:
    bool canConstruct(string s, int k) {
        if ((int)s.size() < k) return false;
        if ((int)s.size() == k) return true;
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        int oddCount = 0, evenCount;
        for (int i = 0; i < 26; ++i) {
            oddCount += (freq[i] & 1);
            evenCount += !(freq[i] & 1);
        }
        if (oddCount > k) return false;
        return pow(2, evenCount + oddCount) >= k;
    }
};
int main() {

    return 0;
}