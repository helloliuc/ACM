//https://code.google.com/codejam/contest/2924486/dashboard#s=p3
//Round A China New Grad Test 2014
//B
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

struct NODE
{
    unsigned long long p,q;
};

NODE getfa(unsigned long long pos)
{
    NODE ret;
    if(pos == 1)
    {
        ret.p = 1;
        ret.q = 1;
        return ret;
    }
    NODE fa = getfa(pos>>1);
    if(pos & 1)//right
    {
        ret.p = fa.p + fa.q;
        ret.q = fa.q;
    }
    else
    {
        ret.p = fa.p;
        ret.q = fa.p + fa.q;
    }
    return ret;
}

unsigned long long getpos(unsigned long long p,unsigned long long q)
{
    if(p == 1 && q == 1)
    {
        return 1;
    }
    if(p<q)
    {
        return getpos(p,q-p)<<1;
    }
    else
    {
        return (getpos(p-q,q)<<1) + 1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas<=T;cas ++)
    {
        int id;
        scanf("%d",&id);
        unsigned long long n;
        if(id == 1)
        {
            cin>>n;
            printf("Case #%d: ",cas);
            NODE ans = getfa(n);
            cout<<ans.p<<" "<<ans.q<<endl;
        }
        else
        {
            unsigned long long p,q;
            cin>>p>>q;
            printf("Case #%d: ",cas);
            cout<<getpos(p,q)<<endl;
        }
    }

    return 0;
}
