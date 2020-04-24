//2016 Al-Baath University Training Camp Contest-1
//CF Gym 101028D - X and paintings

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define eps 1e-6
typedef long long LL;
const double pi = acos(-1.0);
const long long mod = 1e9 + 7;
using namespace std;

char s[105][105];

int main(){
    int T;
    cin >> T;
    int R,C,n;
    int r1,c1,r2,c2;
    char p;
    while(T--){
        cin >> R >> C >> n;
        for(int i = 0;i < R;i++)
            for(int j = 0;j < C;j++)
                s[i][j] = '.';
        while(n--){
            cin >> r1 >> c1 >> r2 >> c2 >> p;
            r1 -= 1,r2 -= 1,c1 -= 1,c2 -= 1;
            for(int i = r1;i <= r2;i++)
                for(int j = c1;j <= c2;j++)
                    s[i][j] = p;
        }
        for(int i = 0;i < R;i++){
            for(int j = 0;j < C;j++)
                printf("%c",s[i][j]);
            puts("");
        }
    }
    return 0;
}
