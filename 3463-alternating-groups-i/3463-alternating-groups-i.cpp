
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int count = 0;
        int  n = colors.size();
        for(int i = 0 ; i < colors.size();i++){
            if(i>0 && i<colors.size()-1){
                if(colors[i] != colors[i-1] && colors[i] != colors[i+1]){
                count++;
            }

            }
            
        }
        if((colors[n-1] != colors[n-2]) && (colors[n-1] != colors[0]) ) count++;
        if((colors[0] != colors[n-1]) && (colors[0] != colors[1]) ) count++;

        
        return count;
    }
};