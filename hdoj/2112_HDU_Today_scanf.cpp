//9226199   2013-09-25 16:49:09 Accepted    2112    1953MS  644K    2049 B  C++ nkhelloworld
//9228102   2013-09-25 21:23:49 Accepted    2112    1984MS  648K    2996 B  C++ nkhelloworld --priority
//9230062   2013-09-26 10:33:50 Accepted    2112    1625MS  728K    3715 B  G++ nkhelloworld 用cin,cout,开启sync_with_studio(false)优化
//9230079   2013-09-26 10:39:12 Accepted    2112    1406MS  712K    3942 B  G++ nkhelloworld scanf
//9230078   2013-09-26 10:39:00 Accepted    2112    1500MS  616K    3942 B  C++ nkhelloworld scanf
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

typedef pair<int, int> pii;
void dijkstra_priority(int n, int st, int ed) {
    bool flag[MAXN];
    memset(flag, false, sizeof(flag));
    memset(dis, -1, sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii> > q;

    dis[st] = 0;
    q.push(make_pair(dis[st], st));
    while(!q.empty()) {
        pii tmp = q.top();  q.pop();
        if(flag[tmp.second])    continue;
        if(tmp.second == ed)    return ;
        flag[tmp.second] = true;
        for(int j=idx[tmp.second]; j!=-1; j=edge[j].nxt) {
            if(!flag[edge[j].v] && dis[edge[j].u] + edge[j].d < dis[edge[j].v] || dis[edge[j].v] == -1) {
                dis[edge[j].v] = dis[edge[j].u] + edge[j].d;
                q.push(make_pair(dis[edge[j].v], edge[j].v));
            }
        }
    }
}

/*
int map_find(const string &s) {
    if(m.count(s))  return m[s];
    m[s] = cnt_map++;
    return cnt_map-1;
}
*/
map<string, int> m;
int main()
{
    char tmp1[100], tmp2[100];
    int n;
    while(scanf("%d",&n), n!=-1) {
        m.clear();
        scanf("%s%s",tmp1,tmp2);
        string s,e;
        s=tmp1; e=tmp2;
        initEdge();
        int cnt_map = 1;
        string a,b;
        int d;
        for(int i=0;i<n;i++) {
            scanf("%s%s%d",tmp1,tmp2,&d);
            a=tmp1; b=tmp2;
            //if(m.insert(make_pair(a, cnt_map)).second == true)  cnt_map++;
            //if(m.insert(make_pair(b, cnt_map)).second == true)  cnt_map++;
            if(m[a] == 0)   m[a] = cnt_map++;
            if(m[b] == 0)   m[b] = cnt_map++;
            //if(!m.count(a)) m[a] = cnt_map++;
            //if(!m.count(b)) m[b] = cnt_map++;
            addEdge(m[a], m[b], d);
            addEdge(m[b], m[a], d);
            /*
            int t1 = map_find(a);
            int t2 = map_find(b);
            addEdge(t1,t2,d);
            addEdge(t2,t1,d);
            */
        }

        if(m[s] == 0)   m[s] = cnt_map++;
        if(m[e] == 0)   m[e] = cnt_map++;

        //dijkstra(cnt_map-1, m[s], m[e]);
        dijkstra_priority(cnt_map-1, m[s], m[e]);
        printf("%d\n",dis[m[e]]);
        //cout<<dis[m[e]]<<endl;
    }

    return 0;
}
