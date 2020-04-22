//CF Gym 102443H - Planet Nine

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define endl "\n"

lli complementTo0[11];
lli complementToN[11];

queue<tuple<bool,lli,lli>> ops;

void goto0(lli n){
	if(n == 0)
		return;

	string num = to_string(n);
	for(lli i=0; i<num.size(); i++){
		if(num[i] == '0')
			continue;
		if(num[i] == '1'){
			lli j = i+1;
			for(; j<num.size(); j++){
				if(num[j] != '1')
					break;
			}
			ops.push(make_tuple(false, lli(j-i), 0LL));
			i = j-1;
			continue;
		}else{
			ops.push(make_tuple(true,lli((complementTo0[num[i]-'0'])/9), lli(num.size()-i-1)));
			if((num[i]-'0') > 0)
				ops.push(make_tuple(false,lli(num[i]-'0'),0LL));
		}
	}
	return;
}

void gotoN(lli n){
	if(n == 0)
		return;
	string num = to_string(n);
	for(lli i=num.size()-1; i>=0; i--){
		if(num[i] == '0')
			continue;
		ops.push(make_tuple(true,lli(complementToN[num[i]-'0']/9),lli(num.size()-i-1)));
		if(9-(num[i]-'0') > 0)
			ops.push(make_tuple(false,lli(9-(num[i]-'0')),0LL));
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	complementTo0[2] = 9;
	complementTo0[3] = 108;
	complementTo0[4] = 1107;
	complementTo0[5] = 11106;
	complementTo0[6] = 111105;
	complementTo0[7] = 1111104;
	complementTo0[8] = 11111103;
	complementTo0[9] = 111111102;

	complementToN[9] = 9;
	complementToN[8] = 18;
	complementToN[7] = 117;
	complementToN[6] = 1116;
	complementToN[5] = 11115;
	complementToN[4] = 111114;
	complementToN[3] = 1111113;
	complementToN[2] = 11111112;
	complementToN[1] = 111111111;


	lli a,b,n; cin >> a >> b;
	if(a == b){
		cout << "Stable" << endl << "0" << endl;
		return 0;
	}

	cout << "Stable" << endl;
	goto0(a);
	gotoN(b);
	cout << ops.size() << endl;
	for(;!ops.empty();ops.pop()){
		cout << (get<0>(ops.front())?"+ ":"- ") << get<1>(ops.front());
		n = get<2>(ops.front());
		while(n--) cout << "0";
		cout << endl;
	}

	return 0;
}
