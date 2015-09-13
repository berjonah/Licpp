#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ParseTree.h"
#include "Atom.h"
#include "Expression.h"

class Repl
{
public:
	Repl();
	~Repl();
	static void Loop();
private:
	static std::string Evaluate(std::string input);
};

