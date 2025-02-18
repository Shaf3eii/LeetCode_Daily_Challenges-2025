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



// Another Solution
class Solution { // Stack
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans;
        stack<char> st;
        for (int i = 0; i <= n; ++i) {
            st.push((i + 1) + '0');
            if (i == n or pattern[i] == 'I') {
                while (!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};
