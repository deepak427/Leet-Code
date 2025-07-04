class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int c_sum = 0;
        for(int i = 0; i < minutes; ++i){
            sum+=customers[i]*grumpy[i];
            c_sum = sum;
        }

        for(int end = minutes; end < customers.size(); ++end){
            c_sum = c_sum - (customers[end-minutes]*grumpy[end-minutes]) + (customers[end]*grumpy[end]);
            sum = max(sum, c_sum); 
        }
        cout << sum;
        
        int output = sum;
        for(int i  = 0; i < customers.size(); ++i){
            output = output + customers[i]*(!grumpy[i]);
        }

        return output;
    }
};