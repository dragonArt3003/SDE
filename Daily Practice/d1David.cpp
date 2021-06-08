# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<string> &res, string &str, int ind){
        if (ind == str.size()){
            res.push_back(str);
            return;
        }
        if (48 <= str[ind] && str[ind] <= 57){
            solve(res, str, ind + 1);
        }
        else{
            solve(res, str, ind + 1);
            if (97 <= str[ind] && str[ind] <= 122){
                str[ind] = str[ind] - 32;
                solve(res, str, ind + 1);
                str[ind] = str[ind] + 32;
            }
            else{
                str[ind] = str[ind] + 32;
                solve(res, str, ind + 1);
                str[ind] = str[ind] - 32;
            }
        }
    }
 
    vector<string> letterCasePermutation(string &s) {
        vector<string> res;
        solve(res, s, 0);
        return res;
    }
};

int main(){
    int tc;
    cin >> tc;
    while (tc--){
        string str;
        getline(cin, str);
        Solution sol;
        vector<string> res = sol.letterCasePermutation(str);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
    }
    return 0;
}
