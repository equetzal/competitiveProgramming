//Caribbean Camp 2019 - Contest1 - [1] Ploughing, [ID]=4037
#include <bits/stdc++.h>

#define maxn 50005
#define inf LLONG_MAX-5

using namespace std;

typedef long long ll;
typedef pair <ll,ll> pii;

int p[ 3 ], n, m;
vector< pii > Lista[ maxn ]; 

void Dijkstra( int root, ll* dist)
{
	priority_queue< pii > pq;
	for (int i = 0; i < n+3; ++i)
		dist[ i ] = inf;
	dist[ root ] = 0;

	pq.push( make_pair( 0,root ) );
	pii aux;

	while( !pq.empty() )
	{
		aux = pq.top(); pq.pop();
		int u = aux.second;
		ll d = -aux.first;

		if ( d > dist[ u ])
			continue;

		for ( auto &v: Lista[ u ] )
			if ( dist[ u ] + v.second < dist[ v.first ] )
			{
				dist[ v.first ] = dist[u] + v.second;
				pq.push( make_pair(-dist[v.first],v.first) );
			}
	}
}

ll _Dijkstra( ll* root, ll* p1, ll* p2, ll* p3){
	for (int i = 0; i < n; ++i){
		Lista[ n ].push_back( make_pair( i, root[ i ] + p1[ i ] ) );
		Lista[ i ].push_back( make_pair( n+1, p2[ i ] + p3[ i ] ) );
	}

	ll answer[ maxn ];
	Dijkstra( n, answer );

	for (int i = 0; i < n; ++i)
		Lista[ i ].pop_back();
	Lista[ n ].clear();

	return answer[ n+1 ];
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	int a, b;
	ll c;
	
	cin >> n >> m;
	ll distP[ 4 ][ n+4 ];
	for (int i = 0; i < 3; ++i)	{
		cin >> p[ i ]; p[i]--;
	}

	for (int i = 0; i < m; ++i)	{
		cin >> a >> b >> c; a--; b--;
		Lista[ a ].push_back( make_pair(b,c) );
		Lista[ b ].push_back( make_pair(a,c) );
	}

	Dijkstra( 0, distP[ 3 ] ); // Raiz, Distancias del root
	for (int i = 0; i < 3; ++i)
		Dijkstra( p[ i ], distP[ i ] ); //Nodos fav -> todos

	ll ans = inf, aux;
	for (int i = 0; i < 3; ++i){
		aux = _Dijkstra(distP[ 3 ], distP[ i ], distP[ (i+1)%3 ], distP[ (i+2)%3 ]);
		if( ans > aux )
			ans = aux;
	}
	cout << ans << endl;

	return 0;
}