/*
* Fibonacci with memoization
*/
#include <iostream>
#include <unordered_map>

using namespace std;
using fib_int = long long int;

fib_int fib(int n, unordered_map<fib_int, fib_int>& memo) {
	if (memo.find(n) != memo.end())
		return memo[n];
	if (n <= 2) return 1;
	memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
	return memo[n];
}

int main() {
	unordered_map<fib_int, fib_int> memo;
	cout << fib(500, memo);
}

