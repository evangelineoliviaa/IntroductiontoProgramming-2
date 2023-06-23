#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class special_power{
public:
    int n;
    special_power(int n);
    int fpow(int x);
    int fpow(int x, int m);
    int fpow();
    string fpow(string s);
    string fpow(string s, int m);
};

special_power :: special_power (int n)
{
    this->n = n;
}

int special_power :: fpow(int x)
{
    int long long sum = 1;
    for(int i = 0; i<n; i++)
    {
        sum*= x;
        sum%= 880301;
    }
    return sum%880301;
}

int special_power :: fpow(int x, int m)
{
    int long long sum = 1;
    for(int i = 0; i<n; i++)
    {
        sum*= x;
        sum%= m;
    }
    return sum%m;
}
int special_power :: fpow()
{
    int long long sum = 1;
    for(int i = 0; i<n; i++)
    {
        sum*= 2;
        sum%= 880301;
    }
    return sum%880301;
}
string special_power:: fpow(string s)
{
    int length = s.length();
    string sample;
    for(int i = 0; i<length; i++)
    {
        for(int j = 0; j<n;j++){
            sample += s[i];
        }
    }
    return sample;
}
string special_power :: fpow(string s, int m)
{
    int length = s.length();
    string sample2;
    for(int i = 0; i<length; i++)
    {
        for(int j = 0; j<n;j++){
            if(sample2.length()==m)return sample2;
            else sample2 += s[i];
        }
    }
    return sample2;
}
int main(){
    int x, n, m;
    string s;
    cin >> x >> n >> m >> s;
    special_power sp(n);
    cout << sp.fpow(x) << "\n";
    cout << sp.fpow(x, m) << "\n";
    cout << sp.fpow() << "\n";
    cout << sp.fpow(s) << "\n";
    cout << sp.fpow(s, m) << "\n";
}
