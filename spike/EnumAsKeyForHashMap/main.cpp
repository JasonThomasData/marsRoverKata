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
	std::map<char, Colours> coloursAndIntegers = {
		{ 'r', Colours::red },
		{ 'b', Colours::blue },
		{ 'y', Colours::yellow }
	};
	/*
	std::map<char, Colours> coloursAndIntegers;
	coloursAndIntegers['r'] = Colours::red;
	coloursAndIntegers['b'] = Colours::blue;
	coloursAndIntegers['y'] = Colours::yellow;
	*/

	std::cout<< "Char r->" << coloursAndIntegers['r']<< std::endl;

	if(coloursAndIntegers.find('b') != coloursAndIntegers.end())
	{
		std::cout<< "Char b->" << coloursAndIntegers['b']<< std::endl;
	}
	
	if(coloursAndIntegers.count('y') != 0)
	{
		std::cout<< "Char y->"<< coloursAndIntegers['y']<< " with count of "<< coloursAndIntegers.count('y')<< std::endl;
	}

	if(coloursAndIntegers.count('g') == 0)
	{
		std::cout<< "Char g->"<< coloursAndIntegers['g']<< std::endl;
	}

	if(coloursAndIntegers.find('p') == coloursAndIntegers.end())
	{
		std::cout<< "Char p->"<< coloursAndIntegers['p']<< std::endl;
	}

	return 0;
}
