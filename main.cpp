#include<iostream>
#include<fstream>
#include<map>

//The file where all the accounts will be stored
std::ifstream fin("accounts.json");

//open the file in append mode
std::ofstream fout("accounts.json", std::ios_base::app);

class AcessManager {
    public:
        void SignUp() {

            //The username and the password the account will have
            std::string username, password;

            //We give instroctions to the user on how to create the account
            std::cout << "\nCreate a new account:\n";
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;

            //Sets the given username and passwords as the eUsername and ePassword
            set_eUsername(username);
            set_ePassword(password);

            fout << username << " " << password << "\n";
        }

        void LoginIn() {

        }

        void set_eUsername (std::string Username) {
            eUsername = Username;
        }

        void set_ePassword (std::string Password) {
            ePassword = Password;
        } 

    private:
        std::map <std::string, std::string> accounts;
        
        //The username and password entered by the user
        std::string eUsername;
        std::string ePassword;

};

int main() {
    
    //The class that we will use to log in/sign up
    AcessManager AcessManagerObj;

    //Message that we will print to give the user instructions
    std::cout << "Choose what you want to do:\n";
    std::cout << "0. Sign Up\n";
    std::cout << "1. Login In\n";

    /*
    We let the user choose if he wants to signup or login
    0. SignUp
    1. LoginIn
    */

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if(choice == 0) {
        AcessManagerObj.SignUp();
    }
    else if(choice == 1) {
        std::cout << "Log In!\n";
    }

    //While the user enters a invalid choice we will notice him and give him another chance to choose
    else {

        //While error = true it means that the user entered a invalid choice
        bool error = true;
        while(error == true) {

            //Message that we will print to give the user instructions
            std::cout << "\nError! You've entered a invalid choice, please enter 0 or 1:\n";
            std::cout << "0. Sign Up\n";
            std::cout << "1. Login In\n";

            //We let the user choice another time
            std::cout << "\nEnter your choice: ";
            std::cin >> choice;

            //Check if the choice is valid or not
            if(choice == 1 || choice == 0) {
                error = false;
            }
        }

        /*
        If the user enters a valid choice, the while loop will stop and we will verify what choice he has made
        */

        if(choice == 0) {
            std::cout << "Sign Up!\n";
        }
        else {
            std::cout << "Login In!\n";
        }
    }
}
