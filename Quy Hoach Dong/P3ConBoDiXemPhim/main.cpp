#include <iostream>
#define N 5005
using namespace std;
int C, n, w[21], dp[N] = {0};
void giaTriLonNhat(){
    for( int i = 1; i <= n; i++){
        for( int j = C; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]]) ;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> C >> n;
    for( int i = 1; i <= n; i++){
        cin >> w[i];
    }
    dp[0] = 1;
    giaTriLonNhat();
    for( int i = C; ; i--){
        if( dp[i] ){
            cout << i;
            return 0;
        }
    }
    return 0;
}
