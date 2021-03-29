//# Author : godgiyeon =========================#
//# Problem Title : Strange Table ==========#
//# Time Stamp : 2021-03-25T23:41:25 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <math.h>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		ll n, m, x;
		cin >> n >> m >> x;
		ll col = (x-1) / n;
		ll row = (x-1) % n;
		cout << row * m + col + 1 << "\n";
	}

}