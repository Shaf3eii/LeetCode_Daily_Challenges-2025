class Solution {
    bool isPunishmentNumber(int sum, int target) {
        if (target < 0 or sum < target) return false;
        if (sum == target) return true;
        return isPunishmentNumber(sum / 10, target - sum % 10) or isPunishmentNumber(sum / 100, target - sum % 100) or isPunishmentNumber(sum / 1000, target - sum % 1000);
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int sq = i * i;
            ans += isPunishmentNumber(sq, i) * sq;
        }
        return ans;
    }
};



// Another Solution
class Solution {
    bool isPunishmentNumber(int idx, string cur, int sum, int target) {
        if (idx == cur.size()) {
            return sum == target;
        }
        int num = 0;
        for (int i = idx; i < cur.size(); ++i) {
            num = num * 10 + (cur[i] - '0');
            if (num + sum > target) break;
            if (isPunishmentNumber(i + 1, cur, num + sum, target)) return true;
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int sq = i * i;
            ans += int(isPunishmentNumber(0, to_string(sq), 0, i)) * sq;
        }
        return ans;
    }
};