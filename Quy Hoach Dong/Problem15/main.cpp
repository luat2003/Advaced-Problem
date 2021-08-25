#include <iostream>
#include <algorithm>
#define N 105
using namespace std;
int n, kt[N][N] = {0};
long long Min = 1e13 , dp[N][N], a[N];
long long tongNhoNhat(int k, int l){
    if( kt[k][l]){
        return dp[k][l];
    }
    if( k+1 == l ){
        return 0;
    }
    long long minn = 1e13;
    for( int i = k+1; i <= l-1; i++){
        minn = min(minn, tongNhoNhat(k,i) + tongNhoNhat(i,l) + a[i]*a[k]*a[l]);
    }
    kt[k][l] = 1;
    dp[k][l] = minn;
    return minn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for( int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout  << tongNhoNhat(1,n);
    return 0;
}
