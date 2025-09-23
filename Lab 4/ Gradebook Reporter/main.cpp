#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    ifstream inputFile("students.txt");
    
    if (!inputFile) {
        cout << "Error: Could not open students.txt file!" << endl;
        return 1;
    }
    
    string studentName;
    int score;
    
    while (getline(inputFile, studentName)) {
        int totalScore = 0;
        int scoreCount = 0;
        
        while (inputFile >> score && score != -1) {
            totalScore += score;
            scoreCount++;
        }
        
        double average = (scoreCount > 0) ? static_cast<double>(totalScore) / scoreCount : 0.0;
        
        char letterGrade;
        int gradeRange = static_cast<int>(average) / 10;
        
        switch (gradeRange) {
            case 10:
            case 9:
                letterGrade = 'A';
                break;
            case 8:
                letterGrade = 'B';
                break;
            case 7:
                letterGrade = 'C';
                break;
            case 6:
                letterGrade = 'D';
                break;
            default:
                letterGrade = 'F';
                break;
        }
        
        string status = (average >= 60) ? "PASS" : "FAIL";

        cout << setw(100) << studentName << " " << average << " " << letterGrade << " " << status << endl;
        
        inputFile.ignore();
    }
    
    inputFile.close();
    
    cout << "\nWould you like to save this report to a file? (y/n): ";
    char saveChoice;
    cin >> saveChoice;
    
    if (saveChoice == 'y' || saveChoice == 'Y') {
        ofstream outputFile("grade_report.txt");
        
        if (outputFile) {
            inputFile.open("students.txt");
            
            while (getline(inputFile, studentName)) {
                int totalScore = 0;
                int scoreCount = 0;
                
                while (inputFile >> score && score != -1) {
                    totalScore += score;
                    scoreCount++;
                }
                
                double average = (scoreCount > 0) ? static_cast<double>(totalScore) / scoreCount : 0.0;
                
                char letterGrade;
                int gradeRange = static_cast<int>(average) / 10;
                
                switch (gradeRange) {
                    case 10:
                    case 9:
                        letterGrade = 'A';
                        break;
                    case 8:
                        letterGrade = 'B';
                        break;
                    case 7:
                        letterGrade = 'C';
                        break;
                    case 6:
                        letterGrade = 'D';
                        break;
                    default:
                        letterGrade = 'F';
                        break;
                }
                
                string status = (average >= 60) ? "PASS" : "FAIL";
                
                outputFile << studentName << " " << average << " " << letterGrade << " " << status << endl;
                
                inputFile.ignore();
            }
            
            outputFile.close();
            inputFile.close();
            cout << "Report saved to grade_report.txt successfully!" << endl;
        } else {
            cout << "Error: Could not create output file!" << endl;
        }
    }
    
    cin.get();
    
    return 0;
}