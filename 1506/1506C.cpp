//# Author : godgiyeon =========================#
//# Problem Title : Double-ended Strings ===#
//# Time Stamp : 2021-03-26T00:10:56 ===========#
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

vector<int> getPi(string p) {
	vector<int> f(p.size(), 0);
	int j = 0;
	for(int i=1; i<p.size(); i++) {
		while(j > 0 && p[i] != p[j]) j = f[j-1];
		if(p[i] == p[j]) f[i] = ++j;
	}
	return f;
}

int kmp(string s, string p) {
	int ans = 0;
	vector<int> f = getPi(p);
	int j = 0;
	for(int i=0; i<s.size(); i++) {
		while(j>0 && s[i] != p[j]) j = f[j-1];
		if(s[i] == p[j]) {
			j++;
			ans = max(ans, j);
			if(j==p.size()) j = f[j-1];
		}
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		string a, b;
		cin >> a >> b;
		int ans = 0;
		for(int i=0; i<a.size(); i++) {
			string tmp = a.substr(i, a.size());
		//	cout << b << " " << tmp << "\n";
			ans = max(ans, kmp(b, tmp));
		}
		cout << a.size() + b.size() - ans * 2 << "\n";
	}

}