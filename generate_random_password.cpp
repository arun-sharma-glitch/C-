#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>
using namespace std;

string generate(int n){
    string f = "thquickbrwnfxjumpvelazydogTHQUICKBRWNFXJUMPVELAZYDOG1234509876";
    srand(time(0));
    string ans = "";
    for (int i = 0; i <= n; i++)
    {
        int idx = rand()%63;
        ans += f[idx];
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter size(length) of password : ";
    cin>>n;
    string password = generate(n);
    cout<<"Your Password is : "<<password<<endl;
    return 0;
}