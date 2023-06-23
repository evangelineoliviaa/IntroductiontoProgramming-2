#include<iostream>
#include <string>
using namespace std;
// TODO: please implement following overloaded functions
// Generally return 1 if the first parameter is greater than the second, 0 if the two ones are equal, -1 otherwise

int cmp(const string &a, const string &b) // just compare the two strings
{
	if(a>b)return 1;
	else if(a==b)return 0;
	else return -1;
}
int cmp(const string &a, const string &b, int n) // compare the first n characters of two strings
{
	string s1 = a.substr(0,n);
	string s2 = b.substr(0,n);
	if(s1>s2)return 1;
	else if(s1==s2)return 0;
	else return -1;
}
int cmp(const string &a, char b)// compare the character and the string, considering the character as 1-lengthed string
{
	string temp;
	temp.append(1,b);
	if(a>temp)return 1;
	else if(a==temp)return 0;
	else return -1;
}
int cmp(char b, const string &a)// similar with the above, only different in the order of the parameters
{
	string temp;
	temp.append(1,b);
	if(temp>a)return 1;
	else if(temp==a)return 0;
	else return -1;
}
int cmp(char a, const string &b, int n)// compare the character and the n-th character of the string
{
	if(a>b[n])return 1;
	if(a==b[n])return 0;
	else return -1;
}
int cmp(const string &a, char b, int n)// similar with the above, only different in the order of the parameters
{
	if(a[n]>b)return 1;
	if(b==a[n])return 0;
	else return -1;
}
int cmp(char a, char b)// just compare the two characters
{
	if(a>b)return 1;
	else if(a==b)return 0;
	else return -1;
}

// The first 4 ones are about comparing string, whereas the last 3 ones are just about characters.

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    string s, t;
    int n;
    while (cin >> s >> t >> n)
        cout << cmp(s, t) << ' '
             << cmp(s, t, n) << ' '
             << cmp(s, *t.rbegin()) << ' '
             << cmp(*s.begin(), t) << ' '
             << cmp(s, *t.rbegin(), n) << ' '
             << cmp(*s.begin(), t, n) << ' '
             << cmp(*s.rbegin(), *t.begin()) << '\n';
    return 0;
}
