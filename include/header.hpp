#include <iostream>
#include <limits>
#include <math.h>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

class Input{
    private:
    int workDayLen; // lenght of the work day in minutes
    double clientProbability;   // probability that a client will want a sandwith at any time (0-100%)
    int replAmount; // amount of new sandwitches for each replenishment
    int replFreq;    // how frequently sandwitches are being replenished (in minutes)
    int sandwLimit; // longest time a sandwitch remains in market before it gets thrown out (in minutes)
    double sandwPrice;

    public:
    void cleanCinBuffer();

    void getUserInput();

    bool getChoice();   // 0 - user enter starting data manualy. 1 - 3 prewritten case are run automatically.

    void setWorkDayLen();
    void setClientProbability();
    void setReplAmount();  
    void setReplFreq();
    void setSandwLimit();
    void setSandwPrice();

    int getWorkDayLen();
    double getClientProbability();
    int getReplAmount();
    int getReplFreq();
    int getSandwLimit();
    double getSandwPrice();
};

class Solve{
    private:
    int workDayLen;
    double clientProbability;
    int replAmount;
    int replFreq;
    int sandwLimit;
    double sandwPrice;
    int firstSold, firstThrown, secondSold, secondThrown;

    vector<int> h1; // holder 1
    vector<int> h2;
    vector<int> h3;
    vector<int> h4;
    int t;     // current time in minutes
    int counter;    // time since the last replenishment
    int sold=0;    // total amount of sandwitches sold
    int thrown=0;      // amount of sandwitches thrown away
    int total=0;     // total amount of sandwitches made

    public:
    void solve();
    void solveBaseCase(ofstream &fout);
    void solve1ExtraHolder(ofstream &fout);
    void solve2ExtraHolders(ofstream &fout);

    void replenish2(int time);  // time - exact time that sandwitch has been put up
    void replenish3(int time);  // time - exact time that sandwitch has been put up
    void replenish4(int time);  // time - exact time that sandwitch has been put up

    void refresh(vector<int> &h, int time, int n);  // refresh sandwitches, throw out old ones. time - current time. n - number of holder
    void client2();      // check if client wants a sandwitch (from 2 holders)
    void client3();
    void client4();
    void printFirstPart(ofstream &fout);
    void printRes(string str);
    void printSummary();

    ofstream fout;
};