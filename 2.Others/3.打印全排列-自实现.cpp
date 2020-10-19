#include <iostream>
#include <vector>
using namespace std;

int counter = 0;
void dfs(const vector<int> &inputs, int idx){
    static vector<bool> visit(inputs.size(),false);
    static vector<int> values(inputs.size(),-1);

    if(idx == inputs.size()){
        for(const int &val : values){
            cout << val << " ";
        }
        cout << "\n";
        counter++;
        return;
    }

    for(int i = 0;i<inputs.size();i++){
        if(!visit[i]){
            // put
            visit[i] = true;
            values[idx] = inputs[i];
            dfs(inputs,idx+1);
            visit[i] = false;
            values[idx] = -1;
        }
    }
}

int main()
{
    vector<int> inputs{1,2,3,4,5,6,7,8,9};
    dfs(inputs,0);
    cout << counter << endl;
    return 0;
}