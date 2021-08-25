#include<bits/stdc++.h>
#define N 1000006
using namespace std;

typedef long long ll;
string l, r;
double dp[N][2][2][2];

struct Trace{
    int d; int stateL; int stateR; int check;
    Trace(int d, int stateL, int stateR, int check): d(d), stateL(stateL), stateR(stateR), check(check) {};
    Trace(){
        d = stateL = stateR = check = 0;
    }
};

double flog(int d){
    if(d == 0) return -1e9;
    return log(d);
}

Trace trace[N][2][2][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l;
    cin >> r;

    while(l.size() < r.size()) l = '0' + l;
    l = '0' + l; r = '0' + r;
    int k = r.size() - 1;
    for(int i = 0; i <= k; i++){
        for(int stateL = 0; stateL < 2; stateL++){
            for(int stateR = 0; stateR < 2; stateR++){
                for(int check = 0; check < 2; check++){
                    dp[i][stateL][stateR][check] = -1;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    for(int i = 0; i < k; i++){
        for(int stateL = 0; stateL < 2; stateL++){
            for(int stateR = 0; stateR < 2; stateR++){
                for(int check = 0; check < 2; check++){
                    if(dp[i][stateL][stateR][check] >= 0){

                        int lower = (stateL == 0) ? (l[i + 1] - '0') : 0;
                        int upper = (stateR == 0) ? (r[i + 1] - '0') : 9;
                        for(int d = lower; d <= upper; d++){
                            double new_val = flog(d) + dp[i][stateL][stateR][check];
                            int new_stateL = stateL | (d > l[i + 1] - '0');
                            int new_stateR = stateR | (d < r[i + 1] - '0');
                            int new_check = check | (d != 0);
                            if(check == 0 && d == 0){
                                new_val = dp[i][stateL][stateR][check];
                            }
                            if(new_val > dp[i + 1][new_stateL][new_stateR][new_check]){
                                dp[i + 1][new_stateL][new_stateR][new_check] = new_val;
                                trace[i + 1][new_stateL][new_stateR][new_check] = {d, stateL, stateR, check};

                            }
                        }
                    }
                }
            }
        }
    }
    double max_val = -1;
    int bestL = -1;
    int bestR = -1;
    int bestcheck = -1;
    for(int stateL = 0; stateL < 2; stateL++){
        for(int stateR = 0; stateR < 2; stateR++){
            for(int check = 0; check < 2; check++){
                if(max_val < dp[k][stateL][stateR][check]){
                    max_val = dp[k][stateL][stateR][check];
                    bestL = stateL;
                    bestR = stateR;
                    bestcheck = check;
                }
            }
        }
    }
    if(max_val == -1){
        cout << r.substr(1, r.size());
        return 0;
    }
    string x = "";
    for(int i = k; i > 0; i--){
        if(bestcheck == 0) break;
        x = char((trace[i][bestL][bestR][bestcheck].d + '0')) + x;
        int stateL = trace[i][bestL][bestR][bestcheck].stateL;
        int stateR = trace[i][bestL][bestR][bestcheck].stateR;
        int check = trace[i][bestL][bestR][bestcheck].check;
        bestL = stateL;
        bestR = stateR;
        bestcheck = check;
    }
    if(x == "") cout << r.substr(1, r.size());
    else cout << x;
}
