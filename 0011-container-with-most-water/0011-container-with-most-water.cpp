class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1, max_water = 0;

        while (start < end) {
            max_water = max(max_water, (end - start) * min(height[start], height[end]));

            if (height[start] < height[end])
                ++start;
            else
                --end;
        }

        return max_water;
    }
};