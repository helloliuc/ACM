//9227957   2013-09-25 21:09:42 Accepted    1596    984MS   16068K  2189 B  C++ nkhelloworld
//9227956   2013-09-25 21:09:28 Accepted    1596    1593MS  16160K  2189 B  G++ nkhelloworld
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

typedef pair<double, int> pii;
void dijkstra_priority(int n, int st, int ed) {
    bool flag[MAXN];
    memset(flag,false,sizeof(flag));
    memset(dis,0,sizeof(dis));
    priority_queue<pii> q;

    dis[st] = 1.0;
    q.push(make_pair(dis[st], st));
    while(!q.empty()) {
        pii tmp = q.top();  q.pop();
        if(flag[tmp.second])    continue;
        if(tmp.second == ed)    return ;
        flag[tmp.second] = true;
        for(int j=idx[tmp.second]; j!=-1; j=edge[j].nxt) {
            if(!flag[edge[j].v] && dis[edge[j].u] * edge[j].d > dis[edge[j].v]) {
                dis[edge[j].v] = dis[edge[j].u] * edge[j].d;
                q.push(make_pair(dis[edge[j].v], edge[j].v));
            }
        }
    }
}

int main()
{
    int n;
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
            dijkstra_priority(n,a,b);
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
