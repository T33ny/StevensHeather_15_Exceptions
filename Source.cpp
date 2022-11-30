//Heather Stevens
//CIS 1202 R02
//11/28/2022
//Week 15 Exceptions

#include<iostream>
using namespace std;

class invalidCharacterException	//class name for invalid character exception
{

};
class invalidRangeException	//class name for invalid range exception
{

};


char character(char start, int offset);	//function prototype

int main()
{
	cout << character('a', 1) << endl;	//should return b
	cout << character('a', -1) << endl;	//return invalidRangeException
	cout << character('Z', -1) << endl;	//return Y
	cout << character('?', 5) << endl;	//invalidCharacterException
	cout << character('A', 32) << endl;	//exception


	system("pause");
	return 0;
}

char character(char s, int off)
{
	int ascii;	//holds asci value of char
	int target;	//holds value of offset char 

	ascii = int(s);	//calls char ascii value
	target = ascii + off;	//calulates the ascii value plus the offset 



	return target;
}
