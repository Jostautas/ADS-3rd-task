#include <iostream>
#include <limits>

class HelloWorld{
    public:
    void say();
};
class Input{
    private:
    double clientProbability;   // probability that a client will want a sandwith at any time (0-100%)
    int replAmount; // amount of new sandwitches for each replenishment
    double replFreq;    // how frequently sandwitches are being replenished (input minutes and hours, data stored in minutes)
    int sandwLimit; // longest time a sandwitch remains in market before it gets thrown out 
                                //                                          (input minutes and hours, data stored in minutes)
    int workDayLen; // lenght of the work day in hours


    public:
    void getUserInput();

    void setClientProbability();    
    void setReplAmount();  
    void setReplFreq();
    void setSandwLimit();
    void setSandwPrice();
    void setWorkDayLen();

    double getClientProbability();

};