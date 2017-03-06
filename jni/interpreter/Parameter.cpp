#include "./Parameter.h"

Parameter::Parameter(std::string const& data){
	this->data = data;
}

Parameter::~Parameter(){
	this->data = "";
}

bool Parameter::hasNumeric(int index){
	//TODO: implement this method
	return false;
}

bool Parameter::hasAlphabetic(int index){
	//TODO: implement this method
	return false;
}

bool Parameter::hasExpression(int index){
	//TODO: implement this method
	return false;
}

bool Parameter::hasString(int index){
	StringUtils* stru = new StringUtils(this->getArg(index));
	bool hasString1 = stru->contains("\"")==true;
	bool hasString2 = stru->contains("'")==true;
	delete stru;
	if(hasString1) 
		return true;
	else if(hasString2) 
		return true;
	return false;
}


bool Parameter::hasVariable(int index){
	StringUtils* stru = new StringUtils(this->getArg(index));
	
	return false;
}

bool Parameter::hasFunction(int index){
	//TODO: implement this method
	return false;
}

std::string const& Parameter::getString(int index){
	StringUtils*stru = new StringUtils(this->getArg(index));
	stru->replace("\"","");
	std::string result = stru->replace("'","");
	delete stru;
	return result;
}

char const* Parameter::getChar(int index){
	StringUtils*stru = new StringUtils(this->getArg(index));
	stru->replace("\"","");
	stru->replace("\'","");
	char* result = stru->getData().c_str();
	delete stru;
	return result;
}

bool Parameter::getBool(int index){
	if(this->getArg(index)=="0"|this->getArg(index)=="false")
		return false;
	if(this->getArg(index)=="1"|this->getArg(index)=="true")
		return true;
	return false;
}

int Parameter::getInt(int index){
	return StringUtils::toInt(this->getArg(index));
}

std::string Parameter::getArg(int index){
	StringUtils* stru = new StringUtils(this->data);
	std::string result = stru->split(",")[index];
	delete stru;
	return result;
}

std::vector<std::string> const& Parameter::getArgs(){
	std::auto_ptr<StringUtils> stru(new StringUtils(this->data));
	return stru.get()->split(",");
}

int Parameter::length(){
	return this->getArgs().size();
}

