class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size()-1;

        while(low<=high){
            int mid = low+(high-low)/2;

            int leftOrder = -1, rightOrder = -1;
            if(mid-1>=0) leftOrder=arr[mid-1]<arr[mid];
            if(mid+1<arr.size()) rightOrder=arr[mid]<arr[mid+1];

            if(leftOrder && !rightOrder) return mid;
            if(rightOrder) low=mid+1;
            else high=mid-1;
        }

        return -1;
    }
};