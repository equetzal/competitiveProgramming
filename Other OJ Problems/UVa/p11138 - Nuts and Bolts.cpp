//UVa p11138 - Nuts and Bolts

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_BOLTS 500
#define MAX_NUTS 500

int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];

void read_input_data(void){
	int n,b;
	scanf("%d%d",&bolts,&nuts);

	for(b=0;b<bolts;b++){
		for(n=0;n<nuts;n++){
			scanf("%d",&fits[b][n]);
		}
	}
}

int nut_used[MAX_NUTS];
int bestmatched;

void init_match(void){
	int n;
	bestmatched=0;
		for(n=0;n<nuts;n++)
			nut_used[n]=0;
}

void match_bolt(int boltno, int matched){
	int n;
	if(boltno==bolts){
		if(matched>bestmatched) 
			bestmatched=matched;
		return;
	}

	match_bolt(boltno+1,matched);
	for(n=0;n<nuts;n++)
		if(!nut_used[n] && fits[boltno][n]){
			nut_used[n]=1;
			match_bolt(boltno+1,matched+1);
			nut_used[n]=0;
		}
}


bool tryKhun(int i, vector < vector<int> > &A, vector <bool> &used, vector <int> &M){
	cout << "SubCheck " << i << endl;
	cout << "Valores -> ";
	for(auto a:M)
		cout << a << " ";
	cout << endl;
	cout << "Visidados -> ";
	for(auto a:used)
		cout << a << " ";
	cout << endl;
	if(used[i])
		return false;
	for(int b:A[i]){
		if(M[b] == -1){
			M[b] = i;
			used[b] = true;		
			return true;
		}
	}
	for(int b:A[i]){
		cout << "\t It:" << b << endl;
		if(tryKhun(M[b], A, used, M)){
			M[b] = i;
			used[b] = true;		
			return true;
		}
	}
	return false;
}

void imprime(vector < vector<int> > &A){
	for(int i=0; i<A.size(); i++){
		cout << i << " -> ";
		for(auto a:A[i]){
			cout << a << " ";
		}
		cout << endl;
	}
	return;
}

int maxMatching(vector < vector<int> > &A, int mSize){
	vector <int> M(mSize,-1);
	for(int i=0; i<A.size(); i++){
		cout << "Checando " << i << endl;
		vector <bool> used(mSize, false);
		tryKhun(i,A, used, M);
	}

	int tot=0;
	for(int c:M){
		if(c != -1)
			tot++;
	}

	return tot;
}

int main(){
	int casos, tuercas, tornillos;
	cin >> casos;

	while(casos--){
		cin >> tuercas >> tornillos;
		vector < vector<int> > A(tuercas);
		int entrada;

		for(int i=0; i<tuercas; i++){
			for(int j=0; j<tornillos; j++){
				cin >> entrada;
				if(entrada == 1){
					A[i].push_back(j);
				}
			}
		}

		for(int i=0; i<A.size(); i++){
			cout << i << "-> ";
			for(auto a:A[i]){
				cout << a << " ";
			}
			cout << endl;
		}

		cout << maxMatching(A,tornillos) << endl;
	}

}
