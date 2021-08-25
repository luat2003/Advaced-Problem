#include <iostream>
#include <algorithm>
#define N 10005
using namespace std;
int n, s[N], f[N], kt[N] = {0}, dp[N], Max = 0;

int soPhongHopToiDa( int k ){
    if( k == n ){
        return 1;
    }
    if( kt[k] == 1 ){
        return dp[k];
    }
    int maxx = 0;
    for( int i = k+1; i <= n; i++){
        if( s[i] >= f[k] ){
            maxx = max( maxx, soPhongHopToiDa( i) + 1);
        }
    }
    kt[k] = 1;
    dp[k] = maxx;
    return maxx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for( int i = 1; i <= n; i++){
        cin >> s[i] >> f[i];
    }
    for( int i = 1; i < n; i++){
        for( int j = 1; j < n; j++){
            if( (s[j] > s[j+1]) ||  (s[j] == s[j+1] && f[j] > f[j+1]) ){
                swap(s[j], s[j+1]);
                swap(f[j], f[j+1]);
            }
        }
    }
    for( int i = 1; i <= n; i++){
        Max = max(Max, soPhongHopToiDa(i) );
    }
    cout << Max;
    return 0;
}
