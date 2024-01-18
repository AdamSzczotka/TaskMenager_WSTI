/**
 * @brief Klasa reprezentująca pojedynczy ticket.
 * 
 * Klasa Ticket przechowuje informacje o pojedynczym tickecie, 
 * takie jak ID, tytuł, opis, data utworzenia, status i priorytet.
 */
#pragma once
#include <string>
#include <ctime>

class Ticket {
private:
    int ID;
    std::string title;
    std::string description;
    time_t creationDate;
    std::string status;
    int priority;

public:
    /**
     * @brief Konstruktor domyślny.
     */
    Ticket() = default;

    /**
     * @brief Konstruktor inicjalizujący ticket z podanymi wartościami.
     * 
     * @param id Numer identyfikacyjny ticketu.
     * @param title Tytuł ticketu.
     * @param description Opis ticketu.
     * @param status Status ticketu.
     * @param priority Priorytet ticketu.
     */
    Ticket(int id, std::string title, std::string description, std::string status, int priority);

    // Gettery

    /**
     * @brief Pobiera ID ticketu.
     * 
     * @return int ID ticketu.
     */
    int getID() const;

    /**
     * @brief Pobiera tytuł ticketu.
     * 
     * @return std::string Tytuł ticketu.
     */
    std::string getTitle() const;

    /**
     * @brief Pobiera opis ticketu.
     * 
     * @return std::string Opis ticketu.
     */
    std::string getDescription() const;

    /**
     * @brief Pobiera datę utworzenia ticketu.
     * 
     * @return time_t Data utworzenia ticketu.
     */
    time_t getCreationDate() const;

    /**
     * @brief Pobiera status ticketu.
     * 
     * @return std::string Status ticketu.
     */
    std::string getStatus() const;

    /**
     * @brief Pobiera priorytet ticketu.
     * 
     * @return int Priorytet ticketu.
     */
    int getPriority() const;

    // Settery

    /**
     * @brief Ustawia ID ticketu.
     * 
     * @param newID Nowe ID ticketu.
     */
    void setID(int newID);

    /**
     * @brief Ustawia tytuł ticketu.
     * 
     * @param newTitle Nowy tytuł ticketu.
     */
    void setTitle(const std::string& newTitle);

    /**
     * @brief Ustawia opis ticketu.
     * 
     * @param newDescription Nowy opis ticketu.
     */
    void setDescription(const std::string& newDescription);

    /**
     * @brief Ustawia datę utworzenia ticketu.
     * 
     * @param newCreationDate Nowa data utworzenia ticketu.
     */
    void setCreationDate(time_t newCreationDate);

    /**
     * @brief Ustawia status ticketu.
     * 
     * @param newStatus Nowy status ticketu.
     */
    void setStatus(const std::string& newStatus);

    /**
     * @brief Ustawia priorytet ticketu.
     * 
     * @param newPriority Nowy priorytet ticketu.
     */
    void setPriority(int newPriority);
};

