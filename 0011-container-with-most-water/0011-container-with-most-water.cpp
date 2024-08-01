class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;

        int result = 0;

        while(start < end){
            if(height[start] < height[end]){
                if(result < (end-start)*height[start]){
                    result=(end-start)*height[start];
                }
                start++;
            }else{
                if(result < (end-start)*height[end]){
                    result=(end-start)*height[end];
                }
                end--;
            }
        }

        return result;
    }
};