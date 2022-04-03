#include "header.hpp"

using namespace std;

void Input::getUserInput(){
    Input::setClientProbability();
    return;
}

void Input::setClientProbability(){
    double temp;
    while(1){
        cout << "Enter the probability that client will want to order a sandwitch at any time (between 0% to 100%)" << endl;
        cin >> temp;

        if((cin && !cin.fail()) && (temp > 0 && temp < 100)){ // validation
            Input::clientProbability = temp;
            break;
        }
        cout << "EEERRROOR" << endl;

        // clearing buffer:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    
    

    return;
}

void Input::setReplAmount(){

}


double Input::getClientProbability(){
    return Input::clientProbability;
}