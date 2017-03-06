#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <memory>
#include "utils/StringUtils.h"
#include "./Parameter.h"
#include "./Variable.h"


class Interpreter{
	public:
	class Listener{
		public:
		virtual void onRun(Interpreter*interpreter,int line,std::string const& data);
	};
		
	private:
	StringUtils* strutils;
	std::string data;
	std::vector<std::string> functions;	
	std::vector<Listener*> listeners;
	
	void runStandard(int line,std::string const& data);
	
	public:
	~Interpreter();
	Interpreter(std::string const& data);
	void run();
	bool isParameter(int line);
	Parameter* getParameter(int line);
	bool isVariable(int line);
	Variable* getVariable(int line);
	int length();
	std::string const& getData(int line);
	std::string const& getData();
	void addFunction(std::string const& function);
	void removeFunction(std::string const& function);
	bool isFunction(int line);
	std::string const& getFunction(int line);
	bool containsFunction(std::string const& function);
	void append(std::string const& data);
	void addListener(Listener* listener);
	void removeListener(Listener* listener);
	std::vector<Listener*> const& listListener();
	
	StringUtils* getStringUtils(){
		if(this->strutils==NULL){
	    	return (this->strutils = new StringUtils(this->data));
		}else{
			return this->strutils;
		}
	}
	
};

#endif // INTERPRETER_H
