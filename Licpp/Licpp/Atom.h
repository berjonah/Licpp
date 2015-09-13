#pragma once

#include <string>
#include "ParseTree.h"

class Atom :
	public ParseTree
{
public:
	Atom();
	Atom(std::string input);
	~Atom();
	std::string atom;
};

