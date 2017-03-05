#include <iostream>
#include "utils/StringUtils.h"
#include "utils/FileUtils.h"
#include "interpreter/Interpreter.h"

#define print(str) std::cout << str << std::endl;

int main(){
	Interpreter* interpreter = new Interpreter("bool isNull = true;");
	interpreter->setListener(new Interpreter::Listener());
	interpreter->append("log('10');");
	interpreter->append("file_create('10');");
	interpreter->run();
	
	return 0;
}
