#include "./Variable.h"

Variable::Variable(std::string const& data){
	this->data = data;
}

Variable::~Variable(){
	
}

bool Variable::isStatic(){
	
}

bool Variable::isNull(){
	
}

bool Variable::isPrivate(){
	
}

bool Variable::isPublic(){
	
}

std::string const& Variable::getName(){
	
}

std::string const& Variable::getValue(){
	
}

std::string const& Variable::getType_(){
	StringUtils* stru = new StringUtils(this->data);
	std::string result = stru->substring(0,stru->indexOf(" "));
	delete stru;
	return result;
}

Variable::Type Variable::getType(){
	
}

std::vector<std::string> const& Variable::getAttrs(){
	StringUtils* stru = new StringUtils(this->data);
	std::vector<std::string> result = stru->split(" ");
	delete stru;
	return result;
}
