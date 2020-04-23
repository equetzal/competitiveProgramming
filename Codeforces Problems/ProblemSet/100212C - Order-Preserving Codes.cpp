//CF Gym 100212C - Order-Preserving Codes

#include <bits/stdc++.h>

//Team Vaporub.exe /u/

using namespace std;

const double eps(1e-8);
typedef long long lint;

#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clrs( x , y ) memset( x , y , sizeof(x) )

const int Maxn = 2010;

int n;
lint f[Maxn][Maxn], sum[Maxn], x[Maxn];
int g[Maxn][Maxn];
bool visited[Maxn][Maxn];

vector <int> ret[Maxn];
vector <int> temporal;


void printVisited(){
    cout << "vvvvvvvvvvvvvvvv" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

void printF(){
    cout << "ffffffffffffffff" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}
 
void printG(){
    cout << "ggggggggggggggg" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int l, int r) {
        if(visited[l][r]) 
            return;
        
        visited[l][r] = true;

        if(l+1 == r){
            f[l][r] = sum[r]-sum[l-1];
            g[l][r] = l;
            return;
        }

        if(l == r){
            g[l][r] = 0;
            f[l][r] = 0;
            return;
        }
 
        dfs(l, r-1);
        dfs(l+1, r);

        f[l][r] = -1;
 
        for(int i = g[l][r-1]; i <= g[l+1][r]; i ++){
            if(i < l) 
                continue;
            if(i > r - 1) 
                continue;
            
            dfs(l, i);
            dfs(i+1, r);
 
            if(f[l][i] + f[i+1][r] + sum[r] - sum[l-1] < f[l][r] || f[l][r] == -1){
                f[l][r] = f[l][i] + f[i+1][r] + sum[r] - sum[l-1];
                g[l][r] = i;
            }
        }               
}
 
void busca(int l, int r) {
        if (l == r){
            ret[l] = temporal;
            return;
        }
 
        temporal.push_back(0);
        busca(l, g[l][r]);
        temporal.pop_back();
 
        temporal.push_back(1);
        busca(g[l][r] + 1, r);
        temporal.pop_back();
}
 
int main() {

    freopen("codes.in", "r", stdin);
    freopen("codes.out", "w", stdout);

        while (cin >> n){
            sum[0] = 0;

            for(int i=1; i <= n; i++){
                cin >> x[i];
                sum[i] = sum[i-1] + x[i];
            }
 
            memset(visited, 0, sizeof(visited));
            dfs(1, n);           
 
            temporal.clear();
            busca(1, n);
 
            for(int i=1; i<=n; i++){
                for(int j = 0; j < (int)ret[i].size(); j++)
                    cout << ret[i][j];
                if(i != n)
                    cout << "\n";
            }
        }
 
        return 0;
}
