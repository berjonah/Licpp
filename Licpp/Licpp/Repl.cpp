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
		std::cout << output << std::endl;
	}
}

std::string Repl::Evaluate(std::string input)
{
	Repl::Tokenize(Repl::TokenizePrep(input), ' ');
	return input;
}

std::string Repl::TokenizePrep(std::string input)
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
	return inputString;
}


//TODO: fix this 
std::vector<std::string> Repl::Tokenize(std::string input, char delimiter)
{
	std::string token;
	int j = 0;
	std::vector<std::string> returnVector;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != delimiter)
		{
			token = "";
			j = i + 1;
			for (j = i + 1; input[j] != delimiter; j++);
			token = input.substr(i, j - i);
			returnVector.push_back(token);
			i = j;
		}
	}
	return returnVector;
}
