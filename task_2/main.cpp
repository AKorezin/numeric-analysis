#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc,char **argv)
{
	std::ifstream ifs(argv[1], std::ifstream::in);
	std::string sbuf;
	std::getline(ifs,sbuf);
	std::stringstream is(sbuf);
	return 0;

}
