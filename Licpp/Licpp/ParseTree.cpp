#include "ParseTree.h"
#include "Atom.h"

ParseTree::ParseTree()
{
}

ParseTree::ParseTree(std::vector<std::string> &input)
{
	std::string token = "";

	token = input.front();
	input.erase(input.begin());

	if (token == "(")
	{
		while (input.front() != ")")
		{
			this->branches.push_back(new ParseTree(input));
		}
		input.erase(input.begin());
	}
	else if (token == ")")
	{
		std::cout << "Unexpected )";
	}
	else
	{
		this->branches.push_back(new Atom(token));
	}
}

ParseTree::~ParseTree()
{
}

std::vector<std::string> ParseTree::Tokenize(std::string input, char delimiter)
{
	std::string newInput = TokenizePrep(input);
	std::string token;
	int j = 0;
	std::vector<std::string> returnVector;
	for (int i = 0; i < newInput.length(); i++)
	{
		if (newInput[i] != delimiter)
		{
			token = "";
			j = i + 1;
			for (j = i + 1; newInput[j] != delimiter; j++);
			token = newInput.substr(i, j - i);
			returnVector.push_back(token);
			i = j;
		}
	}
	return returnVector;
}

std::string ParseTree::TokenizePrep(std::string input)
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

std::string ParseTree::print()
{
	if (typeid(this) == typeid(Atom))
	{
		typedef(this) Atom;
		return this->atom;
	}
	else
}
