#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int counter = 0;
void dfs(vector<int> &inputs, vector<int> &values, int idx){
    if(values.size() == 4){
        counter++;
        for(const int val : values){
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    if(idx == inputs.size())
        return;

    // put
    values.emplace_back(inputs[idx]);
    dfs(inputs, values, idx + 1);
    // remove
    values.pop_back();
    dfs(inputs,values, idx + 1);

}


int main()
{
    vector<int> inputs {
            -5,-5,-3,-1,0,2,4,5
    };
    sort(inputs.begin(),inputs.end());
    vector<int> values;
    dfs(inputs,values,0);
    cout << counter << endl;
    return 0;
}