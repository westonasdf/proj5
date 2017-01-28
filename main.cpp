#include "Word.cpp"
#include "Word.h"


void printWord(const Word& a){
	std::cout << "dd";
}

int main(){
	std::ifstream infile("english_words.txt”");
	BinarySearchTree<Word> dictionary;
	std::string a;
	while(infile>>a){
		Word newWord(a);
		dictionary.insert(newWord);
	}

	std::ifstream infile2("scambled_words.txt ");
	std::string b;
	bool found;
	while(infile>>b){
		Word newWord(b);
		dictionary.find(newWord,printWord);
	}

}
