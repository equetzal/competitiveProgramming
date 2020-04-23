//https://omegaup.com/arena/problem/ride/

#include <string>
#include <iostream>

using namespace std;

typedef long long int lli;

int main(){
	string group, ovni; cin >> group >> ovni;

	lli g=1,o=1;

	for(char c:group)
		g *= (int)(c-('A'-1));

	for(char c:ovni)
		o *= (int)(c-('A'-1));

	if(g%47 == o%47)
		cout << "GO\n";
	else
		cout << "STAY\n";
}
