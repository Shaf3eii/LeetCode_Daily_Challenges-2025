class Solution {
    public:
        string removeOccurrences(string s, string part) {
            string ans;
            int j = 0;
            for (auto c : s) {
                ans.push_back(c);
                if ((int)ans.size() >= (int)part.size() 
                and !ans.compare((int)ans.size() - (int)part.size(), (int)part.size(), part)) {
                    // compare function is more effecient than substr, since substr() creates a new string O(M) before comparison, 
                    // while compare() directly compares the characters without extra allocation O(1).
                    ans.resize((int)ans.size() - (int)part.size());
                }
            }
            return ans;
        }
    };