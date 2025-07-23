// explained code

// for checking and setting jth bit in number n
bool isset(int n, int j){return n&(1<<j);}
void setbit(int& n, int j){n|=(1<<j);}

struct Node{
    Node *links[2]; // for storing 0 and 1 bit

    // min for current node stored in current node (not in next node)
    int mini0 = 2e9, mini1 = 2e9;
    // mini0 = by taking 0(unset bit) at curr position, whats the minimum value present
    // in vector given(or trie formed)

    bool isPresent(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
    void storeMin0(int a){
        mini0 = min(mini0, a);
    }
    void storeMin1(int a){
        mini1 = min(mini1, a);
    }
    int getMin0(){
        return mini0;
    }
    int getMin1(){
        return mini1;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();      
    }
    
    // insert number n in trie
    void insert(int n) {
        Node* currnode = root;
        for(int i=30; i>=0; --i){
            int bit = 0;
            if(isset(n,i)){
                bit=1;
                currnode->storeMin1(n);
            }
            else{
                currnode->storeMin0(n);
            }
            // after storing min value for current bit, move to next bit
            if(!(currnode->isPresent(bit))){
                currnode->put(bit, new Node());
            }
            currnode = currnode->get(bit);
        }
    }
    
    // find max xor in trie with 'a'
    int findMax(int a, int mx) {
        Node* currnode = root;
        int ans = 0;
        for(int i=30; i>=0; --i){
            int mini0 = currnode->getMin0(), mini1 = currnode->getMin1();
            // there can be 4 combination of a particular bit in 'a' and 'trie'
            if(isset(a,i) && currnode->isPresent(0) && mini0<=mx){
                currnode = currnode->get(0);
                setbit(ans,i);  // xor=1
                continue;
            }
            if(!(isset(a,i)) && currnode->isPresent(1) && mini1<=mx){
                currnode = currnode->get(1);
                setbit(ans,i);  // xor=1
                continue;
            }
            if(!(isset(a,i)) && currnode->isPresent(0) && mini0<=mx){
                currnode = currnode->get(0);
                continue;
            }
            if(isset(a,i) && currnode->isPresent(1) && mini1<=mx){
                currnode = currnode->get(1);
                continue;
            }
            // after this,
            // no condition satisfied => all values of vector(trie) are
            // bigger than curr max given so return -1
            // note:- this condn can be checked before calling the function too by
            // comparing curr max value to the min value of vector(trie) 
            else return -1;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    Trie ds;
    int n = nums.size();
    for(int i=0; i<n; ++i){
        ds.insert(nums[i]);
    }
    vector<int> ans;
    int q = queries.size();
    for(int i=0; i<q; ++i){
        int a = queries[i][0], mx = queries[i][1];
        int ca = ds.findMax(a,mx);
        ans.push_back(ca);
    }
    return ans;
    }
};