#include <iostream> 
#include<string>
#include<fstream>
#include<iomanip>
#include <ctime> 
#include <cstdlib> 
#include<cmath>
#include "Random.h"
long double fact(double n);
using namespace std;
int main () 
{
  double noise, k=1, b,c,a=0, s=2, r=4;
	int n=100, j=90;
	for (noise=0.1; noise<=3.5; noise=noise+0.1) {
		
	
   b=noise/k; c=k*k/noise;
Random rv;
		double meansum=0, meansum2=0;
 for (int m=0; m<20000; m++) {
	 
 
	double SUM=0;
	double  prod=1;
	for (double i=2; i<=n ;i++){
		
		double sum=0;
		for (double m=1; m<i; m++) {
			sum=sum+(rv.gamma(a,b,c));
		}
			prod=prod*sum;
	//}
		SUM=SUM+(fact(i-1))*(pow(s,i-1))/prod;
	}
	 
	 double SUM2=0;
	   prod=1;
	 for (double i=2; i<=j ;i++){
		 
		 double sum=0;
		 for (double m2=1; m2<i; m2++) {
		 sum=sum+(rv.gamma(a,b,c));
		 }
		 prod=prod*sum;
		 //}
		 SUM2=SUM2+(fact(i-1))*(pow(s,i-1))/prod;
	 }

				  
	 meansum=meansum+ 1/(1+SUM);
	 meansum2=meansum2+ 1/(1+SUM2);
	//cout<<1/(1+SUM)<<endl;
	 //cout << rv.gamma(a,b,c)<<endl;
	 
 }
		
		
		
		
		
		cout<<noise<<" "<<meansum/meansum2<<endl;
	}
 return (0);
}
long double fact(double n){
	long double fac=1;
	for (double i=1; i<=n; i++) {
		fac=fac*i;
	}
	return fac;

}
