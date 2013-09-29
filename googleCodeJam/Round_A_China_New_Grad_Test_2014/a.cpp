//https://code.google.com/codejam/contest/2924486/dashboard#s=p3
//Round A China New Grad Test 2014
//A
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

char name[][20] = 
{
    "",
    "",
    "double",
    "triple",
    "quadruple",
    "quintuple",
    "sextuple",
    "septuple",
    "octuple",
    "nonuple",
    "decuple",
    ""
};

char digit[][30] = 
{
    "zero","one","two","three","four","five","six","seven","eight","nine"
};

char str[1100],format[1100];

void work()
{
    int len = 0;
    int j = 0;
    int lenformat = strlen(format);
    for(int i=0;i<=lenformat; i++)
    {
        if(format[i] >= '0' && format[i] <= '9')
        {
            len = len * 10 + format[i] - '0';
        }
        else
        {
            char last = '#';
            int cnt = 0;
            for(int c = 1; c<=len; c++)
            {
                //printf("c:%d\n",c);
                //printf("last:%c str[j]:%c j:%d\n",last,str[j],j);
                if(str[j] != last && last != '#')
                {
                    if(cnt >= 2 && cnt <= 10)
                    {
                        printf(" %s %s",name[cnt], digit[last - '0']);
                    }
                    else
                    {
                        for(int k = 1;k<=cnt;k++)
                        {
                            printf(" %s", digit[last - '0']);
                        }
                    }
                    cnt = 1;
                    last = str[j];
                    j++;
                }
                else
                {
                    cnt++;
                    last = str[j];
                    j++;
                }
                //printf("cnt:%d\n",cnt);
            }

            if(cnt >= 2 && cnt <= 10)
            {
                printf(" %s %s",name[cnt], digit[last - '0']);
            }
            else
            {
                for(int k = 1;k<=cnt;k++)
                {
                    printf(" %s", digit[last - '0']);
                }
            }
            //j++;

            len = 0;
        }

    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas <= T; cas++)
    {
        memset(str,0,sizeof(str));
        memset(format,0,sizeof(format));
        scanf("%s%s",str, format);
        printf("Case #%d:",cas);
        work();
        printf("\n");
    }

    return 0;
}
