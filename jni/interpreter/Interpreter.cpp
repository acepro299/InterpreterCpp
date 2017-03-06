#include "interpreter/Interpreter.h"

Interpreter::Interpreter(std::string const& data){
	this->data = data;
	this->addFunction("log");
	this->addFunction("file_create");
}

Interpreter::~Interpreter(){
	delete this->strutils;
	for(Listener* listener : this->listeners){
		delete listener;
	}
}

void Interpreter::runStandard(int line,std::string const& data){
	std::string funcname = this->getFunction(line);
	if(funcname=="log"){
		std::string arg1;
		Parameter* pmt = this->getParameter(line);
		if(pmt->hasString(0)){
			arg1 = pmt->getString(0);
		}else{
			arg1 = pmt->getArg(0);
		}
		std::cout << arg1 << std::endl;
	}else if(funcname=="file_create"){
		FILE* file;
		Parameter* pmt = this->getParameter(line);
		file = fopen(pmt->getChar(0),"w+");
		fclose(file);
	}else{
		return;
	}
}

void Interpreter::run(){
	for(int i = 0;i<this->length();i++){
		this->runStandard(i,this->getData(i));
		for(Listener* listener : this->listeners){
			listener->onRun(this,i,this->getData(i));
		}
	}
}

bool Interpreter::isParameter(int line){
	StringUtils* stru = new StringUtils(this->getData(line));
	bool isParam = stru->contains("(")&&stru->contains(");");
	delete stru;
	if(isParam)
		return true;
	return false;
}

Parameter* Interpreter::getParameter(int line){
	StringUtils* stru;
	if(this->isParameter(line)) 
		stru = new StringUtils(this->getData(line)); 
		std::string result = stru->substring("(",");");
		delete stru;
		Parameter* param(new Parameter(result));
		return param;
	return NULL;
}

/*
Parameter* Interpreter::getParameter(int line,int arg){
	StringUtils* stru = new StringUtils(this->getParameter(line));
	std::string result = stru->split(",")[arg];
	delete stru;
	return std::auto_ptr<Parameter> param_ptr(new Parameter(result)).get();
}*/

int Interpreter::length(){
	return this->getStringUtils()->split("\n").size();
}

std::string const& Interpreter::getData(int line){
	return this->getStringUtils()->split("\n")[line];
}

std::string const& Interpreter::getData(){
	return this->data;
}

void Interpreter::addFunction(std::string const& function){
	this->functions.push_back(function);
}

void Interpreter::removeFunction(std::string const& function){
	for(int i = 0;i<this->functions.size();i++){
		if(this->functions[i]==function){
	    	this->functions.erase(this->functions.begin()+i);
		}
	}
}

bool Interpreter::isFunction(int line){
	StringUtils*stru = new StringUtils(this->getData(line));
	for(int i = 0;i<this->functions.size();i++){
    	if(stru->contains(this->functions[i])) 
			return true;
	}
	return false;
}

std::string const& Interpreter::getFunction(int line){
	if(this->isFunction(line)){
		StringUtils*stru = new StringUtils(this->getData(line));
		for(int i = 0;i<this->functions.size();i++){
        	if(stru->contains(this->functions[i]))
				return this->functions[i];
		}
	}
	return "null";
}

bool Interpreter::containsFunction(std::string const& function){
	for(int i = 0;i<this->functions.size();i++){
		if(this->functions[i]==function) return true;
	}
	return false;
}

void Interpreter::append(std::string const& data){
	this->data += data+"\n";
}

void Interpreter::addListener(Listener* listener){
	this->listeners.push_back(listener);
}
	
void Interpreter::removeListener(Listener* listener){
	for(int i = 0;i<this->listeners.size();i++){
	   	if(this->listeners[i]==listener)
	       	this->listeners.erase(this->listeners.begin()+i);
	}
}

std::vector<Interpreter::Listener*> const& Interpreter::listListener(){
	return this->listeners;
}
