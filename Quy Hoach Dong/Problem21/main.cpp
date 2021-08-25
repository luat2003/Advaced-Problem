#include <iostream>
#include <string.h>
#define N 100005
using namespace std;
string s;
int n;
int kt[N][3][3], check[N][3][3];

int DienXauDung( int k, char a, int b, int S){
    if( kt[k][a-48][b] ){
        return check[k][a-48][b];
    }

    if( k == s.length() ){
        if( S == s.length()/2 ){
            return 1;
        }else{
            return 0;
        }
    }
    int ktra ;
    if( b == 2 ){
        if( s[k] == a ){
            kt[k][a-48][b] = 1;
            check[k][a-48][b] = 0;
            return 0;
        }
        if( s[k] == '.' ){
            ktra = DienXauDung(k+1, '0'+'1'-a, 1, S + '1' - a);
        }else{
            ktra = DienXauDung(k+1, s[k], 1, S + s[k]-'0' );
        }
    }
    if( b == 1 ){
        if( s[k] == '.' ){
            ktra = max(DienXauDung(k+1, a, 2, S + a-'0'), DienXauDung(k+1, '0'+'1'-a, 1, S + '1'-a) );
        }else if( s[k] == a){
            ktra = DienXauDung(k+1, a, 2, S + a-'0');
        }else{
            ktra = DienXauDung(k+1, s[k], 1, S + s[k] - '0' );
        }
    }
    kt[k][a-48][b] = 1;
    check[k][a-48][b] = ktra;
    return ktra;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for( int j = 1; j <= n; j++){
        cin >> s;
        if( s.length() % 2 != 0 ){
            cout << "no" << endl;
            continue;
        }
        memset(kt, 0, sizeof(kt));
        memset(check, 0, sizeof(check));
        if( s[0] == '.'){
            if( s[1] == '.' ){
                if( DienXauDung(2, '1', 1 ,1) || DienXauDung(2, '1', 2 ,2) || DienXauDung(2, '0', 1,1) || DienXauDung(2, '0', 2, 0) ){
                    cout << "yes" << endl;
                    continue;
                }else{
                    cout << "no" << endl;
                    continue;
                }
            }
            if( DienXauDung(2, s[1], 2, 2*(s[1]-'0') ) || DienXauDung(2, s[1], 1, 1) ){
                cout << "yes" << endl;
                continue;
            }else{
                cout << "no" << endl;
                continue;
            }
        }
        if( s[1] == '.'){
            if( DienXauDung(2, s[0], 2, 2*(s[0]-'0') ) || DienXauDung(2, '1'+'0'-s[0], 1, 1) ){
                cout << "yes" << endl;
                continue;
            }else{
                cout << "no" << endl;
                continue;
            }
        }
        if( s[1] == s[0] ){
            if( DienXauDung(2, s[1], 2, s[1]+s[0]-96) ){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }else{
            if( DienXauDung(2, s[1], 1, 1) ){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }

    }
    return 0;
}
