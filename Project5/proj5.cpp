/*
 * File:   proj5.cpp
 * Author: renatnorderhaug
 *
 * Created on April 4, 2018, 11:55 PM
 */

#include <cstdlib>
#include "Event.h"
#include <sys/time.h>

#include "PriorityQueue.h"
#include "LinkedQueue.h"

using namespace std;


double get_wall_time() {
    struct timeval time;
    if (gettimeofday(&time, NULL)) {
        //  Handle error
        return 0;
    }
    return (double) time.tv_sec + (double) time.tv_usec * .000001;
}

double get_cpu_time() {
    return (double) clock() / CLOCKS_PER_SEC;
}

void processArrival(Event &event, PriorityQueue<Event> &pQueue, LinkedQueue<Event> &bQueue, bool &tellerAvailable,
                    int currentTime, int &queueLegth, int &maxQueueLegth) {

    pQueue.remove();

    Event customer = event;

    if (bQueue.isEmpty() && tellerAvailable) {
        int departureTime = currentTime + event.getLength();
        Event newDepartureEvent('D', departureTime, 0);
        pQueue.add(newDepartureEvent);
        tellerAvailable = false;
    } else {
        bQueue.enqueue(customer);
        queueLegth += 1;
        if (queueLegth > maxQueueLegth) { maxQueueLegth = queueLegth; }
    }
}

void processDeparture(Event &event, PriorityQueue<Event> &pQueue, LinkedQueue<Event> &bQueue,
                      bool &tellerAvailable, int currentTime,
                      int unsigned &wait, int &maxWait,
                      int &queueLength, int &maxQueueLength, int &minQueueLength, int idleTime) {
    pQueue.remove();
    if (!bQueue.isEmpty()) {
        Event customer = bQueue.peekFront();
        bQueue.dequeue();
        int departureTime = currentTime + customer.getLength();
        if (departureTime > customer.getTime()) {
            wait += (departureTime - customer.getTime());
        }
        //cout << "currentTime " << currentTime << endl;
        //cout << "customer arrival time " << customer.getLength() << endl;
        //cout << "customer departure time " << departureTime << endl;
        //cout << "waitTime " << wait << endl;
        Event newDepartureEvent('D', departureTime, 0);
        pQueue.add(newDepartureEvent);
        queueLength -= 1;
        if ((departureTime - customer.getTime()) > maxWait) { maxWait = (departureTime - customer.getTime()); }
        if (queueLength > maxQueueLength) { maxQueueLength = queueLength; }
        if (queueLength > minQueueLength) { minQueueLength = queueLength; }
    } else
        tellerAvailable = true;
        idleTime = currentTime - idleTime;
}

// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid) {
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k, temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;

    // Merge the two parts into temp[].
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            temp[k] = a[i];
            k++;
            i++;
        } else {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid) {
        temp[k] = a[i];
        k++;
        i++;
    }

    // Insert all the remaining values from j to high into temp[].
    while (j <= high) {
        temp[k] = a[j];
        k++;
        j++;
    }


    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }
}

// A function to split array into two parts.
void MergeSort(int *a, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        // Split the data into two half.
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);

        // Merge them to get sorted output.
        Merge(a, low, high, mid);
    }
}

void simulate() {

    LinkedQueue<Event> bankQueue;
    PriorityQueue<Event> eventListPQueue;

    int arriveTime;
    int transTime;
    int unsigned wait = 0;
    int queueLength = 0;
    int maxWait = 0;
    int maxQueueLength = 0;
    int minQueueLength = 0;
    int count = 0;
    int idleTime = 0;

    bool tellerAvailable = true;
    double processingTime = get_wall_time();
    double cpuTime = get_cpu_time();

    srand(time(NULL)); // to seed random numbers
    int i, arr[100000], temp, j, arraySize;
    arraySize = 100000;

    for (int i = 0; i < arraySize - 1; i++) {
        arr[i] = (rand() % 100000) + 1;
    }
    MergeSort(arr, 0, arraySize - 1);

    ofstream fout;
    fout.open("events.txt");

    for (int i = 0; i < 99999; i++) {
        fout << arr[i] << " " << (rand() % 100) + 1 << std::endl;
    }

    unsigned int tempTime; //temporary holders for cin input
    unsigned int tempLength;

    fout.close();

    ofstream logout;
    logout.open("output.log");
    logout << "Starting simulation with one queue one teller. " << endl;

    ifstream infile("events.txt");

    while (!infile.eof()) {

        infile >> arriveTime >> transTime;
        Event newArrivalEvent('A', arriveTime, transTime);
        //cout << "Read in " << newArrivalEvent << endl;
        eventListPQueue.add(newArrivalEvent);
        count++;
    }
    infile.close();

    while (!eventListPQueue.isEmpty()) {
        Event newEvent = eventListPQueue.peek();
        int currentTime = newEvent.getTime();
        logout << "Processing event " << newEvent.getType() << " at " << newEvent.getTime() << endl;

        if (newEvent.getType() == 'A') {
            processArrival(newEvent, eventListPQueue, bankQueue, tellerAvailable, currentTime,
                           queueLength, maxQueueLength);
        } else {
            processDeparture(newEvent, eventListPQueue, bankQueue, tellerAvailable, currentTime,
                             wait, maxWait, queueLength, maxQueueLength, minQueueLength, idleTime);
        }

    }
    processingTime = get_wall_time() - processingTime;
    cpuTime = get_cpu_time() - cpuTime;
    logout << "CPU time  " << cpuTime << " . " << endl;
    logout << "Processing time  " << processingTime << " . " << endl;
    logout << "Number of customers  " << count << " . " << endl;
    logout << "Max wait time is  " << maxWait << " . " << endl;
    logout << "Average wait time is  " << wait / count << " . " << endl;
    logout << "Max queue length is  " << maxQueueLength << " . " << endl;
    logout << "Average queue length is " << (maxQueueLength+minQueueLength) / 2 << " . " << endl;
    logout << "Idle time is " << idleTime << " . " << endl;

    logout.close();
}

int main() {
    simulate();

    //system("pause");
    return 0;
}

