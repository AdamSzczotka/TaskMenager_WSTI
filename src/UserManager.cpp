#include "UserManager.h"
#include <fstream>
#include <iostream>

UserManager::UserManager() {
    initializeUserDataFile();
}

void UserManager::initializeUserDataFile() {
    const std::string filePath = "../data/user_data.bin";
    std::ifstream file(filePath);
    if (!file) {
        std::ofstream outFile(filePath, std::ios::binary);
        outFile.close();
    }
}

bool UserManager::registerUser(const std::string& username, const std::string& password) {
    std::string storedPassword;
    if (loadUserData(username, storedPassword)) {
        std::cout << "User already exists.\n";
        return false;
    }
    saveUserData(username, password);
    std::cout << "User registered successfully.\n";
    return true;
}

bool UserManager::loginUser(const std::string& username, const std::string& password) {
    std::string storedPassword;
    if (loadUserData(username, storedPassword)) {
        if (storedPassword == password) {
            std::cout << "Login successful.\n";
            return true;
        } else {
            std::cout << "Invalid password.\n";
            return false;
        }
    } else {
        std::cout << "User not found.\n";
        return false;
    }
}

bool UserManager::validateUser(const std::string& username, const std::string& password) {
    std::string storedPassword;
    return loadUserData(username, storedPassword) && storedPassword == password;
}

void UserManager::saveUserData(const std::string& username, const std::string& password) {
    std::ofstream outFile("../data/user_data.bin", std::ios::binary | std::ios::app);
    if (!outFile) {
        std::cerr << "Failed to open user data file for writing.\n";
        return;
    }

    size_t usernameLength = username.size();
    size_t passwordLength = password.size();

    outFile.write(reinterpret_cast<char*>(&usernameLength), sizeof(usernameLength));
    outFile.write(username.c_str(), usernameLength);
    outFile.write(reinterpret_cast<char*>(&passwordLength), sizeof(passwordLength));
    outFile.write(password.c_str(), passwordLength);

    outFile.close();
}

bool UserManager::loadUserData(const std::string& username, std::string& password) {
    std::ifstream inFile("../data/user_data.bin", std::ios::binary);
    if (!inFile.is_open()) {
        return false;
    }

    while (inFile.peek() != EOF) {
        size_t usernameLength;
        inFile.read(reinterpret_cast<char*>(&usernameLength), sizeof(usernameLength));
        std::string storedUsername(usernameLength, ' ');
        inFile.read(&storedUsername[0], usernameLength);

        size_t passwordLength;
        inFile.read(reinterpret_cast<char*>(&passwordLength), sizeof(passwordLength));
        std::string storedPassword(passwordLength, ' ');
        inFile.read(&storedPassword[0], passwordLength);

        if (storedUsername == username) {
            password = storedPassword;
            inFile.close();
            return true;
        }
    }

    inFile.close();
    return false;
}
