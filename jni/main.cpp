#include <iostream>
#include "utils/StringUtils.h"
#include "utils/FileUtils.h"
#include "interpreter/Interpreter.h"
#include "interpreter/Variable.h"

#define print(str) std::cout << str << std::endl;

class Listener : public Interpreter::Listener{
	public:
	virtual void onRun(Interpreter*parent,int line,std::string const& data);
};

void Listener::onRun(Interpreter*parent,int line,std::string const& data){
	
}

int main(){
	print((new Variable("bool test = 0;"))->getType_());
	Interpreter* interpreter = new Interpreter("bool isNull = true;");
	interpreter->addListener(new Listener());
	interpreter->append("log('10');");
	interpreter->append("file_create(sdcard/atatxt.txt);");
	interpreter->run();
	return 0;
}
