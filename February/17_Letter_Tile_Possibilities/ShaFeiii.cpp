class Solution {
    bitset<8> vis;
    
    int genTiles(string &s) {
        int cnt = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (vis[i] or (i and s[i] == s[i - 1] and !vis[i - 1])) { continue;}
            vis[i] = true;
            cnt += genTiles(s);
            vis[i] = false;
        }
        return cnt;
    }

public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        return genTiles(tiles) - 1;
    }
};