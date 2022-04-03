#include "header.hpp"

using namespace std;

int main(){
    Input input;
    input.getUserInput();

    double temp = input.getClientProbability();

    cout << endl << "The probability is = " << temp << endl;
    return 0;
}