#pragma once

#include <iostream>
#include <string>

class Repl
{
public:
	Repl();
	~Repl();
	static void Loop();
private:
	static std::string Evaluate(std::string input);
};

