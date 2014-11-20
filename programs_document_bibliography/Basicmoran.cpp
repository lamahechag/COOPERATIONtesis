// Proceso de Moran
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
 
  double randomr, randomk;
  int  randomr1, randomk1, n=30, i=6;
 // Parametros de la matriz
 double R=1, S=0.1, T=0.5, P=0, x,X,Pc,Pd, Fc, Fd, w=1, pro, pc, pd, re;
 
 // 0 defect, 1 cooperate: los valores de las componentes de los vectores
  double A[n], A1[n], B[100],B1[100];
  //randomr = (rand()%99)+1;
  //randomk = (rand()%99)+1;

 srand((unsigned)time(0));
  for(int se=0;se<i;se++)
  {
       A1[se]=1;	
  }
  int t=0;
  x=i;
 while(x>0 && x<n)
{
  t++;
  x=0;
  for(int a=0;a<n;a++)
    { 
     if(A1[a]==1) x=x+1;
    }
   X=x/n;
 cout<<t<<" "<<X<<" "<<1-X<<endl;
 Pc=((x-1)*R+(n-x)*S)/(n-1); Pd=(x*T + (n-1-x)*P)/(n-1);//mean payoff 
   pc=x*Pc/(Pc*x+Pd*(n-x));  

   //pro=Pc/(Pc+Pd);
   //pro=(Pc-Pd)/(2*10)+0.5;
   //pro=1 - exp((Pd-Pc));
   //pro= 1/(1+exp(-(Pc-Pd)));
   
  
 randomk1 = (rand()%n);
 randomr1 = (rand()%n);
 re=A1[randomk1];
A1[randomr1]=re; 
// cout<<randomr1<<endl;

  
}
return 0;
}
