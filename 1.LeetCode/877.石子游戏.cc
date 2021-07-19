//
// Created by raven on 2021/7/19.
//

class Solution {
public:
    bool stoneGame(vector<int> &piles)
    {
        int odd_values = 0;
        int even_values = 0;
        
        for(int i = 0; i < piles.size(); i+=2){
            odd_values += piles[i];
        }
        for(int i = 1;i< piles.size(); i+=2){
            even_values += piles[i] ;
        }
        
        
    }
};
