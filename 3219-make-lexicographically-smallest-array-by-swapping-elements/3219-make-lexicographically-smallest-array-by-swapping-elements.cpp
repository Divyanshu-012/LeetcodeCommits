class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int lim) {
        int n = nums.size();
        vector<int>sor = nums;
        

        sort(sor.begin(),sor.end());
        int groupNum = 0;

        // this map is for --> konsa no kis group mei gya 
        unordered_map<int,int> numToGroup;
        numToGroup[sor[0]] = groupNum;

        // this map is for --> kis group mei kon kon sa elment hai 

        unordered_map<int,list<int>> groupToList;  
        // list is used in above map to make it a doubly linked list , because to pop the first item it is useful as in vector to pop the front element it is task of O(n), but in linked list it is of O(1) only 
        groupToList[groupNum].push_back(sor[0]);
    
        for(int  i =1; i< n; i++){
            if(abs(sor[i]-sor[i-1]) > lim){
                groupNum +=1;

            }
            numToGroup[sor[i]] = groupNum;
            groupToList[groupNum].push_back(sor[i]);

        }

        // build the answer !!
        for(int i = 0 ; i< n ; i++){
            int num  = nums[i];
            int group = numToGroup[num];

            // smallest avialable no, in the group 
            nums[i] = *(groupToList[group].begin());
            groupToList[group].pop_front();
        }
        return nums;
        
        
    }
};