#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>

class StringUtils{
	private:
	std::string data;
	std::string currentIndexOf;
	public:
	
	~StringUtils();
	StringUtils(std::string const& data);
	std::vector<std::string> const& split(std::string const& delimiter);
	std::size_t indexOf(std::string const& input);
	bool contains(std::string const& input);
	//std::string const& substring(std::size_t x,std::size_t y);
	std::string const& substring(std::string const& x,std::string const& y);
	std::string const& substring(int x,std::string const& y);
	std::string const& substring(int x,int y);
	std::string const& replace(std::string const& input,std::string const& output);
	std::string const& getData();
	
	template <class T>
	static std::string const& toString(T const& object){
		std::stringstream ss;
    	ss << object;
    	return ss.str();
	}
	
	static int toInt(std::string const& data){
		return std::atoi(data.c_str());
	}
	
	static bool toBool(std::string const& data){
		if(data=="0") return false;
		else if(data=="false") return false;
		else if(data=="1") return true;
		else if(data=="true") return true;
		return false;
	}
	
};

#endif // STRINGUTILS_H
