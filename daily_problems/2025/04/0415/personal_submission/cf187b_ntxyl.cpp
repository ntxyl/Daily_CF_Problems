#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int dp[61][61][61];

void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    // memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++) dp[i][j][k]=1e18;
        }
    }
    
    while(m--){
        vector<vector<int>>a(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cin>>a[i][j];
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j][0]=min(dp[i][j][0],a[i][j]);
            }
        }
    }
    for(int k=1;k<n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int t=1;t<=n;t++){
                    dp[i][t][k]=min(dp[i][t][k],dp[i][j][k-1]+dp[j][t][0]);
                }
            }
        }
    }


    while(q--){
        int x,y,k;
        cin>>x>>y>>k;
        cout<<dp[x][y][min(k,n-1)]<<endl;
    }

}
signed main() {
    fastio;
    int T;
 T = 1;
    // cin>>T;
    while (T--) solve();

    return 0;
}
