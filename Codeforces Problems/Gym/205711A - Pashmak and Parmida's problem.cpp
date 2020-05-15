//CF Gym 205711A - Pashmak and Parmida's problem

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MAXN 1000010

struct Node {
	int best;

	void make_Node(int v){
		best = v;
	}

	void merge(Node left, Node right) {	
		best = left.best + right.best;
	}
};

struct SegmentTree{
	Node *stree;

	SegmentTree(int N){
		stree = new Node[getSegmentTreeSize(N)];
		buildTree(1, 0, N - 1);
	}

	void buildTree(int nodo, int L, int R){
		if (L == R)
			stree[nodo].make_Node(0);
		else {
			int mid = (L + R)/2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
			buildTree(leftIdx, L, mid);
			buildTree(rightIdx, mid + 1, R);
			stree[nodo].merge(stree[leftIdx], stree[rightIdx]);
		}
	}

	Node query(int nodo, int L, int R, int i, int j){

		if(R < L || j < i){
			Node ans = Node();
			ans.best = 0;
        	return ans;
		}

		if (L <= i && R <= j)
			return stree[nodo];
		
		int mid = (L + R)/2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
		if (j <= mid)
			return query(leftIdx, L, mid, i, j);
		if (i > mid)
			return query(rightIdx, mid + 1, R, i, j);
		
		Node leftResult = query(leftIdx, L, mid, i, mid);
		Node rightResult = query(rightIdx, mid + 1, R, mid + 1, j);
		Node result;
		result.merge(leftResult, rightResult);
		return result;
	}

	void update(int nodo, int L, int R, int idx, int value){
		if(R < idx || idx < L)
        	return;

		if (L == R) {
			stree[nodo].best += value;
			return;
		}

		int mid = (L + R)/2, leftIdx = 2 * nodo, rightIdx = 2 * nodo + 1;
		if (idx <= mid)
			update(leftIdx, L, mid, idx, value);
		else
			update(rightIdx, mid + 1, R, idx, value);
		stree[nodo].merge(stree[leftIdx], stree[rightIdx]);
	}

	int getSegmentTreeSize(int N) {

		int size = 1;
		for(; size < N; size <<= 1);
		return size << 1;
	}
};

vector<int> fLeft(vector<int> &v){
	map<int,int> frec;
	vector<int> ans(v.size());

	for(int i=0; i<v.size(); i++){
		frec[v[i]]++;
		ans[i] = frec[v[i]];
	}

	return ans;
}

vector<int> fRight(vector<int> &v){
	map<int,int> frec;
	vector<int> ans(v.size());

	for(int i=v.size()-1; i>=1; i--){
		frec[v[i]]++;
		ans[i] = frec[v[i]];
	}

	return ans;
}

int main(){
	fast_io

	int n; cin >>n;
	vector<int> v(n);
	for(auto &x:v) cin >> x;

	vector<int> fL = fLeft(v);
	vector<int> fR = fRight(v);

	SegmentTree st(v.size());

	lli sol = 0;
	for(int i=v.size()-1; i>=1; i--){
		sol += st.query(1,1,v.size(),1,fL[i]-1).best;
		st.update(1,1,v.size(),fR[i],1);
	}

	cout << sol << endl;

	return 0;
}
