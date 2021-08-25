#include <iostream>
#include <string.h>
#include <string>
#define N 401
long long count1[6][N][N] = {0}, count2[6][N] = {0}, count3[6][N] = {0};
using namespace std;

int f( int u, int v){
    int c = 0;
    for( int k = 0; k < 5; k++){
        if( count3[k][v] - count3[k][u-1] > 0 ){
            c++;
        }
    }
    return c;
}

int main()
{

    int n, m;
    long long dem = 0;
    cin >> n;
    for( int i = 1; i <= n; i++){
        string s;
        cin >> s;
        m = s.length();
        for( int j = 1; j <= m; j++){
            for( int k = 0; k < 5; k++){
                count1[k][i][j] = count1[k][i][j-1];
                if( s[j-1] - 'A' == k){
                     count1[k][i][j]++;
                }
            }
        }
    }
    for( int i = 1; i <= m; i++){
        for( int j = i; j <= m; j++){
            for( int v = 1; v <= n; v++){
                for( int k = 0; k < 5; k++){
                    count2[k][v] = count1[k][v][j] - count1[k][v][i-1];
                    count3[k][v] = count3[k][v-1] + count2[k][v];
                }
            }
            for( int u = 1, v1 = 0, v2 = 0; u <= n; u++){
                while( v1 <= n-1 && f( u, v1+1) < 3){
                    v1++;
                }
                while( v2 <= n-1 && f( u, v2+1) <= 3){
                    v2++;
                }
                dem +=  v2-v1;
            }
        }
    }
    cout << dem;
    return 0;
}
