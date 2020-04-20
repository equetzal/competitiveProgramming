#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010

typedef pair<int,int> ii;

int arr[MAXN], lastPos[MAXN];

struct Node {

	int sum;

	void make_Node(int v) {
		sum = v;
	}

	void merge(Node left, Node right) {
		sum = left.sum + right.sum;
	}
}; 

struct SegmentTree{
	Node *stree;
	SegmentTree(int N){
		  stree=new Node[getSegmentTreeSize(N)];
		  buildTree(1,0,N-1);		
	}
	void buildTree(int nodo, int L, int R){
		if(L==R)
			 stree[nodo].make_Node(arr[L]);
		else{
			int mid= (L+R)/2;
			int leftIdx=2*nodo;
			int rightIdx=2*nodo + 1;
			buildTree(leftIdx,L,mid);
			buildTree(rightIdx,mid+1,R);
			stree[nodo].merge(stree[leftIdx], stree[rightIdx]);
		}
	}
	Node query(int nodo, int L, int R, int i, int j){
		if(L >=i && R<=j) return stree[nodo];
		int mid = (L+R)/2;
		int leftIdx= 2*nodo;
		int rightIdx= 2*nodo +1;
		if(j<=mid)
			return query(leftIdx, L,mid,i,j);
		if(i>mid)
			return query(rightIdx,mid+1,R,i,j);
		Node leftResult =query(leftIdx,L,mid,i,mid);
		Node rightResult= query(rightIdx,mid+1,R,mid+1,j);
		Node result;
		result.merge(leftResult,rightResult);
		return result;
	}
	void update(int nodo, int L, int R , int idx, int value){
		if(L==R){
			arr[idx]=value;
			stree[nodo].make_Node(value);
			return;
		}
		int mid = (L+R)/2;
		int leftIdx=2*nodo;
		int rightIdx = 2*nodo+1;
		if(idx <=mid){
			update(leftIdx,L,mid,idx,value);
		}else{
			update(rightIdx,mid+1,R,idx,value);
		}
		stree[nodo].merge(stree[leftIdx], stree[rightIdx]);
	}

	int getSegmentTreeSize(int N){
		int size=1;
		for(;size<N;size<<=1);
		return size<<1;
	}	

};

int main() {

	int TC, N, Q, x, y, a[100010];
	vector<pair<ii,int> > queries;
	vector<int> ans;

	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &N, &Q);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < Q; i++) {
			scanf("%d %d", &x, &y);
			queries.push_back(make_pair(ii(y,x), i));
		}
		sort(queries.begin(), queries.end());
		ans.assign(Q, 0);
		memset(lastPos, -1, sizeof(lastPos));
		SegmentTree st(N + 1);
		int idx = 0;
		for (int i = 0; i < N; i++) {
			if (lastPos[a[i]] != -1)
				st.update(1, 0, N - 1, lastPos[a[i]], 0);
			lastPos[a[i]] = i;
			st.update(1, 0, N - 1, i, 1);
			while (i == queries[idx].second) {
				ans[queries[idx].second] = st.query(1, 0, N - 1, queries[idx].first.second, queries[idx].first.first).sum;
				idx++;
			}
		}
		for (int i = 0; i < ans.size(); i++) {
			printf("%d\n", ans[i]);
		}
		queries.clear();
	}
	return 0;
}