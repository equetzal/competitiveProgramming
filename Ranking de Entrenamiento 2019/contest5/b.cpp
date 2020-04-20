//Original by https://codeforces.com/profile/alaneos777 - Almost free falling
//https://codeforces.com/group/PzLcHnJr9l/contest/242659/problem/B

#include <bits/stdc++.h>
 
using namespace std;
 
double m,b1,b2,t1,hf,g=9.81, querys;
 
double f(double t, double x, double v, double b){
	double toExp = (-1)*b*t/m;
	double ans = x+m*g*t/b+(m*(v-(m*g/b))/b)*(1.0-exp(toExp));
	return ans;
}
 
double f_p1(double t, double v, double b){ //Primera derivada de x
	double toExp = (-1)*b*t/m;
	double ans = (v*exp(toExp))+((m*g/b)*(1.0-exp(toExp)));
	return ans;
}
 
double newton_raphson(int it, double sol_prev){
	if(it == 10000) //100 iteracion de aproximacion
		return sol_prev;
 
	double new_sol = sol_prev - ((f( sol_prev, f(t1,0,0,b1), f_p1(t1,0,b1),b2)-hf)/f_p1(sol_prev,0,b2));
	return newton_raphson(it+1, new_sol);
}
 
double binary(){
	double hi = numeric_limits<double>::max();
	double lo = numeric_limits<double>::max()*(-1);
	double mid = (lo+hi)/2.0;
	
	double x = f(t1,0,0,b1);
	double v = f_p1(t1,0,b1);
	
	int it=10000;
	while(it--){
		double val = f(mid,x,v,b2)-hf;
		if(val < 0){
			lo = mid;
		}else if(val > 0){
			hi = mid;
		}
		mid = (lo+hi)/2;
	}
	
	return lo;
}
 
int main(){
    cin >> m >> b1 >> b2 >> t1 >> hf >> querys;
    
    cout << fixed;
    while(querys--){
        double time; cin >> time;
        if(time <= t1)
            cout << setprecision(10) << f(time, 0, 0,b1) << endl;
        else
            cout << setprecision(10) << f(time-t1, f(t1,0,0,b1), f_p1(t1,0,b1), b2) << endl;
    }
    
	cout << setprecision(10) << t1+binary() << endl;
    
    return 0;
}
