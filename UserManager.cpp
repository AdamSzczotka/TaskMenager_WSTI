#include "UserManager.h"
#include <iostream>
#include <algorithm>

void UserManager::manageUsers() {
    int choice;
    do {
        std::cout << "\nUser Management Menu\n";
        std::cout << "1. Add User\n";
        std::cout << "2. Remove User\n";
        std::cout << "3. Display Users\n";
        std::cout << "4. Assign Permissions\n";
        std::cout << "5. Check Permissions\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string username;
                std::cout << "Enter username: ";
                std::cin >> username;
                addUser(username);
                break;
            }
            case 2: {
                std::string username;
                std::cout << "Enter username to remove: ";
                std::cin >> username;
                removeUser(username);
                break;
            }
            case 3:
                displayUsers();
                break;
            case 4: {
                std::string username, permission;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter permission: ";
                std::cin >> permission;
                assignPermissions(username, permission);
                break;
            }
            case 5: {
                std::string username, permission;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter permission to check: ";
                std::cin >> permission;
                if (hasPermission(username, permission)) {
                    std::cout << "User has the permission.\n";
                } else {
                    std::cout << "User does not have the permission.\n";
                }
                break;
            }
            case 0:
                std::cout << "Exiting User Management Menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);
}

void UserManager::assignPermissions(const std::string& username, const std::string& permission) {
    for (auto& user : users) {
        if (user.username == username) {
            user.permissions.push_back(permission);
            std::cout << "Permission assigned for user " << username << ": " << permission << "\n";
            return;
        }
    }
    std::cout << "User not found.\n";
}

void UserManager::displayUsers() {
    std::cout << "List of Users:\n";
    for (const auto& user : users) {
        std::cout << "Username: " << user.username << "\n";
        std::cout << "Permissions: ";
        for (const auto& permission : user.permissions) {
            std::cout << permission << " ";
        }
        std::cout << "\n\n";
    }
}

void UserManager::addUser(const std::string& username) {
    users.push_back(User(username));
    std::cout << "User added: " << username << "\n";
}

void UserManager::removeUser(const std::string& username) {
    auto it = std::remove_if(users.begin(), users.end(),
                             [username](const User& user) { return user.username == username; });

    if (it != users.end()) {
        users.erase(it, users.end());
        std::cout << "User removed: " << username << "\n";
    } else {
        std::cout << "User not found.\n";
    }
}

bool UserManager::hasPermission(const std::string& username, const std::string& permission) {
    for (const auto& user : users) {
        if (user.username == username) {
            return std::find(user.permissions.begin(), user.permissions.end(), permission) != user.permissions.end();
        }
    }
    return false;
}
