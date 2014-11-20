//Programa basico de evolucion de cooperacion para 1 generacion
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
 // Parametros de la matriz
 double R=1, S=0, T=0.7, P=0.2, x,X,Pc,Pd, pro;
 
 // 0 defect, 1 cooperate: los valores de las componentes de los vectores
  double A[10000], A1[10000], B[100],B1[100];
  //randomr = (rand()%99)+1;
  //randomk = (rand()%99)+1;

 srand((unsigned)time(0));
  for(int se=0;se<10;se++)
  {
       A1[se]=1;	
  }
for(int t=0;t<100;t++)
{
  x=0;
  for(int a=0;a<10000;a++)
    { 
     if(A1[a]==1) x=x+1;
    }
   X=x/10000;
   cout<<t<<" "<<X<<" "<<1-X<<endl;
   Pc=((x-1)*R+(10000-x)*S)/9999; Pd=(x*T + (9999-x)*P)/9999;//mean payoff 
   //pro=Pc/(Pc+Pd);
   pro=(Pc-Pd)/(2*0.3)+0.5;
   //pro=1 - exp((Pd-Pc));
   //pro= 1/(1+exp(-((Pc-Pd)*20/0.3)+10));

  for(int b=0;b<10000;b++)
    {   
     randomr = (rand()%999)+1;
     randomk=randomr/1000;
        
     if( randomk <= pro) A1[b]=1;
     else A1[b]=0; //definir si de lo contrario tambien cambia o permanece
    }
    //for(int n=0;n<100; n++) { cout<<A1[n]<<endl;}

  
}
return 0;
}
