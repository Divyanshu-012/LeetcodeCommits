class Solution {
     public: 
     int maxChunksToSorted(vector<int>& arr) {
         int n = arr.size(); 
         int maxSoFar = 0; 
         int chunks = 0;
          for (int i = 0; i < n; ++i) {
             maxSoFar = max(maxSoFar, arr[i]);
              if (maxSoFar == i) { 
                chunks++; 
            } 
          }
           return chunks;
 }

};