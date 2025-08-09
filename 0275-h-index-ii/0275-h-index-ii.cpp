class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int low = 0, high = size-1;
        int hVal = INT_MIN;

        while(low<=high){
            int mid = low +(high-low)/2;

            if(citations[mid]>size-mid) high=mid-1;
            else low=mid+1;
            hVal = max(hVal, min(citations[mid],size-mid));
        }

        return hVal;
    }
};