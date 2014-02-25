/*
 * Author: Ryan Dougherty
 *
 * Description:
 Disemvoweling means removing the vowels from text. (For this challenge, the letters a, e, i, o, and u are considered vowels, 
 and the letter y is not.) The idea is to make text difficult but not impossible to read, for when somebody posts something 
 so idiotic you want people who are reading it to get extra frustrated.
 
 To make things even harder to read, we'll remove spaces too. For example, this string:
 two drums and a cymbal fall off a cliff
 can be disemvoweled to get:
 twdrmsndcymblfllffclff
 We also want to keep the vowels we removed around (in their original order), which in this case is:
 ouaaaaoai
 
 * Formal Inputs & Outputs
 
 * Input Description:
 A string consisting of a series of words to disemvowel. It will be all lowercase (letters a-z) and without punctuation. The 
 only special character you need to handle is spaces.
 
 * Output Description:
 Two strings, one of the disemvoweled text (spaces removed), and one of all the removed vowels.
 
 * Sample Input:
 all those who believe in psychokinesis raise my hand
 
 * Sample Output:
 llthswhblvnpsychknssrsmyhnd
 aoeoeieeioieiaiea
 
 *
 */

#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

bool find_vowel(const std::string&);

const std::string vowels = "aeiouAEIOU ";

int main()
{
    string str, out = "";
    getline(cin, str);
    size_t found = find_vowel(str);
    while (found!=string::npos) {
        if(str[found] != ' ')
            out += str[found];
        str.erase(found, 1);
        found = find_vowel(str);
    }
    cout << str << endl << out <<endl;
	
    cin.get();
    return 0;
}

bool find_vowel(const std::string& str) {
	return str.find_first_of(vowels);
}