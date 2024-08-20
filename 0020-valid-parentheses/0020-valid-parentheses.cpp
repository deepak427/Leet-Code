class Solution {
public:
    bool isValid(string s) {
        stack<char> brac;
        brac.push('u');

        for(char c : s){
            if(c == ')' && brac.top() == '(' || c == '}' && brac.top() == '{' || c == ']' && brac.top() == '['){
                brac.pop();
            }else {
                brac.push(c);
            }
        }

        brac.pop();

        if(brac.empty()){
            return true;
        }else{
            return false;
        }
    }
};