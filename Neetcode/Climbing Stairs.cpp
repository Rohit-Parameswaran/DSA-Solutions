class Solution {
public:
    int climbStairs(int n) {
        int two_sb=1, one_sb=1, cur_s = 1;
        for(int i=2;i<=n;++i) {
            cur_s = two_sb + one_sb;
            two_sb = one_sb;
            one_sb = cur_s;
        }
        return cur_s;
    }
};
