class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m_nums;
        for(int i = 0; i< nums.size(); ++i){
            m_nums[nums[i]] = i;
        }

        for(int i = 0; i< nums.size(); ++i){
            if(m_nums.find(target - nums[i]) != m_nums.end()){
                if( i != m_nums.find(target - nums[i])->second){
                    cout << i << endl;
                    vector<int> result;
                    result.push_back(i);
                    result.push_back(m_nums.find(target - nums[i])->second);
                    return result;                    
                }
            }
            m_nums.erase(nums[i]);
        }
        vector<int> result;
        return result;

    }
};