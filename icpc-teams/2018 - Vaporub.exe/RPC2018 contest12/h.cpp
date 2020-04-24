#include <set>
#include <iostream>

using namespace std;


int main(){
	set <int> el;
	set <int> ella;
	set <int> ambos;

	int kEl, kElla;
	cin >> kEl;
	int k;
	while(kEl--){
		cin >> k;
		el.insert(k);
	}
	cin >> kElla;
	while(kElla--){
		cin >> k;
		if(el.find(k) == el.end()){
			ella.insert(k);
		}else{
			el.erase(el.find(k));
			ambos.insert(k);
		}
	}

	int maxDays = ambos.size();
	int mn = min(ella.size(), el.size());
	if(!el.empty() || !ella.empty())
		maxDays += 2*mn;
	if(el.size()-mn > 0 || ella.size()-mn > 0)
		maxDays++;

	cout << maxDays << endl;

	return 0;
}
