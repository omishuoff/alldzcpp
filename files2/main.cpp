#include <iostream>
#include <string>
#include "filter.h"

using namespace std;

int main() {
    string inputFile, wordsFile, outputFile;

    cin >> inputFile;
    cin >> wordsFile;
    cin >> outputFile;

    filterFile(inputFile, wordsFile, outputFile);

    return 0;
}