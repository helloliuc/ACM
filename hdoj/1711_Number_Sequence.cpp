//9184515   2013-09-17 12:57:23 Accepted    1711    515MS   4632K   1244 B  C++ nkhelloworld
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int MAXN = 1100000;
const int MAXM = 110000;

int a[MAXN], b[MAXM];

//kmp
#define _match(a,b) ((a)==(b))
#define MAXP 110000
typedef int elem_t;

int kmp(int ls,elem_t *s, int lp,elem_t* p) {
    int i,j,k,fail[MAXP] = {-1};
    for(j=1; j<lp; j++) {
        k=fail[j-1];
        while(k>=0 && !_match(p[k+1], p[j]))    k = fail[k];
        fail[j] = (_match(p[k+1], p[j]))?k+1:-1;
    }
    for(i=0, j=0; i<ls && j<lp; i++) {
        if(_match(s[i], p[j]))  j++;
        else if(j) {
            j = fail[j-1] + 1;
            i--;
        }
    }
    return j==lp?(i-lp):-1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&b[j]);
        }
        int ans = kmp(n,a,m,b);
        printf("%d\n", ans==-1?ans:ans+1);
    }

    return 0;
}
