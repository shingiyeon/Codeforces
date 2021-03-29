//# Author : godgiyeon =========================#
//# Problem Title : Basic Diplomacy ========#
//# Time Stamp : 2021-03-25T21:38:10 ===========#
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

vector<int> dp[100001];
vector<int> pd[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		vector<int> v(m+1, 0);
		for(int i=0; i<=100000; i++) {
			dp[i].clear();
			pd[i].clear();
		}
		int sz = (m+1)/2;
		for(int i=1; i<=m; i++) {
			int tmp; cin >> tmp;
			for(int j=1; j<=tmp; j++) {
				int k; cin >> k;
				dp[i].push_back(k);
				pd[k].push_back(i);
			}
		}
		vector< pair<int, int> > ttmp;
		for(int i=1; i<=n; i++) {
			ttmp.push_back({pd[i].size(), i});
		}
		sort(ttmp.begin(), ttmp.end());

		for(auto val: ttmp) {
			int man = val.second;
			vector< pair<int, int> > tmp;

			for(auto day: pd[man]) {
				if(v[day] != 0) continue;
				tmp.push_back( {dp[day].size(), day} );
			}
			
			sort(tmp.begin(), tmp.end());
			int num = 0;
			int idx = 0;
			while(idx < min(sz, (int)tmp.size())) {
				int day = tmp[idx].second;
				v[day] = man;
				idx++; 
			}
		}

		bool flag = true;
		for(int i=1; i<=m; i++) {
			if(v[i] == 0) flag = false;
		}

		if(flag) {
			cout << "YES\n";
			for(int i=1; i<=m; i++) {
				cout << v[i] << " ";
			}
			cout << "\n";
		}
		else {
			cout << "NO\n";
		}

	}
}