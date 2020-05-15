#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

typedef long long int lli;
map<tuple<int,int,int>, int> res;
set<int> preVals;

struct Query{
	int l, r, x, idx; 
}; 

struct ArrayElement{ 
	int val, idx; 
}; 

bool cmp1(Query q1, Query q2) { 
	return q1.x < q2.x;
} 

bool cmp2(ArrayElement x, ArrayElement y) { 
	return x.val < y.val; 
} 

void update(int bit[], int idx, int val, int n) { 
	for (; idx<=n; idx +=idx&-idx)
		bit[idx] += val;
} 

int query(int bit[], int idx, int n) { 
	int sum = 0; 
	for (; idx > 0; idx -= idx&-idx) 
		sum += bit[idx]; 
	return sum; 
}

void answerQueries(int n, Query queries[], int q, ArrayElement arr[]){
	int bit[n+1]; 
	memset(bit, 0, sizeof(bit)); 
	
	int last_visit[MAX]; 
    memset(last_visit, -1, sizeof(last_visit));

	sort(arr, arr+n, cmp2); 
	sort(queries, queries+q, cmp1); 

	int curr = 0; 
	int ans[q];

	for (int i=0; i<q; i++) { 
		cout << "en q=" << i << endl;
		while(arr[curr].val <= queries[i].x && curr<n){ 
			if (last_visit[arr[curr].val] !=-1) 
				update(bit, last_visit[arr[curr].val] + 1, -1, n);
			last_visit[arr[curr].val] = max(arr[curr].idx,last_visit[arr[curr].val]);
			
			update(bit, last_visit[arr[curr].val] + 1, 1, n);
			curr++; 
		}

		ans[queries[i].idx] = query(bit, queries[i].r+1, n) - query(bit, queries[i].l, n); 
		cout << "l=" << queries[i].l << " r=" << queries[i].r << " x=" << queries[i].x << " ans=" << ans[queries[i].idx] << endl; 
		res[make_tuple(queries[i].l, queries[i].r, queries[i].x)] = ans[queries[i].idx];
	} 

} 

// driver function 
int main() { 
	int n, q; cin >> n >> q;
	cout << "n=" << n << ", q=" << q << endl;
	ArrayElement arr[n];
	
	for(int i=0; i<n; i++){
		cin >> arr[i].val;
		cout << arr[i].val << " ";
		arr[i].idx = i;
	}
	cout << endl;

	// number of queries
	vector<tuple<int,int,int,int>> orgQueries;
	Query queries[q*2];
	int l,r,x,y;
	for(int i=0; i<q; i++){
		cin >> l >> r >> x >> y;
		orgQueries.push_back(make_tuple(l-1,r-1,x-1,y));
		queries[i*2].l = queries[i*2+1].l = l-1;
		queries[i*2].r = queries[i*2+1].r = r-1;
		queries[i*2].x = x-1;
		queries[i*2+1].x = y;
		queries[i*2].idx = i*2;
		queries[i*2+1].idx = i*2+1;
	}
	
	cout << "lectura ok" << endl;
	
	answerQueries(n, queries, q*2, arr); 
	
	cout << "LLego" << endl;
	for(auto t:orgQueries){
		l = get<0>(t);
		r = get<1>(t);
		x = get<2>(t);
		y = get<3>(t);
		cout << "l=" << l << " r=" << r << " x=" << x << " ans=" << res[make_tuple(l,r,x)] << endl; 
		cout << "l=" << l << " r=" << r << " y=" << y << " ans=" << res[make_tuple(l,r,y)] << endl; 
		cout << res[make_tuple(l,r,y)] - res[make_tuple(l,r,x)] << endl;
	}

	return 0; 
} 
