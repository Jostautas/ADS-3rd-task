#include <iostream>
#include <limits>
#include <math.h>

class Input{
    private:
    int workDayLen; // lenght of the work day in hours
    double clientProbability;   // probability that a client will want a sandwith at any time (0-100%)
    int replAmount; // amount of new sandwitches for each replenishment
    int replFreq;    // how frequently sandwitches are being replenished (in minutes)
    int sandwLimit; // longest time a sandwitch remains in market before it gets thrown out (in minutes)
    double sandwPrice;


    public:
    void cleanCinBuffer();

    void getUserInput();

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
    int holder = 2; // number of sandwitch holders

    public:
    void cleanCinBuffer();

    void setHolder();

    int getHolder();
};