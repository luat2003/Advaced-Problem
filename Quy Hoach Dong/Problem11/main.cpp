#include <iostream>
#define N 1005
using namespace std;
int n, K, a[N], s = 0, kt[N][N] = {0}, dp[N][N], Max = 0;
int xoaItSoNhat( int k, int vp){
    if( k == n && vp > K){
        return -99999999;
    }
    if( k == n && vp <= K){
        return 0;
    }
    if( kt[k][vp] ){
        return dp[k][vp];
    }
    int maxx = 0;
    for( int i = k+1; i <= n; i++){
        if( a[i] > a[k] && vp <= K){
            maxx = max(maxx, 1+xoaItSoNhat(i,vp));
        }
        if( a[i] < a[k] && vp < K){
            maxx = max(maxx, 1+xoaItSoNhat(i, vp+1));
        }
    }
    kt[k][vp] = 1;
    dp[k][vp] = maxx;
    return maxx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> K;
    a[0] = -99999999;
    for( int i = 1; i <= n; i++){
        cin >> a[i];
        if( a[i-1] > a[i] ){
            s++;
        }
    }
    if( s <= K ){
        cout << 0;
        return 0;
    }
    for( int k = 1; k <= n; k++){
        Max = max(Max, 1+xoaItSoNhat(k,0));
    }
    cout << n-Max;
    return 0;
}
