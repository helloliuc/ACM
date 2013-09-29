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

const int MAXN = 1100;
const int MAXEDGE = 2100000;

int idx[MAXN];
double dis[MAXN];

struct EDGE {
    int u,v,nxt;
    double d;
}edge[MAXEDGE];
int pedge = 0;

void initEdge() {
    memset(idx,-1,sizeof(idx));
    pedge = 0;
}

void addEdge(int u, int v, double d) {
    edge[pedge].u = u;  edge[pedge].v = v;  edge[pedge].d = d;
    edge[pedge].nxt = idx[u];   idx[u] = pedge++;
}

struct NODE {
    int pt;
    double d;
    friend bool operator < (NODE n1, NODE n2) {
        return n1.d < n2.d;
    }
};

int n;

void dijkstra_priority(int s, int e) {
    memset(dis,0,sizeof(dis));
    priority_queue<NODE> pq;
    NODE now, tmp;
    dis[s] = 1; now.d = 1; now.pt = s;
    pq.push(now);
    while(!pq.empty()) {
        now = pq.top(); pq.pop();
        if(now.pt == e) {
            return ;
        }
        if(now.d >= dis[now.pt]) {
            for(int j=idx[now.pt]; j!=-1; j=edge[j].nxt) {
                int u=edge[j].u, v=edge[j].v;
                double d=edge[j].d;
                if(dis[v] < dis[u] * d) {
                    dis[v] = dis[u] * d;
                    tmp.pt = v; tmp.d = d; pq.push(tmp);
                }
            }
        }
    }
}

void dijkstra(int s,int e) {
    bool flag[MAXN];
    memset(flag,false,sizeof(flag));
    for(int i=1;i<=n;i++)   dis[i] = -1;
    dis[s] = 1;
    for(int i=1;i<=n;i++) {
        double minval = -1.0;
        int minpt;
        for(int j=1;j<=n;j++) {
            if(flag[j] == false && dis[j] > minval && dis[j] != -1) {
                minval = dis[j];
                minpt = j;
            }
        }
        if(minval == -1.0)   return ;
        if(minpt == e)  return ;
        flag[minpt] = true;
        for(int j=idx[minpt]; j!=-1; j=edge[j].nxt) {
            int u = edge[j].u, v=edge[j].v;
            double d = edge[j].d;
            if(flag[v] == false && dis[v] < dis[u] * d || dis[v] == -1) {
                dis[v] = dis[u] * d;
            }
        }
    }
}

int main()
{
    while(~scanf("%d",&n)) {
        initEdge();
        for(int i=1; i<=n; i++) {
            for(int j=1;j<=n;j++) {
                double d;
                scanf("%lf",&d);
                addEdge(i, j, d);
            }
        }
        int q;
        scanf("%d",&q);
        while(q--) {
            int a,b;
            scanf("%d%d",&a,&b);
            //dijkstra_priority(a,b);
            dijkstra(a,b);
            if(dis[b] <= 0.0) {
                printf("What a pity!\n");
            }
            else {
                printf("%.3f\n",dis[b]);
            }
        }
    }


    return 0;
}
