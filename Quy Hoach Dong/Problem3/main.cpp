#include <iostream>
#define N 10005
using namespace std;
long long n, P, a[N], dp[N], kt[N] = {0};
int chiPhiNhoNhat( int k ){
    if( k == n ){
        return 0;
    }
    if( kt[k] == 1 ){
        return dp[k];
    }
    long long minn = 9999999999;
    for( int i = k+1; i <= n; i++){
        if( a[i] >= a[k]+2*P ){
            for( int j = k+1; j <= i; j++){
                minn = min( minn, chiPhiNhoNhat(j) + (a[k]+P-a[j])*(a[k]+P-a[j]) );
            }
            break;
        }
        if( i == n ){
            for( int j = k+1; j <= n; j++){
                minn = min( minn, chiPhiNhoNhat(j) + (a[k]+P-a[j])*(a[k]+P-a[j]) );
            }
        }
    }
    kt[k] = 1;
    dp[k] = minn;
    return dp[k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> P;
    a[0] = 0;
    for( int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << chiPhiNhoNhat(0);
    return 0;
}
