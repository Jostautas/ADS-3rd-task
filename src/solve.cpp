#include "header.hpp"

void Solve::solveBaseCase(){
    srand (time(NULL));

    Input input;
    input.getUserInput();
    workDayLen = input.getWorkDayLen();
    clientProbability = input.getClientProbability();
    replAmount = input.getReplAmount();
    replFreq = input.getReplFreq();
    sandwLimit = input.getSandwLimit();
    sandwPrice = input.getSandwPrice();
    outputType = input.getOutputType();

    t = 0;
    counter = replFreq-1;
    cout << "Time = 0000. Holder1 = 0. Holder 2 = 0" << endl;
    do{
        ++counter;
        ++t;
        cout << "Time = " << setprecision(4) << t << ". ";
        refresh(h1, t, 1);    // check if any sandwitches need to be thrown out
        refresh(h2, t, 2);    // check if any sandwitches need to be thrown out
        if(counter == replFreq){
            replenish(t);
            counter = 0;
        }
        client2();   // check if client wants to take a sandwitch
        cout << "Holder1 = " << h1.size() << ". Holder 2 = " << h2.size() << endl;
        

    }while(t < workDayLen);

    printRes("Base case (2 holder, stack format)");
};

void Solve::solve1ExtraHolder(){
    srand (time(NULL));

    Input input;
    input.getUserInput();
    workDayLen = input.getWorkDayLen();
    clientProbability = input.getClientProbability();
    replAmount = input.getReplAmount();
    replFreq = input.getReplFreq();
    sandwLimit = input.getSandwLimit();
    sandwPrice = input.getSandwPrice();
    outputType = input.getOutputType();

    t = 0;
    counter = replFreq-1;
    cout << "Time = 0000. Holder1 = 0. Holder 2 = 0" << endl;
    do{
        ++counter;
        ++t;
        cout << "Time = " << setprecision(4) << t << ". ";
        refresh(h1, t, 1);    // check if any sandwitches need to be thrown out
        refresh(h2, t, 2);    // check if any sandwitches need to be thrown out
        if(counter == replFreq){
            replenish(t);
            counter = 0;
        }
        client2();   // check if client wants to take a sandwitch
        cout << "Holder1 = " << h1.size() << ". Holder 2 = " << h2.size() << endl;
        

    }while(t < workDayLen);

    printRes("Change 1 (1 extra holder and queue format)");
}

void Solve::replenish(int t){
    int ran = rand() % 2 + 1;
    switch(ran){
        case 1:
            cout << "ACTION - 1st holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h1.push_back(t);
            }
            break;
        case 2:
            cout << "ACTION - 2nd holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h2.push_back(t);
            }
            break;
        default:
            cout << endl << "ERROR - error in replenishment()" << endl;
            break;
    }
}

void Solve::refresh(vector<int> &h, int t, int n){
    for(int i = 0; i < (int)h.size(); i++){
        if(sandwLimit < t - h.at(i)){
            h.erase(h.begin()+i);
            ++thrown;
            cout << "ACTION - a sandwitch has been thrown out of holder " << n << ". ";
        }
    }
}

void Solve::client2(){
    double ran = (rand() % 100) + 1;
    if(clientProbability > ran){
        cout << "Clients wants a sandwitch. ";
        int ran = rand() % 2 + 1;
        cout << "He chose holder nr " << ran << ". ";
        switch (ran){
            case 1:
                if(h1.size() > 0){
                    h1.erase(h1.end()-1);
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                }
                break;
            case 2:
                if(h2.size() > 0){
                    h2.erase(h2.end()-1);
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                }
                break;
            default:
                cout << "ERROR - client2 case not found. ";
                break;
        }
        
    }
}

void Solve::printRes(string str){
    cout << endl << "Results of " << str << " are:" << endl;
    cout << "   " << total * sandwPrice << " euros of sandwitches made." << endl;
    cout << "   " << sold * sandwPrice << " euros of sanwitches sold." << endl;
    cout << "   " << thrown * sandwPrice << " euros of sandwitches thrown away." << endl;
}