#include <iostream>
#include <fstream>
#include <cmath>
int main(int argc,char **argv)
{
	std::ifstream ifs(argv[1], std::ifstream::in);
	double a[4];
	int n=0;
	std::ofstream ofs(argv[2], std::ofstream::out);
	for(int i=0;i<4;i++)
		if(ifs>>a[i])
			n++;
	if(n!=4)
	{
		ofs<<"not cubic"<<std::endl;
		return 1;
	}
	for(int i=1;i<4;i++)
		a[i]/=a[0];
	
	double discrim,q,r,dum1,s,t,term;

	q=(3*a[2]-pow(a[1],2))/9;
	r=(-(27*a[3])+a[1]*(9*a[2]-2*pow(a[1],2)))/54;
	discrim = pow(q,3)+pow(r,2);
	term=a[1]/3;
	
	double x[3];
	if (discrim > 0)
	{
		s=cbrt(r+sqrt(discrim));
		t=cbrt(r-sqrt(discrim));
		x[0]=-term+s+t;
		term+=(s+t)/2;
		x[1]=-term;
		term=sqrt(3)*(s-t)/2;
		ofs<<x[0]<<" ";
		ofs<<x[1]<<"+"<<term<<"*i ";	
		ofs<<x[1]<<"-"<<term<<"*i ";
		ofs<<std::endl;
		return 0;
	}
	if (discrim == 0)
	{
		r=cbrt(r);
		x[0]=-term+2*r;
		x[1]=x[2]=-r-term;
		for(int i=0;i<3;i++)
			ofs<<x[i]<<" ";
		ofs<<std::endl;
		return 0;
	}
	q=-q;
	dum1=acos(r/sqrt(pow(q,3)));
	r=2*sqrt(q);
	x[0]=(-term+r*cos(dum1/3));
	x[1]=(-term+r*cos((dum1+2*M_PI)/3));
	x[2]=(-term+r*cos((dum1+4*M_PI)/3));
	for(int i=0;i<3;i++)
		ofs<<x[i]<<" ";

	ofs<<std::endl;

	return 0;

}


