// Proceso de Moran
#include <iostream> 
#include<string>
#include<fstream>
#include<iomanip>
#include <ctime> 
#include <cstdlib> 
#include<cmath>
#include "Random.h"
double a=0.0, b=4, c=2, d=2; 
double round( double k );
double fitness( double k );
using namespace std; 
int main () 
{
  double randomr, randomk, r1, p1, r2, p2, r, p, f1, f2, pro1=2, pro2=1, sigma1, sigma2=0;
  int  x, randomr1, randomk1, n=100, i=10, deltat=500;
 
  double  T, X, f0,Pc,Pd, Fc, Fd, w=1, pro, pc, pd, re, aux;
  // 0 defect, 1 cooperate: los valores de las componentes de los vectores
  double A[n], A1[n], B[n], TD[10000];
    double noise, k=2, b,c,a1=0;
	
for(noise=0.1; noise<=3.5; noise=noise + 0.1)
  {
	  Random rv;
	  b=noise/k; c=k*k/noise;
	  
    T=0; 
    for(int m=0; m<10000; m++ )
      {
srand((unsigned)time(0));
for(int se=0;se<n;se++)
  {
    if(se<i) A1[se]=1;	
    else A1[se]=0;    
  }
 for(int se=0;se<n;se++)//asignacion de la distribucion fenotipica(fitness) inicial para los alelos 1 y 0 
  {
   if(A1[se]==1){ 
/*randomk = (rand()%1000)+1;
randomr= (rand()%1000)+1;
r1=randomk/1000;
r2=randomr/1000;
p1=pro1+sigma1*sqrt(-2*log(r1))*sin(6.28*r2);*/
p1=rv.gamma(a1,b,c);
B[se]=fitness(p1);  
              }
   else{
randomk = (rand()%1000)+1;
randomr = (rand()%1000)+1;
r1=randomk/1000;
r2=randomr/1000;
p2=pro2+sigma2*sqrt(-2*log(r1))*sin(6.28*r2);
B[se]=p2;
             }
   }
  x=i;
  int t=0;
srand((unsigned)time(0));
while(x>0 && x<n)
{
x=0;
  for(int a=0;a<n;a++)
    { 
     if(A1[a]==1) x=x+1;
    }
  X=double(x)/double(n);
  //cout<<t<<" "<<X<<" "<<1-X<<endl;
 
 double f0=0, f1=0; 
for(int se=0;se<n;se++)
  {
    if(A1[se]==1){ f1=f1+B[se];}
    else{ f0=f0+B[se]; }    
  }
//if(X==0.99){break;}  
 t++;
 pc=f1/(f1+f0);
double random = (rand()%1001);
double randoM =random/1000;
 if(randoM < pc){  
randomk1 = (rand()%n);
A1[randomk1]=1;
/*randomk = (rand()%1000)+1;
randomr= (rand()%1000)+1;
r1=randomk/1000;
r2=randomr/1000;
p1=pro1 + sigma1*sqrt(-2*log(r1))*sin(6.28*r2); */
 p1=rv.gamma(a1,b,c);
B[randomk1]=fitness(p1);
                 }
 else{ 
randomk1 = (rand()%n);
A1[randomk1]=0;
randomk = (rand()%1000)+1;
randomr= (rand()%1000)+1;
r1=randomk/1000;
r2=randomr/1000;
p2=pro2+sigma2*sqrt(-2*log(r1))*sin(6.28*r2);
B[randomk1]=p2; 
    } 
 }
 if(X==1){ T=T+double(t); TD[m]= double(t);}
  } 
    double Dess2=0, Dess;
    for(int con=0; con<10000; con++){Dess2= Dess2 + (TD[con]-(T/10000))*(TD[con]-(T/10000)); }

Dess=sqrt(Dess2/10000);
cout<<noise<<" "<<T/10000<<" "<<Dess<<endl;
  }
return 0;
}
double round( double k )
{
const double sd = 100; //for accuracy to 3 decimal places
return int(k*sd + (k<0? -0.5 : 0.5))/sd;
}
double fitness( double k )
{
 double f;
 if(k>a && k<b){
 if(k <= c ){f=d*a/(a-c)+d*k/(c-a) ;}
 else f=d*b/(b-c) - d*k/(b-c);}
 else f=0;

return k;
}
