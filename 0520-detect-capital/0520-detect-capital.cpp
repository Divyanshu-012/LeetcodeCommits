class Solution {
public:
    // bool check(string word, char start,  char end){
    //     for(char &ch : word){
    //         if(ch < start || ch > end) return false;
            
    //     }    
    //     return true ;  
    // }

    
    bool detectCapitalUse(string word) {
    //     if(check(word,'A','Z') || check(word,'a','z') || check(word.substr(1),'a','z')){
    //         return true ;
    //     }
    //     return false ;
    // }

    int countCap = 0;
    for(char &ch :  word ){
        if(isupper(ch)) 
        countCap ++;

    }

    if(word.length() == countCap || countCap == 0 || (countCap == 1 && isupper(word[0]))) 
    return true ;

    return false ;

    }
};