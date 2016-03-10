class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //corner case: less than three elements in nums;
        if(nums.size() < 3){
            return result;
        }
        //sort the numbers;
        sort(nums.begin(), nums.end());
        //squeeze for right solution recursively;
        for(auto i=nums.begin(); i<nums.end()-2; ++i){
            auto j=i+1;
            if((i>nums.begin()) && (*i == *(i-1))){
                //jump off repetitive values;
                continue;
            }
            auto k = nums.end()-1;
            while(j < k){
                if(*i + *j + *k < 0){
                    ++j;
                    while((*j == *(j-1)) && (j < k)){
                        ++j;
                    }
                }
                else if(*i + *j + *k > 0){
                    --k;
                    while((*k == *(k+1)) && (j < k)){
                        --k;
                    }
                }
                else{
                    result.push_back({*i, *j, *k});
                    ++j;
                    --k;
                    while((*j == *(j-1)) && (*k == *(k+1)) && (j < k)){
                        ++j;
                    }
                }
            }
        }
        return result;
    }
};
