/**
 * @brief Klasa zarządzająca użytkownikami i ich uprawnieniami.
 * 
 * UserManager odpowiada za zarządzanie użytkownikami i ich uprawnieniami
 * w kontekście aplikacji. Pozwala na dodawanie, usuwanie użytkowników oraz
 * sprawdzanie ich uprawnień.
 */
#pragma once
#include <string>
#include <unordered_map>

class UserManager {
private:
    /**
     * @brief Mapa przechowująca uprawnienia użytkowników.
     * 
     * Klucz mapy to nazwa użytkownika, a wartość to przypisane mu uprawnienia.
     */
    std::unordered_map<std::string, std::string> userPermissions;

public:
    /**
     * @brief Dodaje nowego użytkownika z określonymi uprawnieniami.
     * 
     * @param username Nazwa użytkownika.
     * @param permission Uprawnienia przypisane użytkownikowi.
     */
    void addUser(const std::string& username, const std::string& permission);

    /**
     * @brief Usuwa użytkownika z systemu.
     * 
     * @param username Nazwa użytkownika do usunięcia.
     */
    void removeUser(const std::string& username);

    /**
     * @brief Sprawdza, czy użytkownik posiada określone uprawnienia.
     * 
     * @param username Nazwa użytkownika.
     * @param permission Uprawnienia do sprawdzenia.
     * @return true Jeśli użytkownik posiada uprawnienia.
     * @return false Jeśli użytkownik nie posiada uprawnienia.
     */
    bool checkPermission(const std::string& username, const std::string& permission) const;

    // Dodatkowe metody zarządzania użytkownikami...
    // Klasa posłuży do rozbudowy programu na 2 semestrze
};
