//https://code.google.com/codejam/contest/2924486/dashboard#s=p3
//Round A China New Grad Test 2014
//E
//using map
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

struct EDGE
{
    int u, v, w, nxt;
}edge[MAXEDGE];
int pedge;

void addEdge(int u,int v,int w)
{
    edge[pedge].u = u;   edge[pedge].v = v;   edge[pedge].w = w;
    edge[pedge].nxt= idx[u]; idx[u] = pedge++;
}

int hash(char *s)
{
    int ret = 0;
    for(int i=0; s[i]; i++)
    {
        int val;
        if(s[i] >= 'a' && s[i] <='z')
        {
            val = s[i] - 'a' + 10;
        }
        else
        {
            val = s[i] - '0';
        }
        ret  = ret * 36 + val;
    }
    return ret;
}

int dis[2000];
typedef pair<int, int> pii;
void dijkstra_priority(int s, int e) {
    bool flag[MAXN];
    memset(flag,false,sizeof(flag));
    memset(dis, -1, sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii> > q;
    dis[s] = 0;
    q.push(make_pair(dis[s], s));
    while(!q.empty()) {
        pii t = q.top();    q.pop();
        if(flag[t.second])  continue;
        flag[t.second] = true;
        if(e == t.second)   return ;
        for(int j=idx[t.second]; j!=-1; j=edge[j].nxt) {
            if(!flag[edge[j].v] && dis[edge[j].v] > dis[edge[j].u] + edge[j].w || dis[edge[j].v] == -1) {
                dis[edge[j].v] = dis[edge[j].u] + edge[j].w;
                q.push(make_pair(dis[edge[j].v], edge[j].v));
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
        memset(idx,-1,sizeof(idx));
        pedge = 0;
        pmap = 1;

        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            char str[10];
            scanf("%s",str);
            string ss = str;
            if(mmap[ss] == 0) {
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
            a = color[a];   b = color[b];
            addEdge(a,b,t);
        }
        int s;
        scanf("%d",&s);
        printf("Case #%d:\n",cas);
        while(s--)
        {
            int p,q;
            scanf("%d%d",&p,&q);
            dijkstra_priority(color[p], color[q]);
            printf("%d\n",dis[color[q]]);
        }
    }
    return 0;
}
