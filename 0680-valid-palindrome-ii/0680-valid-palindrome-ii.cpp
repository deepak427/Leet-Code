class Solution {
public:
    bool ispalindrome(string s,int delchar) {
        int start = 0;
        int end = s.size()-1;

        while(start < end){
            if((s[start] != s[end]) && (delchar == 1)){
                return false;
            }else if((s[start] != s[end]) && (delchar == 0)){
                if(ispalindrome(s.substr(start+1,end-start), 1)){
                    return true;
                }else{
                    if(ispalindrome(s.substr(start,end-start), 1)){
                        return true;
                    }else{
                        return false;
                    }
                }
            }else{
                start++;
                end--;
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        return ispalindrome(s,0);
    }
};