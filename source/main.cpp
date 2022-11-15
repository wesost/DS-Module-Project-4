// Wes Ostlund
// cs-273-2 mp4
//
#include <iostream>
#include <fstream> // file i/o
#include <map> // using maps as associative data structure
#include <vector>

using std::string;
using std::cout;
using std::endl;

int main()
{

    std::map<string,int> numOccurences; // create a map with the key being a word and the stored value being the number of times that word occured
    std::map<int, std::vector<string>> wordOccured; // another map to hold a vector of words that occured int times

    std::ifstream openBook("meditations.txt"); // ifstream object to read from file

    if(openBook.fail()){ // make sure nothing went wrong 
        cout << "Error opening book. " << endl;
    }
    std::vector<string> allWords; // vector to hold every unique string in the book

    string word; // initialize a string to hold input
    while(openBook >> word) { // take in words from file
        
        if(numOccurences[word] >= 1) { // if the word has already appeared at least once
            numOccurences[word]++; // increment the number of times word has occured 
        } else {
            numOccurences[word] = 1; // if word hasn't been seen before, create a new "bucket" in the map for that word
            allWords.push_back(word); // and add the new word to the vector of all words
        }
    }

    for (int i = 0; i < allWords.size(); i++) // iterate through the vector holding all the words
    {                                                                   
        wordOccured[numOccurences[allWords[i]]].push_back(allWords[i]); // the word at position i is used as the key for numOccurences, the number
        // of occurences of that word is used as the key to the second data structure, mapping to a vector holding every word that
        // occured numOccurences[allWords[i]] times. The word to be added is pushed back to the mapped vector
    }

    int n;
    cout << "Enter a number to see which words occured that many times" << endl; // get user input
    std::cin >> n;

    cout << wordOccured[n].size() << " words occured " << n << " times! " << endl; // display how many words total occured n times
    cout << "They are: " << endl;
    cout << "-----" << endl;

    for (int i = 0; i<wordOccured[n].size(); i++){ // print out each word which occured n times
    cout << wordOccured[n][i] << "  ||  "; // wordOccured[n] gets the vector of words which occured n times, i accesses each word
    }
    
    cout << endl;
    cout << "-----" << endl;

    openBook.close(); // close the stream object we worked with
    return 0;
}