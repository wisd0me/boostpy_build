#include <iostream>
#include <boost/format.hpp>

int main(int argc, char **argv)
{
	std::cout << boost::format("%1% %1% son") % "wuddup" << std::endl;
	return 0;
}

