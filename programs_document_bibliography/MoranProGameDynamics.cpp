//  Moran's process using Game dynamics
#include <iostream> 
#include<string>
#include<fstream>
#include<iomanip>
#include <ctime> 
#include <cstdlib> 
#include<cmath>
using namespace std; 
int main () 
{
  double randomr, randomk, r1=1, s1=1.2, r2=1.1, s2=1.5, r, s;
  int  randomr1, randomk1, n=1000, i=10, deltat=700;
 // Parametros de la matriz
  double R=1, S=0, T=0.3, P=0, x,X,Pc,Pd, Fc, Fd, w=1, pro, pc, pd, re, aux;
  // 0 defect, 1 cooperate: los valores de las componentes de los vectores
  double A[n], A1[n], B[100],B1[100];
  //randomr = (rand()%99)+1;
  //randomk = (rand()%99)+1;
srand((unsigned)time(0));
for(int se=0;se<n;se++)
  {
    if(se<i) A1[se]=1;	
    else A1[se]=0;    
  }
  x=i;
  int t=0;
 while(x>0 && x<n)
{
x=0;
  for(int a=0;a<n;a++)
    { 
     if(A1[a]==1) x=x+1;
    }
   X=x/n;
 cout<<t<<" "<<X<<" "<<1-X<<endl;
 //if(t==30000){break;}
 //if(t!=0 && t%deltat==0){ if(r==r1){r=r2; s=s2;} else{s=s1; s=s1;} }
 
Pc=(R*(x-1)+S*(double(n)-x))/(double(n)-1); Pd=(T*x+P*(double(n)-x-1))/(double(n)-1);
r=1-w+w*Pc; s=1-w+w*Pd; // resultin fitness due to the benefit or cost of the game
 pc=r*x/(r*x+s*(double(n)-x));  
 t++;

 randomk = (rand()%1001);
 randomr1 = (rand()%n);
 randomr=randomk/1000;
 if(randomr < pc)re=1;//A1[randomr1]=1;
 else re=0;//A1[randomr1]=0; 
 A1[randomr1]=re;
 //cout<<randomr<<" "<<pc<<endl;
 }
 //cout<<x<<endl; 
return 0;
}
