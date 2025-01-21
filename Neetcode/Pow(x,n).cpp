class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return 1/myPow(x, -n);
        else if(n == 0) return 1;
        return n&1 ? x*myPow(x*x, n/2) : myPow(x*x, n/2);
    }
};

// Iterative
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;

        double ans = 1;
        int power = abs((long)n);

        while(power) {
            if(power & 1){
                ans *= x;
            }
            x *= x;
            power /= 2;
        }

        return n<0 ? 1/ans : ans;
    }
};
