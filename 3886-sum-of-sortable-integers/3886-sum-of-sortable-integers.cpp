class Solution {
public:
    void computeLPS(vector<int>& pattern, vector<int>& lps) {
        int M = pattern.size();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool KMP(vector<int>& pat, vector<int>& txt) {
        if (pat.empty()) return true;
        int N = txt.size();
        int M = pat.size();

        vector<int> lps(M, 0);
        computeLPS(pat, lps);

        int i = 0; // index for text
        int j = 0; // index for pattern

        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == M) {
                return true; // pattern found , return true
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }

    bool rotationPossible(vector<int>& block,vector<int>& target){
        vector<int> doubled = target;
        doubled.insert(doubled.end(), target.begin(), target.end());
        return KMP(block,doubled);  //o(k)
    }

    int sortableIntegers(vector<int>& nums) {
        vector<int> sorted=nums;
        //sorted cuz we have to know what is the target we are trying to achive after rotating
        sort(sorted.begin(),sorted.end()); // O(n log n)
        int ans=0;
        int n=nums.size();

        //run a loop from 1 to n, to find k which divides n 
        // O(n/k) => O(m)
        for(int k=1;k<=n;k++){
            //if k divides n we have to make k consecutive subarrays
            if(n%k==0){
                bool valid=true;  //to check if we can get the k which satisfy the conditions
                //O(n/k *k) => O(n)
                for(int start=0;start<n;start+=k){
                    //dividing into k blocks one by one 
                    vector<int> block(nums.begin()+start,nums.begin()+start+k);
                    vector<int> target(sorted.begin()+start,sorted.begin()+start+k);
                    // now we have to check whether we can get target from block after rotations
                    if(!rotationPossible(block,target)){
                        valid=false;
                        break;
                    }
                }
                if(valid){
                    ans+=k;
                }
            }
        }
        return ans;
    }
};

//TC => O(n log n + m*n)

/*
we can find if after any rotation we can get a desired arrangement without doing it 

1. add target to the target ; target={5,6} => target={5,6,5,6}
2. now check if block is present in target as a subarray 
3. if yes then rotation possible
4. but it can take too much time, so we can use KMP here 
*/