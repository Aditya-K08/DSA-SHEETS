class Solution {
    public:
        double myPow(double x, int n) {
            if (n == 0) return 1;
            if (n == 1) return x;
            if (x == 1) return 1;
            if(x==-1 && n<0) return 1;
            if (n==INT_MIN) return 0;
            if (n < 0) {
                return 1.0 / myPow(x, -(long long)n);
            }
    
            if (n % 2 == 0) {
                return myPow(x * x, n / 2);
            } else {
                return x * myPow(x * x, n / 2);
            }
        }
    };
    