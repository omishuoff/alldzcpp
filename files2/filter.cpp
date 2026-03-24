#include "filter.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void filterFile(const string& inputFile, const string& wordsFile, const string& outputFile) {
    ifstream badWordsStream(wordsFile);
    vector<string> badWords;
    string word;

    while (badWordsStream >> word) {
        badWords.push_back(word);
    }
    badWordsStream.close();

    ifstream inStream(inputFile);
    ofstream outStream(outputFile);
    string line;

    while (getline(inStream, line)) {
        stringstream ss(line);
        string currentWord;
        bool first = true;

        while (ss >> currentWord) {
            bool isBad = false;
            for (size_t i = 0; i < badWords.size(); ++i) {
                if (currentWord == badWords[i]) {
                    isBad = true;
                    break;
                }
            }

            if (!isBad) {
                if (!first) {
                    outStream << " ";
                }
                outStream << currentWord;
                first = false;
            }
        }
        outStream << endl;
    }

    inStream.close();
    outStream.close();
}