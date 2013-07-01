/*
The Bank of Heather has performed a study showing that ATM customers won't wait more than one minute in line.

Using the simulation from Listing 12.10, find a value for number of customers per hour that leads to an average wait time of one minute.
(Use at least a 100-hour trial period.)
*/
#include "queue.h"

const int MIN_PER_HR = 60;
bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    // setting things up
    std::srand(std::time(0)); // random initializing of rand()
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs); // line queue holds up to qs people
    cout << "Enter the number of simulation hours: ";
    int hours; // hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles
    double perhour; // average # of arrival per hour
    double min_per_cust; // average time between arrivals

    //Item temp; // new customer data
    long turnaways = 0; // turned away by full queue
    long customers = 0; // joined the queue
    long served = 0; // served during the simulation
    long sum_line = 0; // cumulative line length
    int wait_time = 0; // time until auto teller is free
    long line_wait = 0; // cumulative time in line
    double averagewait = 0;
    // running the simulation, brute force method
    // since values for processing times are random it will take a while, on average 5-10 min of running this program, be patient
    // sometimes it finds value very fast, again, because it's random
    do
    {
        // reset all values for a new simulation loop
        Item temp;
        turnaways = 0; // turned away by full queue
        customers = 0; // joined the queue
        served = 0; // served during the simulation
        sum_line = 0; // cumulative line length
        wait_time = 0; // time until auto teller is free
        line_wait = 0; // cumulative time in line

        perhour = std::rand() % 60 + 1; // 60 people max per hour with 1 min of waiting (average)
        min_per_cust = MIN_PER_HR / perhour;

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust)) // have newcomer
            {
                if (line.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle); // cycle = time of arrival
                    line.enqueue(temp); // add newcomer to line
                }
            }
            if (wait_time <= 0 && !line.isempty())
            {
                line.dequeue (temp); // attend next customer
                wait_time = temp.ptime(); // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            sum_line += line.queuecount();
        }

        averagewait = (double) line_wait / served;
        cout << "\nAverage wait: " << averagewait << ", Customers served: " << served;
    }while (averagewait != 1.0);  // runs until average wait is 0, which may take up to 10 minutes of real life time to find
    //  also you can try averagewait > 0.99 and averagewait < 1.1
    // reporting results
    if (customers > 0)
    {
        cout << "\n\n############ V A L U E  F O U N D #######################" << endl; // Success!!
        cout << "customers accepted: " << customers << endl;
        cout << " customers served: " << served << endl;
        cout << " turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: "
            << averagewait << " minutes\n";
    }
    else
        cout << "No customers!\n";

    cout << "Done!\n";
    cin.get();
    cin.get();
    return 0;
}
// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}