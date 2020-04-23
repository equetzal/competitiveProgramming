//2016 Al-Baath University Training Camp Contest-1
//CF Gym 101028F - Good Words

#include <bits/stdc++.h>

using namespace std;

bool isSubstring(string &s, string &p) {
	for (int i = 0; i < s.size(); i++) {
		int j;
		for (j = 0; j < p.size(); j++) {
			if (s[i + j] != p[j])
				break;
		}
		if (j == p.size())
			return true;
	}
	return false;
}

int main() {
	int TC;
	string s, p;

	cin >> TC;
	while (TC--) {
		cin >> s >> p;

		string p1, p2, p3, p4;
		p1 = p2 = p3 = p4 = p;
		p1.erase(0, 1);
		p2.erase(1, 1);
		p3.erase(2,1);
		p4.erase(3,1);

		if (isSubstring(s, p)) {
			cout << "good\n";
		}
		else if(isSubstring(s, p1)) {
			cout << "almost good\n";
		}
		else if(isSubstring(s, p2)) {
			cout << "almost good\n";
		}
		else if(isSubstring(s, p3)) {
			cout << "almost good\n";
		}
		else if(isSubstring(s, p4)) {
			cout << "almost good\n";
		}
		else {
			cout << "none\n";
		}
	}
	return 0;
}
