#pragma once
#include <vector>
#include <string>
#include <iostream>

class UserManager {
private:
    struct User {
        std::string username;
        std::vector<std::string> permissions;

        User(const std::string& name) : username(name) {}
    };

    std::vector<User> users;

public:
    void manageUsers();
    void assignPermissions(const std::string& username, const std::string& permission);
    void displayUsers();
    void addUser(const std::string& username);
    void removeUser(const std::string& username);
    bool hasPermission(const std::string& username, const std::string& permission);
};
