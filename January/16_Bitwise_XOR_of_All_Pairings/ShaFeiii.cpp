/*
    each element in nums1 will appear m times (size of the nums2)
    and
    each element in nums2 will appear n times (size of the nums1)
    thus, based on the properties of xor 
    num ^ num = 0
    if the size is even then each element will cancel out to 0, otherwise will make differnce
*/

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size(), m = (int)nums2.size();
        int res = 0;
        if (m & 1) {
            for (int i = 0; i < n; ++i) {
                res ^= nums1[i];
            }
        }
        if (n & 1) {
            for (int i = 0; i < m; ++i) {
            res ^= nums2[i];
            }
        }
        return res;
    }
};