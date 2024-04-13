#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class User {
public:
    std::string name;
    std::string gender;
    std::string interests;

    User(const std::string& name, const std::string& gender, const std::string& interests)
        : name(name), gender(gender), interests(interests) {}
};

class DatingApp {
private:
    std::vector<User> users;

public:
    void addUser(const std::string& name, const std::string& gender, const std::string& interests) {
        users.push_back(User(name, gender, interests));
    }

    void matchUsers(const User& currentUser) {
        std::vector<User> matches;

        for (const auto& user : users) {
            if (user.gender != currentUser.gender && user.interests == currentUser.interests) {
                matches.push_back(user);
            }
        }

        if (matches.empty()) {
            std::cout << "No matches found for " << currentUser.name << "." << std::endl;
            return;
        }

        std::cout << "Matches for " << currentUser.name << ":" << std::endl;
        for (const auto& match : matches) {
            std::cout << "- " << match.name << " (" << match.gender << ")" << std::endl;
        }
    }

    void displayMenu() {
        std::cout << "Dating App Menu:" << std::endl;
        std::cout << "1. Add User" << std::endl;
        std::cout << "2. Match Users" << std::endl;
        std::cout << "3. Exit" << std::endl;
    }

    void run() {
        int choice;
        std::string name, gender, interests;

        while (true) {
            displayMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Enter name: ";
                    std::cin >> name;
                    std::cout << "Enter gender: ";
                    std::cin >> gender;
                    std::cout << "Enter interests: ";
                    std::cin >> interests;
                    addUser(name, gender, interests);
                    break;
                case 2:
                    std::cout << "Enter your name: ";
                    std::cin >> name;
                    std::cout << "Enter your gender: ";
                    std::cin >> gender;
                    std::cout << "Enter your interests: ";
                    std::cin >> interests;
                    matchUsers(User(name, gender, interests));
                    break;
                case 3:
                    std::cout << "Exiting..." << std::endl;
                    return;
                default:
                    std::cout << "Invalid choice! Try again." << std::endl;
            }
        }
    }
};

int main() {
    DatingApp app;
    app.run();

    return 0;
}
