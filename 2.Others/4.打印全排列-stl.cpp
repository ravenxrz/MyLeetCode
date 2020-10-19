#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> inputs{1,2,3,4,5,6};
    int counter = 0;

    do{
        for(const int &val : inputs){
            cout << val << " ";
        }
        cout << "\n";
        counter++;
    }while(next_permutation(inputs.begin(),inputs.end()));

    cout << counter << "\n";
    return 0;
}