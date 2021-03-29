//# Author : godgiyeon =========================#
//# Problem Title : Coffee and Coursework (Hard Version) #
//# Time Stamp : 2019-02-20T19:29:55 ===========#
//# Language : GNU C++14 =======================#

#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m;
int MIN = 200001;
int arr[200000];
bool cmp(int a, int b){
	return a > b;
}
int max1(int a){
	return a > 0? a : 0;
}

void b_search(int start, int end){
	if(start<1||end>200000||start>end) return;
	int mid = (start+end)/2;
	
	long long sum = 0;
	for(int j=0; j<n; j++){
		sum += max1(arr[j] - (j/mid));
	}
	if(sum>=m){
		if(mid < MIN) MIN = mid;
		return b_search(start, mid-1);
	}
	return b_search(mid+1, end);
	
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	sort(arr, arr+n, cmp);
	
	b_search(1, 200000);
	if(MIN == 200001)
		printf("-1");
	else
		printf("%d", MIN);
}