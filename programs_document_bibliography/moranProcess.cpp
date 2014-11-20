//Programa basico de evolucion de cooperacion para Proceso de Moran
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
  int  randomr1, randomk1, n=1000, i=10;
 // Parametros de la matriz
 double R=0.7, S=0.1, T=1, P=0, x,X,Pc,Pd, Fc, Fd, w=1, pro, pc, pd, re;
 
 // 0 defect, 1 cooperate: los valores de las componentes de los vectores
  double A[n], A1[n], B[100],B1[100];
  //randomr = (rand()%99)+1;
  //randomk = (rand()%99)+1;

 srand((unsigned)time(0));
  for(int se=0;se<i;se++)
  {
       A1[se]=1;	
  }
for(int t=0;t<40000;t++)
{
  x=0;
  for(int a=0;a<n;a++)
    { 
     if(A1[a]==1) x=x+1;
    }
   X=x/n;
 cout<<t<<" "<<X<<" "<<1-X<<endl;
 Pc=((x-1)*R+(n-x)*S)/(n-1); Pd=(x*T + (n-x-1)*P)/(n-1);//mean payoff 
 // pc=x*Pc/(Pc*x+Pd*(n-x));  

 //pro=Pc/(Pc+Pd);
   pro=(Pc-Pd)/(2*0.3)+0.5;
   //pro=1 - exp((Pd-Pc));
   //pro= 1/(1+exp(-(Pc-Pd)));

randomr1 = (rand()%n);
randomk1 = (rand()%n);
randomr = (rand()%101);
randomk=randomr/100;
 if(A1[randomr1]==1){
   if(randomk < pro) A1[randomk1]=1;
 }
 if(A1[randomr1]==0){
   if(randomk < (1-pro)) A1[randomk1]=0;
 }
// cout<<randomr1<<endl;

  
}
return 0;
}
