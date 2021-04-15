#include <iostream>
#include <string>
#include "./BitArray.h"

using namespace std;
int main() {

	// check if a string contains unique letters
	string name = "game";
	bool duplicate = false;
	BitArray b(256);
	for (size_t i = 0; i < name.length(); i++)
	{
		if (!b.check(name[i]))
			b.add(name[i]);
		else {
			duplicate = true;
			break;
		}
	}

	if (duplicate)
		cout << name << ": contains non-unique letters" << endl;
	else
		cout << name << ": contains unique letters" << endl;

	// Anagram check
	/*
	* Insert the ASCII representation of each letter in both strings into one BitArray, resetting a bit if that bit has previosly been set i.e if a character has been seen previously, reset it's bit
	* loop through the bit array, if any position has value greater than 0 then the two strings aren't anagrams
	*/
	string word1 = "bellow";
	string word2 = "below";
	BitArray A(256);
	bool is_anagram = true;
	if (word1.length() != word2.length()) {
		cout << "Not anagrams" << endl;
		return 0;
	}
	for (size_t i = 0; i < word1.length(); i++)
	{
		A.add(word1[i]);
	}
	for (size_t i = 0; i < word2.length(); i++)
	{
		if (A.check(word2[i]))
			A.remove(word2[i]);
		else
			A.add(word2[i]);
	}

	for (size_t i = 0; i < A.capacity; i++)
	{
		if (A[i] != 0) {
			is_anagram = false;
			break;
		}
	}
	cout << endl;
	if (is_anagram)
		cout << word1 << " and " << word2 << " are anagrams";
	else
		cout << word1 << " and " << word2 << " are not anagrams";
}	