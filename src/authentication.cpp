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

    rc = sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) {
        cout << "Error binding username: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    rc = sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_TRANSIENT);
    if (rc != SQLITE_OK) {
        cout << "Error binding password: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        cout << "User not found" << endl;
        return false;
    }

    // User found, check two-factor code
    string storedTwoFactorCode = sqlite3_column_text(stmt, 3);
    if (storedTwoFactorCode != twoFactorCode) {
        cout << "Invalid two-factor code" << endl;
        return false;
    }

    // User authenticated, return true
    return true;
}


