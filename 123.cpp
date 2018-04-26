#include <fstream>

using namespace std;

ifstream f("matrice.in");
ofstream g("matrice.out");

int a[50][50],n,i,j,k;

void citire()
{
        f>>n;
        for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                        f>>a[i][j];
}
void Roy_Warshall()
{
        for(k=1; k<=n; k++)
                for(i=1; i<=n; i++)
                        for(j=1; j<=n; j++)
                                if(a[i][j]==0 && k!=i && k!=j)
                                        a[i][j]=a[i][k]*a[j][k];
}
void afis()
{
        for(i=1; i<=n; i++)
        {
                for(j=1; j<=n; j++)
                        g<<a[i][j]<<" ";
                g<<'\n';
        }
}
int main()
{
        citire();
        Roy_Warshall();
        afis();
        f.close();
        g.close();
        return 0;
}
