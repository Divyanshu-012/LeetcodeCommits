
class Solution {
public:
   

    int maxVowels(string s, int k) {
         char arr[5] = {'a','e','i','o','u'};
         unordered_set<char>st(arr,arr+5);
        int i =0,j=0;
        int maxCnt = 0;

        int cnt = 0;
        while(j < s.size()){
            if(st.find(s[j]) != st.end()){
                cnt++;
            }
            if((j-i+1 )== k){
                maxCnt = max(maxCnt,cnt);
                if(st.find(s[i]) != st.end()){
                    cnt--;

                }
                i++;
            }
            j++;
        }

        return maxCnt;
    }
};