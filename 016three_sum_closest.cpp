class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        int closest = INT_MAX;
        //handle corner case;
        if(nums.size() < 3){
            return 0;
        }
        //sort the numbers;
        sort(nums.begin(), nums.end());
        //find the closest;
        for(auto i = nums.begin(); i<nums.end()-2; ++i){
            auto j = i+1;
            if((i > nums.begin()) && (*i == *(i-1))){
                continue;
            }
            auto k = nums.end()-1;
            while(j < k){
                auto sum = *i + *j + *k;
                auto distance = abs(sum - target);
                if(distance < closest){
                    closest = distance;
                    result = sum;
                }
                //decide j or k who should move next;
                if(sum < target){
                    ++j;
                    while((*j == *(j-1)) && (j < k)){
                        ++j;
                    }
                }
                else if(sum > target){
                    --k;
                    while((*k == *(k+1)) && (j < k)){
                        --k;
                    }
                }
                else{
                    return result;
                }
            }
        }
        return result;
    }
};
