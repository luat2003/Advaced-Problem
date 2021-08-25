#include <iostream>
#include <string.h>
#include <algorithm>
#define N 3005
using namespace std;
int t, n, r[N];
long long  dp[N][N], max_p1[N][N] , max_p2[N][N], Max = 0;


struct Meeting {
    long long st, en, c;
} requests[N];


bool cmp(Meeting a, Meeting b) {
    return a.st < b.st;
}


void giaTriLonNhat(){

    for( int i = 0; i <= n; i++){
        for( int j = i+1; j <= n+1; j++){
            if( requests[j].st > requests[i].en ){
                r[i] = j;
                break;
            }
        }
    }

    for( int p1 = n; p1 >= 0; p1--){
        for( int p2 = n; p2 >= 0; p2--){
            if( p1 == p2 && p1 != 0){
                max_p1[p1][p2] = max_p1[p1][p2+1];
                max_p2[p1][p2] = max_p2[p1+1][p2];
                continue;
            }
            int i1 = max(max(p1,p2)+1, r[p1]), i2 = max(max(p1,p2)+1, r[p2]);
            dp[p1][p2] = max(max_p1[p1][i2], max_p2[i1][p2]);
            max_p1[p1][p2] = max(dp[p1][p2] + requests[p2].c, max_p1[p1][p2+1] );
            max_p2[p1][p2] = max(dp[p1][p2] + requests[p1].c, max_p2[p1+1][p2] );
            Max = max(Max, dp[p1][p2]);
        }
    }

}

int main()
{
    cin >> t;
    requests[0].st = 0;
    requests[0].en = 0;
    requests[0].c = 0;

    for( int i = 1; i <= t; i++){
        cin >> n;
        requests[n+1].st = 1e10;
        Max = 0;
        memset(dp, 0, sizeof(dp));
        memset(max_p1, 0, sizeof(max_p1));
        memset(max_p2, 0, sizeof(max_p2));

        for( int j = 1; j <= n; j++){
            cin >> requests[j].st >> requests[j].en >> requests[j].c;
        }

        sort(requests + 1, requests + n + 1, cmp);
        giaTriLonNhat();
        cout << "#" << i << " " <<  Max << endl;;
    }

    return 0;
}
