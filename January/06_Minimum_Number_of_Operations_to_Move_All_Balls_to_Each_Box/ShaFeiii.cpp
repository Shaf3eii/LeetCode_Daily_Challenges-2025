#include <bits/stdc++.h>
using namespace std;


// c++ Solution
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = (int)boxes.size();
        vector<int> ans(n, 0);
        int ballsLeft = 0, ballsRight = 0, movesLeft = 0, movesRight = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] += movesLeft;
            ballsLeft += (boxes[i] == '1');
            movesLeft += ballsLeft;
            ans[n - i - 1] += movesRight;
            ballsRight += (boxes[n - i - 1] == '1');
            movesRight += ballsRight;
        }
        return ans;
    }
};

int main() {

    return 0;
}