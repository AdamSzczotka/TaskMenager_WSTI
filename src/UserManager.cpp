#include "../include/UserManager.h"

void UserManager::addUser(const std::string& username, const std::string& permission) {
    userPermissions[username] = permission;
}

void UserManager::removeUser(const std::string& username) {
    userPermissions.erase(username);
}

bool UserManager::checkPermission(const std::string& username, const std::string& permission) const {
    auto it = userPermissions.find(username);
    return it != userPermissions.end() && it->second == permission;
}

// Implementacja dodatkowych metod
