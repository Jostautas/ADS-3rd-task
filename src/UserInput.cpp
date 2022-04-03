#include "header.hpp"

using namespace std;

void Input::getUserInput(){
    Input::setClientProbability();
    return;
}

void Input::setClientProbability(){
    cout << "Enter the probability that client will want to order a sandwitch at any time (from 0% to 100%)" << endl;
    cin >> Input::clientProbability;
    return;
}

double Input::getClientProbability(){
    return Input::clientProbability;
}