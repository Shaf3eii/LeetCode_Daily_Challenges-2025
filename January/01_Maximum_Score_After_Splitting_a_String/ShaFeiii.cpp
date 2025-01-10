#include <bits/stdc++.h>
using namespace std;


// c++ Solution
class Solution {
public:
    int maxScore(string s) {
        int leftZeros = 0;
        int rightOnes = 0;
        int maxSum = 0;
        for (auto c : s) rightOnes += (c == '1');
        for (int i = 0; i < (int)s.size() - 1; ++i) {
            leftZeros += (s[i] == '0');
            rightOnes -= (s[i] == '1');
            maxSum = max(maxSum, leftZeros + rightOnes);
        }
        return maxSum;
    }
};

int main() {

    return 0;
}