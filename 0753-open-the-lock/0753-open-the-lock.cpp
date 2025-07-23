class Solution {
public:
    vector<string> getNeighbours(string s) {
        vector<string> neighhbours;

        for (int i = 0; i < 4; ++i) {
            string temp = s;
            temp[i] = temp[i] + 1;
            if (temp[i] == ':')
                temp[i] = '0';
            neighhbours.push_back(temp);

            temp = s;
            temp[i] = temp[i] - 1;
            if (temp[i] == '/')
                temp[i] = '9';
            neighhbours.push_back(temp);
        }

        return neighhbours;
    }

    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> visited;
        for (string d : deadends) {
            visited.insert(d);
        }

        int level = 0;

        if (visited.find("0000") == visited.end()) q.push("0000");
        visited.insert("0000");

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; ++i) {
                string curr = q.front();
                if (curr == target)
                    return level;
                q.pop();

                for (string n : getNeighbours(curr)) {
                    if (visited.find(n) == visited.end()) {
                        q.push(n);
                        visited.insert(n);
                    }
                }
            }

            ++level;
        }

        return -1;
    }
};