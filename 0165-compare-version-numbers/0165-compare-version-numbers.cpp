class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;

        while(p1<version1.length() || p2<version2.length()){
            string temp1 = "0", temp2 = "0";

            while(p1<version1.length() && version1[p1]!='.') temp1+=version1[p1++];
            while(p2<version2.length() && version2[p2]!='.') temp2+=version2[p2++];
            if(stoi(temp1)<stoi(temp2)) return -1;
            if(stoi(temp1)>stoi(temp2)) return 1;
            ++p1;
            ++p2;
        }

        return 0;
    }
};