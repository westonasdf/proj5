/*
 * Word.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: wwh160130
 */

#include "Word.h"

Word::Word(){


}

Word::~Word() {
	// TODO Auto-generated destructor stub
}

Word::Word(std::string a){
	word = a;
	std::string temp = a;
	std::locale loc;
	// converts temp to lowercase
	for (std::string::size_type i=0; i<temp.length();i++)
	    std::tolower(temp[i],loc);

	std::sort(temp.begin(),temp.end());
	key = temp;
	std::cout << temp << "\n";

}









