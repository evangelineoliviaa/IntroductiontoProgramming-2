#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = s.size();
    int ans = 0;
    for(int i = 0; i<len; i++)
    {
        if(i-1 >= 0 && s[i]==s[i-1]){
            s[i]='X';
            ans++;
        }else if(i-2>=0 && s[i]==s[i-2]){
            s[i]='X';
            ans++;
        }
    }
    cout << ans << endl;
}