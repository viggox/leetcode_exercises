class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> index;
        vector<int> result;
        /*put indexes into ordered hashmap*/
        for(int i=0; i<numbers.size(); ++i){
            index[numbers[i]] = i;
        }
        /*find pairs which could be added to target*/
        for(int i=0; i<numbers.size(); ++i){
            int distance = target-numbers[i];
            if((index.find(distance) != index.end()) && (index[distance] > i)){
                result.push_back(i+1);
                result.push_back(index[distance]+1);
                break;
            }
        }
        return result;
    }
};
