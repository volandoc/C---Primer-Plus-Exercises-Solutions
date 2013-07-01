/*
The Bank of Heather would like to know what would happen if it added a second ATM.
Modify the simulation in this chapter so that it has two queues.
Assume that a customer will join the first queue if it has fewer people in it than the second queue and that the customer will join the second queue otherwise.
Again, find a value for number of customers per hour that leads to an average wait time of one minute.

(Note:This is a nonlinear problem in that doubling the number of ATMs doesn't double the number of customers who can be handled per hour with a one minute wait maximum.)
*/

#include "queue.h"

const int MIN_PER_HR = 60;
bool newcustomer(double x); // is there a new customer?

int main() {
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
    Queue line1(qs); // line queue holds up to qs people
    Queue line2(qs);
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
    int wait_time1 = 0; // time until autoteller is free
    int wait_time2 = 0;
    long line_wait = 0; // cumulative time in line
    double averagewait = 0;
    // running the simulation, brute force method
    // since values for processing times are random it will take a while, on average 5-10 min of running this program, be patient
    // sometimes it finds value very fast, again, because it's random
    do {
        // reset all values for a new simulation loop
        Item temp;
        turnaways = 0; // turned away by full queue
        customers = 0; // joined the queue
        served = 0; // served during the simulation
        sum_line = 0; // cumulative line length
        wait_time1 = 0; // time until auto teller is free
        wait_time2 = 0;
        line_wait = 0; // cumulative time in line

        perhour = std::rand() % 120 + 1; // 120 people max per hour for 2 lines with 1 min of waiting (average),
        // higher numbers produce more randomness and longer time to find the average
        min_per_cust = MIN_PER_HR / perhour;

        for (int cycle = 0; cycle < cyclelimit; cycle++) {
            if (newcustomer(min_per_cust)) { // have newcomer
                if (line1.isfull() && line2.isfull()) // if both lines are full, customer will turn away
                    turnaways++;
                else {
                    customers++;
                    temp.set(cycle); // cycle = time of arrival
                    if (line1.queuecount() >= line2.queuecount()) // if line2 is longer than line2
                        line2.enqueue(temp); // then bring customer to line 2 since it's shorter
                    else
                        line1.enqueue(temp); // if otherwise, he'll join line 1
                }
            }
            if (wait_time1 <= 0 && !line1.isempty()) { // for line 1
                line1.dequeue (temp); // attend next customer
                wait_time1 = temp.ptime(); // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--;
            sum_line += line1.queuecount();

            if (wait_time2 <= 0 && !line2.isempty()) { // for line 2
                line2.dequeue (temp); // attend next customer
                wait_time2 = temp.ptime(); // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time2 > 0)
                wait_time2--;
            sum_line += line2.queuecount();
        }

        averagewait = (double) line_wait / served;
        cout << "\nAverage wait: " << averagewait << ", Customers served: " << served;

        if (averagewait > 0.999 && averagewait < 1.03) // value between 0.999 and 1.03 will be considered 1 min
            break;
    } while (perhour > 0);

    // reporting results
    if (customers > 0) {
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
    } else
        cout << "No customers!\n";

    cout << "Done!\n";
    cin.get();
    cin.get();
    return 0;
}
// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x) {
    return (std::rand() * x / RAND_MAX < 1);
}