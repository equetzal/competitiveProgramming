//Kattis Open buildingboundaries - Building Boundaries
//Los Hermanos Computadores de Paine - Coded by Quetzalli

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int lli;
#define endl "\n"

int main(){
    int t; cin>>t;
    while(t--){
        vector<pair<lli,lli>> rect(3);
		for(auto &x:rect) cin >> x.first >> x.second;
        sort(rect.begin(),rect.end());

        lli ans = (1L<<63)+1;
        do {
            for(int i = 0;i<=7;i++){
				bool vertA = ((i>>2) &1);
				bool vertB = ((i>>1) & 1);
				bool vertC = ((i&1));

				auto r1 = vertA?rect[0]:make_pair(rect[0].second, rect[0].first);
				auto r2 = vertB?rect[1]:make_pair(rect[1].second, rect[1].first);
				auto r3 = vertC?rect[2]:make_pair(rect[2].second, rect[2].first);

				if(r2.first >= r1.first) swap(r1,r2);
                lli b,h,area;

				//Caso 1
				h = r1.first+r3.first; 
				b = max(r3.second, r1.second+r2.second);
				area = b*h;
				ans = min(ans, area);

				//Caso 2
				h = max(r1.first, r2.first+r3.first); 
				b = r1.second + max(r2.second, r3.second);
				area = b*h;
				ans = min(ans, area);

				//Caso 3
				h = max(r1.first, max(r2.first,r3.first)); 
				b = r1.second+r2.second+r3.second;
				area = b*h;
				ans = min(ans, area);            
            }

        }while(next_permutation(rect.begin(),rect.end()));
        cout << ans << endl;
    }
    return 0;
}
