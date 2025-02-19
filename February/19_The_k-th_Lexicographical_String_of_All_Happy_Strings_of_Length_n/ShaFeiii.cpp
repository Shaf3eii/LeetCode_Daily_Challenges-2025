class Solution {
    vector<string> happyStrings;
    void gen(string cur, int n) {
        if ((int)cur.size() == n) {
            // check happinnes
            bool happy = true;
            for (int i = 0; i < cur.size() - 1; ++i) {
                happy &= !(cur[i] == cur[i + 1]);
            }
            if (happy) happyStrings.push_back(cur);
            return;
        }
        for (int i = 'a'; i <= 'c'; ++i) {
            cur.push_back(i);
            gen(cur, n);
            cur.pop_back();
        }
        
    }
public:
    string getHappyString(int n, int k) {
        gen("", n);
        if (k > happyStrings.size()) return "";
        sort(happyStrings.begin(), happyStrings.end());
        return happyStrings[k - 1];
    }
};



class Solution {
    vector<string> happyStrings;
    void gen(string cur, int n) {
        if ((int)cur.size() == n) {
            happyStrings.push_back(cur);
            return;
        }
        for (char i = 'a'; i <= 'c'; ++i) {
            if (cur.size() > 0 and cur.back() == i) { continue;}
            cur.push_back(i);
            gen(cur, n);
            cur.pop_back();
        }
        
    }
public:
    string getHappyString(int n, int k) {
        gen("", n);
        if (k > happyStrings.size()) return "";
        sort(happyStrings.begin(), happyStrings.end());
        return happyStrings[k - 1];
    }
};
