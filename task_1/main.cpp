#include <iostream>
#include <fstream>
#include <list>


int main(int argc,char **argv)
{
	std::ifstream ifs("data.txt", std::ifstream::in);
	std::string sbuf;//,pattern="\\d*";
	//std::regex rx ("\\d+", std::regex::ECMAScript|std::regex::icase);
	//std::smatch m;
	int n;
	ifs>>n;
	std::list<double> x,y;
	std::list<double>::iterator itx,ity;
	double temp;
	for(int i=0;i<n;i++)
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
	ifs>>temp;
#if (DEBUG)
	for	(itx=x.begin(),ity=y.begin(); itx!=x.end() && ity!=y.end(); itx++, ity++)
	{
		std::cout<<*itx<<" "<<*ity<<" "<<std::endl;
	}
	std::cout<<temp<<std::endl;
#endif
	
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
	std::cout<<"x="<<temp<<std::endl<<"y="<<res<<std::endl;
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
