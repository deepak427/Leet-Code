class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = 0, fuel = 0, i = 0;

        while (i != index+gas.size() && index < gas.size()) {
            fuel = fuel + gas[i % gas.size()] - cost[i % gas.size()];
            ++i;
            if (fuel < 0) {
                index = i;
                fuel = 0;
            }
        }
        if(index>=gas.size()) return -1;

        return index;
    }
};