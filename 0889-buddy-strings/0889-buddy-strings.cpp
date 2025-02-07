class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
        return 0;
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        bool  flag=false;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i])
            count++;
            if(count>2)
            return 0;
            count1[s[i]-'a']++;
            count2[goal[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i])
            return 0;
            if(flag==false){
                if(count1[i]>=2)
                flag=true;
            }
        }
        if(count==0&&flag==false)
        return 0;
        return 1;
        
    }
};