#pragma once

#include <vector>
#include <string>
#include <iostream>

class ParseTree
{
public:
	ParseTree();
	ParseTree(std::vector<std::string> &input);
	~ParseTree();
	static std::vector<std::string> Tokenize(std::string input, char delimiter);
	static std::string TokenizePrep(std::string input);
	std::string print();

	std::vector<ParseTree*> branches;
};

