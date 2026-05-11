#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

class Ticket
{
	private:
		//Declare ticket details
		int ticketID = 0;
		int age = 0;
		int row = 0;
		int col = 0;
		float price = 0;
		std::string status = "Pending";
		std::string name = " ", ic = " ", phone = " ", PID = " ", date = " ", time = " ", category = " ", seat_class = "Economy Class";
		
		//Private function- Calculate price based on age and seat
		void calculatePrice()
		{
			if(age <= 2){
				price = 50.00;
				category = "Infant";
			}
			else if(age <= 12){
				price = 150.00;
				category = "Child";
			}
			else if(age <= 59){
				price = 300.00;
				category = "Adult";
			}
			else{
				price = 250.00;
				category = "Senior";
			}
			
			if(col >= 1 && col <=4)
			{
				price = price * 3.0;
				seat_class = "First Class";
			}
			else if(col >=5 && col <=12)
			{
				price = price *2.0;
				seat_class = "Business Class";
			}
			else
			{
				price = price * 1.0;
				seat_class = "Economy Class";
			}
		}
		
	public:
		void setAge(int cAge)
		{
			if(cAge >= 0) 
			{
				age = cAge;
				calculatePrice();
			}
		}
		
		// setBookingDetails for gather all the data together in one ticket
		void setBookingDetails(int id, int cAge, int cRow, int cCol, 
		std::string cname, std::string cIC, std::string cPh, std::string cPID, std::string cdate, std::string ctime)
		{
			ticketID = id;
			name = cname;			
			row = cRow;
			col = cCol;
			setAge(cAge);
			ic = cIC;
			phone = cPh;
			PID = cPID;
			date = cdate;
			time = ctime;

		}
		
		void setPaidStatus()
		{
			status = "Paid";
		}
		
		void setCancelledStatus()
		{
			status = "Cancelled";
		}
		
		void setInvalidStatus()
		{
			status = "Invalid";
		}
		
		int getTicketID() const
		{
			return ticketID;
		}
		
		std::string getStatus() const
		{
			return status;
		}
		
		float getPrice() const
		{
			return price;
		}
		
		int getRow() const
		{
			return row;
		}
		
		int getCol() const
		{
			return col;
		}
		
		std::string getName() const
		{
			return name;
		}
		
		int getAge() const
		{
			return age;
		}
		
		std::string getCategory() const
		{
			return category;
		}
		
		std::string getSeat_Class() const
		{
			return seat_class;
		}
		
		std::string getIC() const
		{
			return ic;
		}
		
		std::string getPh() const
		{
			return phone;
		}
		
		std::string getPassID() const
		{
			return PID;
		}
		
		std::string getDate() const
		{
			return date;
		}
		
		std::string getTime() const
		{
			return time;
		}
		
		//Structure for display the ticket
		void displayTicket() const
		{
			std::cout << "Ticket ID      : MY" << ticketID << std::endl;
			std::cout << "Name           : " << name << std::endl;
			std::cout << "Age            : " << age << std::endl; 
			std::cout << "Category       : " << category << std::endl; 
			std::cout << "IC Number      : " << ic << std::endl;
			std::cout << "Phone No.      : " << phone << std::endl;
			std::cout << "Passport ID    : A" << PID << std::endl;
			std::cout << "From           : Malaysia" << std::endl;
			std::cout << "Destination    : Singapore" << std::endl;
			std::cout << "Date & Time    : " << date << "  " << time << std::endl;
			std::cout << "Seat           : " << "Row " << row << " Col " << col << std::endl;
			std::cout << "Class          : " << seat_class << std::endl;
			std::cout << "Status         : " << status << std::endl;
			std::cout << "Price          : RM " << std::fixed << std::setprecision(2) 
												<< price << std::endl;
			std::cout << "---------------------------------------" << std::endl;
		}
};

//Seating Management System
class SeatingManager
{	
	private:
		int Rows = 4;
		int Cols = 25;
		char seats[4][25]; // O = available X = Reserved
			
	public:
		//Initializing Seat Layout = 'O'
		SeatingManager()
		{
			for(int i = 0; i < Rows; i++)
				{
					for (int j = 0; j < Cols; j++)
					{
						seats[i][j] = 'O';
					}
				}
		}
			
		// output seat layout (const) cannot be changed	
		void displayLayout() const
		{
			std::cout << "\n==================================================================================\n";
			std::cout << std::setw(60) << "SEAT LAYOUT(FROM: MALAYSIA | DESTINATION: SINGAPORE)";
			std::cout << "\n==================================================================================\n";
			std::cout << "\n      ";
			for (int j=1; j <= Cols; j++)
			{
				std::cout << std::setw(3) << j;
			}
			std::cout << "\n";
			
			for (int i = 0; i < Rows; i++)
			{
				std::cout << "Row " << i + 1 << " ";
				for(int j =0; j < Cols; j++)
				{
					std::cout << std::setw(3) << seats[i][j];
				}
				
				std::cout << std::endl;
			}
			std::cout << "\n[O]= Available 	[X]= Reserved" << std::endl;
			std::cout << "__________________________________________________________________________________\n";
			std::cout << "PRICE TICKET OF CATEGORY "<< std::setw(32) << "| CABIN CLASS CLASSIFICATION\n";
			std::cout << "----------------------------------------------------------------------------------\n";
	        std::cout << "1. INFANT(0-2) : RM 50 " << std::setw(48) << "| COL(1-4)   : First Class    - Price * 3 \n";
	        std::cout << "2. CHILD(3-12) : RM 150" << std::setw(47) << "| COL(5-12)  : Business Class - Price * 2\n";
	        std::cout << "3. ADULT(13-59): RM 300" << std::setw(51) << "| COL(13-25) : Economy Class  - Price(Normal)\n";
	        std::cout << "4. SENIOR(60+) : RM 250" << std::setw(8) << "| \n";
			std::cout << "----------------------------------------------------------------------------------\n";

		}
		
		// Seat reservation conditions( available = true, reserved = false)
		bool reserveSeat(int r, int c)
		{
			if(r < 1 || r > Rows || c < 1 || c > Cols)
			{
				return false;// Not between choice = false
			}
			
			if(seats[r - 1][c - 1] == 'X')
			{
				return false; //be reserved = false
			}
			
			seats[r - 1][c - 1] = 'X';
			{
				return true; //available = true
			}
		}
		
		//Cancel seat reservation
		void cancelSeat(int r, int c)
		{
			//check row and column
			if(r >= 1 && r <= Rows && c >= 1 && c <= Cols)
			{
				seats[r - 1][c - 1]= 'O';// 'X' back to 'O'
			}
		}
};	

//The whole system control system
class AirlineSystem
{
	private:
		//call class Ticket & SeatingManager
		Ticket ticket[100];//call Ticket rename ticket and set ticket maximum 100
		SeatingManager seatManager;
		int ticketCount = 0;//Record the total number of records in the current array.
		int startBookingID = 1001; //ID start form 1001
		
	public:
		AirlineSystem() {} //Default constructor
		
		//Reservstion Module
		void reservationModule()
		{
			char reserve_more = 'Y';//declared reserve_more to 'y'
			while(reserve_more == 'Y' || reserve_more == 'y')
			{
				if(ticketCount >= 100)//ticketCount start with 0 , maximum 99
				{
					std::cout << "System Error: History Ticket records full" << std::endl;
					return;//if ticketCount >= 100 stop with here
				}
				
				seatManager.displayLayout();//display the seat layout
				int row, col, cAge;
				std::string cname, cIC, cPh, cPID, cDate, cTime;
				
				
				std::cout << "Enter row (1-4): ";
				std::cin >> row;
				std::cout << "Enter seat (1-25): ";
				std::cin >> col;
				std::cin.ignore();
				//cin.ignore() use for input buffer to avoid the error after the int value.
				
				if(row < 1 || row > 4 || col < 1 || col > 25)
				{
					std::cout << "\nInvalid seat selection!\n";
					return;
				}
				
				
				if(!seatManager.reserveSeat(row, col)) // if seat are be reserve show Seat already reserved!
				{
					std::cout << "\nSeat already reserved!\n";
					continue;
				}
				
				std::cout << "\nCUSTOMER DETAILS";
				std::cout << "\nEnter name        : ";
				std::getline(std::cin, cname);
				std::cout << "Enter age         : ";
				while(!(std::cin >> cAge) || cAge < 0)
				{
					std::cout << "\nInvalid input! Age must greater than 0... " << std::endl;
					std::cout << "Enter age         : ";
					//clear the data in the variable
					std::cin.clear();
					//Clear remaining input until newline.
					std::cin.ignore(1000, '\n');
				}
				std::cin.ignore();
				
				std::cout << "Enter IC          : ";
				std::getline(std::cin, cIC);
				std::cout << "Enter Phone.Num   : ";
				std::getline(std::cin, cPh);
				std::cout << "Enter Passport ID : A";
				std::getline(std::cin, cPID);
				std::cout << "Enter Date(DD/MM/YY): ";
				std::getline(std::cin, cDate);
				std::cout << "Enter Time(HHMM)    : ";
				std::getline(std::cin, cTime);
				
				//save passenger information and seat details into the Ticket object.
				ticket[ticketCount].setBookingDetails(startBookingID++, cAge,row, col, cname, cIC, cPh, cPID, cDate, cTime);
				ticketCount++;
				
				std::cout << "\nReservation successful!" << std::endl;
				std::cout << "(Booking ID) is MY" << ticket[ticketCount - 1].getTicketID() << std::endl;
				
				std::cout << "Do you want reserve more? (Y/N): ";
				std::cin >> reserve_more;
			}
		}	
		
		// show all the ticket in the system
		void displayAllTickets() const
		{
			std::cout << "\n========================================\n";
			std::cout << std::setw(35) << "TICKET GENERATION(VIEW ALL)";
			std::cout << "\n========================================\n";
			//if no ticket be reserve 
			if (ticketCount == 0)
			{
				std::cout << "No reservation found." << std::endl;
				return;
			}
			
			//Display all tickets in a loop, from ticket 0 to ticketCount-1
			for(int i=0; i< ticketCount; i++)
			{
				/*Call the 'displayTicket()'
				 method of the 'Ticket' class to display 
				 the details of a single ticket.*/
				ticket[i].displayTicket();
			}
		}
		
		void paymentModule()
		{
			int id;
			float payAmount;
			float change, price, extra;
			bool found = false;
			
			std::cout << "\n========================================\n";
			std::cout << std::setw(28) << "PAYMENT PROCESSING";
			std::cout << "\n========================================\n";
			std::cout <<"Enter Booking ID to pay: MY";
			
			if(!(std::cin >> id))
			{
				std::cout << "Invalid input. Please enter a number.\n";
            	std::cin.clear();
        	    std::cin.ignore(1000, '\n');
            	return;
			}
			
			if (ticketCount == 0)
			{
				std::cout << "No reservation found." << std::endl;
				return;
			}
			
			//All tickets are being searched for matching Booking ID
			for (int i = 0; i < ticketCount; i++)
			{
				if (ticket[i].getTicketID() == id)
				{
					found = true;
					
					//If the ticket has already been paid or cancelled
					if(ticket[i].getStatus() != "Pending")
					{
						std::cout << "This ticket is already " << ticket[i].getStatus() << "!" << std::endl;
						return;
					}
					
					//Get the ticket price and notify user
					price = ticket[i].getPrice();
					std::cout << "Ticket Price: RM "<< std::fixed << std::setprecision(2) << price << std::endl;
					std::cout << "Enter payment amount: RM ";
					
					//Enter payment amount verification
					while(!(std::cin >> payAmount) || payAmount < 0)
					{
						std::cout << "Invalid input...\n";
		            	std::cin.clear();
		        	    std::cin.ignore(1000, '\n');
		        	    std::cout << "Enter payment amount: RM ";
					}
					
					// Check if payment is insufficient
					while (payAmount < price)
					{
						std::cout << "\nInsufficient amount! You still owe: RM " << (price - payAmount) << std::endl;
						std::cout << "Please add more money: RM ";
						if(!(std::cin >> extra) || extra < 0)
						{
							std::cout << "Invalid input...\n";
			            	std::cin.clear();
			        	    std::cin.ignore(1000, '\n');
			        	    continue;
						}
						payAmount = payAmount + extra;
					}
					
					change = payAmount - price;
					//The ticket is marked as paid.
					ticket[i].setPaidStatus();
					std::cout << "\nPayment Successfull!" << std::endl;
					if (change > 0)
					{
						std::cout << "Change to return: RM " << change << std::endl;
					}
					
					return;
				}
			}
			
			//If the Booking ID is not found
			if(!found)
			{
				std::cout << "Error: Booking ID MY" << id << " not found!" << std::endl;
			}
		}
		
		void printReceiptModule() const
		{
			int id;
			std::cout << "\n========================================\n";
			std::cout << std::setw(28) << "RECEIPT PRINTING";
			std::cout << "\n========================================\n";
			std::cout << "Enter Booking ID to print receipt: MY";
			
			//Prevent users from entering non-numeric characters
			if(!(std::cin >> id))
			{
				std::cout << "Invalid input. Please enter a number.\n";
            	std::cin.clear();
        	    std::cin.ignore(1000, '\n');
            	return;
			}
			
			//Show the ticket that the status is paid
			for (int i = 0; i < ticketCount; i++)
			{
				if(ticket[i].getTicketID() == id)
				{
					if(ticket[i].getStatus() == "Paid")
					{
						std::cout << "\n----------- OFFICIAL RECEIPT -----------\n";
	                    ticket[i].displayTicket();
	                    std::cout << "Thank you for flying with us!\n";
					}
					else
					{
						std::cout << "Error: Ticket not paid yet or cancelled.\n";
					}
					return;
				}
			}
			std::cout << "Error: Booking ID MY" << id << " not found.\n";
		}
		
		
		void cancelModule()
		{
			int id;
			
			std::cout << "\n========================================\n";
			std::cout << std::setw(28) << "RESERVSATION CANCELLATION";
			std::cout << "\n========================================\n";
			std::cout << "Enter Booking ID to cancel: MY";
			
			//Prevent users from entering non-numeric characters
			if(!(std::cin >> id))
			{
				std::cout << "Invalid input. Please enter a number.\n";
            	std::cin.clear();
        	    std::cin.ignore(1000, '\n');
            	return;
			}
			
			//Used to record whether a ticket was found.
			bool found = false;
			
			//Search the ticket in the loop
			for (int i=0; i < ticketCount; i++)
			{
				if(ticket[i].getTicketID() == id)// Find matching ticket 
				{
					found = true;
					
					//Tickets have been cancelled or are invalid.
				if(ticket[i].getStatus() == "Cancelled" || ticket[i].getStatus() == "Invalid")
				{
					std::cout << "\nThis Booking ID is already inactive." << std::endl;
					return;
				}
				
				//Ticket already paid - Refund required
				if (ticket[i].getStatus() == "Paid")
				{
					std::cout << "\nStatus: Paid. Processing refund of RM "
							  << std::fixed << std::setprecision(2) << ticket[i].getPrice() << "..." << std::endl;
					ticket[i].setCancelledStatus();
					std::cout << "Refund successful. Transaction recorded." << std::endl;
				}
				//Ticket unpaid - Marked as invalid
				else
				{
					std::cout << "\nStatus: Pending. Cancelling unpaid reservation...." << std::endl;
					ticket[i].setInvalidStatus();
				}
				
				//Free up the seats so others can book
				seatManager.cancelSeat(ticket[i].getRow(), ticket[i].getCol());
				std::cout << "\nSeat Row " << ticket[i].getRow() << " Col " << ticket[i].getCol()
						  << " is now AVAILABLE again." << std::endl;
				
				return;
				}
			}
			if(!found)
			{
				std::cout << "Error: Booking ID MY" << id << " not found." << std::endl;
			}		
		}
		
		//Save data and exit the system
		void saveAndExit()
		{
			saveToFile();
			std::cout << "Data saved. Thank you for using Airline System!\n";
		}
		
		//Save ticketing system data to a text file
		void saveToFile() 
		{	
			//Open or create the file Ticket_Details.txt , and show the ticket output in txt file
		    std::ofstream outFile("Ticket_Details.txt", std::ios::out);
		
		    if (outFile.is_open()) 
			{
		        outFile << "==================================================\n";
		        outFile << "       AIRLINE SYSTEM - FINAL TRANSACTION LIST      \n";
		        outFile << "==================================================\n\n";
		
		        int savedCount = 0; 
				float totalRevenue = 0.0;
				
		        for (int i = 0; i < ticketCount; i++) {
		            std::string currentStatus = ticket[i].getStatus();
					
					//Only keep tickets that have been paid or cancelled.
		            if (currentStatus == "Paid" || currentStatus == "Cancelled") 
					{
		                outFile << "Ticket ID   : MY" << ticket[i].getTicketID() << "\n";
		                outFile << "Name	    : " << ticket[i].getName() << "\n";
		                outFile << "Age         : " << ticket[i].getAge() << "\n";
		                outFile << "Category    : " << ticket[i].getCategory() << "\n";
		                outFile << "IC          : " << ticket[i].getIC() << "\n";
		                outFile << "Passport ID : A" << ticket[i].getPassID() << "\n";
		                outFile << "From        : Malaysia" << "\n";
						outFile << "Destination : Singapore" << "\n";
						outFile << "Date & Time : " << ticket[i].getDate() << " " << ticket[i].getTime() << "\n";
		                outFile << "Seat        : Row " << ticket[i].getRow() << ", Col " << ticket[i].getCol() << "\n";
		                outFile << "Class       : " << ticket[i].getSeat_Class() << "\n";
		                outFile << "Price       : RM " << std::fixed << std::setprecision(2) << ticket[i].getPrice() << "\n";
		                outFile << "Status      : [" << currentStatus << "]\n";
		                outFile << "--------------------------------------------------\n";
		                
						//Cumulative Revenue (Only tickets already paid are counted)
						if(currentStatus == "Paid")
		                {
		                	totalRevenue = totalRevenue + ticket[i].getPrice();
						}
		                savedCount++;
		            }
		        }
			
				
		        outFile << "\nTotal Transactions Recorded: " << savedCount << "\n";
		        outFile << "Total Revenue Today: RM " << std::fixed << std::setprecision(2) << totalRevenue << std::endl;
		        outFile << "End of Report.\n";
		        outFile.close();
		        
		        std::cout << "\n[System] Data successfully synchronized to 'Ticket_Details.txt'." << std::endl;
		        std::cout << "[System] Total records saved: " << savedCount << std::endl;
		    } 
			else 
			{
		        std::cout << "Error: Could not create or open file!" << std::endl;
		    }
		}
};
