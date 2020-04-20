//CF ProblemSet 65B - Harry Potter and the History of Magic

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n; cin >> n;
	vector<string> date(n+2);
	
	for(int i=1; i<=n; i++){
		cin >> date[i];
	}
	date[0] = "1000";
	date[n+1] = "2012";
	
	for(int i=1; i<=n; i++){
		set<string> possibleDates;
		
		for(int j=0; j<4; j++){
			for(int k=0; k<10; k++){
				string actDate = date[i];
				actDate[j] = '0'+k;
				possibleDates.insert(actDate);
			}
		}
		
		auto cont = possibleDates.lower_bound(date[i-1]);

		if(cont != possibleDates.end()){
			date[i] = *cont;
		}else{
			cout << "No solution" << endl;
			return 0;
		}
	}
	
	if(date[n] > "2011" || date[1] < "1000"){
		cout << "No solution" << endl;
		return 0;
	}
	
	for(int i=1; i<=n; i++){
		cout << date[i] << endl;
	}
	
	return 0;
}
