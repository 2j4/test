#include<iostream>
#include<stack>
using namespace std;
stack<int>sta;
int a, ans = 1;
int main()
{
    cin >> a;
    while(a)
    {
        sta.emplace(a%2);
        a /= 2;
    }
    sta.pop();
    while(!sta.empty())
    {
        ans = ( ans + sta.top() )*2 -1;
        sta.pop();
    }
    cout << ans << '\n';
}
