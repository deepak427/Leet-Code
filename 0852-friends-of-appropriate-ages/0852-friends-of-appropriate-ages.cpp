class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());

        int requests = 0;
        for (int i = 0; i < ages.size(); ++i) {
            auto it = upper_bound(ages.begin(), ages.end(), ages[i]) - 1;
            int lowerAge = (ages[i] / 2) + 8;
            int req = (it - ages.begin()) -
                      (lower_bound(ages.begin(), ages.end(), lowerAge) -
                       ages.begin() - 1) -
                      1;
            if (req > 0) {
                requests += req;
            }
        }

        return requests;
    }
};