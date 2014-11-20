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
  double randomr, randomk, r=2, s=1;
 int  randomr1, randomk1, n=1000, i=10;
 // Parametros de la matriz
  double R=1, S=0.1, T=0.5, P=0, x,X,Pc,Pd, Fc, Fd, w=1, pro, pc, pd, re, aux;
 // 0 defect, 1 cooperate: los valores de las componentes de los vectores
  double A[n], A1[n], B[100],B1[100];
  //randomr = (rand()%99)+1;
  //randomk = (rand()%99)+1;
srand((unsigned)time(0));
  for(int se=0;se<i;se++)
  {
       A1[se]=1;	
  }
  x=i;
  int t=0;
 while(x>0 && x<double(n))
{
  
  x=0;
  for(int a=0;a<n;a++)
    { 
     if(A1[a]==1) x=x+1;
    }
   X=x/double(n);
	
cout<<t<<" "<<X<<" "<<1-X<<endl;
 Pc=r*x; Pd=s*(double(n)-x);//  reproduction with fitness r for cooperate 
 pc=Pc/(Pc+Pd);  
 t++;
   //pro=Pc/(Pc+Pd);
   //pro=(Pc-Pd)/(2*10)+0.5;
   //pro=1 - exp((Pd-Pc));
   //pro= 1/(1+exp(-(Pc-Pd)));
randomk = (rand()%10001);
randomr1 = (rand()%n);
randomr=randomk/10000;
 if(randomr < pc){
   A1[randomr1]=1;}
 else A1[randomr1]=0; 
 //cout<<randomr<<" "<<pc<<endl;
 }
 
return 0;
}
