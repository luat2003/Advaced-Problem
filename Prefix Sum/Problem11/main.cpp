#include <iostream>
#define X 101

long long s[X][X][X] = {0}, a[X][X][X];
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int L, M, N;
    cin >> L >> M >> N;
    for( int k = 1; k <= N; k++){
        for( int j = 1; j <= M; j++){
            for( int i = 1; i <= L; i++){
                cin >> a[k][j][i];
                s[k][j][i] = s[k][j][i-1]+s[k][j-1][i]-s[k][j-1][i-1]+s[k-1][j][i]-s[k-1][j][i-1]-s[k-1][j-1][i]+s[k-1][j-1][i-1]+a[k][j][i];
            }

        }
    }
    int x1,y1,z1,x2,y2,z2;
    while( cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2){
        cout << s[z2][y2][x2]-s[z2][y2][x1] - s[z2][y1][x2] + s[z2][y1][x1]-s[z1][y2][x2]+s[z1][y2][x1]+s[z1][y1][x2]-s[z1][y1][x1] << endl;
    }
    return 0;
}
