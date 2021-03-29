//# Author : godgiyeon =========================#
//# Problem Title : Water Buying ===========#
//# Time Stamp : 2019-02-19T23:52:48 ===========#
//# Language : GNU C++14 =======================#

#include <stdio.h>
int main(){
	int q; scanf("%d", &q);
	while(q--){
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if(2*b>=c){
			printf("%lld\n", (a/2)*c + (a%2) * b);
		}
		else{
			printf("%lld\n", a * b);
		}
	}
}