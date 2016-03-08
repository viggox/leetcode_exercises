class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int index=0;
        bool dup = false;
        for(int i=1; i<nums.size(); ++i){
            if(nums[index] != nums[i]){
                nums[++index] = nums[i];
                dup = false;
            }
            else if(dup == false){
                nums[++index] = nums[i];
                dup = true;
            }
        }
        return index+1;
    }
};
