class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0;
        int doubleSum = 0;

        for(int &value: nums){
            if(value < 10){
                singleSum+=value;
            }else{
                doubleSum+=value;
            }
        }

        return (singleSum!=doubleSum);
    }
};