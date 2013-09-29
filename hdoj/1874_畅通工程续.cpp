//9227934   2013-09-25 21:07:30 Accepted    1874    15MS    296K    1859 B  C++ nkhelloworld
//9227936   2013-09-25 21:07:53 Accepted    1874    15MS    356K    1859 B  G++ nkhelloworld
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

const int MAXN = 210;
const int MAXEDGE = 2100;

int idx[MAXN];
int dis[MAXN];

struct EDGE {
    int u,v,d,nxt;
} edge[MAXEDGE];//注意无向图里边数可能需要加倍
int pedge = 0;

void initEdge() {
    memset(idx,-1,sizeof(idx));
    pedge = 0;
}

void addEdge(int u, int v, int d) {
    edge[pedge].u = u;  edge[pedge].v = v;  edge[pedge].d = d;
    edge[pedge].nxt = idx[u];   idx[u] = pedge++;
}

typedef pair<int, int> pii;

void dijkstra_priority(int n, int st, int ed) {
    memset(dis, -1, sizeof(dis));
    bool flag[MAXN];
    memset(flag,false,sizeof(flag));
    priority_queue<pii, vector<pii>, greater<pii> > q;
    dis[st] = 0;
    q.push(make_pair(dis[st], st));
    while(!q.empty()) {
        pii tmp = q.top();  q.pop();
        if(flag[tmp.second])    continue;
        flag[tmp.second] = true;
        if(tmp.second == ed) {
            return ;
        }
        for(int j=idx[tmp.second]; j!=-1; j=edge[j].nxt) {
            int u = edge[j].u, v=edge[j].v, d=edge[j].d;
            if(!flag[v] && dis[v] - d > dis[u] || dis[v] == -1) {
                dis[v] = d + dis[u];
                q.push(make_pair(dis[v], v));
            }
        }
    }
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        initEdge();
        while(m--) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        int a,b;
        scanf("%d%d",&a,&b);
        dijkstra_priority(n,a,b);
        printf("%d\n",dis[b]);
    }

    return 0;
}
