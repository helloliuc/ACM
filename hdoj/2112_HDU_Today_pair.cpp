//9230167   2013-09-26 10:57:06 Accepted    2112    1406MS  656K    2861 B  G++ nkhelloworld
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

int dis[MAXN];

map<string, int> m;
vector<pair<int, int> > g[MAXN];

typedef pair<int, int> pii;
void dijkstra_priority_pair(int s, int e) {
    bool flag[MAXN];
    memset(flag,false,sizeof(flag));
    memset(dis,-1,sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii> > q;
    dis[s] = 0;
    q.push(make_pair(dis[s], s));
    while(!q.empty()) {
        pii t = q.top();  q.pop();
        int u = t.second;
        if(flag[u])  continue;
        flag[u] = true;
        if(u == e)   return ;
        for(vector<pair<int, int> >::iterator it=g[u].begin(); it != g[u].end(); it++) {
            int v = it->first, d = it->second;
            if(!flag[v] && dis[u] + d < dis[v] || dis[v] == -1) {
                dis[v] = dis[u] + d;
                q.push(make_pair(dis[v], v));
            }
        }
    }
}

int main()
{
    char tmp1[100], tmp2[100];
    int n;
    while(scanf("%d",&n), n!=-1) {
        m.clear();
        scanf("%s%s",tmp1,tmp2);
        string s,e;
        s=tmp1; e=tmp2;
        int cnt_map = 1;
        string a,b;
        int d;
        for(int i=0;i<n;i++) {
            scanf("%s%s%d",tmp1,tmp2,&d);
            a=tmp1; b=tmp2;
            if(m[a] == 0)
            {
                g[cnt_map].clear();
                m[a] = cnt_map++;
            }
            if(m[b] == 0) 
            {
                g[cnt_map].clear();
                m[b] = cnt_map++;
            }
            g[m[a]].push_back(make_pair(m[b], d));
            g[m[b]].push_back(make_pair(m[a], d));
        }

        if(m[s] == 0)
        {
            g[cnt_map].clear();
            m[s] = cnt_map++;
        }
        if(m[e] == 0)
        {
            g[cnt_map].clear();
            m[e] = cnt_map++;
        }
        dijkstra_priority_pair(m[s], m[e]);
        printf("%d\n",dis[m[e]]);
    }

    return 0;
}
