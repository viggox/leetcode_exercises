class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int result = 0;

        for(int i=0; i<heights.size(); ){
            if(s.empty() || heights[i] > heights[s.top()]){
                s.push(i);
                ++i;
            }
            else{
                int tmp = s.top();
                s.pop();
                result = max(result, heights[tmp]*(s.empty() ? i : i-s.top()-1));
            }
        }
        return result;
    }
};
