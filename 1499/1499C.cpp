//# Author : godgiyeon =========================#
//# Problem Title : Minimum Grid Path ======#
//# Time Stamp : 2021-03-21T21:19:39 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
ll arr[100001];
ll sum[100001];
ll min_v[100001];
ll dy[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		for(int i=1; i<=n; i++) {
			cin >> arr[i];
			sum[i] = 0;
			min_v[i] = 100000000000000;
		}
		for(int i=1; i<=n; i++) {
			if(i >= 2) sum[i] = sum[i-2] + arr[i];
			else sum[i] = arr[i];
		}
		ll ans = n * arr[1] + n * arr[2];
		min_v[1] = arr[1];
		min_v[2] = arr[2];
		dy[1] = n * arr[1];
		dy[2] = n * arr[2];

		for(int i=3; i<=n; i++) {
			min_v[i] = min(min_v[i-2], arr[i]);
			ll num = (ll)(i+1) / 2;
			dy[i] = min_v[i] * (n - num) + sum[i];
			ans = min(ans, dy[i] + dy[i-1]);
		}
		cout << ans << "\n";
	}
}