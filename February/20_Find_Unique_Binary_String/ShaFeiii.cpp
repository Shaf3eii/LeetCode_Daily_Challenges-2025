class Solution { // 100% Time - 47% Memory
    unordered_set<string> freq;
    int n;
    bool special(string& cur) {
        if ((int)cur.size() == n) {
            if (freq.find(cur) == freq.end()) {
                return true;
            }
            return false;
        }
        for (char i = '0'; i <= '1'; ++i) {
            cur.push_back(i);
            if (special(cur)) return true;
            cur.pop_back();
        }
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        for (auto s : nums) {
            freq.insert(s);
        }
        string ans;
        special(ans);
        return ans;
    }
};


class Solution { // 100% Time - 33.5% Memory
    unordered_set<string> freq;
    int n;
    bool special(string& cur, int idx) {
        if (idx == n) {
            if (freq.find(cur) == freq.end()) {
                return true;
            }
            return false;
        }
        for (char i = '0'; i <= '1'; ++i) {
            cur[idx] = i;
            if (special(cur, idx + 1)) return true;
            cur[idx] = ' ';
        }
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        for (auto s : nums) {
            freq.insert(s);
        }
        string ans;
        for (int i = 0; i < n; ++i) ans.push_back(' ');
        special(ans, 0);
        return ans;
    }
};