class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4){
            return result;
        }
        //sort the numbers;
        sort(nums.begin(), nums.end());
        //save a cache hashmap, key is sum of nums[a] and nums[b], value is pair<a, b>;
        unordered_map<int, vector<pair<int, int>>> cache;
        for(size_t a=0; a<nums.size(); ++a){
            for(size_t b=a+1; b<nums.size(); ++b){
                cache[nums[a] + nums[b]].push_back(make_pair(a, b));
            }
        }
        for(int c=0; c<nums.size(); ++c){
            for(size_t d=c+1; d<nums.size(); ++d){
                const int key = target-nums[c]-nums[d];
                //no value matches this key;
                if(cache.find(key) == cache.end()){
                    continue;
                }
                //a vector of int pairs matches this key;
                const auto& vec = cache[key];
                for(size_t k=0; k<vec.size(); ++k){
                    if(c <= vec[k].second){
                        continue;
                    }
                    result.push_back({nums[vec[k].first], nums[vec[k].second], nums[c], nums[d]});
                }
            }
        }
        //sort and erase repetitive quadruplets;
        sort(result.begin(), result.end());
        auto end_unique = unique(result.begin(), result.end());
        result.erase(end_unique, result.end());
        return result;
    }
};
