// Homework 7.cpp : Defines the entry point for the console application.
//Glenn Lumbert- COS 221 - HW 7 

#include "stdafx.h"
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std; 
void sepWords(string, LinkedList<string>&);
void printList(LinkedList<string>&);

int main()
{
	LinkedList<string> list;
	cout << "Glenn Lumbert -COS 221 - HW 7" << endl;
	cout << "This is the beginning string: " << endl;
	string input = "DURING the whole of a dull, dark, and soundless day in the autumn of the year, when the clouds hung oppressively low in the heavens, I had been passing alone, on horseback, through a singularly dreary tract of country; and at length found myself, as the shades of the evening drew on, within view of the melancholy House of Usher.";
	sepWords(input, list);	//turn our sentence into a collection of words
	printList(list);	//print out the linked list
	sepWords(input, list);	//since our printlist function deletes our list we have to redo our linkedlist
	cout << "Removing of: ....." << endl;	
	list.remove("of");		//remove the word of from that
	printList(list);	//print the new linked list without of
}

void sepWords(string input, LinkedList<string>& list) {
	int i, length, index=0, wordSize =0;
	string temp; 
	for (i = 0; i < input.size(); i++) {
		if (!isalpha(input.at(i)) && !isspace(input.at(i))) {
			input.erase(i, 1);
		}
	} //punctuation removed
	length = input.size(); //size after punctuation erase
	input.insert(input.end(), char(32));	//inserts a space at the end so the following code works:
	for (i = 0; i < input.size()-1; i++) {
		temp.insert(temp.begin() + index, input.at(i));	//inserts character into temp string to make words
		index++;	//increments the index so it doesnt replace the characters already inserted
		wordSize++;	//records the length of the word
		if (isspace(input.at(i + 1))) {	//tests if next character is a space
			list.add(temp);			//add whatever is in the temp string to the list
			index = 0;	//reset index
			input.erase(0, 1);	//erase the space so we don't add it to our next words
			temp.erase(0, wordSize);	//clear the temp string
			wordSize = 0;	//reset wordsize
		}
	}

}

void printList(LinkedList<string>& list) {	//print function for LinkedList
	
	int i, end = list.getSize();
	for (i = 0; i<end; i++) {	//for loop to print out the list
		cout << list.getFirst() << " "; 
		list.removeFirst();
	} cout << endl; 
	
}