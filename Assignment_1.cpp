#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str,str1,ch;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>str;
        int len=str.length();
        if(len>10)
        {
            str1[0]=str[0];
            cout<<str1<<endl;
            ch=to_string(len-2);
            //cout<<ch;
            //cout<<str1;
            str1.append(ch);
            //cout<<str1;
            str1[3]=str[len-1];
            
        }
        else
            cout<<str<<endl;
    }
    return 0;
}
