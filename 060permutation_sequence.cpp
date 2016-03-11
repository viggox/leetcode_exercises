class Solution {
public:
    string getPermutation(int n, int k) {
        //create a sorted sequence;
        string s(n, '0');
        for(int i=1; i<=n; ++i){
            s[i-1] += i;
        }
        //set a private function to handle all these dirty stuffs;
        return kth_permutation(s, k);
    }
private:
    //create a function to calculate factorial;
    int factorial(int n) {
        int result = 1;
        for(int i=n; i>=1; --i){
            result *= i;
        }
        return result;
    }
    //the function template which ues contour encoding to find k_th sequence;
    template<typename Sequence>
    //sorted sequence is the first/lowest sequence;
    Sequence kth_permutation(Sequence &seq, int k){
        const int n = seq.size();
        Sequence S(seq);
        Sequence result;

        int base = factorial(n-1);
        --k;

        for(int i=n-1; i>0; --i){
            auto a = next(S.begin(), k/base);    //a1 = k1/(n-1)!;
            result.push_back(*a);
            S.erase(a);     //erase means jump off pushed values by the algorithm side;
            k %= base;       // k2 = k%(n-1)!;
            base /= i;      //(n-1)! ---> (n-2)!;
        }

        result.push_back(S[0]);
        return result;
    }
};
