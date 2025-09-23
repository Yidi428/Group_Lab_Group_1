// File: mahmood.cpp

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;
int main() {
    int choice;
    int correct = 0, incorrect = 0;
    int user_answer=0;
    int quit=1;
    int a, b;
    
    while (quit!=0) {
        cout<<"Welcome to Mahmood's Calculator!"<<endl;
    cout<<"Please select an operation:"<<endl;
    cout<<"1) Addition"<<endl;
    cout<<"2) Subtraction"<<endl;
    cout<<"3) Multiplication"<<endl;
    cout<<"4) Division"<<endl;
    cout<<"5) Statistics (summary of performance)"<<endl;
    cout<<"6) Quit"<<endl;
        cout<<"Please select an operation:"<<endl;
        cin>>choice;
    switch(choice) {
        case 1: {
            while (user_answer != -999) {
            a=rand()%100;
            b=rand()%100;
            cout<<a<<" + "<<b<<" = ";
       
            cin>>user_answer;
            if(user_answer == a + b) {
                cout<<"Correct!"<<endl;
                correct++;
            } else {
                cout<<"Incorrect. The correct answer is "<<a + b<<endl;
                incorrect++;
            }
            cout<<"Enter -999 to stop or any number to continue: ";
            cin>>user_answer;
            }
            break;
        }
        case 2: {
            while (user_answer != -999) {
                a=rand()%100;
                b=rand()%100;
                cout<<a<<" - "<<b<<" = ";
                cin>>user_answer;
                if(user_answer == a - b) {
                    cout<<"Correct!"<<endl;
                    correct++;
                } else {
                    cout<<"Incorrect. The correct answer is "<<a - b<<endl;           
                    incorrect++;
                }
                cout<<"Enter -999 to stop or any number to continue: ";
                cin>>user_answer;
            }
            break;
        }
        case 3: {
            while (user_answer != -999) {
                a=rand()%20;
                b=rand()%20;
                cout<<a<<" * "<<b<<" = ";
                cin>>user_answer;
                if(user_answer == a * b) {
                    cout<<"Correct!"<<endl;
                    correct++;
                } else {
                    cout<<"Incorrect. The correct answer is "<<a * b<<endl;
                    incorrect++;
                }
                cout<<"Enter -999 to stop or any number to continue: ";
                cin>>user_answer;
            }
            break;
        }
        case 4: {
            while (user_answer !=-9999){
                a=rand()%100 + 1; // avoid division by zero
                b=rand()%10 + 1; // keep divisor small
                cout<<a<<" / "<<b<<" = ";
                cin>>user_answer;
                if(user_answer == a / b) {
                    cout<<"Correct!"<<endl;
                    correct++;
                } else {
                    cout<<"Incorrect. The correct answer is "<<a / b<<endl;
                    incorrect++;
                }
                cout<<"Enter -999 to stop or any number to continue: ";
                cin>>user_answer;       
            }
            break;
        }
        case 5: {
            int total = correct + incorrect;
            cout<<"Statistics:"<<endl;
            cout<<"Total Questions: "<<setw(10)<<total<<endl;
            cout<<"Correct Answers: "<<setw(10)<<correct<<endl;
            cout<<"Incorrect Answers: "<<setw(10)<<incorrect<<endl;
            if(total > 0) {
                cout<<"Accuracy: "<<setw(10)<<(correct * 100.0 / total)<<"%"<<endl;
            } else {
                cout<<"No questions answered yet."<<endl;
            }
            ofstream outfile;
            outfile.open("statistics.txt");
            
            outfile<<"Statistics:"<<endl;
            outfile<<"Total Questions: "<<setw(10)<<total<<endl;
            outfile<<"Correct Answers: "<<setw(10)<<correct<<endl;
            outfile<<"Incorrect Answers: "<<setw(10)<<incorrect<<endl;
            break;
        }
        case 6: {
            cout<<"Thank you for using . Goodbye!"<<endl;
            quit=0; 
            break;
        }
    
    } 
    cout<<"enter any number to restart or 0 to end program:"<<endl;
        cin>>quit;
}

    return 0;
}