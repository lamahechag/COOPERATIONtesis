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
  double r=2, s=1, n=100, x,dx, sigma2, dsigma2,x2, dsigmafx, sigmafx, sigmaff0=0.5, dsigmaff,sigmaff;
  x=1/n, sigma2=0, sigmafx=0, sigmaff=sigmaff0;
  for(double m=0; m<2000; m=m+1)
    {
		//r=(sigmaff0/(2*n*x))*(4*n*x/sigmaff0 -1);
      /*dx=x*(1-(x/n))*(r-s)/(s+(r-s)*(x/n))+0.5*n*sigma2*(r-s)*((2*x*(s-r)/n -2*s)*(r*x/n + s*(1-x/n))-2*(r-s)*(s-(x*x*(r-s)/(n*n))-2*s*x/n))/(pow((r*x/n +s*(1-x/n)),3));
		dsigma2=sigma2*2*(r-s)*((1-2*x/n)*(r*x/n + s*(1-x/n))-(x/n - x*x/(n*n))*(r-s))/(n*(pow((r*(x/n) +s*(1-x/n)),2))) + (x/n-x*x/(n*n))*(r+s)/(n*(r*x/n+s*(1-x/n)));*/
		dx=(x/n)*(1-x)*(r-s)/(r*x+s*(1-x))+(0.5/(n*n))*(r-s)*sigma2*((1-2*x*(r-s))*(r*x+s*(1-x))-2*(r-s)*(1-x*(r-s)))/(pow((r*x+s*(1-x)),3));
		//dsigma2=2*sigma2*((r-s)/n)*((1-2*x)*(r*x+s*(1-x))-(x-x*x)*(r-s))/(pow((r*x+s*(1-x)),2))+ (x/n)*(1-x)*(r+s)/(r*x+s*(1-x));
	
		dsigmafx=(sigmaff0*(1-x)*x*s/(n*x) + sigmafx*(r-s)*x*(1-x*(r-s)))/(n*(pow((r*x+s*(1-x)),2)));
		dsigmaff=-(sigmaff0/(n*x*x))*dx;
		dsigma2=2*(sigmafx*x*(1-x)*s + sigma2*(r-s)*x*(1-x*(r-s)))/(n*(pow((r*x+s*(1-x)),2))) + (x/n)*(1-x)*(r+s)/(r*x+s*(1-x));
		x2=x*x;
		if(int(m)%10==0){cout<<m<<" "<<x<<" "<<sigma2/(n*x2)<<endl;}
		x=x+dx;
        sigma2=sigma2+dsigma2;
        sigmafx=sigmafx+dsigmafx;
		sigmaff=sigmaff+dsigmaff;
	}
 
return 0;
}
