
#include <iostream>
#include <string>
using namespace std;

const int notEnoughArguments = 5;
const int currentNotationIsNotANumber = 1;
const int destinationNotationIsNotANumber = 2;
const int currentNotationOutOfRange = 3;
const int destinationNotationOutOfRange = 4;
const int overflowTrouble = -1;
const int enteredNumberNotInCurrentNotation = -2;

bool isUnsignedIntegerNumber(string in)
{
	char ch;
	while (!in.empty())
	{
		ch = in.front();
		in.pop_back();
		if ('0' > ch or ch > '9')
		{
			return false;
		}
	}
	return true;
}

bool isNegative(string inputNumber)
{
	if ((inputNumber).front() == '-')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void removeMinus(string &inputNumber)
{
	inputNumber.erase(0, 1);
}

bool isSumGivesOverflow(long long a, long long b) {
	if (a > 0 && b > 0 && (LLONG_MAX - b < a) ||
		a < 0 && b < 0 && (LLONG_MIN - b > a)) {
		return true;
	}
	else 
	{
		return false;
	}
}

int CharToInt(char ch)
{
	switch (ch)
	{
	case '0': 
		return 0;
	case '1': 
		return 1;
	case '2': 
		return 2;
	case '3': 
		return 3;
	case '4': 
		return 4;
	case '5': 
		return 5;
	case '6': 
		return 6;
	case '7': 
		return 7;
	case '8': 
		return 8;
	case '9': 
		return 9;
	case 'A': 
		return 10;
	case 'B': 
		return 11;
	case 'C': 
		return 12;
	case 'D': 
		return 13;
	case 'E': 
		return 14;
	case 'F': 
		return 15;
	case 'G': 
		return 16;
	case 'H': 
		return 17;
	case 'I': 
		return 18;
	case 'J': 
		return 19;
	case 'K': 
		return 20;
	case 'L': 
		return 21;
	case 'M': 
		return 22;
	case 'N': 
		return 23;
	case 'O': 
		return 24;
	case 'P': 
		return 25;
	case 'Q': 
		return 26;
	case 'R': 
		return 27;
	case 'S': 
		return 28;
	case 'T': 
		return 29;
	case 'U': 
		return 30;
	case 'V': 
		return 31;
	case 'W': 
		return 32;
	case 'X': 
		return 33;
	case 'Y': 
		return 34;
	case 'Z': 
		return 35;
	default:
		return -1;
	}
}

char IntToChar(int number)
{
	switch (number)
	{
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	case 13:
		return 'D';
	case 14:
		return 'E';
	case 15:
		return 'F';
	case 16:
		return 'G';
	case 17:
		return 'H';
	case 18:
		return 'I';
	case 19:
		return 'J';
	case 20:
		return 'K';
	case 21:
		return 'L';
	case 22:
		return 'M';
	case 23:
		return 'N';
	case 24:
		return 'O';
	case 25:
		return 'P';
	case 26:
		return 'Q';
	case 27:
		return 'R';
	case 28:
		return 'S';
	case 29:
		return 'T';
	case 30:
		return 'U';
	case 31:
		return 'V';
	case 32:
		return 'W';
	case 33:
		return 'X';
	case 34:
		return 'Y';
	case 35:
		return 'Z';
	}
}

long long StringToDecimal(string inputNumber, int currentNotation)
{
	long long outputNumber = 0;
	int i = 0;
	while (!inputNumber.empty()) 
	{
		int nextCharValue = CharToInt(inputNumber.back());
		inputNumber.pop_back();

		if (nextCharValue < currentNotation)
		{
			long long nextAdder = nextCharValue * pow(currentNotation, i);

			if (isSumGivesOverflow(nextAdder, outputNumber))
			{
				return overflowTrouble;
			}
			else
			{
				outputNumber += nextAdder;
				i++;
			}
		}
		else
		{
			return enteredNumberNotInCurrentNotation;
		}
	}
	return outputNumber;
}


string DecimalToNotation(long long decNumber, int destinationNotation)
{
	string output = "";

	int powerPosition = 1;
	while (pow(destinationNotation, powerPosition) <= decNumber)
	{
		powerPosition++;
	}
	powerPosition--;
	while (powerPosition >= 0)
	{
		output += IntToChar(decNumber / pow(destinationNotation, powerPosition));
		decNumber %= (long)(pow(destinationNotation, powerPosition));
		powerPosition--;
	}
	return output;
}


int main(int argc, char* argv[])
{
	if (argc < 4) 
	{
		cout << "3 Arguments required\n";
		return notEnoughArguments;
	} 

	string strCurrNotation(argv[1]);
	string strDestNotation(argv[2]);
	string inputNumber(argv[3]);

	if (!isUnsignedIntegerNumber(strCurrNotation))
	{
		cout << "Current Notation must be a positive integer number\n";
		return currentNotationIsNotANumber;
	}
	if (!isUnsignedIntegerNumber(strDestNotation))
	{
		cout << "Destination Notation must be a positive integer number\n";
		return destinationNotationIsNotANumber;
	}

	int currentNotation = stoi(strCurrNotation);
	int destinationNotation = stoi(strDestNotation);

	if (2 > currentNotation or currentNotation > 36)
	{
		cout << "Current Notation Out Of Range 2-36\n";
		return currentNotationOutOfRange;
	}
	if (2 > destinationNotation or destinationNotation > 36)
	{
		cout << "Destination Notation Out Of Range 2-36\n";
		return destinationNotationOutOfRange;
	}

	if (isNegative(inputNumber))
	{
		removeMinus(inputNumber);
		cout << "-";
	}

	long long numberInDecimal = StringToDecimal(inputNumber, currentNotation);
	if (numberInDecimal == overflowTrouble)
	{
		cout << "Entered Number Range Out From LLong\n";
		return overflowTrouble;
	}
	else if (numberInDecimal == enteredNumberNotInCurrentNotation)
	{
		cout << "Entered Number In Another Notation\n";
		return enteredNumberNotInCurrentNotation;
	}
	else
	{
		cout << DecimalToNotation(numberInDecimal, destinationNotation) << endl;
		return 0;
	}
}
