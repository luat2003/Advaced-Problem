#include <iostream>
#define N 305
using namespace std;
long long V, P, a[N], kt[35][N] = {0}, dp[35][N];
long long tongQuangDuong(long long k, long long l){
    if( l == V+1 && k < P+1){
        return 1e8;
    }
    if( k == P+1 && l < V+1){
        return 1e8;
    }
    if( k == P+1 && l == V+1){
        return 0;
    }
    if( kt[k][l] ){
        return dp[k][l];
    }
    long long minn = 1e8;
    for( int i = l+1; i <= V+1; i++){
        long long s = 0;
        for( int j = l+1; j <= i-1; j++){
            s += min(a[j]-a[l], a[i] - a[j]);
        }
        minn = min(minn, tongQuangDuong(k+1,i) + s);
    }
    kt[k][l] = 1;
    dp[k][l] = minn;
    return minn;
}

int main()
{
    a[0] = -1e8;
    cin >> V >> P;
    a[V+1] = 1e8;
    for( int i = 1; i <= V; i++){
        cin >> a[i];
    }
    cout << tongQuangDuong(0,0);
    return 0;
}
