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
		std::getline(std::cin, input);

		//Evaluate
		output = Repl::Evaluate(input);

		//Print
		//std::cout << output << std::endl;
	}
}

std::string Repl::Evaluate(std::string input)
{
	Repl::Tokenize(input);
	return input;
}
//TODO: fix this 
std::string* Repl::Tokenize(std::string input)
{
	std::string inputString = input;
	int j = 0;
	int openParen;
	while (j < inputString.length())
	{
		openParen = inputString.find('(', j);
		if (openParen != -1)
		{
			inputString.replace(openParen, 1, " ( ");
			j = openParen + 2;
		}
		else
		{
			j = inputString.length();
		}
	}

	j = 0;

	while (j < inputString.length())
	{
		openParen = inputString.find(')', j);
		if (openParen != -1)
		{
			inputString.replace(openParen, 1, " ) ");
			j = openParen + 2;
		}
		else
		{
			j = inputString.length();
		}
	}

	std::cout << inputString;

	std::string* tokenizedArray = new std::string[inputString.length()];
	std::istringstream tokenStream(inputString);
	for (int i = 0; std::getline(tokenStream, tokenizedArray[i], ' '); i++)
	{
		std::cout << tokenizedArray[i] << std::endl;
	}
	return tokenizedArray;
}