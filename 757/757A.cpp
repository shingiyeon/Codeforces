//# Author : godgiyeon =========================#
//# Problem Title : Gotta Catch Em' All! ===#
//# Time Stamp : 2017-01-13T00:50:52 ===========#
//# Language : GNU C++ =========================#

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
        char s[100005];
        string a = "Bulbasaur";
        int ans = 0;
        int temp = 0;
        int num[9];
        for(int i=0; i<9; i++)
                num[i] = 0;
        scanf("%s",s);
        for(int i=0; i<strlen(s); i++)
        {
                for(int j=0; j<9; j++)
                {
                        if(s[i] == a[j]){
                                num[j]++;
                                break;
                        }
                }
        }
        int min = 99999999;
        num[1] = (int)(num[1]/2);
        num[4] = (int)(num[4]/2);
        for(int i=0; i<9; i++)
        {
                if(i==7 || i==6)
                        continue;
                if( num[i] < min)
                        min = num[i];
        }
        printf("%d",min);
}