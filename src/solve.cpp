#include "header.hpp"

void Solve::solve(){
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

    solveBaseCase();
    solve1ExtraHolder();
    solve2ExtraHolders();
}

void Solve::solveBaseCase(){
    cout << "   BASE CASE:" << endl;
    t = 0;
    counter = replFreq-1;
    cout << "Time = 0000. Holder1 = 0. Holder2 = 0" << endl;
    do{
        ++counter;
        ++t;
        cout << "Time = " << setw(4) << setfill('0') << t << ". ";
        refresh(h1, t, 1);    // check if any sandwitches need to be thrown out
        refresh(h2, t, 2);
        if(counter == replFreq){
            replenish2(t);
            counter = 0;
        }
        client2();   // check if client wants to take a sandwitch
        cout << "Holder1 = " << h1.size() << ". Holder2 = " << h2.size() << endl;
        

    }while(t < workDayLen);

    printRes("Base case (2 holders, stack format)");
};

void Solve::solve1ExtraHolder(){
    t = 0;
    total = 0;
    sold = 0;
    thrown = 0;
    counter = replFreq-1;
    h1.clear();
    h2.clear();

    cout << endl << "   1 EXTRA HOLDER:" << endl;
    
    cout << "Time = 0000. Holder1 = 0. Holder2 = 0. Holder3 = 0" << endl;
    do{
        ++counter;
        ++t;
        cout << "Time = " << setw(4) << setfill('0') << t << ". ";
        refresh(h1, t, 1);    // check if any sandwitches need to be thrown out
        refresh(h2, t, 2);
        refresh(h3, t, 3);
        if(counter == replFreq){
            replenish3(t);
            counter = 0;
        }
        client3();   // check if client wants to take a sandwitch
        cout << "Holder1 = " << h1.size() << ". Holder2 = " << h2.size() << ". Holder3 = " << h3.size() << endl;
        

    }while(t < workDayLen);

    printRes("Change 1 (1 extra holder and queue format)");
}

void Solve::solve2ExtraHolders(){
    t = 0;
    total = 0;
    sold = 0;
    thrown = 0;
    counter = replFreq-1;
    h1.clear();
    h2.clear();
    h3.clear();

    cout << endl << "   2 EXTRA HOLDERS:" << endl;
    
    cout << "Time = 0000. Holder1 = 0. Holder2 = 0. Holder3 = 0. Holder4 = 0" << endl;
    do{
        ++counter;
        ++t;
        cout << "Time = " << setw(4) << setfill('0') << t << ". ";
        refresh(h1, t, 1);    // check if any sandwitches need to be thrown out
        refresh(h2, t, 2);
        refresh(h3, t, 3);
        refresh(h4, t, 4);
        if(counter == replFreq){
            replenish4(t);
            counter = 0;
        }
        client4();   // check if client wants to take a sandwitch
        cout << "Holder1 = " << h1.size() << ". Holder2 = " << h2.size() << ". Holder3 = " << h3.size() << ". Holder4 = " << h4.size() << endl;
        

    }while(t < workDayLen);

    printRes("Change 2 (2 extra holders and queue format)");
}

void Solve::replenish2(int t){
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

void Solve::replenish3(int t){
    int ran = rand() % 2 + 1;
    ran += rand() % 2; // random int from 1 to 3 included
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
        case 3:
            cout << "ACTION - 3rd holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h3.push_back(t);
            }
            break;
        default:
            cout << endl << "ERROR - error in replenishment()" << endl;
            break;
    }
}

void Solve::replenish4(int t){
    int ran = rand() % 2 + 1;
    ran += rand() % 2;
    ran += rand() % 2;  // random int [1, 4]
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
        case 3:
            cout << "ACTION - 3rd holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h3.push_back(t);
            }
            break;
        case 4:
            cout << "ACTION - 4th holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h4.push_back(t);
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

void Solve::client3(){
    double ran = (rand() % 100) + 1;
    if(clientProbability > ran){
        cout << "Clients wants a sandwitch. ";
        int ran = rand() % 2 + 1;
        ran += rand() % 2;
        cout << "He chose holder nr " << ran << ". ";
        switch (ran){
            case 1:
                if(h1.size() > 0){
                    h1.erase(h1.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                }
                break;
            case 2:
                if(h2.size() > 0){
                    h2.erase(h2.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                }
                break;
            case 3:
                if(h3.size() > 0){
                    h3.erase(h3.begin());
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

void Solve::client4(){
    double ran = (rand() % 100) + 1;
    if(clientProbability > ran){
        cout << "Clients wants a sandwitch. ";
        int ran = rand() % 2 + 1;
        ran += rand() % 2;
        ran += rand() % 2;
        cout << "He chose holder nr " << ran << ". ";
        switch (ran){
            case 1:
                if(h1.size() > 0){
                    h1.erase(h1.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                }
                break;
            case 2:
                if(h2.size() > 0){
                    h2.erase(h2.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                }
                break;
            case 3:
                if(h3.size() > 0){
                    h3.erase(h3.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                }
                break;
            case 4:
                if(h4.size() > 0){
                    h4.erase(h4.begin());
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