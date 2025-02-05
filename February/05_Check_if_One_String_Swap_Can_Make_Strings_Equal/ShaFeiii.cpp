class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        pair<int, int> swaps = {0, 0};
        for (int i = 0; i < (int)s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (swaps.first == 0) swaps.first = i;
                else if (swaps.second == 0) swaps.second = i;
                else break;
            }
        }
        bool flag = false;
        string tmp = s1;
        swap(tmp[swaps.first], tmp[swaps.second]);
        flag |= tmp == s2;
        tmp = s2;
        swap(tmp[swaps.first], tmp[swaps.second]);
        flag |= tmp == s1;
        return flag;
    }
};