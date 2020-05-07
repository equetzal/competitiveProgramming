#include <bits/stdc++.h>

using namespace std;


int main()
{
	vector< vector<bool> > movies(2, vector<bool> (1000000, false));
	//memset(movies, sizeof(movies), 0);
	int k,day;
	cin >> k;
	while(k--){
		cin >> day;
		movies[0][day] = true;
	}
	cin >> k;
	while(k--){
		cin >> day;
		movies[1][day] = true;
	}

	int heMov=0, sheMov=0;
	int who1=false, who2=true; //false el, true ella
	int ans = 0;
	for(int i=0; i<1000000; i++){

		if(movies[0][i] && movies[1][i]){
			// cout << "-------- both" << endl;
			ans += max(heMov, sheMov);
			heMov = 0;
			sheMov = 0;
			who1 = false;
			who2 = true;
		}
		if(who1){
			if(movies[0][i]){
				heMov++;
				who1 = !who1;
			}
		}else{
			if(movies[1][i]){
				heMov++;
				who1 = !who1;
			}
		}

		if(who2){
			if(movies[0][i]){
				sheMov++;
				who2 = !who2;
			}
		}else{
			if(movies[1][i]){
				sheMov++;
				who2 = !who2;
			}
		}

		// if(movies[0][i] || movies[1][i]){
		// 	cout << heMov << " " << sheMov << endl;
		// }
	}
	ans += max(heMov, sheMov);

	cout << ans << endl;



	return 0;
}
