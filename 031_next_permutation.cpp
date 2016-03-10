class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2){
            return;
        }
        //find the violate number;
        int i;
        for(i = nums.size()-2; i>=0; --i){
            if(nums[i] < nums[i+1]){
                break;
            }
        }
        //reverse the numbers after the violate number;
        reverse(nums.begin()+i+1, nums.end());
        //no greater case exist, return lowest possible order;
        if(i == -1){
            return;
        }
        //binary search for the smallest number which greater than violate number;
        auto it = upper_bound(nums.begin()+i+1, nums.end(), nums[i]);
        //swap it with violate number;
        swap(*it, nums[i]);
        return;
    }
};
