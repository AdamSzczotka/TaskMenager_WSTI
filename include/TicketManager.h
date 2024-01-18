/**
 * @brief Klasa zarządzająca ticketami.
 * 
 * TicketManager odpowiada za zarządzanie kolekcją ticketów, w tym dodawanie,
 * aktualizowanie, usuwanie, wyszukiwanie oraz zapisywanie i wczytywanie ticketów do/z pliku.
 */
#pragma once
#include <vector>
#include <fstream>
#include "Ticket.h"

class TicketManager {
private:
    std::vector<Ticket> tickets;

public:
    /**
     * @brief Dodaje nowy ticket do kolekcji.
     * 
     * @param ticket Referencja do obiektu Ticket, który ma zostać dodany.
     */
    void addTicket(Ticket& ticket);

    /**
     * @brief Wczytuje tickety z pliku.
     * 
     * @param filename Nazwa pliku, z którego mają zostać wczytane tickety.
     */
    void loadTicketsFromFile(const std::string& filename);

    /**
     * @brief Zapisuje wszystkie tickety do pliku.
     * 
     * @param filename Nazwa pliku, do którego mają zostać zapisane tickety.
     */
    void saveTicketsToFile(const std::string& filename);

    /**
     * @brief Wyświetla informacje o wszystkich ticketach.
     */
    void viewTickets() const;

    /**
     * @brief Czyta string z pliku.
     * 
     * @param file Referencja do strumienia pliku.
     * @param str Referencja do stringa, do którego zostanie wczytana zawartość.
     */
    void readStringFromFile(std::ifstream& file, std::string& str);

    /**
     * @brief Pobiera ID ostatniego ticketu w kolekcji.
     * 
     * @return int ID ostatniego ticketu.
     */
    int getLastTicketId();

    /**
     * @brief Aktualizuje ticket o podanym ID.
     * 
     * @param id ID ticketu do aktualizacji.
     * @param newTitle Nowy tytuł ticketu.
     * @param newDescription Nowy opis ticketu.
     * @param newStatus Nowy status ticketu.
     * @param newPriority Nowy priorytet ticketu.
     */
    void updateTicket(int id, const std::string& newTitle, const std::string& newDescription, const std::string& newStatus, int newPriority);

    /**
     * @brief Usuwa ticket o podanym ID.
     * 
     * @param id ID ticketu do usunięcia.
     */
    void removeTicket(int id);

    /**
     * @brief Wyszukuje tickety według priorytetu.
     * 
     * @param priority Priorytet ticketów do wyszukania.
     */
    void searchTicketsByPriority(int priority) const;

    /**
     * @brief Wyszukuje tickety według statusu.
     * 
     * @param status Status ticketów do wyszukania.
     */
    void searchTicketsByStatus(const std::string& status) const;

    // Pozostałe metody...
};

