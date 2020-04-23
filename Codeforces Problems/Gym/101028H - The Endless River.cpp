//2016 Al-Baath University Training Camp Contest-1
//CF Gym 101028H - The Endless River

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;

	while(t--){
		int n,d,r; cin >> n >> d >> r;
		vector <bool> Dflags(n,false);
		vector <bool> Rflags(n,false);

		int minutes = 0;
		int Dpos = 0;
		int Rpos = 0;
		while(true){
			minutes++;

			Dpos += d;
			Dpos = Dpos%n;

			Rpos += r;
			Rpos = Rpos%n;

			if(Rflags[Dpos])
				break;
			else
				Dflags[Dpos] = true;

			if(Dflags[Rpos])
				break;
			else
				Rflags[Rpos] = true;
		}

		cout << minutes << "\n";
	}
	return 0;
}
