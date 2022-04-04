#include "header.hpp"

using namespace std;

void Solve::cleanCinBuffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Solve::setHolder(){
    int temp=-1; // work day length in hours
    while(1){
        cout << "Enter number of sandwitch holders" << endl;
        cin >> temp;
        if((cin && !cin.fail()) && (temp > 0)){
            Solve::holder = temp;
            Solve::cleanCinBuffer();
            break;
        }
        cout << "ERROR - Enter positive integer" << endl;
        Solve::cleanCinBuffer();
    }
}

int Solve::getHolder(){ return Solve::holder; }