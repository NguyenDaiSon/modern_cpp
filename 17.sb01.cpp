// Structured binding: since C++17
// Dai Son, NGUYEN < daisonit@gmail.com > 
#include <iostream>
#include <map>

int main() {
	using usmap = std::map<unsigned, std::string>;
	usmap cpp_standard {
		 {1998, "C++98"}
		,{2003, "C++03"}
		,{2011, "C++11"}
		,{2014, "C++14"}
		,{2017, "C++17"}
		,{2020, "C++20"}
	};

	std::cout << "C++ Standards:" << std::endl;
	for (const auto& [year, informal_name] : cpp_standard ) {
		std::cout << year 
			  << " " 
			  << informal_name 
			  << std::endl;
	}

	return 0;
}
