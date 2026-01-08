class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n=v1.size(), m=v2.size();
        int i=0, j=0;

        while(i<n || j<m){
            int a=0, b=0;
            while(i<n && v1[i] != '.') 
            a= a*10 + (v1[i++] - '0');

            while(j<m && v2[j] != '.') 
            b= b*10 + (v2[j++] - '0');

            if(a<b) return -1;
            if(a>b) return 1;
            i++; j++;
        }
        return 0;
    }
};