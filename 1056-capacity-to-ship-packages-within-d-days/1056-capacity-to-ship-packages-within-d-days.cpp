class Solution {
public:
    int findDays(vector<int> &weights, int cap) {
    int days = 1; 
    int load = 0;
    int n = weights.size();
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; 
            load = weights[i]; 
        }
        else {
            
            load += weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int> &weights, int cap) {
    //Find the maximum and the summation:
    int low = *max_element(weights.begin(), weights.end());
    // stl function to find the sum of whole array in c++
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        if (numberOfDays <= cap) {
            
            high = mid - 1;
        }
        else {
            
            low = mid + 1;
        }
    }
    return low;
}
};

int findDays(vector<int> &weights, int cap) {
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); //size of array.
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

