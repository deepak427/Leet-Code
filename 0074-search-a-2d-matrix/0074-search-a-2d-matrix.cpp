class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size()-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            vector<int> row = matrix[mid];
            if(target<row[0]){
                high=mid-1;
                continue;
            }else if(target>row[row.size()-1]){
                low=mid+1;
                continue;
            }
            int rLow = 0, rHigh = row.size()-1;
            while(rLow<=rHigh){
                int rMid = rLow + (rHigh-rLow)/2;

                if(row[rMid]==target) return true;
                if(row[rMid]<target) rLow=rMid+1;
                else rHigh=rMid-1;
            }
            return false;
        }

        return false;
    }
};