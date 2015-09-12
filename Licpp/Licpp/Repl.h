#pragma once

#include <iostream>
#include <string>
#include <sstream>

class Repl
{
public:
	Repl();
	~Repl();
	static void Loop();
private:
	static std::string Evaluate(std::string input);
	static std::string* Tokenize(std::string input);
};

