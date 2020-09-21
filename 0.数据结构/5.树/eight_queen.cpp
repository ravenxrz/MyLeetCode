/**
 * eight queen problem
 */
#include <iostream>
#include <vector>

using namespace std;

int counter = 0;

bool check(vector<vector<bool>>& vec, int i, int j) {
	/* same row check */
	for (int col = 0; col < j; col++) {
		if (vec[i][col]) return false;
	}
	/* major diag line check*/
	{
		int delta = 1;
		while (i - delta >= 0 && j - delta >= 0) {
			if (vec[i - delta][j - delta]) return false;
			delta++;
		}
	}
	/* minor diag line check */
	{
		int delta = 1;
		while (i + delta < vec.size() && j - delta >= 0) {
			if (vec[i + delta][j - delta]) return false;
			delta++;
		}
	}
	return true;
}

void print_chess(vector<vector<bool>>& vec)
{
	cout << "count:" << counter << "\n";
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}



void f(vector<vector<bool>>& vec, int j) {
	if (j == vec.size()) {
		counter++;
		print_chess(vec);
		return;
	}
	else {
		for (int i = 0; i < vec.size(); i++) {
			if (!check(vec, i, j)) {
				continue;;
			}
			vec[i][j] = true;
			f(vec, j + 1);
			vec[i][j] = false;
		}
	}
}

int main() {
	const int n = 8;
	vector<vector<bool>> chess(n, vector<bool>(n, false));
	f(chess, 0);
	cout << "total count:" << counter;
	return 0;
}
