#include "header.hpp"

using namespace std;

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
            Input::workDayLen = temp;
            Input::cleanCinBuffer();
            break;
        }
        cout << "ERROR - Enter positive integer number of hours not greater than 24" << endl;
        Input::cleanCinBuffer();
    }
}

void Input::setClientProbability(){
    double temp = -1;
    while(1){
        cout << "Enter the probability that client will want to order a sandwitch at any time (between 0% to 100%)" << endl;
        cin >> temp;
        if((cin && !cin.fail()) && (temp > 0 && temp < 100)){
            Input::clientProbability = temp;
            Input::cleanCinBuffer();
            break;
        }
        cout << "ERROR - the floating point number should be between 0 and 100" << endl;
        Input::cleanCinBuffer();
    }
}

void Input::setReplAmount(){
    int temp = -1;
    while(1){
        cout << "Enter the amount of new sandwicthes for every replenishment" << endl;
        cin >> temp;
        if((cin && !cin.fail()) && (temp > 0)){
            Input::replAmount = temp;
            Input::cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number must be a positive integer" << endl;
        Input::cleanCinBuffer();
    }
}

void Input::setReplFreq(){
    int hours=-1, minutes=-1;
    cout << "Enter how frequently the sandwich are replenished in hours and minutes (integers)" << endl;
    while(1){
        cout << "Hours (to skip and go to minutes write 0):" << endl;
        cin >> hours;
        if((cin && !cin.fail()) && (hours >= 0 && hours <= Input::workDayLen)){
            Input::replFreq = 60 * hours;
            Input::cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of hours must be a positive integer and not greater than work day length" << endl;
        Input::cleanCinBuffer();
    }
    while(1){
        cout << "minutes:" << endl;
        cin >> minutes;
        if((cin && !cin.fail()) && (minutes >= 0 && ceil((minutes/60)+hours) <= Input::workDayLen)){
            Input::replFreq += minutes;
            Input::cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of minutes must be a positive integer and frequency must be greater than work day len" << endl;
        Input::cleanCinBuffer();
    }
}

void Input::setSandwLimit(){
    int hours=-1, minutes=-1;
    cout << "Enter the maximum amount of time that a sandwich can be sold" << endl;
    while(1){
        cout << "Hours (to skip and go to minutes write 0):" << endl;
        cin >> hours;
        if((cin && !cin.fail()) && (hours >= 0 && hours <= Input::workDayLen)){
            Input::sandwLimit = 60 * hours;
            Input::cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of hours must be a positive integer and not greater than work day length" << endl;
        Input::cleanCinBuffer();
    }
    while(1){
        cout << "minutes:" << endl;
        cin >> minutes;
        if((cin && !cin.fail()) && (minutes >= 0 && ceil((minutes/60)+hours) <= Input::workDayLen)){
            Input::sandwLimit += minutes;
            Input::cleanCinBuffer();
            break;
        }
        cout << "ERROR - the number of minutes must be a positive integer and frequency must be greater than work day len" << endl;
        Input::cleanCinBuffer();
    }
}

void Input::setSandwPrice(){
    double temp = -1;
    while(1){
        cout << "Enter the price of a sandwitch" << endl;
        cin >> temp;
        if((cin && !cin.fail()) && (temp > 0)){
            Input::sandwPrice = temp;
            Input::cleanCinBuffer();
            break;
        }
        cout << "ERROR - input must be a positive floating point number" << endl;
        Input::cleanCinBuffer();
    }
}

int Input::getWorkDayLen(){ return Input::workDayLen; }
double Input::getClientProbability(){ return Input::clientProbability; }
int Input::getReplAmount(){ return Input::replAmount; }
int Input::getReplFreq(){ return Input::replFreq; }
int Input::getSandwLimit(){ return Input::sandwLimit; }
double Input::getSandwPrice(){ return Input::sandwPrice; }