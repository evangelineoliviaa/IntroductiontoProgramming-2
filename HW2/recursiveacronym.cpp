#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
    string s;
    string ss;
    string word;
    string acronym;
    while(getline(cin,s))
    {
        stringstream ss(s);
        ss>>word;
        int len = word.length();
        int ans = 0;
        int ctk = 1;
        int result = 0;
        while(ss>>acronym)
        {
            if(tolower(word[ctk])!=tolower(acronym[0]))
            {
                result = 1;
                break;
            }
            ctk++;
        }
        if(ctk!=len)result = 1;
        if(result == 1)cout<<"QQ"<<endl;
        else if (result == 0)cout<<"o'_'o"<<endl;
    }
}
