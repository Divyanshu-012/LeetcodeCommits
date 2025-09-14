class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactMatch(wordlist.begin(), wordlist.end()); 
        unordered_map<string, string> caseInsensitive;  // lower(word) → original word
        unordered_map<string, string> vowelError;       // devoweled(word) → original word

        // Helper lambda to replace vowels with '*'
        auto devowel = [](string w) {
            for (char &c : w) {
                if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c = '*';
            }
            return w;
        };

        // Preprocess wordlist
        for (string word : wordlist) {
            string lowerWord = word;
            transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

            if (caseInsensitive.find(lowerWord) == caseInsensitive.end())
                caseInsensitive[lowerWord] = word;

            string dv = devowel(lowerWord);
            if (vowelError.find(dv) == vowelError.end())
                vowelError[dv] = word;
        }

        vector<string> result;
        for (string query : queries) {
            if (exactMatch.count(query)) {
                result.push_back(query);  // Rule 1: Exact match
                continue;
            }

            string lowerQuery = query;
            transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

            if (caseInsensitive.count(lowerQuery)) {
                result.push_back(caseInsensitive[lowerQuery]); // Rule 2: Case-insensitive
                continue;
            }

            string dv = devowel(lowerQuery);
            if (vowelError.count(dv)) {
                result.push_back(vowelError[dv]); // Rule 3: Vowel error match
                continue;
            }

            result.push_back(""); // Rule 4: No match
        }

        return result;
        
    }
};