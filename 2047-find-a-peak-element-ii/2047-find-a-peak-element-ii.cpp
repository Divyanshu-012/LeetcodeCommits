class Solution {
public:
    int maxElement(vector<vector<int>>& arr, int col) {
          int n = arr.size();
          int max_val = INT_MIN;
          int index = -1;

          for (int i = 0; i < n; i++) {
              if (arr[i][col] > max_val) {
                  max_val = arr[i][col];
                  index = i;
              }
          }
          return index;
      }
  
      
      vector<int> findPeakGrid(vector<vector<int>>& arr) {
          int n = arr.size();     
          int m = arr[0].size();  
  
          // Initialize the lower and upper bounds for binary search
          int low = 0;           
          int high = m - 1;      
  
         
          while (low <= high) {
              int mid = (low + high) / 2;
  
              // Find the index of the row with the maximum element 
              // in the middle column
              int row = maxElement(arr, mid);
  
              // Determine the elements to the left and right of 
              // the middle element in the found row
              int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
              int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;
  
              // Check if the middle element is greater than its neighbors
              if (arr[row][mid] > left && arr[row][mid] > right) {
                  return {row, mid};
              } 
              else if (left > arr[row][mid]) {
                  high = mid - 1;
              } 
              else {
                  low = mid + 1;
              }
          }
  
          
          return {-1, -1};
      }
  
};