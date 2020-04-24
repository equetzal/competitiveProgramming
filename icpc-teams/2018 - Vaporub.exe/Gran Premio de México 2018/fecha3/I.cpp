#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;

	vector < vector<int> > interruptor(n);
	vector< pair<bool,int> > lamp(m, make_pair(false,0));

	int enc;
	cin >> enc;
	while(enc--){
		int l;
		cin >> l;
		l--;
		lamp[l].first = !lamp[l].first;
	}

	for(int i=0; i<n; i++){
		int nl;
		cin >> nl;

		while(nl--){
			int l;
			cin >> l;
			l--;

			interruptor[i].push_back(l);
			lamp[l].second++;
		}
	}


	bool isAllOff = true;

	for(auto a:lamp){
		if(a.first)
			isAllOff = false;
	}

	if(isAllOff){
		cout << "0" << "\n";
	}

	// bool esCiclo = true;

	// for(auto a:lamp){
	// 	if(a.second % 2 == 1){
	// 		esCiclo = false;
	// 	}
	// 	// cout << a.first;
	// }
	// cout << endl;

	int lim = 50;
	// if(esCiclo)
	// 	lim = 1;

	for(int i=0, c=1; i<lim; i++){
		for(int j=0; j<interruptor.size(); j++, c++){
			for(auto l:interruptor[j]){
				lamp[l].first = !lamp[l].first;
			}
			isAllOff = true;

			// cout << i+1 << ": ";
			for(auto a:lamp){
				if(a.first)
					isAllOff = false;
				// cout << a.first;
			}
			// cout << endl;

			if(isAllOff){
				cout << c << "\n";
				return 0;
			}
		}
	}
	
	cout << "-1\n";


	return 0;

}