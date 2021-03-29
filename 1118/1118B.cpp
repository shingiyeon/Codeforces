//# Author : godgiyeon =========================#
//# Problem Title : Tanya and Candies ======#
//# Time Stamp : 2019-02-20T00:02:10 ===========#
//# Language : GNU C++14 =======================#

#include <stdio.h>
short arr[200000];
int main(){
	int N; scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
	int a = 0; int b = 0; int ans = 0;
	for(int i=0; i<N; i++){
		if(i%2) a += arr[i];
		else b += arr[i];
	}
	
	for(int i=0; i<N; i++){
		if(i%2) a -= arr[i];
		else b -= arr[i];

		if(a==b) ans++;
		
		if(i%2) b += arr[i];
		else a += arr[i];	
	}
	
	printf("%d", ans);
}