class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<31> n1 = num1;
        bitset<31> n2 = num2;
        int ones = n2.count();
        bitset<31> res;
        for (int i = 30; i >= 0; --i) {
            if (ones and n1[i] == 1) {
                ones--;
                res[i] = true;
            }
        }
        for (int i = 0; i < 31; ++i) {
            if (ones and !n1[i]) {
                ones--;
                res[i] = true;
            }
        }
        return res.to_ulong();
    }
};