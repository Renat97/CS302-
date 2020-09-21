The program compiles only in the c++ standard 11 library, you have to use -std=c++11 or just type "make" and the makefile should work. It is testing the requests in the "requestFile.txt" to see if they work for the flight routes given. 

Missing parts:
- incorrect printing out
- I tried debugging the "check path" method many times and added print statements to see how it works and it just won't add the cities to the map correctly. So the if case is never reached.