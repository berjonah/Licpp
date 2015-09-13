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
	ParseTree tree(ParseTree::Tokenize(ParseTree::TokenizePrep(input), ' '));
	return input;
}


//ParseTree* Repl::ReadFromTokens(std::vector<std::string> tokens, ParseTree* lookingAt)
//{
//	std::string token = "";
//
//	if (tokens.size() == 0)
//	{
//		std::cout << "Parse received vector of zero length";
//	}
//
//	token = tokens.front();
//	tokens.erase(tokens.begin());
//
//	if (token == "(")
//	{
//		lookingAt = new Expression();
//		while (true)
//		{
//			token = tokens.front();
//			tokens.erase(tokens.begin());
//			if (token == ")")
//			{
//				break;
//			}
//			else
//			{
//				ParseTree* passIn = 0;
////				lookingAt->addBranch(Repl::ReadFromTokens(tokens, passIn));
//			}
//		}
//		tokens.erase(tokens.begin());
//	}
//	else if (token == ")")
//	{
//		std::cout << "Unexpected ')'" << std::endl;
//	}
//	else
//	{
//		lookingAt = new Atom(token);
//	}
//	return lookingAt;
//}