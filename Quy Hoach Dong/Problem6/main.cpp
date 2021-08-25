#include <iostream>
#include <algorithm>
#define N 5005
using namespace std;
int h[N], a[N], b[N], n, x, y, z, dp[N], kt[N] = {0}, Max = 0;

int chieuCaoToiDa( int k){
    if( kt[k]){
        return dp[k];
    }
    if( k == n ){
        return h[n];
    }
    int c = 0;
    for( int i = k+1; i <= n; i++){
        if( a[i] >= a[k] && b[i] >= b[k]){
            c = max( c, chieuCaoToiDa(i) + h[k]);
        }
        if( i == n ){
            c = max(c,h[k]);
        }
    }
    dp[k] = c;
    kt[k] = 1;
    return c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for( int i = 1; i <= n; i++){
        cin >> x >> y >> z;
        h[i] = min(x, min(y,z));
        a[i] = max(x, max(y,z));
        b[i] = x+y+z - a[i] - h[i];
    }
    for( int i = 1; i < n; i++){
        for( int j = 1; j < n; j++){
            if( (a[j] > a[j+1]) || (a[j] == a[j+1] &&  b[j] > b[j+1])){
                swap(a[j],a[j+1]);
                swap(b[j], b[j+1]);
                swap(h[j],h[j+1]);
            }
        }
    }
    for( int i = 1; i <= n; i++){
        Max = max(Max, chieuCaoToiDa(i));
    }
    cout << Max;
    return 0;
}
