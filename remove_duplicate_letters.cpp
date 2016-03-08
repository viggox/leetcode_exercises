class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> ccount(256, 0);
        vector<bool> visited(256, false);
        string result("0");
        for(auto c : s){
            ccount[(unsigned char)c]++;
        }
        for(auto c: s){
            ccount[(unsigned char)c]--;
            if(visited[(unsigned char)c]){
                continue;
            }
            while((c < result.back()) && ccount[result.back()]){
                visited[(unsigned char)result.back()] = false;
                result.pop_back();
            }
            result += c;
            visited[(unsigned char)c] = true;
        }
        return result.substr(1);
    }
};
