#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("afn.in");
int a[100][100][100],viz[100],k=0;
char sir[256];
int ini;
int fin[100];
int poz=-1,maxi=0,litera=-1;
bool ok=false;
void citire()
{
    int n;
    f>>n;
    int x,y;
    char z;
    for(int i=1; i<=n; i++)
    {
        f>>x>>y>>z;
        if(x>maxi)
            maxi=x;
        if(y>maxi)
            maxi=y;
        a[x][z-'a'+1][y]=1;
    }
    /*for(int i=1; i<=maxi; i++)
    {
        for(int j=1; j<=maxi; j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }*/
    f>>ini;
    while(f>>x)
        fin[x]=1;
}
void DFS(int x,int litera)
{
    while(sir[litera]=='L')
        litera++;
    for(int i=1;i<=maxi;i++)
    if (a[x][sir[litera]-'a'+1][i] && litera<strlen(sir))
        {
            //cout<<sir[litera]<<' '<<x<<' '<<a[x][sir[litera]-'a'+1]<<endl;
            poz=i;
            //viz[i]=++k;
            //cout<<poz<<endl;
            DFS(i,litera+1);
        }
    else
            if (fin[poz]!=0 && litera==strlen(sir))
                {
                    //cout<<poz<<' '<<litera<<endl;
                    ok=true;
                }
}
int main()
{
    citire();
    cin>>sir;
    if(sir[0]=='L' && strlen(sir)==1)
        poz=ini;
    else DFS(ini,0);
    if(ok)
        cout<<"DA";
    else cout<<"NU";
}
