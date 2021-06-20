class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        int side = 0;
        
        // side = 0 means s1[i] == s2[i]
        // side = -1 means that s1[i] > s2[i];
        // side = 1 means that s1[i] < s2[i];
        
        for (int i = 0; i < s1.size(); i++){
            if (s1[i] == s2[i])
                continue;
            else if (s1[i] > s2[i]){
                if (side == 1)  return false;
                else side = -1;
            }
            else if (s1[i] < s2[i]){
                if (side == -1)  return false;
                else side = 1;
            }
        }
        return true;
    }
};
