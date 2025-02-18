class Solution { // BackTracking
    string s, ans;
    bitset<10> vis;

    bool cons(int idx) {
        if (idx == s.size()) return ans.size() == idx + 1;
        for (int i = '1'; i <= '9'; ++i) {
            if (!vis[i - '0'] and ((s[idx] == 'I' and ans.back() < i) or (s[idx] == 'D' and ans.back() > i))) {
                ans.push_back(i);
                vis[i - '0'] = true;
                if (cons(idx + 1)) return true;
                ans.pop_back();
                vis[i - '0'] = false;
            }
        }
        return false;
    }

public:
    string smallestNumber(string pattern) {
        s = pattern;
        for (int i = '1'; i <= '9'; ++i) {
            ans.push_back(i);
            vis[i - '0'] = true;
            if (cons(0)) return ans;
            ans.pop_back();
            vis[i - '0'] = false;
        }
        return ans;
    }
};