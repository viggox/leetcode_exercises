class Solution {
public:
    int climbStairs(int n) {
        int result[2] = {1, 2};
        if(n <= 2){
            return result[n-1];
        }

        int f1 = 1;
        int f2 = 2;
        int fn;

        for(int i=3; i<=n; ++i){
            fn = f1+f2;
            f1 = f2;
            f2 = fn;
        }

        return fn;
    }
};
