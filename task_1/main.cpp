#include <iostream>
#include <fstream>
#include <list>
#include <sstream>

int main(int argc,char **argv)
{
	std::ifstream ifs(argv[1], std::ifstream::in);
	//,pattern="\\d*";
	//std::regex rx ("\\d+", std::regex::ECMAScript|std::regex::icase);
	//std::smatch m;
	std::list<double> x,y;
	std::list<double>::iterator itx,ity;
	double temp;
	int n;
	for(int i=0;!ifs.eof();i++)
	{
	double tx,ty;
	std::string sbuf;
	std::getline(ifs,sbuf);
	std::stringstream is(sbuf);
	if(is>>tx)
		if(is>>ty)
		{
			x.push_back(tx);
			y.push_back(ty);
		}
		else
		{
			temp=tx;
			n=i;
		}

	}

/*	for(int i=0;i<n;i++)
	{
		ifs>>temp;
      #if (DEBUG)
      std::cout<<i<<temp<<std::endl;
      #endif
		x.push_back(temp);
	}
	for(int i=0;i<n;i++)
	{
    	ifs>>temp;
      #if (DEBUG)
      std::cout<<i<<temp<<std::endl;
      #endif
		y.push_back(temp);
	}
	ifs>>temp;*/
	
	std::list<double>::iterator itx1;
	double l=1,res=0;
	for(itx=x.begin(),ity=y.begin();itx!=x.end();itx++,ity++)
	{
		for(itx1=x.begin();itx1!=x.end();itx1++)
			if(itx1!=itx)
			{
				l*=(temp-*itx1)/(*itx-*itx1);
			}
		res+=l*(*ity);
		l=1;
	}

	std::ofstream ofs(argv[2],std::ofstream::out);
	int i=0;
	for	(itx=x.begin(),ity=y.begin(); itx!=x.end() && ity!=y.end() || i<=n; itx++, ity++,i++)
	{
std::cout<<i;
		if(i==n)
			ofs<<temp<<" "<<res<<std::endl;
		ofs<<*itx<<" "<<*ity<<std::endl;
	}
	/*for(i=1;!ifs.eof();i++)
	{
		std::getline(ifs,sbuf,'\n');
		if(!ifs.eof())
		{
			while(std::regex_search (sbuf,m,rx))
			{
				for(auto x:m)
					std::cout << x << " ";
				std::cout<<std::endl;
				sbuf=m.suffix().str();
			}
			

		}
	}*/

	return 0;

}
