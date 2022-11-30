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
class caseException	//class name for case exception
{

};

char character(char start, int offset);	//function prototype

int main()
{
	cout << character('a', 1) << endl;	//should return b
	cout << character('a', -1) << endl;	//return invalidRangeException
	cout << character('Z', -1) << endl;	//return Y
	cout << character('?', 5) << endl;	//invalidCharacterException
	cout << character('A', 32) << endl;	//case Exception


	system("pause");
	return 0;
}

char character(char s, int off)
{
	int ascii;	//holds asci value of char
	char target;	//holds value of offset char 

	ascii = int(s);	//calls char ascii value
	target = ascii + off;	//calulates the ascii value plus the offset 

try		//checks for valid char if it is upper or lower case alpha
	{
		if (ascii < 65 || ascii > 90 && ascii < 97 || ascii > 122)
		{
			throw invalidCharacterException();
		}		
		//checks if target is not upper or lower case alpha
		else if (target < 65 || (target > 90 && target < 97) || target > 122)
		{
			throw invalidRangeException();
		}
		//does not allow case conversion exception
		else if ((target >= 65 && target <= 90 && ascii >= 95 && ascii <= 122) ||
			(target >= 95 && target <= 122 && ascii >= 65 && ascii <= 90))
		{
			throw caseException();
		}
	}
	catch (invalidCharacterException e1)
	{
		cout << "ERROR! Invalid Character!" << endl;
		return ' ';
	}
	catch (invalidRangeException e2)
	{
		cout << "ERROR! Invalid Range!" << endl;
		return ' ';
	}
	catch (caseException e3)
	{
		cout << "ERROR! Case Changes prohibited!" << endl;
		return ' ';
	}

	return target;
}
