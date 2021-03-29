//# Author : godgiyeon =========================#
//# Problem Title : Distinct Digits ========#
//# Time Stamp : 2019-09-29T22:08:30 ===========#
//# Language : GNU C++14 =======================#

#include <stdio.h>

using namespace std;

int main(){
	int l, r;
	scanf("%d%d", &l, &r);
	bool arr[10];
	
	for(int i=l; i<=r; i++){
		for(int j=0; j<10; j++) arr[j] = 0;
		
		bool flag = 0;
		int tmp = i;
		
		while(tmp){
			if(arr[tmp%10]) {
				flag = 1;
				break;
			}
			arr[tmp%10] = 1;
			tmp = tmp/10;
		}
		if(!flag){
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	
}