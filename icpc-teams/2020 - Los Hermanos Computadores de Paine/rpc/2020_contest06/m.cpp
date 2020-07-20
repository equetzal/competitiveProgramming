//CF Gym 102318F - Multimodal Transport
//UCF Locals 2017
//Los Hermanos Computadores de Paine - Coded by Beto 10 min after contests ended

#include <bits/stdc++.h>

using namespace std;
typedef long long int  lli;
const lli maxn = 2000;
vector<pair<lli,lli>> graph[maxn];
void add_edge(lli u,lli v,lli cost){
    graph[u].push_back({v,cost});
    graph[v].push_back({u,cost});
}
lli d[maxn];
#define x first 
#define y second
const lli INF = 1000000000000000;
lli n,m;
int main(){
    int t;
    lli c;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> cost(n);
        map<string,lli> mp;
        string u,v,type,s,t;
        for(int i = 0;i<4*n;i++){
            graph[i].clear();
        }
        for(lli i = 0;i<n;i++){
            cin>>s>>c;
            mp[s] = i;
            cost[i] = c;
        }
        cin>>m;
        for(lli i = 0;i<m;i++){
            cin>>u>>v>>type>>c;
            if(type[0] == 'A')add_edge(mp[u],mp[v],c);
            if(type[0] == 'S')add_edge(mp[u]+n,mp[v]+n,c);
            if(type[0] == 'R')add_edge(mp[u]+(2*n),mp[v]+(2*n),c);
            if(type[0] == 'T')add_edge(mp[u]+(3*n),mp[v]+(3*n),c);
        }

        cin>>s>>t;

        for(lli i = 0;i<n;i++){ 
            for(lli j = 0;j<3;j++){
                for(lli k = j+1;k<=3;k++){
                    add_edge(i+(j*n),i+(k*n),cost[i]);
                }
            }
        }
        int idx = mp[s];
        int idx2 = mp[t];
        int aux = idx2;
        lli ans = INF;
        for(int z = 0;z<=3;z++){
            for(int i = 0; i < 4*n; ++i)
                d[i] = INF;
            d[idx] = 0;
            set<pair<lli,lli> > st;
            st.insert(make_pair(d[idx], idx));
            while (!st.empty()) {
                lli v = st.begin()->second;
                st.erase(st.begin());
                for(auto c:graph[v]){
                    lli u = c.first;
                    lli w = c.second;
                    if (d[v] + w < d[u]) {
                        st.erase(make_pair(d[u], u));
                        d[u] = d[v]+  w;
                        st.insert(make_pair(d[u], u));
                    }
                }
            }
            idx2 = aux;
            for(int i = 0;i<4;i++){
                ans = min(d[idx2],ans);
                idx2+=n;
            }
            idx+=n;
        }
        cout<<ans<<endl;
    }
    return 0;
}
