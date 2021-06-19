class Solution {
public:
    void fun(vector<bool> &A){
        int n = A.size();
        for (int i = 2; i * i <= n; i ++){
            if (A[i] == true){
                for (int j = i * i; j <= n; j += i){
                    A[j] = false;
                }
            }
        }    
    }
    
    int countPrimes(int n) {
        vector<bool> A(n + 1, true);
        fun(A);
        int count = 0;
        for (int i = 2; i < A.size() - 1; i++)
            if (A[i] == true)
                count += 1;
        return count;
    }
};
