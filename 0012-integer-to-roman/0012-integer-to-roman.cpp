class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        if(num%1000 != num){
            for(int tPart = 0;tPart < num/1000;++tPart){
                result+='M';
            }
            num=num%1000;
        }
        if(num%100 != num){
            if(num/100 == 9){
                result+="CM";
            }else if(num/100 == 4){
                result+="CD";
            }else if(num/100 < 4){
                for(int hPart = 0;hPart < num/100;++hPart){
                    result+='C';
                }
            }else{
                result+='D';
                for(int hPart = 0;hPart < num/100-5;++hPart){
                    result+='C';
                }
            }
            num=num%100;
        }
        if(num%10 != num){
            if(num/10 == 9){
                result+="XC";
            }else if(num/10 == 4){
                result+="XL";
            }else if(num/10 < 4){
                for(int hPart = 0;hPart < num/10;++hPart){
                    result+='X';
                }
            }else{
                result+='L';
                for(int hPart = 0;hPart < num/10-5;++hPart){
                    result+='X';
                }
            }
            num=num%10;
        }
            if(num == 9){
                result+="IX";
            }else if(num == 4){
                result+="IV";
            }else if(num < 4){
                for(int hPart = 0;hPart < num;++hPart){
                    result+='I';
                }
            }else{
                result+='V';
                for(int hPart = 0;hPart < num-5;++hPart){
                    result+='I';
                }
            }
            num=num%10;
            return result;

    }
};