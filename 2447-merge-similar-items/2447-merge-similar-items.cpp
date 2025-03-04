
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> output;
        sort(items1.begin(), items1.end());
        sort(items2.begin(), items2.end());
        int i=0, j=0;
        while(i < items1.size() && j < items2.size()){
            if(items1[i][0] == items2[j][0]){
                output.push_back({items1[i][0], items1[i][1] + items2[j][1]});
                i++; j++;
            }
            else if(items1[i][0] < items2[j][0]){
                output.push_back(items1[i]);
                i++;
            }
            else{
                output.push_back(items2[j]);
                j++;
            }
        }
        while(i < items1.size()){
            output.push_back(items1[i]);
            i++;
        }
        while(j < items2.size()){
            output.push_back(items2[j]);
            j++;
        }
        return output;
    }
};