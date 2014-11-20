// Proceso de Moran
#include <iostream> 
#include<string>
#include<fstream>
#include<iomanip>
#include <ctime> 
#include <cstdlib> 
#include<cmath>
double c=2, b=4, r=3.5; 
double P=0, R=b-c, S=-c, T=b, w=0.1;
double pro( double j, double k );
using namespace std; 
int main () 
{
  int n=10, m=10, randomm, N=n*m, randomn, randomn1;
  double q=0.001,x, X,xk,xj, randomk, randomr;
  double B[N], A[N], A1[m], A0[m], A2[n];
  for(int se=0;se<1;se++)
  {
       A[se]=1;	
  }
srand((unsigned)time(0));
// 1 cooperate, 0 no cooperate and 2 no individual
 x=1;
 X=1;
 int t=0;
 int t1=0;
 while(x>0 && X>0){
 x=0;
 X=0;
  for(int a=0;a<N;a++)
    { 
     if(A[a]==1)x=x+1;
     if(A[a]==0)X=X+1;
    }
   
cout<<t<<" "<<x<<" "<<X<<endl;
//if(t==10000){break;}
 t++;
 for(int i=0; i<m; i++){
     xk=0, xj=0; 
     for(int j=n*i; j<(n*(i+1)); j++)
     {
       if(A[j]==0 || A[j]==1){xk=xk+1;}
       if(A[j]==1){xj=xj+1;}
     } 
     //     cout<<pro(xj,xk)<<endl;
     A1[i]=pro(xj,xk);
     A0[i]=xk;
 
 }
 // escojer un grupo aleatoriamente y un tipo para reprodicirse.
//randomm=(rand()%m);
if(t1<m){t1++; if(t1==m){ t1=0; }}
randomk = (rand()%1001);
 randomr=randomk/1000;
cout<<randomr<<" pro "<< A1[t1]<<" numero "<<t1<<endl;
if(A0[t1]==0){cout<<"FALLA"<<endl; break; }
 if(A0[t1] < n){for(int nj=n*t1; nj < (n*t1+n); nj++){if(A[nj]==2){if(randomr <= A1[t1]){A[nj]=1;}else{A[nj]=0;} break;}} }
    else{double randomkq = (rand()%1001);
      double randomrq=randomkq/1000;
      if(randomrq > q){ randomn=(rand()%n);randomn1=n*t1+randomn;if(randomr <= A1[t1]){A[randomn1]=1;} else{A[randomn1]=0;} } 
   // cout<<randomn1<<endl;
      else{double randomk1, randomr1; if(randomr <= A1[t1]){A2[0]=1;} else{A2[0]=0;} 
                 loop:
	         int i1,i2=0;
                 for(int i=1; i<n; i++){
                      randomk1 = (rand()%101);
                      randomr1=randomk1/100; 
		      // cout<<randomr1<<endl;
		      if(randomr1 < 0.5){randomn1=n*t1+i; A2[i]=A[randomn1]; A[randomn1]=2;}
                   else{A2[i]=2;} 
		 }
		 for(i1=0; i1<n; i1++){randomn1=n*t1+i1; if(A[randomn1]==2)i2=i2++;}
                 if(i2==n)goto loop;
                 randomm=(rand()%m);  
                 cout<<randomm<<endl;      
              for(int i=0; i<n; i++){randomn1=n*randomm+i; A[randomn1]=A2[i];}
      }
                         
      }

}

return 0;
}
double pro( double j, double k )
{
  double C=1-w+w*((R*(j-1)+S*(k-j))/(k-1)), D=1- w + w*((T*j+P*(k-j-1))/(k-1)), p;
  //  p=j*C/(j*C+D*(k-j));
  p=r*j/(r*j +(k-j));
  return p;
}




/*{
  double randomr, randomk, r=2, s=1;
 int  randomr1, randomk1, n=1000, i=100;
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
 Cout<<t<<" "<<X<<" "<<1-X<<endl;
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
}*/
