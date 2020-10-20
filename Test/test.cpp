#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int gcd (int a, int b) {
        return b == 0? a: gcd(b, a % b);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() < 2) return false;

        sort(deck.begin(),deck.end());
        vector<int> u = deck;
        u.resize(unique(u.begin(),u.end())- u.begin());

        int counter = 1;
        int idx = 0;
        for (int i = 1; i < deck.size();i++){
            if(deck[i] == deck[i-1]){
                counter++;
            }else{
                u[idx++] = counter;
                counter = 1;
            }
        }
        // put the last one
        u[idx] = counter;

        int rem = u[0];
        for(int i = 1;i<u.size();i++){
            if( (rem = gcd(rem,u[i])) == 1){
                return false;
            }
        }
        return true;
    }
};




int main()
{

    Solution sol;
    vector<int> vec { 1,1,1,1,2,2,2,2,2,2};
    cout << sol.hasGroupsSizeX(vec) << endl;

    return 0;
}