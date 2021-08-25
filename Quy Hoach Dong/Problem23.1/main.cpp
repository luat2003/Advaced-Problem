#include <bits/stdc++.h>
#include <string.h>
#include <string>
using namespace std;
#define N 100005
double dp[N][2][2][2];
int kt[N][2][2][2];
string L, R;

double timSoCoTichLonNhat(int vt, int sl, int sr, int kt0)
{
    if (vt == L.length() ) {
        return 0;
    }
    if( kt0 == 0 && vt > 1 ){
        return -1e8;
    }
    if( kt0 == 0 && vt == 1 ){
        return log(9)*(R.length()-vt);
    }
    if ( kt[vt][sl][sr][kt0] ){
        return dp[vt][sl][sr][kt0];
    }
    int st, en;
    if( sl == 0 ){
        st = L[vt]-'0';
    }else{
        st = 0;
    }
    if( sr == 0 ){
        en = R[vt] - '0';
    }else{
        en = 9;
    }
    double kq = 0;
    for( int i = en; i >= st; i--){
        int val = i;
        if( kt0 == 1 && i == 0){
            val = 1;
        }
        if( kq < timSoCoTichLonNhat(vt+1, sl || (i > L[vt]-'0'), sr || (i < R[vt]-'0'), kt0 && i > 0) + log(val)){
            kq = timSoCoTichLonNhat(vt+1, sl || (i > L[vt]-'0'), sr || (i < R[vt]-'0'), kt0 && i > 0) + log(val);
        }
    }
    dp[vt][sl][sr][kt0] = kq;
    kt[vt][sl][sr][kt0] = 1;
    return kq;
}

void loadLai(int vt, int sl, int sr, int kt0){
    if( vt == R.length() ){
        return;
    }
    int st, en;
    if( sl == 0 ){
        st = L[vt]-'0';
    }else{
        st = 0;
    }
    if( sr == 0 ){
        en = R[vt] - '0';
    }else{
        en = 9;
    }
    double kq = dp[vt][sl][sr][kt0];
    for( int i = st; i <= en; i++){
        int val = i;
        if( kt0 == 0 && i == 0){
            val = 1;
        }
        if( kq == timSoCoTichLonNhat(vt+1, sl || (i > L[vt]-'0'), sr || (i < R[vt]-'0'), kt0 && i > 0) + log(val) ){
            cout << i;
            loadLai(vt+1, sl || (i > L[vt]-'0'), sr || (i < R[vt]-'0'), kt0 && i > 0);
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> L >> R;
    L.insert(0, R.length()-L.length(), '0');
    if( abs(timSoCoTichLonNhat(0,0,0,1) - log(R[0]-'0')) < 1e-6 ){
        cout << R;
        return 0;
    }
    if( R[1] == '0'){
        if( R[0]-'0' > 1 ){
            cout << R[0]-'1';
            if( R[0]-1 > L[0] ){
                loadLai(1,1,1,1);
            }else{
                loadLai(1,0,1,1);
            }
        }else{
            for( int i = 1; i < R.length(); i++){
                cout << 9;
            }
        }
        return 0;
    }
    if( R[1] <= '9' && R[0] == '1' && L[0] == '0'){
        for( int i = 1; i < R.length();i++){
            cout << 9;
        }
        return 0;
    }
    if( R[1] <= '4' && R[0] == '2' && L[0] <= '1'){
        cout << 1;
        for( int i = 1; i < R.length();i++){
            cout << 9;
        }
        return 0;
    }
    loadLai(0,0,0,1);
    return 0;
}
