class Solution {
public:
    bool isVov(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int m_vov = 0, c_vov = 0;

        for(int end = 0; end < s.length(); ++end){
            if(end < k){
                if(isVov(s[end])){
                    m_vov = ++c_vov;
                }
                continue;
            }

            if(isVov(s[end-k])){
                --c_vov;
            }

            if(isVov(s[end])){
                ++c_vov;
            }

            m_vov = max(m_vov, c_vov);
        }

        return max(m_vov, c_vov);
    }
};