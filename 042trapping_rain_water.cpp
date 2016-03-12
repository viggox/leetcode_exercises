class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> max_left(n);         //stores max_lefts;
        vector<int> max_right(n);        //stores max_rights;
        //store max_left from left to right, store max_right from right to left;
        for(int i=1; i<n; ++i){            //i must start from 1, max_left[0] must be 0;
            max_left[i] = max(max_left[i-1], height[i-1]);
            max_right[n-1-i] = max(max_right[n-i], height[n-i]);    //max_right[n-1] must be 0 too;
        }
        int sum = 0, temp;
        for(int i=0; i<n; ++i){           
            if((temp = min(max_left[i], max_right[i])) > height[i]){
                sum += temp - height[i];
            }
        }
        return sum;
    }
};
