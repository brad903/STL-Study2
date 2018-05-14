#include "ThePalindrome.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s = "qwerty";
	ThePalindrome palidrome;
	cout << palidrome.find(s) << '\n';

	return 0;
}
