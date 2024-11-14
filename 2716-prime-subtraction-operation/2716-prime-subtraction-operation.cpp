class Solution {
public:

    bool isPrime[1000];
    void Sieve(){ //O(1)
        //fill syntax -- fill(start,end,value);
        fill(isPrime, isPrime+1000,true); // initialise the array ith all true 
        isPrime[0] = false;
        isPrime[1] = false;

        for(int  i = 2; i*i < 1000; i++){
            if(isPrime [i]== true){
                for(int j = i*i; j<1000; j+= i){
                    isPrime[j] = false;
                }
            }
        }
    }


    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        Sieve(); //it will populate my isPrime array // O(1)

        //O(n* maxNum)
        for(int i = n-2; i>= 0; i--){ //O(n)
            if(nums[i] < nums[i+1]){
                continue;
            }
            // else decrease nums[i] atleast less than nums[i]

            //check prime numbers less than nums[i]

            for(int  p = 2; p < nums[i] ; p++){ // O(max of nums)
                if(!isPrime[p]){
                    continue;
                }

                if(nums[i] - p < nums[i+1]){
                    nums[i] -= p;
                    break;

                }

            }

            if(nums[i] >= nums[i+1]){
                return false;
            }


        }
        return true;

        
        
    }
};