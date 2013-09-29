//AC!
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

class LittleElephantAndBalls {
public:
    int getNumber(string s) {
        map<char, bool> left, right;
        int cnt_left = 0, cnt_right = 0;
        int ans = 0;
        left['R'] = left['G'] = left['B'] = false;
        right['R'] = right['G'] = right['B'] = false;
        for(int i=0; i<s.length(); i++) {
            ans += cnt_left + cnt_right;
            if(left[s[i]] == false) {
                left[s[i]] = true;
                cnt_left ++;
            }
            else if(right[s[i]] == false) {
                right[s[i]] = true;
                cnt_right++;
            }
        }
        return ans;
    }
};

int main()
{
LittleElephantAndBalls e;
string s;
cin>>s;
printf("%d\n",e.getNumber(s));
}
