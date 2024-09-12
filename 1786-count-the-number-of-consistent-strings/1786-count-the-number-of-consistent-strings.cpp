class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
    unordered_set<char> allowedSet;  
   
    for (char &c : allowed) {
        allowedSet.insert(c);
    }
    
    int count = 0;  

    
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        bool isConsistent = true;

        
        for (int j = 0; j < word.length(); j++) {
            // If the character is not in allowedSet
            
            if (allowedSet.find(word[j]) == allowedSet.end()) {  
                isConsistent = false;
                break;  
            }
        }

        if (isConsistent) {
            count++;  
        }

    }
    return count;
    }

     

};