/*
 * Word.h
 *
 *  Created on: Dec 7, 2016
 *      Author: wwh160130
 */

#include "BinarySearchTree.h"
#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>
#include <algorithm>
#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#ifndef WORD_H_
#define WORD_H_

class Word {
public:
	Word(std::string a);
	Word();
	virtual ~Word();

	std::string getKey() const {
		return key;
	}



	bool operator==(const Word& rhs){

		return getKey() == rhs.getKey();
	}

	bool operator>(const Word& rhs){

			return getKey() > rhs.getKey();
		}

	bool operator<(const Word& rhs){

			return getKey() < rhs.getKey();
	}

private:
	std::string word;
	std::string key;

};





#endif /* WORD_H_ */
