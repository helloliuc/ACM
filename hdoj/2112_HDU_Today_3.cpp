//9226247   2013-09-25 16:57:16 Accepted    2112    1468MS  604K    2270 B  C++ nkhelloworld
//9226250   2013-09-25 16:57:48 Accepted    2112    1406MS  688K    2270 B  G++ nkhelloworld
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

const int MAXN = 210;
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
    char tmp1[40], tmp2[40];
    int n;
    string s,e;
    s.resize(40);   e.resize(40);
        string a,b;
        a.resize(40);  b.resize(40);
    while(scanf("%d",&n), n!=-1) {
        //s.reserve(40); e.reserve(40);
        scanf("%s%s",&s[0], &e[0]);
        initEdge();
        map<string, int> m;
        int cnt_map = 1;
        int d;
        for(int i=0;i<n;i++) {
            scanf("%s%s%d",&a[0] ,&b[0] ,&d);
            if(m[a] == 0)   m[a] = cnt_map++;
            if(m[b] == 0)   m[b] = cnt_map++;
            addEdge(m[a], m[b], d);
            addEdge(m[b], m[a], d);
        }

        if(m[s] == 0)   m[s] = cnt_map++;
        if(m[e] == 0)   m[e] = cnt_map++;

        dijkstra(cnt_map-1, m[s], m[e]);
        printf("%d\n",dis[m[e]]);
    }

    return 0;
}
