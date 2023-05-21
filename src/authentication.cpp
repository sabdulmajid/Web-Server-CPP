#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>

using namespace std;

class User {
public:
    string username;
    string password;
    string twoFactorCode;
};

