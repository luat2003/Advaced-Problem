#include <iostream>
#include <string.h>
#define N 100005
using namespace std;
string s;
int n;
int kt1[N][3][3], check1[N][3][3], kt2[N][3][3], check2[N][3][3];

int soSo0NhieuNhatCoThe( int k, char a, int b){
    if( kt2[k][a-48][b] ){
        return check2[k][a-48][b];
    }
    if( k == s.length()){
        return 0;
    }
    int maxx = 0;
    if( b == 2){
        if( s[k] == a){
            kt2[k][a-48][b] = 1;
            check2[k][a-48][b] = -1e8;
            return -1e8;
        }
        maxx = max(maxx, a-'0'+soSo0NhieuNhatCoThe(k+1, '1'+ '0' - a, 1));
    }
    if( b == 1 ){
        if( s[k] == '0'){
            maxx = max(maxx, 1 + soSo0NhieuNhatCoThe(k+1, '0', 1+'1'-a));
        }else if( s[k] == '1') {
            maxx = max(maxx, soSo0NhieuNhatCoThe(k+1, '1', 1+a-'0'));
        }else{
            maxx = max( soSo0NhieuNhatCoThe(k+1, '1', 1+a-'0'), 1 + soSo0NhieuNhatCoThe(k+1, '0', 1+'1'-a));
        }
    }
    check2[k][a-48][b] = maxx;
    kt2[k][a-48][b] = 1;
    return maxx;
}

int soSo1NhieuNhatCoThe( int k, char a, int b){
    if( kt1[k][a-48][b] ){
        return check1[k][a-48][b];
    }
    if( k == s.length()){
        return 0;
    }
    int maxx = 0;
    if( b == 2){
        if( s[k] == a){
            kt1[k][a-48][b] = 1;
            check1[k][a-48][b] = -1e8;
            return 0;
        }
        maxx = max(maxx, '1'-a+soSo1NhieuNhatCoThe(k+1, '1'+ '0' - a, 1));
    }
    if( b == 1 ){
        if( s[k] == '1'){
            maxx = max(maxx, 1 + soSo1NhieuNhatCoThe(k+1, '1', 1+a-'0'));
        }else if( s[k] == '0'){
            maxx = max(maxx, soSo1NhieuNhatCoThe(k+1, '0', 1+'1'-a));
        }else{
            maxx = max( soSo1NhieuNhatCoThe(k+1, '0', 1+'1'-a), 1 + soSo1NhieuNhatCoThe(k+1, '1', 1+a-'0'));
        }

    }
    check1[k][a-48][b] = maxx;
    kt1[k][a-48][b] = 1;
    return maxx;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for( int j = 1; j <= n; j++){
        cin >> s;
        int l = s.length(), chec = 0;
        if( l % 2 != 0 ){
            cout << "no" << endl;
            continue;
        }
        for( int i = 0; i < l-2; i++){
            if( s[i] == s[i+1] && s[i+1] == s[i+2] && s[i] != '.' ){
                chec = 1;
                break;
            }
        }
        if( chec == 1 ){
            cout << "no" << endl;
            continue;
        }
        memset(kt1, 0, sizeof(kt1));
        memset(check1, 0, sizeof(check1));
        memset(kt2, 0, sizeof(kt2));
        memset(check2, 0, sizeof(check2));
        if( s[0] == s[1] ){
            if( s[0]== '.'){
                if( (2+soSo0NhieuNhatCoThe(2,'0',2) >= l/2 || 1+soSo0NhieuNhatCoThe(2,'0',1) >= l/2 || 1+soSo0NhieuNhatCoThe(2,'1',1) >= l/2) && (2+soSo1NhieuNhatCoThe(2,'1',2) >= l/2 || 1+soSo1NhieuNhatCoThe(2,'0',1) >= l/2 || 1+soSo1NhieuNhatCoThe(2,'1',1) >= l/2) ){
                    cout << "yes" << endl;
                }else{
                    cout  << "no" << endl;
                }
                continue;
            }
            if( (2*('1'-s[1]) + soSo0NhieuNhatCoThe(2, s[1], 2) >= l/2) && (2*(s[1]-'0') + soSo1NhieuNhatCoThe(2,s[1],2) >= l/2) ){
                cout << "yes" << endl;
            }else{
                cout  << "no" << endl;
            }
            continue;
        }
        if( s[1] == '.' ){
            if( (1+s[0]-'0' + soSo1NhieuNhatCoThe(2,'1', 1+s[0]-'0') >= l/2 || s[0]-'0'+soSo1NhieuNhatCoThe(2, '0', 1+'1'-s[0]) >= l/2 ) && (1+'1'-s[0] + soSo0NhieuNhatCoThe(2,'0', 1+'1'-s[0]) >= l/2 || '1'-s[0]+soSo0NhieuNhatCoThe(2, '1', 1+s[0]-'0') >= l/2 )){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
            continue;
        }
        if( s[0] == '.' ){
            if( (1+s[1]-'0' + soSo1NhieuNhatCoThe(2,s[1], 1+s[1]-'0') >= l/2 || s[1]-'0'+soSo1NhieuNhatCoThe(2, s[1], 1+'1'-s[1]) >= l/2 ) && (1+'1'-s[1] + soSo0NhieuNhatCoThe(2,s[1], 1+'1'-s[1]) >= l/2 || '1'-s[1]+soSo0NhieuNhatCoThe(2, s[1], 1+s[1]-'0') >= l/2 )){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
            continue;
        }
        if( 1+soSo1NhieuNhatCoThe(2,s[1], 1) >= l/2 && (1 + soSo0NhieuNhatCoThe(2,s[1], 1) ) >= l/2 ){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
    }
    return 0;
}
