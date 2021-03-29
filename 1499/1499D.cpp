//# Author : godgiyeon =========================#
//# Problem Title : The Number of Pairs ====#
//# Time Stamp : 2021-03-23T18:06:20 ===========#
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
#define range (int)2e7 + 23

vector<int> spf(range, -1);
vector<int> prime;
vector<int> pn(range, 0);
void make_spf() {
	for(int i=2; i<range; i++) {
		if(spf[i] == -1) {
			spf[i] = i;
			prime.push_back(i);
		}
		for(auto prime_num: prime) {
			if(i * prime_num >= range) break;
			spf[i * prime_num] = prime_num;
			if(i % prime_num == 0) break;
		}
	}
}

void make_pn() {
	pn[1] = 0;
	spf[1] = 1;
	for(int i=2; i<range; i++) {
		int j = i / spf[i];
		pn[i] = pn[j] + (spf[i] != spf[j]);
	}
}

int pow(int x, int n) {
	int ans = 1;
	while(n) {
		if(n % 2) {
			ans *= x;
		}
		x = x * x;
		n /= 2;
	}
		return ans;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	make_spf();
	make_pn();
	int t; cin >> t;
	while(t--) {
		int c, d, x; cin >> c >> d >> x;
		int ans = 0;
		for(int i=1; i*i < x; i++) {
			if(x % i) continue;
			int k = (x / i) + d;
			if(k % c == 0) ans += pow(2, pn[k/c]);
			k = i + d;
			if(k % c == 0) ans += pow(2, pn[k/c]);
		}
		int i = (int)sqrt(x);
		if(i * i == x) {
			if((i+d)%c == 0) {
				ans += pow(2, pn[(i+d)/c]);
			}
		}
		cout << ans << "\n";
	}
	
}