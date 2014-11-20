// Proceso de Moran
#include <iostream> 
#include<string>
#include<fstream>
#include<iomanip>
#include <ctime> 
#include <cstdlib> 
#include<cmath>
#include "Random.h"
double a=0, b=4, c=2, d=2;
double fitness( double k );
using namespace std; 
int main () 
{
double randomr, randomk, r1, p1, r2, p2, sigma, pro=10, sum, i;
int  randomr1, randomk1;
/*for(sigma=0.05; sigma<=0.5; sigma=sigma+0.05){
srand((unsigned)time(0));
sum=0;
 for(i=0; i<1000; i++){
randomk = (rand()%1000) + 1;

randomr= (rand()%1000 + 1);
 r1=randomk/1000;
 r2=randomr/1000;
p1=pro+sigma*sqrt(-2*log(r1))*sin(6.28*r2);
sum=sum+fitness(p1); 
//cout <<p1<<" "<<fitness(p1)<<endl;
   }
 cout<<sigma<<" "<<sum/1000<<endl;
 }*/
	double noise=3.5, k=10, b,c,a=0, mean=1, var=0.001;
	b=noise/k; c=k*k/noise;
	//b=sqrt(var*6)/3.1416, a=mean+b*0.57721;
	Random rv;

	for (int i=0; i<10000; i++) {
		cout<<20-rv.gamma(a,b,c)<<endl;
	}
return 0;
}
double fitness( double k )
{
 double f;
 if(k>a && k<b){
 if(k <= c ){f=d*a/(a-c)+d*k/(c-a) ;}
 else f=d*b/(b-c) - d*k/(b-c);}
 else f=0;

return f;
}
