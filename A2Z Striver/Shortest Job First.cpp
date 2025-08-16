class Solution {
  public:
    long long solve(vector<int>& bt) {
        //your code goes here
        auto bursts = bt;
        long long ans = 0, n=1*bt.size();
        sort(bursts.begin(), bursts.end());
        for(int i=0 ; i<n ;++i) {
          ans += (n-i-1)*bursts[i];
        }
        return ans/n;
    }
};
