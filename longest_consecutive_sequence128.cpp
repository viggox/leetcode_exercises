class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_map<int, bool> n_used;
        for(auto i : nums){
            n_used[i] = false;
        }
        int longest = 0;
        for(auto i: nums){
            if(n_used[i]){
                continue;
            }
            int length = 1;
            n_used[i] = true;
            for(int j=i+1; n_used.find(j) != n_used.end(); ++j){
                n_used[j] = true;
                ++length;
            }
            for(int j=i-1; n_used.find(j) != n_used.end(); --j){
                n_used[j] = true;
                ++length;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};
