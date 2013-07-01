/*
Define a QueueTp template.
Test it by creating a queue of pointers-to-Worker (as defined in Listing 14.10)
and using the queue in a program similar to that in Listing 14.12.
*/
#include "workermi.h"
#include "queuetp.h"

const int SIZE = 5;
const int range = 20; // simulate a range of employee answers, const value for rand(), provides random #s in range of 0 - range
bool passedexam(int answer); // answer = if matched by rand(), a worker is removed from queue and new one is added.

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    std::srand(std::time(0));

    Worker * in[SIZE]; // array of pointers to Worker based classes
    int ct;
    for (ct = 0; ct < SIZE; ct++) { // get input from user and store in Worker *
        char choice;
        cout << "Enter the employee category:\n"
             << "w: waiter s: singer "
             << "t: singing waiter q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL) {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice) {
        case 'w':
            in[ct] = new Waiter;
            break;
        case 's':
            in[ct] = new Singer;
            break;
        case 't':
            in[ct] = new SingingWaiter;
            break;
        }
        cin.get();
        in[ct]->Set(); // get information about chosen worker
    }

    // QUALITY ASSURANCE EMPLOYEE EXAM, uses pointers to workers : waiters, singers, and singingwaiters take mandatory exam
    // required for continued employment. Only 1 person can take exam at a time in manager's room.

    QueueTP<Worker *> exam(ct);
    Worker * out[SIZE];

    int total_exam_mins = 0;
    int empl_exam_mins = 1;
    int failed = 0;
    int passed = 0;
    int index = 0;
    bool correct_answer = false;

    // Time limit for exam = 10 mins, if employee can't provide correct answer within 10 mins, employee fails the exam.

    int timelimit = 10;

    while (!exam.isfull()) {
        exam.enqueue(in[index]);
        index++;
    }

    index = 0; // reset array index to 0

    cout << "\nThe number of employees taking exam: " << exam.queuecount() << ", Exam time limit = " << timelimit << " minutes." << endl;

    while (!exam.isempty()) {
        correct_answer = passedexam(10); // passedexam randomly generates a number and compares to answer(argument), true if equal

        if (correct_answer && (empl_exam_mins < timelimit) && !exam.isempty()) { // Passed if correct answer is generated
            // and within timelimit
            exam.dequeue(out[index]); // passed ? remove from queue, and move on to next employee
            cout << "\nPASSED! Employee [" << out[index]->Worker::Name() << ", " << out[index]->Worker::ID() // display info
                 << "], exam time: " << empl_exam_mins << "minutes.";
            empl_exam_mins = 1; // reset individual time of exam for the next employee
            index++;
            passed++; // increase Passed Employee count
        } else if (!correct_answer && (empl_exam_mins > timelimit) && !exam.isempty()) { // Failed if correct answer is not generated
            // within timelimit
            exam.dequeue(out[index]); // failed ? remove from queue and move on to the next employee
            cout << "\nFAILED! Employee [" << out[index]->Worker::Name() << ", " << out[index]->Worker::ID()
                 << "], exam time: " << empl_exam_mins << " minutes.";
            empl_exam_mins = 1;
            index++;
            failed++;
        } else if (!correct_answer && !exam.isempty()) // if correct answer is not generated and time is within the timelimit,
            empl_exam_mins++;                        // move on to the next cycle (minute) and try again to generate an answer

        total_exam_mins++;
    }
    // Final examination statistics
    cout << "\n\nTotal exam time: " << total_exam_mins << " minutes.";
    cout << "\nPassed: " << passed;
    cout << "\nFailed: " << failed;

    // Employee overview, doublechecking that Worker * array of pointers contains correct information and values
    cout << "\n\nEmployee overview: \n\n";
    for (int i = 0; i < ct; i++) {
        out[i]->Show(); // display info
        delete in[i]; // delete stored pointer objects
        cout << endl;
    }

    cout << "\nBye.";
    cin.get();
    cin.get();
    return 0;
}

bool passedexam(int answer) { // answer = if matched by rand(), a worker is removed from queue and new one is added.
    if ((std::rand() * range / RAND_MAX) == answer) // generate a random number influenced by range variable, and compare to answer
        return true; // return true if equal
    else
        return false; // false otherwise
}