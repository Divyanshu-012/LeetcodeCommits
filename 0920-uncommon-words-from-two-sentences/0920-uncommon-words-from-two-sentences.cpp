class Solution {
public:
    map<string,int>mp;
    
    void stringstreeam(string s)
    {
        stringstream ss(s);
        string word;
        while(ss>>word) mp[word]++;
    }vector<string> split_sentence(const string& sentence) {
    vector<string> words;  // Stores the split words
    string word = "";  // Temporarily holds characters of the current word

    
    for (char ch : sentence) {
        if (ch == ' ') {  
            if (!word.empty()) {  
                words.push_back(word);  
                word = "";  
            }
        } else {
            word += ch; 
        }
    }

    // Add the last word 
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;  
}


    vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> wordCount;
    vector<string> result;

    // Split both sentences and add words to the map
    vector<string> words1 = split_sentence(s1);
    vector<string> words2 = split_sentence(s2);

    // Count the occurrences of each word in both sentences
    for (const string& word : words1) {
        wordCount[word]++;
    }
    for (const string& word : words2) {
        wordCount[word]++;
    }

    // Collect words that appear exactly once
    for (const auto& entry : wordCount) {
        if (entry.second == 1) {
            result.push_back(entry.first);
        }
    }

    return result;
}
};