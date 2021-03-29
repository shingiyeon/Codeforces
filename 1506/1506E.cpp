//# Author : godgiyeon =========================#
//# Problem Title : Restoring the Permutation #
//# Time Stamp : 2021-03-26T15:41:13 ===========#
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
int arr[200005];
int p[200005];
int parent(int cur){
	if(p[cur] == cur){
		return cur;
	}
  return p[cur] = parent(p[cur]);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		for(int i=1; i<=n; i++) cin >> arr[i];
		vector<int> minp, maxp;
		for(int i=1; i<=n; i++) p[i] = i;
		int min_v = 1;
		for(int i=1; i<=n; i++) {
			if(arr[i] != arr[i-1]) {
				minp.push_back(arr[i]);
				p[parent(arr[i])] = parent(parent(arr[i]) + 1);
			}
			else {
				minp.push_back(parent(min_v));
				p[parent(min_v)] = parent(parent(min_v) + 1);
			}
		}
		
		for(int i=1; i<=n; i++) p[i] = i;
		int max_v = 0;
		for(int i=1; i<=n; i++) {
			if(arr[i] != arr[i-1]) {
				maxp.push_back(arr[i]);
				p[parent(arr[i])] = parent(parent(arr[i]) - 1);
				max_v = max(max_v, arr[i]);
			}
			else {
				maxp.push_back(parent(max_v));
				p[parent(max_v)] = parent(parent(max_v) - 1);
			}
		}
		
		for(auto val: minp) {
			cout << val << " ";
		}
		cout << "\n";

		for(auto val: maxp) {
			cout << val << " ";
		}
		cout << "\n";
		

	}
}