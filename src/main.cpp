#include <iostream>
#include "../include/TicketManager.h"
#include "../include/FileHandler.h"
#include "../include/UserManager.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8); // Ustawienie strony kodowej konsoli na UTF-8
    TicketManager ticketManager;
    UserManager userManager;
    FileHandler fileHandler;
    std::string filename = "../data/tickets.bin";

    // Załaduj tickety z pliku, jeśli istnieje
    ticketManager.loadTicketsFromFile(filename);

    int choice;
    bool running = true;
    bool validPriority;

    while (running) {
        std::cout << "Menu:\n";
        std::cout << "1. Dodaj Ticket\n";
        std::cout << "2. Pokaż Tickety\n";
        std::cout << "3. Aktualizuj Ticket\n";
        std::cout << "4. Usuń Ticket\n";
        std::cout << "5. Eksportuj Tickety do TXT\n";
        std::cout << "6. Wyszukaj Tickety\n";
        std::cout << "7. Zapisz i wyjdź\n";
        std::cout << "Wybierz opcję: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title, description, status;

                int id = ticketManager.getLastTicketId() + 1;

                std::cin.ignore();

                std::cout << "Wprowadź tytuł ticketu: ";
                std::getline(std::cin, title);

                std::cout << "Wprowadź opis ticketu: ";
                std::getline(std::cin, description);

                std::cout << "Wprowadź status ticketu: Zrobione lub Do Zrobienia ";
                std::getline(std::cin, status);

                int priority;
                bool validPriority;

                do {
                    std::cout << "Wprowadź priorytet ticketu (1 - najważniejszy, 2 - średnio, 3 - najmniej ważny): ";
                    std::cin >> priority;

                    validPriority = (priority == 1 || priority == 2 || priority == 3);

                    if (!validPriority) {
                        std::cout << "Niepoprawny priorytet. Wybierz 1, 2 lub 3." << std::endl;
                    }
                } while (!validPriority);

                Ticket newTicket(id, title, description, status, priority);
                ticketManager.addTicket(newTicket);

                break;
            }
            case 2: {
                ticketManager.viewTickets();
                break;
            }
            case 3: {
                int id;
                std::string title, description, status;
                
                std::cout << "Podaj ID ticketu do aktualizacji: ";
                std::cin >> id;
                std::cin.ignore();

                std::cout << "Nowy tytuł ticketu: ";
                std::getline(std::cin, title);

                std::cout << "Nowy opis ticketu: ";
                std::getline(std::cin, description);

                std::cout << "Nowy status ticketu: Zrobione lub Do Zrobienia ";
                std::getline(std::cin, status);

                int priority;

                do {
                    std::cout << "Wprowadź priorytet ticketu (1 - najważniejszy, 2 - średnio, 3 - najmniej ważny): ";
                    std::cin >> priority;

                    validPriority = (priority == 1 || priority == 2 || priority == 3);

                    if (!validPriority) {
                        std::cout << "Niepoprawny priorytet. Wybierz 1, 2 lub 3." << std::endl;
                    }
                } while (!validPriority);


                ticketManager.updateTicket(id, title, description, status, priority);
                break;
            }
            case 4: {
                int id;
                std::cout << "Podaj ID ticketu do usunięcia: ";
                std::cin >> id;
                ticketManager.removeTicket(id);
                break;
            }
            case 5: {
                std::string sourceFilename = filename; // Nazwa pliku binarnego
                std::string targetFilename; 

                std::cout << "Podaj nazwę pliku docelowego do eksportu: ";
                std::cin >> targetFilename;

                fileHandler.exportTicketsToTxt(sourceFilename, "../"+targetFilename);
                break;
            }
            case 6: {
                int searchType;
                std::cout << "Wybierz typ wyszukiwania: 1 - Priorytet, 2 - Status: ";
                std::cin >> searchType;

                if (searchType == 1) {
                    int priority;
                    std::cout << "Wpisz priorytet (1, 2, 3): ";
                    std::cin >> priority;
                    ticketManager.searchTicketsByPriority(priority);
                } else if (searchType == 2) {
                    std::string status;
                    std::cout << "Wpisz status (np. Zrobione, Do Zrobienia): ";
                    std::cin.ignore();
                    std::getline(std::cin, status);
                    ticketManager.searchTicketsByStatus(status);
                } else {
                    std::cout << "Nieprawidłowy wybór." << std::endl;
                }
                break;
            }
            case 7: {
                ticketManager.saveTicketsToFile(filename);
                running = false;
                break;
            }
            default:
                std::cout << "Nieznana opcja!\n";
        }
    }

    return 0;
}
