#include "header.hpp"

using namespace std;

int main(){
    Input input;
    input.getUserInput();

    cout << endl;
    cout << "workDayLen = " << input.getWorkDayLen() << endl;
    cout << "clientProbability = " << input.getClientProbability() << endl;
    cout << "replAmount = " << input.getReplAmount() << endl;
    cout << "replFreq = " << input.getReplFreq() << endl;
    cout << "SandwLimit = " << input.getSandwLimit() << endl;
    cout << "SandwPrice = " << input.getSandwPrice() << endl;

    Solve solve;
    
    return 0;
}