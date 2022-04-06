#include "header.hpp"

void Input::cleanCinBuffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Input::getUserInput(){
    Input::setWorkDayLen();
    Input::setClientProbability();
    Input::setReplAmount();
    Input::setReplFreq();
    Input::setSandwLimit();
    Input::setSandwPrice();
    //Input::setOutputType();
    return;
}

void Input::setWorkDayLen(){
    int temp=-1; // work day length in hours
    while(1){
        cout << "Enter the length of work day in hours" << endl;
        cin >> temp;
        if((cin && !cin.fail()) && (temp > 0 && temp <= 24)){
            workDayLen = temp*60;
            cleanCinBuffer();
            break;
        }
        cout << "ERROR - Enter positive integer number of hours not greater than 24" << endl;
        cleanCinBuffer();
    }
}

void Input::setClientProbability(){
    double temp = -1;
    while(1){
        cout << "Enter the probability that client will want to order a sandwitch at any time (between 0% to 100%)" << endl;
        cin >> temp;
        if((cin && !cin.fail()) && (temp > 0 && temp < 100)){
            clientProbability = temp;
            cleanCinBuffer();
            break;
        }
        cout << "ERROR - the floating point number should be between 0 and 100" << endl;
        cleanCinBuffer();
    }
}

void Input::setReplAmount(){
    int temp = -1;
    while(1){
        cout << "Enter the amount of new sandwicthes for every replenishment" << endl;
        cin >> temp;
        if((cin && !cin.fail()) && (temp > 0)){
            replAmount = temp;
            cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number must be a positive integer" << endl;
        cleanCinBuffer();
    }
}

void Input::setReplFreq(){
    int hours=-1, minutes=-1;
    cout << "Enter how frequently the sandwich are replenished in hours and minutes (integers)" << endl;
    while(1){
        cout << "Hours (to skip and go to minutes write 0):" << endl;
        cin >> hours;
        if((cin && !cin.fail()) && (hours >= 0 && hours <= Input::workDayLen)){
            replFreq = 60 * hours;
            cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of hours must be a positive integer and not greater than work day length" << endl;
        cleanCinBuffer();
    }
    while(1){
        cout << "minutes:" << endl;
        cin >> minutes;
        if((cin && !cin.fail()) && (minutes >= 0 && ceil((minutes/60)+hours) <= Input::workDayLen)){
            replFreq += minutes;
            Input::cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of minutes must be a positive integer and frequency must be greater than work day len" << endl;
        cleanCinBuffer();
    }
}

void Input::setSandwLimit(){
    int hours=-1, minutes=-1;
    cout << "Enter the maximum amount of time that a sandwich can be sold" << endl;
    while(1){
        cout << "Hours (to skip and go to minutes write 0):" << endl;
        cin >> hours;
        if((cin && !cin.fail()) && (hours >= 0 && hours <= workDayLen)){
            sandwLimit = 60 * hours;
            cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of hours must be a positive integer and not greater than work day length" << endl;
        cleanCinBuffer();
    }
    while(1){
        cout << "minutes:" << endl;
        cin >> minutes;
        if((cin && !cin.fail()) && (minutes >= 0 && ceil((minutes/60)+hours) <= workDayLen)){
            sandwLimit += minutes;
            cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of minutes must be a positive integer and frequency must be greater than work day len" << endl;
        cleanCinBuffer();
    }
}

void Input::setSandwPrice(){
    double temp = -1;
    while(1){
        cout << "Enter the price of a sandwitch" << endl;
        cin >> temp;
        if((cin && !cin.fail()) && (temp > 0)){
            sandwPrice = temp;
            cleanCinBuffer();
            break;
        }
        cout << "ERROR - input must be a positive floating point number" << endl;
        cleanCinBuffer();
    }
}

/*void Input::setOutputType(){
    cout << "What output would you like to get? Enter a corresponding digit (file would be stored in project directory)" << endl;
    cout << "   1 - console" << endl << "   2 - file" << endl << "   3 - console and file" << endl;
    int choice;
    bool success;
    while(!success){
        cin >> choice;
        cleanCinBuffer();
        switch (choice)
        {
        case 1:
            outputType = 1;
            success = true;
            break;
        case 2:
            outputType = 2;
            success = true;
            break;
        case 3:
            outputType = 3;
            success = true;
            break;
        default:
            cout << "ERROR - enter a correct integer (1, 2 or 3)" << endl;
            break;
        }
    }
    
}*/

int Input::getWorkDayLen(){ return workDayLen; }
double Input::getClientProbability(){ return clientProbability; }
int Input::getReplAmount(){ return replAmount; }
int Input::getReplFreq(){ return replFreq; }
int Input::getSandwLimit(){ return sandwLimit; }
double Input::getSandwPrice(){ return sandwPrice; }
int Input::getOutputType(){ return outputType; }