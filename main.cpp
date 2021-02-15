#include <iostream>
using namespace std;

class LoginManager {
    public:
        string UserNameAttempt;
        string PasswordAttempt;
        LoginManager() {

        }
        void login() {
            cout << "You need to enter your password and username." << endl;
            cout << "Username: ";
            cin >> UserNameAttempt;
            cout << "Password: ";
            cin >> PasswordAttempt;

            if(UserNameAttempt == username && PasswordAttempt == password) {
                cout << "You sucessfully logged in your account.";
            }
            else {
                cout << "Error! The credentials that you've entered are wrong!";
                }
            }

    private:
        string username = "admin";
        string password = "password";
};

int main() {

    LoginManager LoginManagerObj;
    LoginManagerObj.login();

    return 0;
}