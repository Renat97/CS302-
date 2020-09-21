/*
 * File:   Event.h
 * Author: Renat Norderhaug
 *
 * Created on April 4, 2018, 11:05 PM
 */
// event class that stores the arriving and departure events

#ifndef EVENT_H
#define EVENT_H

#include <fstream>
#include <string>
#include <iostream>


using namespace std;

class Event {
private:
    char type;
    int time;
    int length;

public:
    char getType();

    int getTime();

    int getLength();

    Event(char t, int time, int length);

    friend bool operator>(const Event &e1, const Event &e2);

    friend bool operator<(const Event &e1, const Event &e2);

    friend bool operator==(const Event &e1, const Event &e2);

    friend ostream &operator<<(ostream &out, Event &e);
};

Event::Event(char tp, int tm, int l) {
    type = tp;
    time = tm;
    length = l;
}

char Event::getType() {
    return type;
}

int Event::getTime() {
    return time;
}

int Event::getLength() {
    return length;
}

bool operator>(const Event &e1, const Event &e2) {
    return e1.time > e2.time;
}

bool operator<(const Event &e1, const Event &e2) {
    return e1.time < e2.time;
}

bool operator==(const Event &e1, const Event &e2) {
    return e1.time == e2.time;
}

ostream &operator<<(ostream &out, Event &e) {
    out << e.type << " " << e.time << " " << e.length;
    return out;
}

#endif // EVENT_H
