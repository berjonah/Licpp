#pragma once

#include <iostream>
#include <string>
#include <vector>

class Repl
{
public:
	Repl();
	~Repl();
	static void Loop();
private:
	static std::string Evaluate(std::string input);
	static std::vector<std::string> Tokenize(std::string input, char delimiter);
	static std::string TokenizePrep(std::string input);
};

