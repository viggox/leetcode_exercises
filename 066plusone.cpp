class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        bool add = false;
        for(auto it = digits.rbegin(); it != digits.rend(); ++it){
            *it += 1;
            if(*it > 9){
                *it %= 10;
                add = true;
                continue;
            }
            else{
                add = false;
                break;
            }
        }
        if(add == true){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
