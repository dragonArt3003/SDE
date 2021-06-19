class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> A(n);
        string res;
        for (int i = n - 1; i >= 0; i--){
            if (i + 26 <= k){
                A[i] = 26;
                k = k - 26;
            }
            else{
                A[i] = k - i;
                for (int j = i - 1; j >= 0; j--)
                    A[j] = 1;
                break;
            }
        }
        
        for (int i = 0; i < n; i++)
            res.push_back('a' + A[i] - 1);
        return res;
    }
};
