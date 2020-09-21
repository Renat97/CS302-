//
///  main.cpp
///  Project 3
//
///  Created by Renat Norderhaug on 2/27/18.
///  Copyright © 2018 Renat Norderhaug. All rights reserved.
//
/* @file main.cpp
   @author Renat norderhaug
   @date 2/28/18
 */

/// main.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <list>
#include <stack>
#include "FlightMap.v2.cpp"

/// tester file for the Flightmap

int main() {
    ///declare pair variables
    std::pair<string, string> connection, request;
    /// object of class readfiles
    /// parameter: the names of the files it reads
    /// returns: the data inside the files
    /// pre: none
    ///post: files read
    ReadFiles rf("cityFile.txt", "flightFile.txt", "requestFile.txt");
    /// object of class map as datatype string
    Map<string> map(3);
    /// parameter: an integer value regarding what cities in map
    /// returns: the cities in the map
    /// pre: empty map
    ///post: cities from the files into the map
    map.SetV();
    /// while loop which sets flight paths in the adjacency list
    while (1) {
        /// assign the pair value
        connection = rf.getNamePair<string>();
        /// if end of file is reached
        if (connection.first == "stop")
            /// break the loop
            break;
        /// adds the edge onto the adjacency list
        map.addEdge(connection.first, connection.second);
    }
    /// the while loop to serve the requests
    while (1) {
        /// sets the request pair
        request = rf.getRequestPair<string>();
        /// if request is Empty
        if (request.first == "stop") {
            /// break loop
            break;
        }
        else {
        /// display the request
        cout << "\n Request is to fly from " << request.first << " to " << request.second << "\n";
        /// if first city is not in city list
        cout << request.first << endl;
        cout << request.second << endl;
        if (!map.checkCity(request.first)) {
            /// display the result
            cout << " Sorry. HPAir does not serve " << request.first << "\n";
        }
        /// if their is a path that exists
        else if (map.isPath(request.first, request.second))
            /// display result
            cout << "HPAir flies from" << request.first << " to " << request.second << "\n";
        /// if there is no path that exists
        else if (!map.isPath(request.first, request.second))
            /// display result
            cout << "Sorry, PAair does not fly from " << request.first << " to " << request.second << "\n";
    }
    }

    return 0;

}
