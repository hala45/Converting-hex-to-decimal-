// Hala Basyouni >> LAB #5 CSC326 02/20/2020
/*
This program is taking hexadecimal values(string) as an input from a file, converting each value(char) in it into decimal and then adding all the hex numbers and printing out the sum in decimal

The output would look like:

The original hexadecimal value: AAB
The number in hex: A have a decimal value of: 10
The number in hex: A have a decimal value of: 10
The number in hex: B have a decimal value of: 11
The sum in decimal: 2731
Press any key to continue . . .


*/
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<cstring>

using namespace std;

//functions prototypes
int sum(string c);
int convert(char c);

//main starts here
int main() {

	string nameFile;
	ifstream input;
	int result;
	int sum1;
	int size;
	char c;
	//open input file
	input.open("numbers.txt");
	//checking if the file opens
	if (input.fail()) {
		cerr << "Error opening the file..." << endl;
	}
	//initializing a variable for the string 
	string numberToConvert;
	//getting the string from the file 
	input >> numberToConvert;
	//outputting the original string (all the hex numbers)
	cout << "The original hexadecimal value: " << numberToConvert << endl;
	//size is the length of the string which contains all the hex numbers
	size = numberToConvert.length();
	//looping to get each number in the string 
	for (int i = 0; i < size; i++) {
		c = numberToConvert[i];
		//converting each number into its decimal form 
		result = convert(c);
		//printing each number(char) in hex and then it decimal form 
		cout << "The number in hex: " << c << " have a decimal value of: " << result << endl;
	}

	//This calls the function sum to convert all the numbers and add them and print out the sum in decimal 
	sum1 = sum(numberToConvert);
	//printing out the sum in decimal 
	cout << " The sum in decimal: " << sum1 << endl;

	system("pause");
	return 0;

}
//returning the sum in decimal by using the convert function
int sum(string c) {
	int length = c.length();
	int i, sum = 0;
	int x = 0;
	for (i = length - 1; i >= 0; i--) {
		sum = sum + pow(16, i)*convert(c[x]);
		x++;
	}
	return sum;
}
//switch cases to convert each hex number to decimal
int convert(char c) {
	switch (c) {
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	case 'A':
		return 10;
		break;
	case 'B':
		return 11;
		break;
	case 'C':
		return 12;
		break;
	case 'D':
		return 13;
		break;
	case 'E':
		return 14;
		break;
	case 'F':
		return 15;
		break;
	}
}

