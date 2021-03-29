//# Author : godgiyeon =========================#
//# Problem Title : Theatre Square =========#
//# Time Stamp : 2017-01-12T00:33:33 ===========#
//# Language : GNU C++ =========================#

#include <iostream>
using namespace std;
int main(){
        long long n,m,a;
        cin>>n>>m>>a;
        long long ans = (long long)(n/a);
        if(n%a)
                ans += 1;
        if(m%a)
                ans *= ((long long)(m/a)+1);
        else
                ans *= ((long long)(m/a));
        cout<<ans<<endl;
}