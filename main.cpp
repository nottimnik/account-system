#include<iostream>
#include<fstream>
#include<map>
#include<vector>

//The file where all the accounts will be stored
std::ifstream fin("accounts.json");

//open the file in append mode
std::ofstream fout("accounts.json", std::ios_base::app);

class AcessManager {
    public:
        void SignUp() {

            //The username and the password the account will have
            std::string username, password;

            //We give instructions to the user on how to create the account
            std::cout << "\nCreate a new account:\n";
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;

            //Sets the given username and passwords as the eUsername and ePassword

            fout << username << " " << password << "\n";
        }

        void LoginIn() {

            //The username and the password that the user entered
            std::string username, password;

            //See if the user is loggedin or not
            bool loggedin = false;

            //We create the map with all the accounts and passwords
            create_vectors();

            //We give instructions to the user on how to log in the account
            std::cout << "\nLogin In your account:\n";
            std::cout << "Username: ";
            std::cin >> username; //the username that the user entered
            std::cout << "Password: ";
            std::cin >> password; //the password that the user entered

            int size = accounts_number(); //the number of the accounts
            
            //searches for a account that has the username, that the user entered
            for(int i = 0;i<size;++i) {
                if(username == usernames[i]) {
                    if(password == passwords[i]) {
                        std::cout << "Welcome, " + username + "! You sucessfully logged in your account.";
                        loggedin = true;
                        break;
                    }
                }
            }

            if(loggedin == false) {
                std::cout << "The Username or the Password that you have entered are wrong! Please try again.";
            }
        }

        //creates the usernames and the passwords vectors
        void create_vectors() {
            std::string username, password;
            while(fin>>username && fin>>password) {
                insert_username(username); //insert the username read from the file into the vector
                insert_password(password); //insert the password read from the file into the vector
            }
        }

        //returns the numbers of the accountts in the file
        int accounts_number() {
            return usernames.size();
        }

        //inserts a new element in the usernames vector
        void insert_username(std::string username) {
            usernames.push_back(username);
        }

        //inserts a new element in the passwords vector
        void insert_password(std::string password) {
            passwords.push_back(password);
        }

    private:

        std::vector <std::string> usernames; //all the usernames of the existing accounts
        std::vector <std::string> passwords; //all the passwords of the existing accounts

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
        AcessManagerObj.SignUp(); //Lets the user create a new account
    }
    else if(choice == 1) {
        AcessManagerObj.LoginIn();
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
            AcessManagerObj.SignUp(); //Lets the user create a account
        }
        else {
            AcessManagerObj.LoginIn();
        }
    }
    return 0;
}
