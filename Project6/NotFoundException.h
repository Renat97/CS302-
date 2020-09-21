//
// Created by Renat Norderhaug on 4/22/2018.
//

#ifndef PROJECT6_NOTFOUNDEXCEPTION_H
#define PROJECT6_NOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

class NotFoundException : public logic_error {
public:
    NotFoundException(const string &message = "");
};

#endif //PROJECT6_NOTFOUNDEXCEPTION_H
