#include <iostream>
#include <vector>
#include <string>

struct User {
    int id;
    std::string name;
};

std::vector<User> users;
int nextId = 1;

void addUser(const std::string& name) {
    users.push_back({nextId++, name});
    std::cout << "User added: " << name << std::endl;
}

void listUsers() {
    if (users.empty()) {
        std::cout << "No users found.\n";
        return;
    }
    std::cout << "--- User List ---\n";
    for (const auto& user : users) {
        std::cout << "ID: " << user.id << " | Name: " << user.name << std::endl;
    }
}

int main() {
    int choice;
    std::string name;

    do {
        std::cout << "\n--- User Management ---\n";
        std::cout << "1. Add User\n2. List Users\n3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // flush newline

        switch (choice) {
            case 1:
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                addUser(name);
                break;
            case 2:
                listUsers();
                break;
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
