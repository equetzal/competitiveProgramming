//https://omegaup.com/arena/problem/Mega-Lista/

#include <iostream>
#include <vector>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);

	char op;
	int pos=0;
	vector <int> res;

	while(op = getchar()){
		cout << op;
		if(op == '#'){
			// string a;
			// cin >> a;
			break;
		}

		if(op == '+'){
			cin >> pos;
			cout << " = " << pos << endl;
			res.push_back(pos);
		}else{
			cin >> pos;
			cout << " = " << pos << endl;
			res.erase(res.begin()+pos,res.begin()+pos+1);
		}
		getchar();
		getchar();
	}

	for(int i=0; i<res.size(); i++){
		if(i+1==res.size())
			cout << res[i];
		else
			cout << res[i] << " -> ";
	}

	return 0;
}
