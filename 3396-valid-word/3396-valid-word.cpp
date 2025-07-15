class Solution {
public:
    bool isVowel(char ch){
         return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
        
    }
    bool isCons(char ch ){
        return isalpha(ch) && !isVowel(ch);
    }
    bool isValid(string word) {
        if(word.size() < 3) return false;

        bool Vowel = false;
        bool Cons = false;
        for(char ch : word){
            if( !isalnum(ch) ) return false;
                
            if(isVowel(ch)) Vowel = true;
            if(isCons(ch)) Cons = true;
            
        }
        
        return (Vowel && Cons);
    }
};