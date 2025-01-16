class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> commonArr; 
    unordered_set<int> seenA, seenB; 
    int commonCount = 0;

    for (int i = 0; i < n; i++) {
        
        seenA.insert(A[i]);
        seenB.insert(B[i]);

        
        if (seenB.find(A[i]) != seenB.end()) {
            commonCount++; 
        }

        
        if (seenA.find(B[i]) != seenA.end()) {
            commonCount++; 
        }

        
        if (A[i] == B[i]) {
            commonCount--;
        }

        
        commonArr.push_back(commonCount);
    }

    return commonArr;
}


};