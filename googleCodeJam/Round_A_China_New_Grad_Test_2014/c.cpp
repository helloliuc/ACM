//https://code.google.com/codejam/contest/2924486/dashboard#s=p3
//Round A China New Grad Test 2014
//C
//Small AC
//large AC
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
const double PI = acos(-1.0f);

int n;
int ans[11000];

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas<=T; cas++)
    {
        scanf("%d",&n);
        vector<int> a,b;
        vector<int> pos1,pos2;
        int tmp;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            if((tmp+10000) % 2)
            {
                a.push_back(tmp);
                pos1.push_back(i);
            }
            else
            {
                b.push_back(tmp);
                pos2.push_back(i);
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<int>());
        for(int i=0;i<pos1.size();i++)
        {
            ans[pos1[i]] = a[i];
        }
        for(int i=0;i<pos2.size();i++)
        {
            ans[pos2[i]] = b[i];
        }
        printf("Case #%d:", cas);
        for(int i=0;i<n;i++)
        {
            printf(" %d",ans[i]);
        }
        printf("\n");
    }

    return 0;
}
