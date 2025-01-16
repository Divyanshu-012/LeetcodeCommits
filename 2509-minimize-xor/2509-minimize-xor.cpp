class Solution {
public:
    bool isSet(int &x , int bit){
        return x & (1<< bit);
    }

    bool setBit(int &x, int bit){
        return x |= (1<<bit);
    }

    bool unsetBit(int &x, int bit){
       return  x &= ~(1 << bit);
    }
    int minimizeXor(int num1, int num2) {
        int x= num1;

        int reqSetBitCnt = __builtin_popcount(num2); // function to count set bits 
        int currSetBitCnt = __builtin_popcount(x);
    int bit = 0; // position of bit
        if(currSetBitCnt < reqSetBitCnt) {
            while(currSetBitCnt < reqSetBitCnt){
                if(!isSet(x,bit)){
                    setBit(x,bit);
                    currSetBitCnt++;
                }
                bit++;
            }
        }
        else if(currSetBitCnt > reqSetBitCnt){
            while(currSetBitCnt > reqSetBitCnt){
                if(isSet(x,bit)){
                    unsetBit(x,bit);
                    currSetBitCnt--;
                }
                bit++;
            }

        }
        return x;
        
    }
};