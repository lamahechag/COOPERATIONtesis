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
  long double sum1=0,j=10, tj, tjn;
 long  double n=1000, k, l,r , s=1, t1;
 for(r=1.6; r<= 2.04; r =r+0.04){
 long double sdr=s/r;
  for(k=1; k<=(n-1);k++){long double  sum2=0;
    for(l=1;l<=k;l++){ sum2=sum2 + (1/(pow(sdr,l)) - 1)*(1/(n-l) + s/(r*l)); }
     sum1=sum1+ pow(sdr,k)*sum2;
    // cout<<sum1<<" "<<k<<" "<<sum2<<endl; 
     if(k==(j-1)){tj=sum1;} 
  }
  t1=(n/(1-pow(sdr,n)))*sum1;
  tjn=t1-tj*(n/(1-pow(sdr,n)))*((1-pow(sdr,n))/(1-pow(sdr,j)));
  cout<<r<<" "<<tjn<<endl;
 }
 return 0;
}
