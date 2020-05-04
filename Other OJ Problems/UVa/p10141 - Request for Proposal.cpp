//UVa p10141 - Request for Proposal

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	int n,p,r,caseId=1;
	double price;
	string s;
	bool isFirst = true;
	while(cin >> n >> p){
		if(n == 0 && p == 0)
			break;

		if(!isFirst)
			cout << endl;
		isFirst = false;

		for(int i=0; i<n; i++)
			getline(cin,s);

		vector<pair< pair<double, double>, int>> sol;
		vector<string> names(p); getline(cin, names[0]);

		for(int i=0; i<p; i++){
			getline(cin, names[i]);
			cin >> price >> r;  getline(cin,s);

			sol.push_back(make_pair(make_pair(double(r)/double(n), -price), -i));
			while(r--)
				getline(cin,s);
		}

		sort(sol.rbegin(), sol.rend());
		cout << "RFP #" << caseId << endl;
		cout << names[-sol[0].second] << endl;

		caseId++;
	}

	return 0;
}
