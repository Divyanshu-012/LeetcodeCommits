class Solution {
public:
    // typedef pair<int,char>P;
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        priority_queue<pair<int,char>>pq;

        if (a > 0) pq.push({a,'a'});

        if (b > 0) pq.push({b,'b'});

        if (c > 0) pq.push({c,'c'});

        while(!pq.empty()){
            int currCount = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            if( s.length() >= 2 && s[s.length()-1] == currChar && s[s.length()-2]== currChar){
                if(pq.empty()){
                    break;
                }

                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                s.push_back(nextChar);
                nextCount--;
                if(nextCount > 0){
                    pq.push({nextCount,nextChar});
                }

            } else{
                currCount-- ;
                s.push_back(currChar);

            }

            if(currCount > 0){
                pq.push({currCount,currChar});
            }


        }



        return s;
        
    }
};