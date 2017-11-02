// Glenn Lumbert - COS 221 - HW 5

#include "stdafx.h"
#include <iostream>
#include <string>	//for use of strings
#include <vector>	//for use of vectors

using namespace std; 

void longest(string a);	//instantiation of the longest funtion which takes the string of numbers and prints the necessary info to console
int convChar(char x);	//handy function to convert characters to ints
int main()
{
	cout << "Glenn Lumbert - COS 221 - HW 5" << endl;
	string a;										//string to store our initial set of numbers
	while (1) {										//while loop to continually call the function
		cout << "Enter a string of numbers ending in 0" << endl;	//prompt for the user
		cin >> a;										
		longest(a);													//use of the longest function with our input string
	}
}

void longest(string a) {					//definition of our longest function
	vector<int> length(1);				//length vector to store our the length of each section of numbers
	vector<int> number(1);				//number vector to store each number which will correspond directly with length, they are set to size one to avoid errors
	int i, index = 0, lengtH = 1, placeholder = 0, startOfIndex=0;	//ints that we will need later. lengtH is the current length of the section of numbers we are reading
	for (i = 0; i < (a.length()-1); i++) {				//for loop that reads from 0 to the length of the string -1 since we have that 0 at the end. 
		 if (a[i] == a[i + 1]) {					//if two consecutive chars are the same in our string then this if statement will trigger. 
			 if (lengtH == 1) {		//length is the factor that determines if something is entered into the vector, since each new set of consecutive numbers
										//has only one entry this is to avoid overwriting an old entry
				 number.insert(number.begin() + index, a[i]);	//inserts a new number into our vector adding new memory
			 }
			 lengtH++;	//regardless of if a number is inserted we know the length is going to be increased(base of 2) because at minimum we have 2 in a row
		} else {
			if (lengtH <= 2) {	//the else is if the two numbers are not matching, similar to the length ==1 line this is to make sure numbers are inserted when necessary
				number.insert(number.begin() + index, a[i]);	//same insert funciton as before
			}
			length.insert((length.begin() + index), lengtH);	//length is only inserted when there is a difference identified
			lengtH = 1;			//once we have identified a difference and stored our length we reset the length
			index+=1;	//once we have identified the new section of numbers we increase our index variable so we can store the new length and number in the next spot in our vector
		}
	}
	for (index = 0; index < length.size() - 1; index++) {	//this for loop is for identifying which section is the longest by comparing the length of each of our length entries in our vector
		if ((length[index] == NULL) || number.at(index + 1) == 0) {}	//this is a base case so that if there is a null pointer or we have reached the end of our string we do not continue to compare
		else if((length.at(placeholder) < length.at(index + 1))) {	//placeholder base case is 0, if we find a longer length we replace our placeholder with that
			placeholder = (index+1);
		}
	}
	for (i = 0; i < placeholder; i++) {	//even though our placeholder found out how far in our longest string of numbers was we still need to calculate at what index of the 
		startOfIndex += length.at(i);	// whole string that is. so by adding every length of all entries before our desired vector section we find our index
	}

	cout << "The longest same number sequence starts at index " << startOfIndex << " with " << length[placeholder] << " values of " << convChar(number[placeholder]) << endl;
 }//above is the output of our function


int convChar(char x) {	//convChar function to convert the asci charatcer 0-9 to numbers. they are all 48 off from their true value.
	int y; 
	y = x - 48;
	return y; 
}
