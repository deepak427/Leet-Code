class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int min_arrows = 1;

        int comp = 0;
        for(int i = 1; i < points.size(); ++i){
            if(points[i][0] > points[comp][1]){
                ++min_arrows;
                comp=i;
            }
        }

        return min_arrows;

    }
};