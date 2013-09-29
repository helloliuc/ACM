//9225519   2013-09-25 14:52:58 Accepted    2544    0MS 396K    1713 B  G++ nkhelloworld
//9225518   2013-09-25 14:52:52 Accepted    2544    15MS    352K    1713 B  C++ nkhelloworld
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

const int MAXN = 110;
const int MAXEDGE = 21000;

int idx[MAXN];
int dis[MAXN];

struct EDGE {
    int u,v,d,nxt;
}edge[MAXEDGE];//注意无向图里边数可能需要加倍
int pedge = 0;

void initEdge() {
    memset(idx,-1,sizeof(idx));
    pedge = 0;
}

void addEdge(int u, int v, int d) {
    edge[pedge].u = u;  edge[pedge].v = v;  edge[pedge].d = d;
    edge[pedge].nxt = idx[u];   idx[u] = pedge++;
}

void dijkstra(int n,int s,int e)
{
    memset(dis,-1,sizeof(dis));
    bool flag[MAXN];
    memset(flag,false,sizeof(flag));
    dis[s] = 0;
    for(int i=1;i<=n;i++) {
        int mindis = INF, minpos = s;
        for(int j=1;j<=n;j++) {
            if(!flag[j] && dis[j] < mindis && dis[j] != -1) {
                minpos = j; mindis = dis[j];
            }
        }
        flag[minpos] = true;
        if(minpos == e)  return ;
        for(int j=idx[minpos]; j!=-1; j=edge[j].nxt) {
            int u=edge[j].u, v=edge[j].v, d=edge[j].d;
            if(!flag[v] && (dis[v] - d > dis[u] || dis[v] == -1)) {
                dis[v] = d + dis[u];
            }
        }
    }
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m), n||m) {
        initEdge();
        while(m--) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        dijkstra(n,1,n);
        printf("%d\n",dis[n]);
    }

    return 0;
}
