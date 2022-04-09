#include "header.hpp"

void Solve::solve(){
    srand (time(NULL));

    Input input;
    bool choice = input.getChoice();

    if(choice == 0){
        input.getUserInput();
        workDayLen = input.getWorkDayLen();
        clientProbability = input.getClientProbability();
        replAmount = input.getReplAmount();
        replFreq = input.getReplFreq();
        sandwLimit = input.getSandwLimit();
        sandwPrice = input.getSandwPrice();

        fout.open("custom_result.txt");
        printFirstPart(fout);
        solveBaseCase(fout);
        solve1ExtraHolder(fout);
        solve2ExtraHolders(fout);
        fout.close();
    }
    else if(choice == 1){

        // average case:
        workDayLen = 1*60;
        clientProbability = 10;
        replAmount = 2;
        replFreq = 10;
        sandwLimit = 30;
        sandwPrice = 2;

        fout.open("average.txt");
        printFirstPart(fout);
        solveBaseCase(fout);
        solve1ExtraHolder(fout);
        solve2ExtraHolders(fout);
        fout.close();

        // worst case:
        workDayLen = 1*60;
        clientProbability = 2;
        replAmount = 5;
        replFreq = 10;
        sandwLimit = 30;
        sandwPrice = 4;

        fout.open("worst.txt");
        printFirstPart(fout);
        solveBaseCase(fout);
        solve1ExtraHolder(fout);
        solve2ExtraHolders(fout);
        fout.close();

        // best case:
        workDayLen = 1*60;
        clientProbability = 40;
        replAmount = 3;
        replFreq = 5;
        sandwLimit = 3*60;
        sandwPrice = 3;

        fout.open("best.txt");
        printFirstPart(fout);
        solveBaseCase(fout);
        solve1ExtraHolder(fout);
        solve2ExtraHolders(fout);
        fout.close();
    }
    else{
        cout << "ERROR - choice not correct in solve.cpp func void Solve::solve()" << endl;
    }
    
}

void Solve::solveBaseCase(ofstream &fout){
    cout << "   BASE CASE:" << endl;
    fout << "   BASE CASE:" << endl;
    t = 0;
    counter = replFreq-1;
    cout << "Time = 0000. Holder1 = 0. Holder2 = 0" << endl;
    fout << "Time = 0000. Holder1 = 0. Holder2 = 0" << endl;
    do{
        ++counter;
        ++t;
        cout << "Time = " << setw(4) << setfill('0') << t << ". ";
        fout << "Time = " << setw(4) << setfill('0') << t << ". ";
        refresh(h1, t, 1);    // check if any sandwitches need to be thrown out
        refresh(h2, t, 2);
        if(counter == replFreq){
            replenish2(t);
            counter = 0;
        }
        client2();   // check if client wants to take a sandwitch
        cout << "Holder1 = " << h1.size() << ". Holder2 = " << h2.size() << endl;
        fout << "Holder1 = " << h1.size() << ". Holder2 = " << h2.size() << endl;
        

    }while(t < workDayLen);


    firstSold = sold * sandwPrice;
    firstThrown = thrown * sandwPrice;

    printRes("Base case (2 holders, stack format)");
};

void Solve::solve1ExtraHolder(ofstream &fout){
    t = 0;
    total = 0;
    sold = 0;
    thrown = 0;
    counter = replFreq-1;
    h1.clear();
    h2.clear();

    cout << endl << "   1 EXTRA HOLDER:" << endl;
    fout << endl << "   1 EXTRA HOLDER:" << endl;
    
    cout << "Time = 0000. Holder1 = 0. Holder2 = 0. Holder3 = 0" << endl;
    fout << "Time = 0000. Holder1 = 0. Holder2 = 0. Holder3 = 0" << endl;
    do{
        ++counter;
        ++t;
        cout << "Time = " << setw(4) << setfill('0') << t << ". ";
        fout << "Time = " << setw(4) << setfill('0') << t << ". ";
        refresh(h1, t, 1);    // check if any sandwitches need to be thrown out
        refresh(h2, t, 2);
        refresh(h3, t, 3);
        if(counter == replFreq){
            replenish3(t);
            counter = 0;
        }
        client3();   // check if client wants to take a sandwitch
        cout << "Holder1 = " << h1.size() << ". Holder2 = " << h2.size() << ". Holder3 = " << h3.size() << endl;
        fout << "Holder1 = " << h1.size() << ". Holder2 = " << h2.size() << ". Holder3 = " << h3.size() << endl;

    }while(t < workDayLen);

    secondSold = sold * sandwPrice;
    secondThrown = thrown * sandwPrice;
    printRes("Change 1 (1 extra holder and queue format)");
}

void Solve::solve2ExtraHolders(ofstream &fout){
    t = 0;
    total = 0;
    sold = 0;
    thrown = 0;
    counter = replFreq-1;
    h1.clear();
    h2.clear();
    h3.clear();

    cout << endl << "   2 EXTRA HOLDERS:" << endl;
    fout << endl << "   2 EXTRA HOLDERS:" << endl;
    
    cout << "Time = 0000. Holder1 = 0. Holder2 = 0. Holder3 = 0. Holder4 = 0" << endl;
    fout << "Time = 0000. Holder1 = 0. Holder2 = 0. Holder3 = 0. Holder4 = 0" << endl;
    do{
        ++counter;
        ++t;
        cout << "Time = " << setw(4) << setfill('0') << t << ". ";
        fout << "Time = " << setw(4) << setfill('0') << t << ". ";
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
        fout << "Holder1 = " << h1.size() << ". Holder2 = " << h2.size() << ". Holder3 = " << h3.size() << ". Holder4 = " << h4.size() << endl;

    }while(t < workDayLen);

    printRes("Change 2 (2 extra holders and queue format)");

    printSummary();
}

void Solve::replenish2(int t){
    int ran = rand() % 2 + 1;
    switch(ran){
        case 1:
            cout << "ACTION - 1st holder got replenished. ";
            fout << "ACTION - 1st holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h1.push_back(t);
            }
            break;
        case 2:
            cout << "ACTION - 2nd holder got replenished. ";
            fout << "ACTION - 2nd holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h2.push_back(t);
            }
            break;
        default:
            cout << endl << "ERROR - error in replenishment()" << endl;
            fout << endl << "ERROR - error in replenishment()" << endl;
            break;
    }
}

void Solve::replenish3(int t){
    int ran = rand() % 2 + 1;
    ran += rand() % 2; // random int from 1 to 3 included
    switch(ran){
        case 1:
            cout << "ACTION - 1st holder got replenished. ";
            fout << "ACTION - 1st holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h1.push_back(t);
            }
            break;
        case 2:
            cout << "ACTION - 2nd holder got replenished. ";
            fout << "ACTION - 2nd holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h2.push_back(t);
            }
            break;
        case 3:
            cout << "ACTION - 3rd holder got replenished. ";
            fout << "ACTION - 3rd holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h3.push_back(t);
            }
            break;
        default:
            cout << endl << "ERROR - error in replenishment()" << endl;
            fout << endl << "ERROR - error in replenishment()" << endl;
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
            fout << "ACTION - 1st holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h1.push_back(t);
            }
            break;
        case 2:
            cout << "ACTION - 2nd holder got replenished. ";
            fout << "ACTION - 2nd holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h2.push_back(t);
            }
            break;
        case 3:
            cout << "ACTION - 3rd holder got replenished. ";
            fout << "ACTION - 3rd holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h3.push_back(t);
            }
            break;
        case 4:
            cout << "ACTION - 4th holder got replenished. ";
            fout << "ACTION - 4th holder got replenished. ";
            for(int i = 0; i < replAmount; ++i){
                ++total;
                h4.push_back(t);
            }
            break;
        default:
            cout << endl << "ERROR - error in replenishment()" << endl;
            fout << endl << "ERROR - error in replenishment()" << endl;
            break;
    }
}

void Solve::refresh(vector<int> &h, int t, int n){
    for(int i = 0; i < (int)h.size(); i++){
        if(sandwLimit < t - h.at(i)){
            h.erase(h.begin()+i);
            ++thrown;
            cout << "ACTION - a sandwitch has been thrown out of holder " << n << ". ";
            fout << "ACTION - a sandwitch has been thrown out of holder " << n << ". ";
        }
    }
}

void Solve::client2(){
    double ran = (rand() % 100) + 1;
    if(clientProbability > ran){
        cout << "Clients wants a sandwitch. ";
        fout << "Clients wants a sandwitch. ";
        int ran = rand() % 2 + 1;
        cout << "He chose holder nr " << ran << ". ";
        fout << "He chose holder nr " << ran << ". ";
        switch (ran){
            case 1:
                if(h1.size() > 0){
                    h1.erase(h1.end()-1);
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                    fout << "The chosen holder is empty. ";
                }
                break;
            case 2:
                if(h2.size() > 0){
                    h2.erase(h2.end()-1);
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                    fout << "The chosen holder is empty. ";
                }
                break;
            default:
                cout << "ERROR - client2 case not found. ";
                fout << "ERROR - client2 case not found. ";
                break;
        }
        
    }
}

void Solve::client3(){
    double ran = (rand() % 100) + 1;
    if(clientProbability > ran){
        cout << "Clients wants a sandwitch. ";
        fout << "Clients wants a sandwitch. ";
        int ran = rand() % 2 + 1;
        ran += rand() % 2;
        cout << "He chose holder nr " << ran << ". ";
        fout << "He chose holder nr " << ran << ". ";
        switch (ran){
            case 1:
                if(h1.size() > 0){
                    h1.erase(h1.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                    fout << "The chosen holder is empty. ";
                }
                break;
            case 2:
                if(h2.size() > 0){
                    h2.erase(h2.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                    fout << "The chosen holder is empty. ";
                }
                break;
            case 3:
                if(h3.size() > 0){
                    h3.erase(h3.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                    fout << "The chosen holder is empty. ";
                }
                break;
            default:
                cout << "ERROR - client2 case not found. ";
                fout << "ERROR - client2 case not found. ";
                break;
        }
        
    }
}

void Solve::client4(){
    double ran = (rand() % 100) + 1;
    if(clientProbability > ran){
        cout << "Clients wants a sandwitch. ";
        fout << "Clients wants a sandwitch. ";
        int ran = rand() % 2 + 1;
        ran += rand() % 2;
        ran += rand() % 2;
        cout << "He chose holder nr " << ran << ". ";
        fout << "He chose holder nr " << ran << ". ";
        switch (ran){
            case 1:
                if(h1.size() > 0){
                    h1.erase(h1.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                    fout << "The chosen holder is empty. ";
                }
                break;
            case 2:
                if(h2.size() > 0){
                    h2.erase(h2.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                    fout << "The chosen holder is empty. ";
                }
                break;
            case 3:
                if(h3.size() > 0){
                    h3.erase(h3.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                    fout << "The chosen holder is empty. ";
                }
                break;
            case 4:
                if(h4.size() > 0){
                    h4.erase(h4.begin());
                    ++sold;
                }
                else{
                    cout << "The chosen holder is empty. ";
                    fout << "The chosen holder is empty. ";
                }
                break;
            default:
                cout << "ERROR - client2 case not found. ";
                fout << "ERROR - client2 case not found. ";
                break;
        }
        
    }
}

void Solve::printFirstPart(ofstream &fout){
    fout << "Jostautas Sakas. 4 gr. 2 pogr. 3 uzd. 6 var." << endl << endl;
    fout << "-----------------------   FIRST PART   ------------------------" << endl << endl;
    fout << "Starting data:" << endl;
    fout << "   Work day length = " << workDayLen << " minutes" << endl;
    fout << "   Client probability = " << clientProbability << "%" << endl;
    fout << "   Replenishment amount = " << replAmount << endl;
    fout << "   Replenishment frequency = " << replFreq << " minutes" << endl;
    fout << "   Sandwitch time limit = " << sandwLimit << " minutes" << endl;
    fout << "   Sandwitch price = " << sandwPrice << " euros" << endl << endl;
    ifstream in;
    in.open("FirstPart.txt");
    if(in.is_open()){
        fout << in.rdbuf();
    }
    else{
        cout << "ERROR - cannot open FirstPart.txt in func Solve::printFirstPart(ofstream &fout)" << endl;
    }

    
}

void Solve::printRes(string str){
    cout << endl << "Results of " << str << " are:" << endl;
    cout << setw(4) << setfill(' ') << total * sandwPrice << " euros of sandwitches made." << endl;
    cout << setw(4) << setfill(' ') << sold * sandwPrice << " euros of sandwitches sold." << endl;
    cout << setw(4) << setfill(' ') << thrown * sandwPrice << " euros of sandwitches thrown away." << endl;

    fout << endl << "Results of " << str << " are:" << endl;
    fout << setw(4) << setfill(' ') << total * sandwPrice << " euros of sandwitches made." << endl;
    fout << setw(4) << setfill(' ') << sold * sandwPrice << " euros of sandwitches sold." << endl;
    fout << setw(4) << setfill(' ') << thrown * sandwPrice << " euros of sandwitches thrown away." << endl;
}

void Solve::printSummary(){
    cout << endl << "-----------------------   THIRD PART (summary)   ------------------------" << endl;
    cout << "2 holders and stack format - sold sandwitches = " << setw(3) << setfill(' ') << firstSold << ", thrown sandwitches = " << setw(3) << setfill(' ') << firstThrown <<
                                                        ". Profit = " << setw(3) << setfill(' ') << (firstSold - firstThrown) * sandwPrice << " euros" << endl;
    cout << "3 holders and queue format - sold sandwitches = " << setw(3) << setfill(' ') << secondSold << ", thrown sandwitches = " << setw(3) << setfill(' ') << secondThrown <<
                                                        ". Profit = " << setw(3) << setfill(' ') << (secondSold - secondThrown) * sandwPrice << " euros" << endl;
    cout << "4 holders and queue format - sold sandwitches = " << setw(3) << setfill(' ') << sold << ", thrown sandwitches = " << setw(3) << setfill(' ') << thrown <<
                                                        ". Profit = " << setw(3) << setfill(' ') << (sold - thrown) * sandwPrice << " euros" << endl;


    fout << endl << "-----------------------   THIRD PART (summary)   ------------------------" << endl;
    fout << "2 holders and stack format - sold sandwitches = " << setw(3) << setfill(' ') << firstSold << ", thrown sandwitches = " << setw(3) << setfill(' ') << firstThrown <<
                                                        ". Profit = " << setw(3) << setfill(' ') << (firstSold - firstThrown) * sandwPrice << " euros" << endl;
    fout << "3 holders and queue format - sold sandwitches = " << setw(3) << setfill(' ') << secondSold << ", thrown sandwitches = " << setw(3) << setfill(' ') << secondThrown <<
                                                        ". Profit = " << setw(3) << setfill(' ') << (secondSold - secondThrown) * sandwPrice << " euros" << endl;
    fout << "4 holders and queue format - sold sandwitches = " << setw(3) << setfill(' ') << sold << ", thrown sandwitches = " << setw(3) << setfill(' ') << thrown <<
                                                        ". Profit = " << setw(3) << setfill(' ') << (sold - thrown) * sandwPrice << " euros" << endl;
}