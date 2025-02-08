class NumberContainers {
public:
    unordered_map<int,int>idxToNum;
    unordered_map<int,set<int>> numToIdx;

    NumberContainers() {
        // do nothing 
    }
    
    void change(int index, int number) {
        if(idxToNum.count(index)){
            int  prev = idxToNum[index];
            numToIdx[prev].erase(index);

            if(numToIdx[prev].empty()){
                numToIdx.erase(prev);
            }

            

        }
        idxToNum[index] = number;
        numToIdx[number].insert(index);
        
        
    }
    
    int find(int number) {
        
        if(numToIdx.count(number)){
            return *numToIdx[number].begin();
        }
        
        return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */