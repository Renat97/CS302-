//
// Created by Renat Norderhaug on 4/22/2018.
//

#ifndef PROJECT6_PRECONDVIOLATEDEXCEP_H
#define PROJECT6_PRECONDVIOLATEDEXCEP_H


#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error {
public:
    PrecondViolatedExcep(const string &message = "");
};

#endif //PROJECT6_PRECONDVIOLATEDEXCEP_H
