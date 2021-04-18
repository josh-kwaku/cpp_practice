/*
* Find the number of ways to travel from the top left to the bottom right of an m * n grid. You can only move down or right
*/
#include <iostream>
#include <vector>

using l_int = long long int;

using namespace std;
using vec = vector<vector<l_int>>;

long long int gridTraveller(int m, int n, vec& memo) {
	if (memo[m][n] != -1)
		return memo[m][n];
	if (n == 0 || m == 0)
		return 0;
	if (n == 1 && m == 1)
		return 1;
	memo[m][n] =  gridTraveller(m - 1, n, memo) + gridTraveller(m, n - 1, memo);
	return memo[m][n];
}

int main() {
	int m, n;
	cin >> m >> n;
	vec memo(m + 1, vector<l_int>(n + 1, - 1));
	cout << gridTraveller(m, n, memo);
}