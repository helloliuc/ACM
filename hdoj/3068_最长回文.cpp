//9188986   2013-09-18 00:40:43 Accepted    3068    296MS   1384K   1156 B  G++ nkhelloworld
//9188985   2013-09-18 00:40:24 Accepted    3068    296MS   1328K   1156 B  C++ nkhelloworld
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

//Manacher算法，求一个字符串中的最长回文字串
//插入#将奇数长度和偶数长度实现统一处理
//时间复杂度O(n)
//p[i]记录新串中以newstr[i]为中心的回文串的半径，最小为1
const int MAXN = 120000;
char str[MAXN],newstr[2*MAXN];
int p[2*MAXN];

void change() {
    int i,j;
    newstr[0] = '@'; newstr[1] = '#';
    for(i=0, j=2; str[i]; i++) {
        newstr[j++] = str[i]; newstr[j++] = '#';
    }
    newstr[j] = '\0';
    return ;
}

int Manacher() {
    change();
    int maxid=0, id, ans=1;
    for(int i=0; newstr[i]; i++) {
        if(maxid > i) {
            p[i] = min(p[2*id-i], maxid-i);
        }
        else {
            p[i] = 1;
        }
        while(i>=p[i] && newstr[i+p[i]] == newstr[i-p[i]]) {
            p[i]++;
        }
        if(p[i] + i > maxid) {
            maxid = p[i] + i;   id = i;
        }
        if(ans < p[i]) {
            ans = p[i];
        }
    }
    return ans - 1;
}

int main()
{
    while(scanf("%s",str)!=EOF) {
        printf("%d\n",Manacher());
    }

    return 0;
}
