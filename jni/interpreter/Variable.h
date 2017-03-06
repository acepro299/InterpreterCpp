#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include "utils/StringUtils.h"

class Variable{
	public:
	
	enum Type: int{
		Integer,Boolean,String
	};
	
	private:
	std::string data;
	
	public:
	~Variable();
	Variable(std::string const& data);
	bool isStatic();
	bool isNull();
	bool isPrivate();
	bool isPublic();
	std::string const& getName();
	std::string const& getValue();
	std::string const& getType_();
	Variable::Type getType();
	std::vector<std::string> const& getAttrs();
	
};

#endif // VARIABLE_H
