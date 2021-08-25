#include <iostream>
#define N 105
using namespace std;
int n, a[N], s = 0,  kt[N][N] = {0}, dp[N][N], x[N];

int soBuocNhoNhat(int k, int j){
    if( kt[k][j] ){
        return dp[k][j];
    }
    if( k == n ){
        return 0;
    }
    int minn = 1e8;
    for( int i = j+1; i <= 100-(n-k-1); i++){
        minn = min( minn, soBuocNhoNhat(k+1, i) + abs(a[k+1] - i) );
    }
    kt[k][j] = 1;
    dp[k][j] = minn;
    return minn;
}

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int Min = 1e8;
    for( int i = 1; i <= 100-(n-1); i++){
        Min = min( Min, soBuocNhoNhat(1, i) + abs(a[1] - i) );
    }
    cout << Min;
    return 0;
}
