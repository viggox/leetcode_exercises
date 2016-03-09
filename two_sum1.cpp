class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        vector<int> result;
        /*put indexes into hashtable*/
        for(int i=0; i<nums.size(); ++i){
            index[nums[i]] = i;
        }
        /*find pairs number which could be added to target*/
        for(int i=0; i<nums.size(); ++i){
            int distance = target - nums[i];
            if((index.find(distance) != index.end()) && (index[distance] != i)){
                result.push_back(i);
                result.push_back(index[distance]);
                break;
            }
        }
        return result;
    }
};
