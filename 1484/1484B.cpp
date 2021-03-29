//# Author : godgiyeon =========================#
//# Problem Title : Restore Modulo =========#
//# Time Stamp : 2021-03-21T22:38:51 ===========#
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

int arr[100001];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int max_val = 0;
		for(int i=1; i<=n; i++) {
			cin >> arr[i];
			max_val = max(max_val, arr[i]);
		}
		set<int> s;

		for(int i=2; i<=n; i++) {
			s.insert(arr[i] - arr[i-1]);
		}

		if(s.size() <= 1) {
			cout << "0" << "\n";
		}
		else if(s.size() > 2) {
			cout << "-1" << "\n";
		}
		else {
			int p = 0; int m = 0;
			for(auto it=s.begin(); it!=s.end(); it++) {
				if(*it > 0) p = *it;
				if(*it < 0) m = *it;
			}
			if(p==0 || m==0 || p-m < max_val) {
				cout << "-1" << "\n";
			}
			else {
				cout << p - m << " " << p << "\n";
			}
		}
	}
}