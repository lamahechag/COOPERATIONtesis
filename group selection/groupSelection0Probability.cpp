// Proceso de Moran
#include <iostream> 
#include<string>
#include<fstream>
#include<iomanip>
#include <ctime> 
#include <cstdlib> 
#include<cmath>
double c=2, b=4; 
double P=0, R=b-c, S=-c, T=b, w=0.1;
double pro( double j, double k, double r );
using namespace std; 
int main () 
{
int n=10, m=10, randomm, N=n*m, randomn, randomn1;
double q=0.001,x, X,xk,xj, randomk, randomr,p;
double  A[N], A1[m], A0[m], A2[n];
srand((unsigned)time(0));
for(double r=0.5; r<4; r=r+0.1){  
p=0;
for(int i2=0; i2<1000; i2++)  
 { 
for(int se=0;se<N;se++)
  {
    if(se<1){ A[se]=1;}
    else A[se]=0;	
  }
// 1 cooperate, 0 no cooperate and 2 no individual
 x=1; X=1;
 int t=0;
 int t1=0;
 while(x>0 && X>0){
 x=0; X=0;
  for(int a=0;a<N;a++)
    { 
     if(A[a]==1)x=x+1;
     if(A[a]==0)X=X+1;
    }
 t++;
 for(int i=0; i<m; i++){
     xk=0, xj=0; 
     for(int j=n*i; j<(n*(i+1)); j++)
     {
       if(A[j]==0 || A[j]==1){xk=xk+1;}
       if(A[j]==1){xj=xj+1;}
     } 
     A1[i]=pro(xj,xk,r);
     A0[i]=xk;
 
 }
 // escojer un grupo aleatoriamente y un tipo para reprodicirse.
randomm=(rand()%m);
//if(t1<m){t1++; if(t1==m){ t1=0; }}
randomk = (rand()%1001);
randomr=(randomk)/1000;
 if(A0[randomm] < n){for(int nj=n*randomm; nj < (n*randomm+n); nj++){if(A[nj]==2){if(randomr <= A1[randomm]){A[nj]=1;}else{A[nj]=0;} break;}} }
else{double randomkq = (rand()%1001);
      double randomrq=randomkq/1000;
      if(randomrq > q){ randomn=(rand()%n);randomn1=n*randomm+randomn;if(randomr <= A1[randomm]){A[randomn1]=1;} else{A[randomn1]=0;}} 
      else{double randomk1, randomr1; if(randomr <= A1[randomm]){A2[0]=1;} else{A2[0]=0;} 
                 loop:
	         int i1,i2=0;
                 for(int i=1; i<n; i++){
                      randomk1 = (rand()%1001);
                      randomr1=randomk1/1000; 
		      if(randomr1 < 0.5){randomn1=n*randomm+i; A2[i]=A[randomn1]; A[randomn1]=2;}
                   else{A2[i]=2;} 
		 }
		 for(i1=0; i1<n; i1++){randomn1=n*randomm+i1; if(A[randomn1]==2)i2=i2++;}
                 if(i2==n)goto loop;
                 randomm=(rand()%m);        
              for(int i=0; i<n; i++){randomn1=n*randomm+i; A[randomn1]=A2[i];}
      }
                         
      }
 
}

if(X==0){p=p+1;}
  }
 cout<<r<<" "<<p/1000<<endl;  
}
return 0;
}
double pro( double j, double k, double r)
{
  double C=1-w+w*((R*(j-1)+S*(k-j))/(k-1)), D=1- w + w*((T*j+P*(k-j-1))/(k-1)), p;
  //  p=j*C/(j*C+D*(k-j));
  p=r*j/(r*j +(k-j));
  return p;
}




