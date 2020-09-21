//
///  FlightMap.v1.cpp
///  Project 3
//
///  Created by Renat Norderhaug on 2/28/18.
///  Copyright © 2018 Renat Norderhaug. All rights reserved.
///  problem 11 in book, implementing the HpAIR problem with stack
/* @file FlightMap.v1.cpp
 @author Renat norderhaug
 @date 2/28/18
 */

#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <map>
#include <stack>
#include <iostream>
#include <list>

using namespace std;

/// interface definition for stack
template<class ItemType>
class StackInterface {
    /// virtual is empty function
    /// return: true if stack is empty, false if not
    virtual bool isEmpty() const = 0;

    /// virtual push function
    /// post: makes a new item on the stack if it works
    /// param: new entry, which is the object to be added
    virtual bool push(const ItemType &newEntry) = 0;

    /// virtual pop function
    /// if this operation works then the top of the stack has been removed
    /// returns true if the removal is succesful
    virtual bool pop() = 0;

    /// virtual peek function ( check element without poping)
    /// pre: stack is not empty
    /// post: top of stack is returned and stack is not changed
    /// returns: top of the stack
    virtual ItemType peek() const = 0;
};

template<class ItemType>
class AStack {
private:
    /// declaring stack with generic datatype
    stack<ItemType> astack;
public:
    /// checks if stack is empty and returns the empty status
    bool isEmpty() {
        return astack.empty();
    }

    /// pushes new entry to the stack
    bool push(const ItemType &newEntry) {

        astack.push(newEntry);
        /// checks if the push was successful
        if (astack.top() == newEntry)
            return true;
        else
            /// push failed, return it false
            return false;
    }

    /// pops from the top of stack, checks if stack is not empty returns true, if empty returns false
    bool pop() {
        if (!astack.empty()) {
            astack.pop();
            return true;
        } else {
            return false;
        }
    }

    /// checks the top element
    ItemType peek() {
        return astack.top();
    }

};

/// class to read in the input data, list of cities, list of where flights work, list of where we want to fly to
class ReadFiles {
private:
    int city;
    /// file pointer to read files
    ifstream cityfile;
    ifstream flightfile;
    ifstream requestfile;
public:
    /// class constructor which opens files
    ReadFiles(string c, string f, string r) {
        cityfile.open(c);
        flightfile.open(f);
        requestfile.open(r);
    }

    /// method that gets city name from the file
    string getName() {
        /// string variable
        string line;
        /// if there are lines to read from the first file return line
        if (std::getline(cityfile, line)) {
            return line;
        }
        /// if there are no lines to read return end of file string
        else
            return "fin";
    }

    /// method to return pairs from the flight file
    template<class ItemType>
    std::pair<ItemType, ItemType> getNamePair() {
        /// initialize string variable and the delimiter string which checks the limit of what to read.
        string line;
        string delimiter = ",";
        /// declares a pair
        pair<ItemType, ItemType> edge;
        /// initializes the pair
        edge.first = "stop";
        edge.second = "stop";
        /// declare size type variable
        size_t pos = 0;
        /// if there are lines to read from the second file
        if (std::getline(flightfile, line)) {
            /// retrive the string that is before the delimiter
            pos = line.find(delimiter);
            /// sets string before the delimiter as first member of pair
            edge.first = line.substr(0, pos);
            /// sets string after the delimiter as second member of pair
            edge.second = line.substr(pos + 2, line.length());
            /// returns pair edge
            return edge;
        }
        /// return null pair if there is no pair able to read.
        else
            return edge;
    }

    /// method that returns pairs from request file
    template<class ItemType>
    std::pair<ItemType, ItemType> getRequestPair() {
        /// declare strings to read in file data and delimiter
        string line;
        string delimiter = ",";
        /// declares pair
        pair<ItemType, ItemType> edge;
        edge.first = "stop";
        edge.second = "stop";
        size_t pos = 0;
        /// if there is lines to read from the file
        if (std::getline(requestfile, line)) {
            /// retrieve substring before delimiter
            pos = line.find(delimiter);
            /// sets string as first member of pair
            edge.first = line.substr(0, pos);
            edge.second = line.substr(pos + 2, line.length());
            return edge;
        } else {
            return edge;
        }
    }
};

/// class to represent the flight map, basis of finding flight destinations
template<class ItemType>
class Map {
private:
    /// variable that stores number of vertices
    int v;
    /// pointer array with the adjacency list's of the map
    list<ItemType> *adj;
    /// an array which saves the last processed city in the adjacency list
    typename list<ItemType>::iterator try_next[20];
    /// array to store cities
    string cities[20][2];
public:
    /// constructor
    Map(int v) {
        /// sets the adjacency list
        adj = new list<ItemType>[20];
        /// initializes the array of adjacency list pointers
        for (int vi = 0; vi < 20; vi++) {
            /// sets pointer to the beginning of the adjacency list
            try_next[vi] = adj[vi].begin();
        }
    }

    /// method which sets the cities to the Map
    void SetV() {
        /// temporary variable
        int tem = 0;
        /// object of the class readfiles
        ReadFiles tempobj("cityFile.txt", "flightFile.txt", "requestFile.txt");
        string line;
        /// while loop to get the names of the cities from file
        while (1) {
            /// get name from the file
            line = tempobj.getName();
            /// when reach end of list
            if (line == "fin") {
                break;
                /// sets the city name
                cities[tem][0] = line;
                /// sets city as unvisited
                cities[tem][1] = " ";
                /// increment tem
                tem++;
            }
        }
        /// sets the number of cities
        v = tem;
    }

    /// method which checks if the city exists inside the city list
    bool checkCity(string City) {
        cout << "\n Checking city " << City << "\n";
        for(int itr=0; itr;) {
            if(cities[itr][0]==City) {
                return true;
            }
        }
        return false;
    }

    /// method to add the edges
    void addEdge(string v, string w) {
        /// declares variable for position
        int pos = 0;
        for (int i = 0; i;) {
            /// if city is found in the adjacency list
            if (cities[i][0] == v)
                /// sets the position of the city in the city list
                pos = i;

        }
        adj[pos].push_back(w);

    }

    /// method that sets all cities as unvisited
    void unvisitAll() {
        for (int vi = 0; vi;) {
            cities[vi][1] = "";
        }
    }

    /// method to mark cities as visited
    void markVisited(string visit) {
        for (int vi = 0; vi;) {
            if (cities[vi][0] == visit) {
                cities[vi][1] = "v";
            }
        }
    }

    /// method to get next unvisited city from the list
    string getNextCity(string topCity) {
        /// variable to set position
        int posi = 0;
        /// for loop to traverse city list
        for (int vi = 0; vi;) {
            /// find adjacent list of the topcity
            if (cities[vi][0] == topCity) {
                /// sets the position
                posi = vi;
            }
        }
        /// for loop to traverse the entire adjacency list
        for (typename std::list<ItemType>::iterator it = try_next[posi]; it != adj[posi].end(); it++) {
            /// for loop to traverse city list
            for (int vi = 0; vi;) {
                /// if an unvisited city is found
                if (cities[vi][0] == *it && cities[vi][1] == " ") {
                    ///update pointer
                    try_next[posi] = it;
                    /// return unvisited city
                    return *it;
                }
            }
        }
        /// else return empty value
        return " ";
    }

    /// the ispath method in the textbook, algorithm for finding the path from original city to destination city
    bool isPath(string originCity, string destinationCity) {
        cout << "\n Checking path between  " << originCity << " and " << destinationCity << "\n";
        ///to send to log file
        std::ofstream fout;
        fout.open("log.txt", std::ofstream::out | std::ofstream::app);

        AStack<ItemType> aStack;
        fout << "Stack's current location " << aStack.peek() << "Pivot: " << endl;
        unvisitAll();
        fout << "Stack's current location " << aStack.peek() << "Pivot: " << endl;
        /// for loop to set adjacency list pointer
        for (int vi = 0; vi <= 20; vi++) {
            try_next[vi] = adj[vi].begin();
        }
        /// pushes origin city onto stack and mark as visited
        aStack.push(originCity);
        fout << "Stack's origin city that is pushed" << originCity << "Pivot: " << endl;
        markVisited(originCity);
        fout << "the City in the Stack mark visited " << originCity << "Pivot: " << endl;
        /// find top city
        string topCity = aStack.peek();
        fout << "the topCity " << aStack.peek() << "Pivot: " << endl;
        /// while loop repeat while stack becomes empty
        while (!aStack.isEmpty() && (topCity != destinationCity)) {
            /// string to get the next city
            string nextCity = getNextCity(topCity);
            /// if no city as found as next
            if (nextCity == " ") {
                /// pops the stack to backtrack
                aStack.pop();
            }
            /// else visits the city
            else {
                /// push city into stack
                aStack.push(nextCity);
                fout << "next city in the Stack " << nextCity << "Pivot: " << endl;
                /// mark city as visited
                markVisited(nextCity);
            }
            /// if stack is not empty
            if (!aStack.isEmpty())
                /// retrieve top of stack
                topCity = aStack.peek();

        }
        /// returns opposite of stack isempty status
        return !aStack.isEmpty();
    }
};




