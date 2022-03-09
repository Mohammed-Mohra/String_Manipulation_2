
#include "Header.h"


using namespace HomeMadeString;


String::String() {
	this->pData = NULL;
	this->elementNum = 0;
}
String::String(const String& other) {
	elementNum = other.elementNum;
	pData = new char[elementNum];
	for (int i = 0;i < elementNum;i++) {
		pData[i] = other.pData[i];
	}
}
String::String(const char* str) {
	for (int i = 0;i < 5000;i++) {
		if (str[i] == '\0') {
			elementNum = i;
			break;
		}}
	pData = new char[elementNum];
	for (int i = 0;i < elementNum;i++)
		pData[i] = str[i];
}
String::String(char letter, int times) {
	elementNum = times;
	pData = new char[elementNum];
	for (int i = 0;i < elementNum;i++)
		pData[i] = letter;
}
String::~String() {
	delete[] pData;
	//free (pData);
	elementNum = 0;

}
void String::getStr(char* pbuff) {
	for (int i = 0;i < elementNum;i++)
		pbuff[i] = pData[i];
	pbuff[elementNum] = '\0';
}


char String::getChar(int POS) {
	if ( POS>= this->elementNum || POS < 0)
		return 0;
	else
		return pData[POS];
}
String String::concatenate(String string1, String string2){
	String sum;
	sum.elementNum = string1.elementNum + string2.elementNum;
	sum.pData = new char[sum.elementNum];
	for (int i = 0;i < string1.elementNum;i++) 
		sum.pData[i] = string1.pData[i];
	for (int i = 0;i < string2.elementNum;i++)
		sum.pData[string1.elementNum+i] = string2.pData[i];

		return sum;
}


void String::copy(String& string1, String string2) {
	if (string1.pData != NULL) {
		delete[] string1.pData;
		//free(string1.pData);
	}
	string1.elementNum = string2.elementNum;
	string1.pData = new char[string1.elementNum];
	for (int i = 0;i < string1.elementNum;i++)
		string1.pData[i] = string2.pData[i];
}

void String::print(std::ostream& os) {
	for (int i = 0;i < elementNum;i++)
		os << pData[i];
}
bool String::compare(String string1, String string2) {
	if (string1.elementNum != string2.elementNum)
		return false;
	for (int i = 0;i < string1.elementNum;i++) {
		if (string1.pData[i] != string2.pData[i])
			return false;
	}
	return true;
}




