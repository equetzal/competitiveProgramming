//Help Chef Gerasim - CF ProblemSet 99B

#include <bits/stdc++.h>

using namespace std;

const int MAX=1001;

typedef struct Cup{
	int v;
	int num;
}cup;
cup s[MAX];

bool cmp(cup a,cup b){
	return a.v<b.v;
}

int main(){
	int n,i,j,aver,count,p;
	double sum;
	cin>>n;
	sum=0;
	for(i=1;i<=n;i++){
		cin>>s[i].v;
		s[i].num=i;
		sum+=double(s[i].v);
	}
	aver=int(sum/n);
	
	if(aver==sum/n){
		count=0;
		for(i=1;i<=n;i++){
			if(s[i].v==aver)
				count+=1;
		}
		
		if(count==n)
			cout<<"Exemplary pages."<<endl;
		else{
			sort(s+1,s+n+1,cmp);
			p=0;
			for(i=1;i<=n/2;i++){
				if(((s[i].v+s[n-i+1].v)/2==aver)&&(s[i].v!=aver&&s[n-i+1].v!=aver)){
					p+=1;
				}
			}
			if(p==1){
				for(i=1;i<=n/2;i++){
					if(((s[i].v+s[n-i+1].v)/2==aver)&&(s[i].v!=aver&&s[n-i+1].v!=aver)){
						cout<<(s[n-i+1].v-s[i].v)/2<<" ml. from cup #"<<s[i].num<<" to cup #"<<s[n-i+1].num<<'.'<<endl;
						break;
					}
				}
			}
			else
				cout<<"Unrecoverable configuration."<<endl;
		}
	}
	else
		cout<<"Unrecoverable configuration."<<endl;
}
