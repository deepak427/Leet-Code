class Solution {
public:
    int getRadius(vector<int>& nums, int& target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return 0;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        if (low >= nums.size())
            return target - nums[high];
        if (high < 0)
            return nums[low] - target;
        return min(target - nums[high], nums[low] - target);
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int radius = INT_MIN;
        for (auto& h : houses) {
            radius = max(radius, getRadius(heaters, h));
        }

        return radius;
    }
};