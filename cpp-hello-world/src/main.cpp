// #include <bits/stdc++.h>
// using namespace std;

// // Function to be run by the thread
// void func() {
//     cout << "Hello from the thread!" << endl;
// }

// int main() {
//     cout << "Main thread started." << endl;
    
//     // Create a thread that runs 
//     // the function func
//     thread t(func);
    
//     // Main thread waits for 't' to finish
//     t.join();  
//     cout << "Main thread finished." << endl;
//     return 0;
// }

// -------------------------------------------

#include <iostream>
#include <thread>
#include <chrono>
using namespace std; 

void task1() {
    cout << "Thread 1 is running. ID: " << this_thread::get_id() << "\n";
}

void task2() {
    cout << "Thread 2 is running. ID: " << this_thread::get_id() << "\n";
}

int main() {
    thread t1(task1);
    thread t2(task2);

    // Get thread IDs
    cout << "t1 ID: " << t1.get_id() << "\n";
    cout << "t2 ID: " << t2.get_id() << "\n";

    // Join t1 if joinable
    if (t1.joinable()) {
        t1.join();
        cout << "t1 joined\n";
    }

    // Detach t2
    if (t2.joinable()) {
        t2.detach();
        cout << "t2 detached\n";
    }

    cout << "Main thread sleeping for 1 second...\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Main thread awake.\n";

    return 0;
}
