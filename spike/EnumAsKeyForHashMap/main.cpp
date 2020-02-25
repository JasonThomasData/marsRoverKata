#include <map>
#include <iostream>

enum Colours
{
	red,
	yellow,
	blue
};

int main(int argc, char** argv)
{
	std::map<Colours, int> coloursAndIntegers;
	coloursAndIntegers[Colours::red] = 1;
	coloursAndIntegers[Colours::blue] = 23;
	coloursAndIntegers[Colours::yellow] = -100;

	std::cout<< "At "<< Colours::red<< " is "<< coloursAndIntegers[Colours::red]<< std::endl;
	std::cout<< "At "<< Colours::blue<< " is "<< coloursAndIntegers[Colours::blue]<< std::endl;
	std::cout<< "At "<< Colours::yellow<< " is "<< coloursAndIntegers[Colours::yellow]<< std::endl;

	return 0;
}
