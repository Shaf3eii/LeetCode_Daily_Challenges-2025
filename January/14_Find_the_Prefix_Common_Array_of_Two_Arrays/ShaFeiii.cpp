#include <bits/stdc++.h>
using namespace std;


// c++ Solution
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int len = (int)A.size();
        vector<int> C(len);
        vector<int> freq(len + 1, 0);
        int distinctSoFar = 0;
        for (int i = 0; i < len; ++i) {
            freq[A[i]]++;
            freq[B[i]]++;
            if (freq[A[i]] == 2) distinctSoFar++;
            if (freq[B[i]] == 2) distinctSoFar++;
            if (A[i] == B[i]) distinctSoFar--;
            C[i] = distinctSoFar;
        }
        return C;
    }
};

int main() {

    return 0;
}