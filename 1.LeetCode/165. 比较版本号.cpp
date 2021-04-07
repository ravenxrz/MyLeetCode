#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        int idx1 = 0;
        int idx2 = 0;
        
        while (idx1 < version1.size() && idx2 < version2.size()) {
            string num1_str = next_num_str(version1, idx1);
            string num2_str = next_num_str(version2, idx2);
            
            int num1 = strtol(num1_str.c_str(), nullptr, 10);
            int num2 = strtol(num2_str.c_str(), nullptr, 10);
            
            if(num1 < num2) return -1;
            else if(num1 > num2) return 1;
        }
        
        // check remaining chars
        while(idx1 < version1.size()){
            string num1_str = next_num_str(version1, idx1);
            int num1 = strtol(num1_str.c_str(), nullptr, 10);
            if(num1 != 0) return 1;
        }
        while(idx2 < version2.size()){
            string num2_str = next_num_str(version2, idx2);
            int num2 = strtol(num2_str.c_str(), nullptr, 10);
            if(num2 != 0) return -1;
        }
        
        return 0;
    }
    
    string next_num_str(string &version, int &idx)
    {
        if (idx == version.size()) return "";
        if (version[idx] == '.') ++idx;      // skip .
        int old_idx = idx;
        while (idx < version.size() && version[idx] != '.') {
            idx++;
        }
        return version.substr(old_idx, (idx - old_idx + 1));
    }
};

