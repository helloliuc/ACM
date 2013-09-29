//https://code.google.com/codejam/contest/2924486/dashboard#s=p3
//Round A China New Grad Test 2014
//E
//using map
//using pair
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
#include <map>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0f);

const int MAXN = 2000;
const int MAXEDGE = 7000;

int color[81000];
int idx[MAXN];
map<string, int> mmap;
int pmap;

typedef pair<int, int> pii;
vector<pii> g[MAXN];

int dis[2000];

void dijkstra_priority_pair(int s, int e) {
    bool flag[MAXN];
    memset(flag,false,sizeof(flag));
    memset(dis, -1, sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii> > q;
    dis[s] = 0;
    q.push(make_pair(dis[s], s));
    while(!q.empty()) {
        pii t = q.top();    q.pop();
        int u = t.second;
        if(flag[u])  continue;
        flag[u] = true;
        if(e == u)   return ;
        for(vector<pii>::iterator it = g[u].begin(); it!=g[u].end(); it++) {
            int v = it->first, d=it->second;
            if(!flag[v] && dis[v] > dis[u] + d || dis[v] == -1) {
                dis[v] = dis[u] + d;
                q.push(make_pair(dis[v], v));
            }
        }
    }

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas <= T; cas++)
    {
        pmap = 1;

        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            char str[10];
            scanf("%s",str);
            string ss = str;
            if(mmap[ss] == 0) {
                g[pmap].clear();
                mmap[ss] = pmap++;
            }
            color[i] = mmap[ss];
        }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            int a,b,t;
            scanf("%d%d%d",&a,&b,&t);
            g[color[a]].push_back(make_pair(color[b], t));
        }
        int s;
        scanf("%d",&s);
        printf("Case #%d:\n",cas);
        while(s--)
        {
            int p,q;
            scanf("%d%d",&p,&q);
            dijkstra_priority_pair(color[p], color[q]);
            printf("%d\n",dis[color[q]]);
        }
    }
    return 0;
}
