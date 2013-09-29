//https://code.google.com/codejam/contest/2924486/dashboard#s=p3
//Round A China New Grad Test 2014
//D
//Small AC
//large AC
#include <cstdio>
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

int n;
char map[110][110];
bool flag[110][110][5];

struct ST
{
    int row,col,dir,step,from;
}st[110*110*5];
int tail,head;
int sx,sy,ex,ey;
int ans_step;

int mv[][2] = {
    0,1,
    1,0,
    0,-1,
    -1,0
};

int left[][2] = {
    -1,0,
    0,1,
    1,0,
    0,-1
};

int leftback[][2] = {
    -1,-1,
    -1,1,
    1,1,
    1,-1
};

int forward[][2] = {
    0,1,
    1,0,
    0,-1,
    -1,0
};

int right[][2] = {
    1,0,
    0,-1,
    -1,0,
    0,1
};

vector<char> ans_path;
char dir_name[10] = "ESWN";

void get_path(int pos)
{
    ans_path.clear();
    while(pos != 0)
    {
        ans_path.push_back(dir_name[st[pos].dir]);
        pos = st[pos].from;
    }
    return ;
}

void bfs(int dir)
{
    memset(flag,false,sizeof(flag));

    st[0].row = sx;
    st[0].col = sy;
    st[0].step = 0;
    st[0].dir = dir;
    st[0].from = -1;

    head=0;tail=1;

    while(head < tail)
    {
        if(st[head].row == ex && st[head].col == ey)
        {
            if(ans_step > st[head].step)
            {
                ans_step = st[head].step;
                get_path(head);
            }
            break;
        }

        for(int i=0;i<4;i++)
        {
            st[tail].row = st[head].row + mv[i][0];
            st[tail].col = st[head].col + mv[i][1];
            st[tail].step = st[head].step + 1;
            st[tail].dir = i;
            st[tail].from = head;

            if(map[st[tail].row][st[tail].col] != '.')  continue;
            if(flag[st[tail].row][st[tail].col][i] == true) continue; 

            //forward
            if(i == st[head].dir)
            {
                int tmp_x = st[head].row + left[st[head].dir][0];
                int tmp_y = st[head].col + left[st[head].dir][1];
                if(map[tmp_x][tmp_y] == '#')
                {
                    flag[st[tail].row][st[tail].col][i] = true;
                    tail++;
                }
            }
            //turn left
            else if( (st[head].dir + 4 - 1) % 4 == i)
            {
                if(st[head].step == 0)  continue;
                int tmp_x = st[head].row + leftback[st[head].dir][0];
                int tmp_y = st[head].col + leftback[st[head].dir][1];
                if(map[tmp_x][tmp_y] == '#') {
                    flag[st[tail].row][st[tail].col][i] = true;
                    tail++;
                }

            }
            //turn right
            else if( (st[head].dir + 1) % 4 == i)
            {
                int tmp_x1 = st[head].row + left[st[head].dir][0];
                int tmp_y1 = st[head].col + left[st[head].dir][1];
                int tmp_x2 = st[head].row + forward[st[head].dir][0];
                int tmp_y2 = st[head].col + forward[st[head].dir][1];
                if(map[tmp_x1][tmp_y1] == '#' && map[tmp_x2][tmp_y2] == '#')
                {
                    flag[st[tail].row][st[tail].col][i] = true;
                    tail++;
                }
            }
            //turn back
            else if( (st[head].dir + 2) % 4 == i)
            {
                int tmp_x1 = st[head].row + left[st[head].dir][0];
                int tmp_y1 = st[head].col + left[st[head].dir][1];
                int tmp_x2 = st[head].row + forward[st[head].dir][0];
                int tmp_y2 = st[head].col + forward[st[head].dir][1];
                int tmp_x3 = st[head].row + right[st[head].dir][0];
                int tmp_y3 = st[head].col + right[st[head].dir][1];

                if(map[tmp_x1][tmp_y1] == '#' && map[tmp_x2][tmp_y2] == '#' && map[tmp_x3][tmp_y3] == '#')
                {
                    flag[st[tail].row][st[tail].col][i] = true;
                    tail++;
                }
            }
        }

        head++;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    char str[300];
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        memset(map,'#',sizeof(map));
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            for(int j=0;j<n;j++)
            {
                map[i][j+1] = str[j];
            }
        }

        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        ans_step = 10001;
        ans_path.clear();
        for(int i=0;i<4;i++)
        {
           bfs(i);
        }
        printf("Case #%d: ", cas);
        if(ans_step > 10000)
        {
            printf("Edison ran out of energy.\n");
        }
        else
        {
            printf("%d\n",ans_step);
            for(int i=ans_path.size()-1; i>=0;i--)
            {
                printf("%c",ans_path[i]);
            }
            printf("\n");
        }

    }

    return 0;
}
