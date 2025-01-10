#include <bits/stdc++.h>
using namespace std;


// c++ Solution
class Solution {
    vector<int> getStringFrequency(string& word) {
        vector<int> freq(26, 0);
        for (char word2 : word) {
            freq[word2 - 'a']++;
        }
        return freq;
    }
    bool compare(vector<int> &original, string& s) {
        vector<int> freq2 = getStringFrequency(s);
        for (int i = 0; i < 26; ++i) {
            if (freq2[i] < original[i]) return false;
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> original(26, 0);
        for (string& word : words2) {
            vector<int> temp = getStringFrequency(word);
            for (int i = 0; i < 26; ++i) {
                original[i] = max(original[i], temp[i]);
            }
        }
        for (string word : words1) {
            if (compare(original, word)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}