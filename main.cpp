#include "TicketManager.h"
#include "UserManager.h"
#include <iostream>

int main() {
    TicketManager ticketManager;
    UserManager userManager;

    int choice;
    do {
        std::cout << "\nTicket Management System\n";
        std::cout << "1. Manage Tickets\n";
        std::cout << "2. Manage Users\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                ticketManager.manageTickets();
                break;
            case 2:
                userManager.manageUsers();
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
