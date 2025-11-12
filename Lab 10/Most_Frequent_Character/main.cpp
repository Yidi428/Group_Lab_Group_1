#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

void mostFrequentCharacter(char* cstr) {
    vector<char> charCollection;
    vector<int> charOccurrence;
    for (int i = 0; i < strlen(cstr); i++) {
        char current = cstr[i];
        bool found = false;
        for (int j = 0; j < charCollection.size(); j++) {
            if (charCollection[j] == current) {
                charOccurrence[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            charCollection.push_back(current);
            charOccurrence.push_back(1);
        }
    }

    int max = 0;
    for (int i = 1; i < charOccurrence.size(); i++) {
        if (charOccurrence[i] > charOccurrence[max]) {
            max = i;
        }
    }
    cout << "Most frequent character: " << charCollection[max] << endl;
}

int main() {
    string str;
    
    cout << "Enter a word that's less than 100 characters (no spaces. Ex. 'Banana' not 'Banana Banana'): ";
    
    cin >> str;
    
    int size = str.length();
    
    char word[size];
    
    strcpy(word, str.c_str());
    
    mostFrequentCharacter(word);
    
    return 0;
}