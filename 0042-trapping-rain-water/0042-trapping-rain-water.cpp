class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefix(n);
        vector<int>suffix(n);

         prefix[0] = height[0];
        

        // prefixmax
        for(int i = 1; i< height.size();i++){
            prefix[i]= max(height[i],prefix[i-1]);
        }

        suffix[n-1] = height[n-1];

        //suffixmax
        for(int i = n-2; i>=0 ;i--){
            suffix[i] = max(height[i],suffix[i+1]);
        }
        int water = 0;
        for(int i = 1; i< n-1;i++){
            if(height[i] <= min(prefix[i],suffix[i])){
                water +=( min(prefix[i],suffix[i])- height[i]);
            }
            
        }

        return water;


        
    }
};