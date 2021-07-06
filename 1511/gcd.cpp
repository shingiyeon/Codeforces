#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <queue>
#include <stack>
#include <string>
using namespace std;
int gcd(int a, int b) {
    while(a % b){
        int t = a % b;
        a = b; b = t;
    } 
    return b;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b; cin >> a >> b;
    cout << gcd(a,b) << "\n";    
}
