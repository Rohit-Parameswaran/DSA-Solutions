class Solution {
public:
    int getSum(int a, int b) {
        int c;
        do {
            c = a ^ b;
            b = (a & b) << 1;
            a = c;
        } while(b);
        return a;
    }
};
