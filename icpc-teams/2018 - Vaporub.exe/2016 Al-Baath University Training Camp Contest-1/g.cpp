//2016 Al-Baath University Training Camp Contest-1
//CF Gym 101028G - The Tower of Evil
//UPSOLVING

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int h, w, d; cin >> h >> w >> d;
		bool dir = true;
		int veces = h/w;
		h -= w*(veces-1);

		if(h>w){
			h -= w;
			if(veces % 2 == 0)
				dir = true;
			else
				dir = false;
		}else{
			if((veces-1) % 2 == 0)
				dir = true;
			else
				dir = false;
		}

		int p;
		if(dir)
			p = 1;
		else
			p = w-1;
		
		while(h--){
			if(dir)
				if(p == w)
					dir = !dir;
				else
					p++;
			else
				if(p == 0)
					dir = !dir;
				else
					p--;
		}

		if(p == d)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
