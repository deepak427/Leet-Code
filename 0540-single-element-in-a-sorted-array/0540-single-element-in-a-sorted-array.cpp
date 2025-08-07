class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1;

        while(low<=high){
            int mid = low+(high-low)/2;
            int pos = -1;
            if(mid+1<nums.size() && nums[mid+1]==nums[mid]) pos=0;
            else if(mid-1>=0 && nums[mid-1]==nums[mid]) pos=1;
            
            if(pos==-1) return nums[mid];
            if(pos==1){
                if(mid%2==0) high=mid-2;
                else low=mid+1;
            }else{
                if(mid%2==0) low=mid+2;
                else high=mid-1;
            }
        }

        return -1;
    }
};