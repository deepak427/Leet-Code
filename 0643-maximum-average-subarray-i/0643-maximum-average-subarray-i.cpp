class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int start = 1;
        int sum = 0;
        for(int i = 0; i < k; ++i){
            sum = sum + nums[i];
        }
        double avg = static_cast<double>(sum)/k;
        double r_avg = avg;

        for(int end = k; end < nums.size(); ++end){
            avg = avg - (static_cast<double>(nums[start-1])/k) + (static_cast<double>(nums[end])/k);
            r_avg = max(r_avg, avg);
            ++start;
        }

        return r_avg;
    }
};