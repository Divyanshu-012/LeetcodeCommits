class Solution {
public:

    vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> mergedArray;
    
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray.push_back(arr1[i]);
            i++;
        } else {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n1) {
        mergedArray.push_back(arr1[i]);
        i++;
    }
    while (j < n2) {
        mergedArray.push_back(arr2[j]);
        j++;
    }
    return mergedArray;
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray = mergeSortedArrays(nums1, nums2);
        int n = mergedArray.size();
        int mid1 = n / 2;

        
        if (n % 2 == 0) {
            
            return (mergedArray[mid1 - 1] + mergedArray[mid1]) / 2.0;
        } else {
            
            return mergedArray[mid1];
        }
    }
};