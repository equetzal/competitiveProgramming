//UVa p11686 - Pick up sticks

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(){
	    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m;

	while(cin >> n >> m){
		if (n == 0 || m == 0)
			break;
		vector < vector <int> > graph(n);
		vector <int> degree(1000005, 0);

		while(m--){
			int a,b;
			cin >> a >> b;
			graph[a-1].push_back(b-1);
			degree[b-1]++;
		}

		vector <bool> visited(n,false);

		queue<int> Q;
		queue<int> res;
		for(int i=0; i<n; i++){
			if(degree[i] == 0)
				Q.push(i);
		}

		int front;
		while(!Q.empty()){
			front = Q.front();
			res.push(front);
			Q.pop();
			for(auto a:graph[front]){
				degree[a]--;
				if(degree[a] == 0)
					Q.push(a);
			}
		}

		if(res.size() != n){
			cout << "IMPOSSIBLE\n";
		}else{
			while(!res.empty()){
				cout << res.front()+1 << endl;
				res.pop();
			}
		}
	}


	return 0;
}
