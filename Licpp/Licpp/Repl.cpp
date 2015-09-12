#include "Repl.h"

Repl::Repl()
{
}

Repl::~Repl()
{
}

void Repl::Loop()
{
	std::string input = "";
	std::string output = "";
	while (true)
	{
		std::cout << ">";

		//Read
		std::cin >> input;

		//Evaluate
		output = Repl::Evaluate(input);

		//Print
		std::cout << output << std::endl;
	}
}

std::string Repl::Evaluate(std::string input)
{
	//TODO: Actually evaluate things
	return input;
}
