class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int output = 0, c_sum = 0;
        int sum = threshold*k;

        for(int i =0; i < k; ++i){
            c_sum+=arr[i];
        }

        if(c_sum >= sum){
            ++output;
        }

        for(int end = k; end < arr.size(); ++end){
            c_sum+=arr[end];
            c_sum-=arr[end-k];

            if(c_sum >= sum){
                ++output;
            }
        }

        return output;
    }
};