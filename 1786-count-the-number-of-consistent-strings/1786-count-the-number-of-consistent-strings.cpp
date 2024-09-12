class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
    unordered_set<char> allowedSet;  
   
    for (char &c : allowed) {
        allowedSet.insert(c);
    }
    // count the number of consistent strings
    int count = 0;  

    
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        bool isConsistent = true;

        
        for (int j = 0; j < word.length(); j++) {
            if (allowedSet.find(word[j]) == allowedSet.end()) {  // If the character is not in allowedSet
                isConsistent = false;
                break;  // No need to check further, this word is inconsistent
            }
        }

        if (isConsistent) {
            count++;  // Increment count if the word is consistent
        }
    }

    return count;  // Return the total number of consistent strings
}

};