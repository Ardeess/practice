#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;


string findLastWord(const string& str) {
    string lastWord;
    string currentWord;

    for (char ch : str) {
        if (isalpha(ch)) { 
            currentWord += tolower(ch); 
        }
        else if (!currentWord.empty()) {
            lastWord = currentWord;
            currentWord.clear();
        }
    }


    if (!currentWord.empty()) {
        lastWord = currentWord;
    }

    return lastWord;
}


vector<pair<char, int>> createFrequencyAlphabet(const string& text) {
    map<char, int> freqMap;

    for (char ch : text) {
        if (isalpha(ch)) { 
            char lowerCh = tolower(ch);
            freqMap[lowerCh]++;
        }
    }


    vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());


    sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
        });

    return freqVec;
}

int main() {
    setlocale(LC_ALL, "Russian");

    string testStr = "Hello, world! This is a test string.";
    string lastWord = findLastWord(testStr);
    cout << "Последнее слово в строке: " << lastWord << endl;


    ifstream fin("F1.txt");
    ofstream fout("F2.txt");

    if (!fin.is_open()) {
        cerr << "Не удалось открыть файл F1.txt" << endl;
        return 1;
    }

    if (!fout.is_open()) {
        cerr << "Не удалось открыть файл F2.txt" << endl;
        return 1;
    }

    string line;
    string fullText;


    while (getline(fin, line)) {
        fullText += line + " ";
    }


    vector<pair<char, int>> freqAlphabet = createFrequencyAlphabet(fullText);


    fout << "Частотный алфавит:" << endl;
    for (const auto& entry : freqAlphabet) {
        fout << entry.first << ": " << entry.second << endl;
    }

    fin.close();
    fout.close();

    cout << "Частотный алфавит успешно записан в файл F2.txt" << endl;

    return 0;
}