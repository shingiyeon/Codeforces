//# Author : godgiyeon =========================#
//# Problem Title : Filling the Grid =======#
//# Time Stamp : 2019-09-29T22:25:03 ===========#
//# Language : GNU C++14 =======================#

#include <stdio.h>
using namespace std;

short map[1000][1000];



int main(){
	int h, w; scanf("%d%d",&h,&w);
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			map[i][j] = -1;
		}
	}
	
	bool flag = 0;
	for(int i=0; i<h; i++)
	{
		int tmp; scanf("%d", &tmp);
		if(!tmp){
			if(map[i][0] == 1) flag = 1;
			map[i][0] = 0;
		}
		else{
			for(int j=0; j<tmp; j++){
				if(map[i][j] == 0) flag = 1;
				map[i][j] = 1;
			}
			if(tmp != w){
				if(map[i][tmp] == 1) flag = 1;
				map[i][tmp] = 0;
			}
		}
	}
	
	for(int i=0; i<w; i++){
		int tmp; scanf("%d", &tmp);
		if(!tmp){
			if(map[0][i] == 1) flag = 1;
			map[0][i] = 0;
		}
		else{
			for(int j=0; j<tmp; j++){
				if(map[j][i] == 0) flag = 1;
				map[j][i] = 1;
			}
			if(tmp != h){
				if(map[tmp][i] == 1) flag = 1;
				map[tmp][i] = 0;
			}
		}
	}
	
	if(flag){
		printf("0");
		return 0;
	}
	
	int ans = 1;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(map[i][j] == -1){
				ans = (ans % 1000000007 * 2) % 1000000007;
			}
		}
	}
	printf("%d", ans);
}