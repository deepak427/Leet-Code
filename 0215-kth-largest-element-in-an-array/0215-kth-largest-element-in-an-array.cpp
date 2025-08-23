class Solution {
public:
    struct Compare {
        bool operator()(int a, int b) {
            return a > b;
        }
    };
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, Compare> heap;

        for (int& i : nums) {
            heap.push(i);
            if (heap.size() > k)
                heap.pop();
        }

        return heap.top();
    }
};