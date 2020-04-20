//Tests Renumeration - CF ProblemSet 860C

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	
	vector<string> name(n+1);
	vector<short> type(n+1);
	
	int e=0;
	for(int i=0; i<n; i++) {
		cin >> name[i] >> type[i];
		if(type[i]==1) 
			e++;
	}
	
	set<string> example, test;
	for(int i=1;i<=n;i++) {
		string s=to_string(i);
		if(i<=e) 
			example.insert(to_string(i));
		else 
			test.insert(to_string(i));
	}
	
	set<string> testToExample, exampleToTest, ilegalToExample, ilegalToTest;
	for(int i=0; i<n; i++) {
		if(example.count(name[i])) {
			example.erase(name[i]);
			if(type[i]==0) testToExample.insert(name[i]);
		}
		else if(test.count(name[i])) {
			test.erase(name[i]);
			if(type[i]==1) exampleToTest.insert(name[i]);
		}
		else {
			if(type[i]==0) ilegalToTest.insert(name[i]);
			else ilegalToExample.insert(name[i]);
		}
	}
	
	vector< pair<string,string> > moves;
	while(example.size() || test.size() || testToExample.size() || exampleToTest.size()) {
		if(example.size() && exampleToTest.size()) {
			moves.push_back({*exampleToTest.begin(),*example.begin()});
			example.erase(example.begin());
			test.insert(*exampleToTest.begin());
			exampleToTest.erase(exampleToTest.begin());
			continue;
		}
		if(test.size() && testToExample.size()) {
			moves.push_back({*testToExample.begin(),*test.begin()});
			test.erase(test.begin());
			example.insert(*testToExample.begin());
			testToExample.erase(testToExample.begin());
			continue;
		}
		if(example.size() && ilegalToExample.size()) {
			moves.push_back({*ilegalToExample.begin(),*example.begin()});
			example.erase(example.begin());
			ilegalToExample.erase(ilegalToExample.begin());
			continue;
		}
		if(test.size() && ilegalToTest.size()) {
			moves.push_back({*ilegalToTest.begin(),*test.begin()});
			test.erase(test.begin());
			ilegalToTest.erase(ilegalToTest.begin());
			continue;
		}
		
		assert(testToExample.size()==exampleToTest.size() && testToExample.size());
		example.insert(*testToExample.begin());
		moves.push_back({*testToExample.begin(),"escom"});
		testToExample.erase(testToExample.begin());
		ilegalToTest.insert("escom");
	}
	
	cout << moves.size() << "\n";
	for(auto m:moves){
		cout << "move " <<  m.first << " " << m.second << "\n";
	}
	
	return 0;
}
