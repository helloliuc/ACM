//5177727   23:31:02
//17 Sep 2013   rookie052   1297. Palindrome    G++ 4.7.2   Accepted    
//0.031 341 KB
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
const int MAXN = 1100;
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
    int maxid=0, id, ans=1, ans_mid;
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
            ans_mid = i;
        }
    }
    char ret[1100];
    int p=0;
    for(int i=ans_mid, j=1; j <= ans; j++,i++) {
        if(newstr[i] != '#') {
            ret[p++] = newstr[i];
        }
    }
    for(int i=p-1; i>=0; i--) {
        printf("%c", ret[i]);
    }
    for(int i=(newstr[ans_mid] == '#'?0:1); i<p; i++) {
        printf("%c", ret[i]);
    }
    printf("\n");
}

int main()
{
    scanf("%s",str);
    Manacher();
    return 0;
}
