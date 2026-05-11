#include <iostream>
#include "Ticket.h"


int main() 
{
    AirlineSystem sys;
    int choice;

    do {
        std::cout << "\n========================================";
        std::cout << "\n   AIRLINE TICKET RESERVATION SYSTEM";
        std::cout << "\n========================================\n";
        std::cout << "1. Seating Arrangement & Reservation\n";
        std::cout << "2. Ticket Generation (View All)\n";
        std::cout << "3. Payment Processing\n";
        std::cout << "4. Receipt Printing\n";
        std::cout << "5. Reservation Cancellation\n";
        std::cout << "6. Exit\n";
        std::cout << "----------------------------------------\n";
        
        std::cout << "\nEnter choice: ";
        
        if (!(std::cin >> choice)) 
		{
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
			//clear the data in the variable
            std::cin.ignore(1000, '\n');
           	//Clear remaining input until newline.

            continue;
        }

        switch (choice) 
		{
            case 1: sys.reservationModule(); break;
            case 2: sys.displayAllTickets(); break;
            case 3: sys.paymentModule(); break;
            case 4: sys.printReceiptModule(); break;
            case 5: sys.cancelModule(); break;
            case 6: sys.saveAndExit(); break;
            default: std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}