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

bool login(string username, string password, string twoFactorCode) {
    string query = "SELECT * FROM users WHERE username = ? AND password = ?";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare(db, query.c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        cout << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return false;
    }

