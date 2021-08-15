#include "leetcode_base.h"

class Solution {
public:
    bool isValid(string s) {
		stack<char> stk;
		for(auto c : s){
			switch(c){
				case ')':
				if(stk.empty() || stk.top() != '(') return false;
				stk.pop();
				break;
				
				case ']':
				if(stk.empty() || stk.top() != '[') return false;
				stk.pop();
				break;

				case '}':
				if(stk.empty() || stk.top() != '{') return false;
				stk.pop();
				break;
			
			default:
				stk.push(c);
				break;
			}
		}
		return stk.empty();
    }
};


int main()
{
	Solution sol;
	{
		string s = "()()(}){}{{}";
		cout << sol.isValid(s) << endl;
	}
	return 0;
}