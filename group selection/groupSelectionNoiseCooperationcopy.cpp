// Proceso de Moran, Group selection. Where the benefit by individual is the divition of the whole group investment
#include <iostream> 
#include<string>
#include<fstream>
#include<iomanip>
#include <ctime> 
#include <cstdlib> 
#include<cmath> 
double  w=1;
double pro1( double j, double k, double r );
double pro0( double j, double k, double r);
double probabilidad(int n, int m, int i0,double beneficio, double sigma0,double sigma1,double mean0,double mean1);
using namespace std; 
int main () 
{
  int n=10, m=10, i0=10;
  double beneficio=2, sigma0=0.1,sigma1=0.1,mean0=1,mean1;
  for(mean1=0; mean1<6; mean1=mean1+0.1){
    cout<<mean1<<" "<<probabilidad(n,m, i0,beneficio, sigma0,sigma1,mean0,mean1)<<" "<<probabilidad(n,m, i0,beneficio, sigma0,0.2,mean0,mean1)<<" "<<probabilidad(n,m, i0,beneficio, sigma0,0.3,mean0,mean1)<<" "<<probabilidad(n,m, i0,beneficio, sigma0,0.6,mean0,mean1)<<" "<<probabilidad(n,m, i0,beneficio, sigma0,0.7,mean0,mean1)<<endl;
  }
return 0;
}
double pro1( double j, double k, double r)
{  
  double C=1-w+w*r/j, p;
  if(j==0){p=0;}   
  else p=j*C;
   return p;
}
double pro0( double j, double k, double r)
{
  double  D=1- w + w*r/(k-j), p;
  if(k==j){p=0;} 
  else p=(k-j)*D;
  return p;
}
double probabilidad(int n, int m, int i0,double beneficio, double sigma0,double sigma1,double mean0,double mean1)
{
  double r1,r2,p0,p1;
int  randomm, N=n*m, randomn, randomn1;
 double q=0.001,x, X,xk,xj, randomk, randomr, sumpro, count=0;
double  A[N], AcooLevel[N],A1[m], A12[m],A0[m], A2[n],A2cooLevel[n];
 for(int i=0; i<500;i++){
 srand(((unsigned)time(0))*i);
for(int se=0;se<N;se++)
  {
    if(se<i0){ A[se]=1;}
    else A[se]=0;	
  }
 for(int se=0;se<N;se++){
   if(A[se]==1){
randomk = (rand()%1000)+1;
randomr= (rand()%1000)+1;
 r1=randomk/1000;
 r2=randomr/1000;
 p1=mean1+sigma1*sqrt(-2*log(r1))*sin(6.28*r2);
 if(p1<0){p1=0;}
 AcooLevel[se]=p1; 
              }
   else{
randomk = (rand()%1000)+1;
randomr= (rand()%1000)+1;
 r1=randomk/1000;
 r2=randomr/1000;
 p0=mean0+sigma0*sqrt(-2*log(r1))*sin(6.28*r2);
if(p0<0){p0=0;}
 AcooLevel[se]=p0; 
}

 }
// 1 cooperate, 0 no cooperate and 2 no individual
 x=1; X=1;
 int t=0;
 // int t1=0;
 while(x>0 && X>0){
 x=0; X=0;
  for(int a=0;a<N;a++)
    { 
     if(A[a]==1)x=x+1;
     if(A[a]==0)X=X+1;
    }
 
 sumpro=0;
 for(int i=0; i<m; i++){
     double cost=0;
     xk=0, xj=0; 
     for(int j=n*i; j<(n*(i+1)); j++)
     {
       if(A[j]==0 || A[j]==1){xk=xk+1;cost=cost+AcooLevel[j];}
       if(A[j]==1){xj=xj+1;}
     } 
     double Benefit=beneficio*cost/xk, utility0=0,utility1=0;
 for(int j=n*i; j<(n*(i+1)); j++)
     {
       if(A[j]==1){utility1=utility1+Benefit-AcooLevel[j];}
       if(A[j]==0){utility0=utility0+Benefit-AcooLevel[j];}
     } 
     A1[i]=pro1(xj,xk,utility1);  A12[i]=pro0(xj,xk,utility0);
     A0[i]=xk;
     sumpro=sumpro+pro1(xj,xk,utility1)+pro0(xj,xk,utility0);
 }
 //if(t==1000){break;}
 // escojer un grupo aleatoriamente y un tipo para reprodicirse
 // cout<<t<<" "<<x/(x+X)<<" "<<X/(x+X)<<endl;
 t++;
 // if(x/(x+X)==0.7){break;}
 double sumpro1=0, verdad;
 int mselect;
randomk = (rand()%1001);
randomr=(randomk)/1000;
 for(int im=0;im<m;im++)
   { // cout<<"A1="<<A1[im]<<endl;
     //cout<<"A12="<<A12[im]<<" "<<im<<endl;
     // if(im==5){break;}
     if(sumpro1<randomr && randomr<= (sumpro1+(A1[im]/sumpro))){verdad=1; mselect=im; break;}
     sumpro1=sumpro1+ (A1[im]/sumpro);
    
     if(sumpro1<randomr && randomr<= (sumpro1+(A12[im]/sumpro))){verdad=0; mselect=im; break;}
     sumpro1=sumpro1+ (A12[im]/sumpro);
   }
 //cout<<verdad<<" "<<mselect<<" "<<randomr<<" "<<sumpro<<endl;
 if(A0[mselect] < n){for(int nj=n*mselect; nj < (n*mselect+n); nj++){if(A[nj]==2){A[nj]=verdad; if(verdad==1){randomk=(rand()%1000)+1;
randomr=(rand()%1000)+1;r1=randomk/1000;r2=randomr/1000;p1=mean1+sigma1*sqrt(-2*log(r1))*sin(6.28*r2);if(p1<0){p1=0;}
 AcooLevel[nj]=p1;}
else{randomk = (rand()%1000)+1;
randomr= (rand()%1000)+1;
 r1=randomk/1000;
 r2=randomr/1000;
 p0=mean0+sigma0*sqrt(-2*log(r1))*sin(6.28*r2);if(p0<0){p0=0;}
 AcooLevel[nj]=p0; }break;}} 
}
else{double randomkq = (rand()%1001);
      double randomrq=randomkq/1000;
    if(randomrq > q){ randomn=(rand()%n);randomn1=n*mselect+randomn;A[randomn1]=verdad;if(verdad==1){randomk=(rand()%1000)+1; randomr=(rand()%1000)+1;
 r1=randomk/1000;
 r2=randomr/1000;
 p1=mean1+sigma1*sqrt(-2*log(r1))*sin(6.28*r2);if(p1<0){p1=0;}
 AcooLevel[randomn1]=p1;} 
     else{randomk = (rand()%1000)+1;
randomr= (rand()%1000)+1;
 r1=randomk/1000;
 r2=randomr/1000;
 p0=mean0+sigma0*sqrt(-2*log(r1))*sin(6.28*r2);if(p0<0){p0=0;}
 AcooLevel[randomn1]=p0; }} 
else{double randomk1, randomr1; A2[0]=verdad;if(verdad==1){randomk = (rand()%1000)+1;
randomr= (rand()%1000)+1;
 r1=randomk/1000;
 r2=randomr/1000;
 p1=mean1+sigma1*sqrt(-2*log(r1))*sin(6.28*r2);if(p1<0){p1=0;}
 A2cooLevel[0]=p1;} 
         else{ randomk=(rand()%1000)+1; randomr=(rand()%1000)+1; r1=randomk/1000; r2=randomr/1000; p0=mean0+sigma0*sqrt(-2*log(r1))*sin(6.28*r2);if(p0<0){p0=0;} 
A2cooLevel[0]=p0;}
                 loop:
	         int i1,i2=0;
                 for(int i=1; i<n; i++){
                      randomk1=(rand()%1001);
                      randomr1=randomk1/1000; 
		      if(randomr1 < 0.5){randomn1=n*mselect+i; A2[i]=A[randomn1]; A2cooLevel[i]=AcooLevel[randomn1];
			A[randomn1]=2; AcooLevel[randomn1]=0;}
		      else{A2[i]=2; A2cooLevel[i]=0;} 
		 }
		 for(i1=0; i1<n; i1++){randomn1=n*mselect+i1; if(A[randomn1]==2)i2=i2++;}
                 if(i2==n) goto loop;
                 randomm=(rand()%m);        
		 for(int i=0; i<n; i++){randomn1=n*randomm+i; A[randomn1]=A2[i];AcooLevel[randomn1]=A2cooLevel[i];}
      }
                         
      }
 }
 if(X==0){count=count+1;}
}
 double pro=count/500;
return pro;
}




