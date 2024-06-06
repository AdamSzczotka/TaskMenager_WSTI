#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>

class UserManager {
public:
    UserManager();
    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
    bool validateUser(const std::string& username, const std::string& password);

private:
    void initializeUserDataFile();
    void saveUserData(const std::string& username, const std::string& password);
    bool loadUserData(const std::string& username, std::string& password);
};

#endif // USERMANAGER_H
