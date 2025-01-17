// if number of 1's is odd --> false

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ones = accumulate(derived.begin(), derived.end(), 1);
        return (ones & 1);
    }
};