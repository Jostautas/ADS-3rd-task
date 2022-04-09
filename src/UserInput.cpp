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
        cout << "Enter the amount of new sandwitches for every replenishment" << endl;
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
        if((cin && !cin.fail()) && hours >= 0){
            replFreq = 60 * hours;
            cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of hours must be a positive integer" << endl;
        cleanCinBuffer();
    }
    while(1){
        cout << "minutes:" << endl;
        cin >> minutes;
        if((cin && !cin.fail()) && minutes >= 0){
            replFreq += minutes;
            Input::cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of minutes must be a positive integer" << endl;
        cleanCinBuffer();
    }
}

void Input::setSandwLimit(){
    int hours=-1, minutes=-1;
    cout << "Enter the maximum amount of time that a sandwich can be sold" << endl;
    while(1){
        cout << "Hours (to skip and go to minutes write 0):" << endl;
        cin >> hours;
        if((cin && !cin.fail()) && hours >= 0){
            sandwLimit = 60 * hours;
            cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of hours must be a positive integer" << endl;
        cleanCinBuffer();
    }
    while(1){
        cout << "minutes:" << endl;
        cin >> minutes;
        if((cin && !cin.fail()) && minutes >= 0){
            sandwLimit += minutes;
            cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of minutes must be a positive integer" << endl;
        cleanCinBuffer();
    }
}

void Input::setSandwPrice(){
    double temp = -1;
    while(1){
        cout << "Enter the price of a sandwitch in euros" << endl;
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

bool Input::getChoice(){
    cout << "How would you like to handle input (enter corresponding number):" << endl;
    cout << "'0' - cutom input" << endl;
    cout << "'1' - 3 calculations - worst, best, average case" << endl;

    bool temp;
    while(1){
        cin >> temp;
        if(cin && !cin.fail() && (temp == 0 || temp == 1)){
            cleanCinBuffer();
            return temp;
        }
        else{
            cout << "ERROR - Enter 1 or 0" << endl;
            cleanCinBuffer();
        }
    }
}

int Input::getWorkDayLen(){ return workDayLen; }
double Input::getClientProbability(){ return clientProbability; }
int Input::getReplAmount(){ return replAmount; }
int Input::getReplFreq(){ return replFreq; }
int Input::getSandwLimit(){ return sandwLimit; }
double Input::getSandwPrice(){ return sandwPrice; }