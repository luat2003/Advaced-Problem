#include<bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int n, dp1[50002], dp2[50002], id[50002], truyvan, maxy, miny;
ii a[50002];
vector<int> adj[50002], ngc[50002], ngang[50002], moe;
unordered_map<int,int> nen;
bool ok[50002];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    miny = (int)1e9, maxy = -miny;
    bool oki = 0, oki2 = 0, oki3 = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i].fi >> a[i].se;
        maxy = max(maxy, a[i].se), miny = min(miny, a[i].se);
        oki |= (!a[i].fi);
        oki2 |= (a[i].fi + a[i].se == 0);
        oki3 |= (a[i].fi-a[i].se == 0);
        moe.pb(a[i].se);
    }
    if(maxy == miny){
        if(oki || oki2 || oki3) cout << n;
        else cout << 0;
        return 0;
    }
    moe.pb(0); // nen toa do y
    sort(moe.begin(), moe.end());
    moe.resize(unique(moe.begin(), moe.end()) - moe.begin());
    nen[moe[0]] = 0;
    for(int i = 1;i < (int)moe.size();i ++) nen[moe[i]] = nen[moe[i-1]] + (moe[i] > moe[i-1]);
    for(int i = 0;i <= n;i ++){
        ngang[nen[a[i].se]].pb(i);
        id[i] = i;
    }
    sort(id, id+n+1, [&](const int &x,const int &y){
        if(a[x].fi == a[y].fi) return a[x].se < a[y].se;
        return a[x].fi < a[y].fi;
    });
    int xp = 0;
    while(1){
        if(xp > n) break;
        int dich = xp;
        while(dich <= n && a[id[dich]].fi == a[id[xp]].fi){
            if(dich > xp){
                adj[id[dich]].pb(id[dich-1]);
                ngc[id[dich-1]].pb(id[dich]);
            }
            dich ++;
        }
        xp = dich;
    }
    for(int i = 0;i <= n;i ++) id[i] = i;
    sort(id, id+n+1, [&](const int &x,const int &y){
        if(a[x].fi+a[x].se == a[y].fi+a[y].se) return a[x].se < a[y].se;
        return a[x].fi+a[x].se < a[y].fi+a[y].se;
    });
    xp = 0;
    while(1){
        if(xp > n) break;
        int dich = xp;
        while(dich <= n && a[id[dich]].fi+a[id[dich]].se == a[id[xp]].fi+a[id[xp]].se){
            if(dich > xp){
                adj[id[dich]].pb(id[dich-1]);
                ngc[id[dich-1]].pb(id[dich]);
            }
            dich ++;
        }
        xp = dich;
    }
    for(int i = 0;i <= n;i ++) id[i] = i;
    sort(id, id+n+1, [&](const int &x,const int &y){
        if(a[x].fi-a[x].se == a[y].fi-a[y].se) return a[x].se < a[y].se;
        return a[x].fi-a[x].se < a[y].fi-a[y].se;
    });
    xp = 0;
    while(1){
        if(xp > n) break;
        int dich = xp;
        while(dich <= n && a[id[dich]].fi-a[id[dich]].se == a[id[xp]].fi-a[id[xp]].se){
            if(dich > xp){
                adj[id[dich]].pb(id[dich-1]);
                ngc[id[dich-1]].pb(id[dich]);
            }
            dich ++;
        }
        xp = dich;
    }
    for(int it : moe) sort(ngang[nen[it]].begin(), ngang[nen[it]].end(), [&](const int &x,const int &y){
        return a[x].fi < a[y].fi;
    });
    for(int it : ngang[nen[0]]) if(!ok[it]) ok[it] =1, q.push(it);
    while(q.size()){
        int moe2 = q.front(); q.pop();
        for(int it : ngc[moe2]) if(!ok[it]) ok[it] = 1, q.push(it);
        for(int it : ngang[nen[a[moe2].se]]) if(!ok[it]) ok[it] = 1, q.push(it);
    }
    for(int i = 0;i < (int)ngang[nen[0]].size();i ++){
        int it = ngang[nen[0]][i];
        if(a[it].fi < 0) dp2[it] = (int)ngang[nen[0]].size() - i;
        else if(!a[i].fi) dp2[it] = 1;
        else dp2[it] = i+1;
    }
    memset(id, 0, sizeof(id));
    for(int it : moe){
        if(!it) continue;
        truyvan ++;
        int dau = (int)1e9, cuoi = -dau;
        for(int i = 0;i < (int)ngang[nen[it]].size();i ++){
            int it2 = ngang[nen[it]][i];
            for(int it3 : adj[it2]) if(ok[it3]){
                id[it2] = truyvan;
                dp1[it2] = max(dp1[it2], dp2[it3]);
                dau = min(dau, i), cuoi = max(cuoi, i);
            }
        }
        if(dau == (int)1e9) continue;
        int maxx = dp1[ngang[nen[it]][dau]];
        for(int i = dau+1;i < (int)ngang[nen[it]].size();i ++){
            dp2[ngang[nen[it]][i]] = max(dp2[ngang[nen[it]][i]], maxx + i + 1);
            maxx = max(maxx, dp1[ngang[nen[it]][i]]);
        }
        maxx = dp1[ngang[nen[it]][cuoi]];
        for(int i = cuoi-1;i >= 0;i --){
            dp2[ngang[nen[it]][i]] = max(dp2[ngang[nen[it]][i]], maxx + (int)ngang[nen[it]].size() - i);
            maxx = max(maxx, dp1[ngang[nen[it]][i]]);
        }
        for(int it2 : ngang[nen[it]]) if(id[it2] == truyvan) dp2[it2] = max(dp2[it2], dp1[it2] + 1);
    }
    int ans(0);
    for(int i = 0;i <= n;i ++) if(ok[i]) ans = max(ans, dp2[i]);
    cout << --ans;

    return 0;
}