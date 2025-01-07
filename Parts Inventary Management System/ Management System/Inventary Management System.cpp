// Inventary Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <C:\Learning\oops C++\Inventary Management System\Inventary Management System\Inventary Management System.h>
#include <string>
#include <map>        // Needed for std::map
#include <memory>     // Needed for std::shared_ptr
#include <mutex>      // Needed for std::mutex
#include <vector>     // Needed for std::vector
#include <stdexcept>  // Needed for std::invalid_argument
#include <functional> // Needed for std::function
#include <ctime>      // Needed if you are dealing with time-related functions
#include <iomanip>
#include <typeinfo>
#include<fstream>
#include <sstream>
#include<algorithm>
#include <filesystem>
#include<fstream>
#include<conio.h>
#define NOMINMAX
#include <windows.h>
#include <limits>
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>


void handleUserInput(int& userId);

namespace fs = std::filesystem;
// Define the static members of the Inventory class
Inventory* Inventory::InventoryObj = nullptr;  // Initialize pointer to nullptr
std::mutex Inventory::mtx;                     // Define the static mutex

// Function to clear the console screen based on platform
void clearScreen() {
	// Clear the screen using system call
	// For Windows, use system("cls"); For Linux/Mac, use system("clear");
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#else
	system("clear");
#endif
}


Part::Part()
{
}

Engine::Engine()
{
}

Hydraulic::Hydraulic()
{
}

Electrical::Electrical()
{
}

Transmission::Transmission()
{
}




Inventory* CAT_INV = Inventory::getInventory();


// Template function to compare based on selected member variable
template <typename T>
bool compareByAttribute(std::shared_ptr<T> obj1, std::shared_ptr<T> obj2, int attribute, const std::string& type) {
	// Common attributes
	switch (attribute) {
	case 1:
		return obj1->GetPartId() < obj2->GetPartId();
	case 2:
		return obj1->GetSerialNumber() < obj2->GetSerialNumber();
	case 3:
		return obj1->GetName() < obj2->GetName();
	case 4:
		return obj1->GetQuantity() < obj2->GetQuantity();
	case 5:
		return obj1->GetManufacturer() < obj2->GetManufacturer();
	case 6:
		return obj1->GetWeight() < obj2->GetWeight();
	case 7:
		return obj1->GetCategory() < obj2->GetCategory();
	case 8:
		return obj1->GetProductionDate() < obj2->GetProductionDate();
	case 9:
		return obj1->GetWarrantyPeriod() < obj2->GetWarrantyPeriod();
	default:
		break; // Continue for specialized attributes
	}

	// Type-specific attributes
	if (type == "ENG") {
		auto engine1 = std::dynamic_pointer_cast<Engine>(obj1);
		auto engine2 = std::dynamic_pointer_cast<Engine>(obj2);
		if (engine1 && engine2) {
			switch (attribute) {
			case 10:
				return engine1->GetHorsePower() < engine2->GetHorsePower();
			case 11:
				return engine1->GetEngineType() < engine2->GetEngineType();
			case 12:
				return engine1->GetFuelType() < engine2->GetFuelType();
			case 13:
				return engine1->GetFuelCapacity() < engine2->GetFuelCapacity();
			default:
				break;
			}
		}
	}
	else if (type == "ELE") {
		auto electrical1 = std::dynamic_pointer_cast<Electrical>(obj1);
		auto electrical2 = std::dynamic_pointer_cast<Electrical>(obj2);
		if (electrical1 && electrical2) {
			switch (attribute) {
			case 10:
				return electrical1->GetVoltageRating() < electrical2->GetVoltageRating();
			case 11:
				return electrical1->GetCurrentRating() < electrical2->GetCurrentRating();
			case 12:
				return electrical1->GetInsulationType() < electrical2->GetInsulationType();
			case 13:
				return electrical1->GetPowerConsumption() < electrical2->GetPowerConsumption();
			default:
				break;
			}
		}
	}
	else if (type == "HYD") {
		auto hydraulic1 = std::dynamic_pointer_cast<Hydraulic>(obj1);
		auto hydraulic2 = std::dynamic_pointer_cast<Hydraulic>(obj2);
		if (hydraulic1 && hydraulic2) {
			switch (attribute) {
			case 10:
				return hydraulic1->GetPressureRating() < hydraulic2->GetPressureRating();
			case 11:
				return hydraulic1->GetFluidType() < hydraulic2->GetFluidType();
			case 12:
				return hydraulic1->GetCylinderBore() < hydraulic2->GetCylinderBore();
			case 13:
				return hydraulic1->GetStrokeLength() < hydraulic2->GetStrokeLength();
			default:
				break;
			}
		}
	}
	else if (type == "TRANS") {
		auto transmission1 = std::dynamic_pointer_cast<Transmission>(obj1);
		auto transmission2 = std::dynamic_pointer_cast<Transmission>(obj2);
		if (transmission1 && transmission2) {
			switch (attribute) {
			case 10:
				return transmission1->GetTransmissionType() < transmission2->GetTransmissionType();
			case 11:
				return transmission1->GetGearCount() < transmission2->GetGearCount();
			case 12:
				return transmission1->GetTorqueRating() < transmission2->GetTorqueRating();
			case 13:
				return transmission1->GetShiftPattern() < transmission2->GetShiftPattern();
			default:
				break;
			}
		}
	}

	return false; // Default fallback
}



// Template function to sort vector based on the selected member variable
template <typename PartType>
void compareAndSortByAttribute(std::vector<std::shared_ptr<PartType>>& parts, int attribute, std::string type) {
	std::sort(parts.begin(), parts.end(), [&attribute, &type](const std::shared_ptr<PartType>& part1, const std::shared_ptr<PartType>& part2) {
		return compareByAttribute(part1, part2, attribute, type);
	});
}




void UniqueHandler(int& PartId, std::string& Prefix)
{
	bool isUnique = false;

	// Check for unique PartId for each category
	while (!isUnique) {
		std::cout << "Enter Part ID: ";
		std::cin >> PartId;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


		if (Prefix == "ENG")
		{
			if (EnginePartIDs.insert(PartId).second) {

				isUnique = true;
				break;
			}
			else {
				std::cout << "Warning: This Part ID already exists in ENGINE category. Please enter a unique one." << std::endl;
				
			}
		}

		else if (Prefix == "HYD")
		{
			if (HydraulicPartIDs.insert(PartId).second) {

				isUnique = true;
				break;
			}
			else {
				std::cout << "Warning: This Part ID already exists in Hydraulic category. Please enter a unique one." << std::endl;
				
			}

		}


		else if (Prefix == "ELE")
		{
			if (ElectricalPartIDs.insert(PartId).second) {

				isUnique = true;
				break;
			}
			else {
				std::cout << "Warning: This Part ID already exists in Electrical category. Please enter a unique one." << std::endl;
				
			}
		}

		else if (Prefix == "TRANS")
		{
			if (TransmissionPartIDs.insert(PartId).second) {
				isUnique = true;
				break;
			}
			else {
				std::cout << "Warning: This Part ID already exists in Transmission category. Please enter a unique one." << std::endl;
				
			}
		}
	}
}

template<typename PartType>
void PartFactory::AddPart() {

	system("cls");

	if (typeid(PartType) == typeid(Engine)) {
		auto engpart = CAT_INV->PartFactory->CreateEngine();
		engpart->AddObserver(CAT_INV->alert);
		std::string str("ENG");
		engpart->initializeAttributes(str);
		engpart->saveToFile("EngineParts.txt");
	}

	else if (typeid(PartType) == typeid(Hydraulic)) {
		auto hydpart = CAT_INV->PartFactory->CreateHydraulic();
		hydpart->AddObserver(CAT_INV->alert);
		std::string str("HYD");
		hydpart->initializeAttributes(str);
		hydpart->saveToFile("HydraulicParts.txt");
	}
	else if (typeid(PartType) == typeid(Electrical)) {
		auto elepart = CAT_INV->PartFactory->CreateElectrical();
		elepart->AddObserver(CAT_INV->alert);
		std::string str("ELE");
		elepart->initializeAttributes(str);
		elepart->saveToFile("ElectricalParts.txt");
	}
	else if (typeid(PartType) == typeid(Transmission)) {
		auto transpart = CAT_INV->PartFactory->CreateTransmission();
		transpart->AddObserver(CAT_INV->alert);
		std::string str("TRANS");
		transpart->initializeAttributes(str);
		transpart->saveToFile("TransmissionParts.txt");
	}
}



void Inventory::AddPartMenu(int & userId) {
	const int consoleWidth = 200;  // Console width for alignment
	const int consoleHeight = 50;  // Console height for vertical centering

	const int boxWidth = 58;      // Width of the box for menu
	const int boxHeight = 8;      // Total lines for the menu box

	int paddingLeft = (consoleWidth - boxWidth) / 2; // Center horizontally
	int paddingTop = (consoleHeight - boxHeight) / 2; // Center vertically

	int choice;

	do {
		clearScreen(); // Clear the screen

		// Add vertical padding (empty lines)
		for (int i = 0; i < paddingTop; i++) {
			std::cout << std::endl;
		}

		// Top border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

		// Title inside the border
		std::cout << std::string(paddingLeft, ' ')
			<< " ||                  ADD PART MENU                 || " << std::endl;

		// Middle border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

		// Menu options inside the border
		std::cout << std::string(paddingLeft, ' ')
			<< " ||              1. Engine Part                   || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||              2. Hydraulic Part                || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||              3. Electrical Part               || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||              4. Transmission Part             || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||              5. Exit                          || " << std::endl;

		// Bottom border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

	

		choice = _getch(); // Capture the input with _getch()
		std::cout << "\n"; // For clean output (since _getch() doesn't require Enter)

		switch (choice) {
		case '1':
			CAT_INV->PartFactory->AddPart<Engine>();
			break;
		case '2':
			CAT_INV->PartFactory->AddPart<Hydraulic>();
			break;
		case '3':
			CAT_INV->PartFactory->AddPart<Electrical>();
			break;
		case '4':
			CAT_INV->PartFactory->AddPart<Transmission>();
			break;
		case '5':
			std::cout << std::string(paddingLeft, ' ') << "Exiting to Main Menu...\n";
			handleUserInput(userId);
			return; // Exit the menu
		default:
			std::cout << std::string(paddingLeft, ' ') << "Invalid choice, please try again.\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			break;
		}
	} while (choice != '5');
}



template <typename PartType>
void Inventory::loadParts() {

	std::string filename;
		if (std::is_same<PartType, Transmission>::value) filename = "TransmissionParts.txt";
		// Check if the part type is Engine and add specific fields
		else if (std::is_same<PartType, Engine>::value) filename = "EngineParts.txt";
		// Check if the part type is Hydraulic and add specific fields
		else if (std::is_same<PartType, Hydraulic>::value) filename = "HydraulicParts.txt";
		// Check if the part type is ElectricalPar and add specific fields
		else if (std::is_same<PartType, Electrical>::value) filename = "ElectricalParts.txt";
	std::ifstream inFile(filename);
	if (!inFile) {
		std::cerr << "Error: Unable to open " << filename << std::endl;
		return;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		// Skip empty lines
		if (line.empty()) {
			continue;
		}

		std::istringstream iss(line);

		int PartId, Quantity, WarrantyPeriod;
		std::string SerialNumber, Name, Manufacturer, Category, ProductionDate;
		double Weight;
		char delimiter;

		if (!(iss >> PartId >> delimiter) || delimiter != ',' ||
			!std::getline(iss, SerialNumber, ',') ||
			!std::getline(iss, Name, ',') ||
			!(iss >> Quantity >> delimiter) || delimiter != ',' ||
			!std::getline(iss, Manufacturer, ',') ||
			!(iss >> Weight >> delimiter) || delimiter != ',' || // Read Weight as double
			!std::getline(iss, Category, ',') ||
			!std::getline(iss, ProductionDate, ',') ||
			!(iss >> WarrantyPeriod >> delimiter) || delimiter != ',')
		{
			std::cerr << "Error parsing common fields. Line: " << line << std::endl;
			continue;
		}

		// Part-specific fields parsing
		if (std::is_same<PartType, Engine>::value) {
			int HorsePower;
			std::string EngineType, FuelType;
			double FuelCapacity;

			if (std::getline(iss, EngineType, ',') &&
				(iss >> HorsePower >> delimiter) && delimiter == ',' &&
				std::getline(iss, FuelType, ',') &&
				(iss >> FuelCapacity)) {
				if( !(EnginePartIDs.insert(PartId).second))
				{
					std::cout << "Unable the enter the PartId.Please enter the Unique";
				}
				
				std::shared_ptr<Engine> engpart = CAT_INV->PartFactory->CreateEngine(PartId, SerialNumber, Name, Quantity, Manufacturer, Weight, Category, ProductionDate, WarrantyPeriod, EngineType, HorsePower, FuelType, FuelCapacity);
				CAT_INV->Engines.push_back(engpart);
				engpart->AddObserver(CAT_INV->alert);
			}
			else {
				std::cerr << "Error parsing Engine line: " << line << std::endl;
			}
		}
		else if (std::is_same<PartType, Hydraulic>::value) {
			int PressureRating;
			std::string FluidType;
			double CylinderBore, StrokeLength;

			if ((iss >> PressureRating >> delimiter) && delimiter == ',' &&
				std::getline(iss, FluidType, ',') &&
				(iss >> CylinderBore >> delimiter) && delimiter == ',' &&
				(iss >> StrokeLength)) {

				if ((!HydraulicPartIDs.insert(PartId).second))
				{
					std::cout << "Unable the enter the PartId.Please enter the Unique";
				}
				std::shared_ptr<Hydraulic> hydpart = CAT_INV->PartFactory->CreateHydraulic(PartId, SerialNumber, Name, Quantity, Manufacturer, Weight, Category, ProductionDate, WarrantyPeriod, PressureRating, FluidType, CylinderBore, StrokeLength);
				CAT_INV->Hydraulics.push_back(hydpart);
				hydpart->AddObserver(CAT_INV->alert);
			}
			else {
				std::cerr << "Error parsing Hydraulic line: " << line << std::endl;
			}
		}
		else if (std::is_same<PartType, Electrical>::value) {
			int VoltageRating, CurrentRating;
			std::string InsulationType;
			double PowerConsumption;

			if ((iss >> VoltageRating >> delimiter) && delimiter == ',' &&
				(iss >> CurrentRating >> delimiter) && delimiter == ',' &&
				std::getline(iss, InsulationType, ',') &&
				(iss >> PowerConsumption)) {
				if ((!ElectricalPartIDs.insert(PartId).second))
				{
					std::cout << "Unable the enter the PartId.Please enter the Unique";
				}
				std::shared_ptr<Electrical> elepart = CAT_INV->PartFactory->CreateElectrical(PartId, SerialNumber, Name, Quantity, Manufacturer, Weight, Category, ProductionDate, WarrantyPeriod, VoltageRating, CurrentRating, InsulationType, PowerConsumption);
				CAT_INV->ElectricalParts.push_back(elepart);
				elepart->AddObserver(CAT_INV->alert);
			}
			else {
				std::cerr << "Error parsing ElectricalPart line: " << line << std::endl;
			}
		}
		else if (std::is_same<PartType, Transmission>::value) {
			int GearCount, TorqueRating;
			std::string TransmissionType, ShiftPattern;

			if (std::getline(iss, TransmissionType, ',') &&
				(iss >> GearCount >> delimiter) && delimiter == ',' &&
				(iss >> TorqueRating >> delimiter) && delimiter == ',' &&
				std::getline(iss, ShiftPattern)) {
				if ((!TransmissionPartIDs.insert(PartId).second))
				{
					std::cout << "Unable the enter the PartId.Please enter the Unique";
				}
				std::shared_ptr<Transmission> transpart = CAT_INV->PartFactory->CreateTransmission(PartId, SerialNumber, Name, Quantity, Manufacturer, Weight, Category, ProductionDate, WarrantyPeriod, TransmissionType, GearCount, TorqueRating, ShiftPattern);
				CAT_INV->Transmissions.push_back(transpart);
				transpart->AddObserver(CAT_INV->alert);
			}
			else {
				std::cerr << "Error parsing Transmission line: " << line << std::endl;
			}
		}
		else {
			std::cerr << "Error parsing part-specific fields. Line: " << line << std::endl;
		}
	}

	inFile.close();
}



template <typename PartType>
void PartFactory::printParts(const std::vector<std::shared_ptr<PartType>>& parts) const {
	system("cls");
	if (parts.empty()) {
		std::cout << "No parts available in this category.\n";
		return;
	}

	// Print table header for common fields
	std::cout << std::left << std::setw(7) << "Part ID" << " | "
		<< std::setw(13) << "Serial Number" << " | "
		<< std::setw(20) << "Name" << " | "
		<< std::setw(8) << "Quantity" << " | "
		<< std::setw(16) << "Manufacturer" << " | "
		<< std::setw(6) << "Weight" << " | "
		<< std::setw(10) << "Category" << " | "
		<< std::setw(10) << "Prod Date" << " | "
		<< std::setw(8) << "Warranty";

	// Check if the part type is Transmission and add specific fields
	if (std::is_same<PartType, Transmission>::value) {
		std::cout << " | " << std::setw(12) << "Trans Type"
			<< " | " << std::setw(12) << "Gear Count"
			<< " | " << std::setw(7) << "Torque"
			<< " | " << std::setw(14) << "Shift Pattern";
	}
	// Check if the part type is Engine and add specific fields
	else if (std::is_same<PartType, Engine>::value) {
		std::cout << " | " << std::setw(12) << "Engine Type"
			<< " | " << std::setw(12) << "Horse Power"
			<< " | " << std::setw(10) << "Fuel Type"
			<< " | " << std::setw(12) << "Fuel Capacity";
	}
	// Check if the part type is Hydraulic and add specific fields
	else if (std::is_same<PartType, Hydraulic>::value) {
		std::cout << " | " << std::setw(14) << "Pressure Rating"
			<< " | " << std::setw(12) << "Fluid Type"
			<< " | " << std::setw(12) << "Cylinder Bore"
			<< " | " << std::setw(12) << "Stroke Length";
	}
	// Check if the part type is ElectricalPart and add specific fields
	else if (std::is_same<PartType, Electrical>::value) {
		std::cout << " | " << std::setw(12) << "VoltageRating"
			<< " | " << std::setw(9) << "CurrentRating"
			<< " | " << std::setw(9) << "PowerRating"
	    	<< " | " << std::setw(16) << "InsulationType";
	}

	std::cout << "\n" << std::string(185, '-') << "\n";

	// Now print the details for each part
	for (const auto& part : parts) {
		part->Display();
		std::cout << "\n";
	}

		std::cout << "\nPress any key to continue...";
		while (!_kbhit()) {
			// Keep looping until a key is pressed
		}
		_getch();  // Consume the pressed key
}



// Mutex to ensure thread-safe access to shared resources
std::mutex fileMutex;

template<typename PartType>
void PartFactory::updatePartDetails(std::vector<std::shared_ptr<PartType>>& parts, int partId) {
	system("cls");
	auto it = std::find_if(parts.begin(), parts.end(),
		[partId](const std::shared_ptr<PartType>& part) {
		return part->GetPartId() == partId;
	});

	if (it == parts.end()) {
		std::cout << "Part with ID " << partId << " not found.\n";
		return;
	}
	std::shared_ptr<PartType> part = *it;

	part->UpdatePart();

	// Use a separate thread to handle file updates
	std::thread updateThread(&PartFactory::updatePartInFile<PartType>, this, partId, part);
	updateThread.detach(); // Allow thread to run independently
}

template<typename PartType>
void PartFactory::updatePartInFile(int partId, std::shared_ptr<PartType> updatedPart) {
	std::string filename;
	if (std::is_same<PartType, Transmission>::value) filename = "TransmissionParts.txt";
	else if (std::is_same<PartType, Engine>::value) filename = "EngineParts.txt";
	else if (std::is_same<PartType, Hydraulic>::value) filename = "HydraulicsParts.txt";
	else if (std::is_same<PartType, Electrical>::value) filename = "ElectricalParts.txt";

	std::lock_guard<std::mutex> lock(fileMutex); // Lock the mutex for file access

	std::ifstream inFile(filename);
	if (!inFile) {
		std::cerr << "Error: Unable to open " << filename << std::endl;
		return;
	}

	std::vector<std::string> lines;
	std::string line;
	bool partFound = false;

	while (std::getline(inFile, line)) {
		if (line.empty()) continue;

		std::istringstream iss(line);
		int PartId;
		char delimiter;
		std::string SerialNumber, Name, Manufacturer, Weight, Category, ProductionDate;
		int Quantity, WarrantyPeriod;

		// Parse the common fields
		if (!(iss >> PartId >> delimiter) || delimiter != ',' ||
			!std::getline(iss, SerialNumber, ',') ||
			!std::getline(iss, Name, ',') ||
			!(iss >> Quantity >> delimiter) || delimiter != ',' ||
			!std::getline(iss, Manufacturer, ',') ||
			!std::getline(iss, Weight, ',') ||
			!std::getline(iss, Category, ',') ||
			!std::getline(iss, ProductionDate, ',') ||
			!(iss >> WarrantyPeriod >> delimiter) || delimiter != ',') {
			lines.push_back(line);  // If parsing fails, just add the original line
			continue;
		}

		// If part found, update it with new values
		if (PartId == partId) {
			partFound = true;

			// Update the part's data fields
			line = std::to_string(updatedPart->GetPartId()) + "," + updatedPart->GetSerialNumber() + "," +
				updatedPart->GetName() + "," + std::to_string(updatedPart->GetQuantity()) + "," +
				updatedPart->GetManufacturer() + "," + std::to_string(updatedPart->GetWeight()) + "," +
				updatedPart->GetCategory() + "," + updatedPart->GetProductionDate() + "," +
				std::to_string(updatedPart->GetWarrantyPeriod());

			// Add specific fields for derived classes

			// Engine-specific fields
			if (std::is_same<PartType, Engine>::value) {
				auto enginePart = std::dynamic_pointer_cast<Engine>(updatedPart);
				if (enginePart) {
					line += "," + enginePart->GetEngineType() + "," +
						std::to_string(enginePart->GetHorsePower()) + "," +
						enginePart->GetFuelType() + "," +
						std::to_string(enginePart->GetFuelCapacity());
				}
			}
			// Hydraulic-specific fields
			else if (std::is_same<PartType, Hydraulic>::value) {
				auto hydraulicPart = std::dynamic_pointer_cast<Hydraulic>(updatedPart);
				if (hydraulicPart) {
					line += "," + std::to_string(hydraulicPart->GetPressureRating()) + "," +
						hydraulicPart->GetFluidType() + "," +
						std::to_string(hydraulicPart->GetCylinderBore()) + "," +
						std::to_string(hydraulicPart->GetStrokeLength());
				}
			}
			// ElectricalPart-specific fields
			else if (std::is_same<PartType, Electrical>::value) {
				auto electricalPart = std::dynamic_pointer_cast<Electrical>(updatedPart);
				if (electricalPart) {
					line += "," + std::to_string(electricalPart->GetVoltageRating()) + "," +
						std::to_string(electricalPart->GetCurrentRating()) + "," +
						electricalPart->GetInsulationType() + "," +
						std::to_string(electricalPart->GetPowerConsumption());
				}
			}
			// Transmission-specific fields
			else if (std::is_same<PartType, Transmission>::value) {
				auto transmissionPart = std::dynamic_pointer_cast<Transmission>(updatedPart);
				if (transmissionPart) {
					line += "," + transmissionPart->GetTransmissionType() + "," +
						std::to_string(transmissionPart->GetGearCount()) + "," +
						std::to_string(transmissionPart->GetTorqueRating()) + "," +
						transmissionPart->GetShiftPattern();
				}
			}
		}

		lines.push_back(line);
	}

	inFile.close();

	if (!partFound) {
		std::cerr << "Part with ID " << partId << " not found.\n";
		return;
	}

	// Rewrite the file with updated content
	std::ofstream outFile(filename, std::ios::trunc);
	if (!outFile) {
		std::cerr << "Error: Unable to open file for writing " << filename << std::endl;
		return;
	}

	for (auto it = lines.begin(); it != lines.end(); ++it) {
		outFile << *it;
		if (std::next(it) != lines.end()) { // Check if it's not the last line
			outFile << "\n";
		}
	}

	outFile.close();
	std::cout << "Part with ID " << partId << " has been updated in " << filename << std::endl;
}
void Inventory::UpdatePartMenu(int& userId) {
	const int consoleWidth = 200;  // Console width for alignment
	const int consoleHeight = 50;  // Console height for vertical centering

	const int boxWidth = 58;      // Width of the box for menu
	const int boxHeight = 10;     // Total lines for the menu box

	int paddingLeft = (consoleWidth - boxWidth) / 2; // Center horizontally
	int paddingTop = (consoleHeight - boxHeight) / 2; // Center vertically

	int choice;

	do {
		clearScreen(); // Clear the screen

		// Add vertical padding (empty lines)
		for (int i = 0; i < paddingTop; i++) {
			std::cout << std::endl;
		}

		// Top border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

		// Title inside the border
		std::cout << std::string(paddingLeft, ' ')
			<< " ||                  UPDATE PART MENU              || " << std::endl;

		// Middle border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

		// Menu options inside the border
		std::cout << std::string(paddingLeft, ' ')
			<< " ||            1. Update Engine Part                || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||            2. Update Hydraulic Part             || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||            3. Update Electrical Part            || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||            4. Update Transmission Part          || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||            5. Exit                             || " << std::endl;

		// Bottom border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

		std::cout << std::string(paddingLeft, ' ') << "Enter your choice: ";

		choice = _getch(); // Capture the input with _getch()
		std::cout << "\n"; // For clean output (since _getch() doesn't require Enter)

		switch (choice) {
		case '1': {
			int partId;
			std::cout << std::string(paddingLeft, ' ') << "Enter Engine Part ID to update: ";
			std::cin >> partId;
			CAT_INV->PartFactory->updatePartDetails(CAT_INV->Engines, partId);
			break;
		}
		case '2': {
			int partId;
			std::cout << std::string(paddingLeft, ' ') << "Enter Hydraulic Part ID to update: ";
			std::cin >> partId;
			CAT_INV->PartFactory->updatePartDetails(CAT_INV->Hydraulics, partId);
			break;
		}
		case '3': {
			int partId;
			std::cout << std::string(paddingLeft, ' ') << "Enter Electrical Part ID to update: ";
			std::cin >> partId;
			CAT_INV->PartFactory->updatePartDetails(CAT_INV->ElectricalParts, partId);
			break;
		}
		case '4': {
			int partId;
			std::cout << std::string(paddingLeft, ' ') << "Enter Transmission Part ID to update: ";
			std::cin >> partId;
			CAT_INV->PartFactory->updatePartDetails(CAT_INV->Transmissions, partId);
			break;
		}
		case '5':
			std::cout << std::string(paddingLeft, ' ') << "Exiting update menu...\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			handleUserInput(userId);
			return; // Exit the menu
		default:
			std::cout << std::string(paddingLeft, ' ') << "Invalid choice, please try again.\n";
			std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause to display invalid choice
			break;
		}
	} while (choice != '5');
}

void Inventory::PrintPartMenu(int& userId) const {
	const int consoleWidth = 200;  // Console width for alignment
	const int consoleHeight = 50;  // Console height for vertical centering

	const int boxWidth = 58;      // Width of the box for menu
	const int boxHeight = 10;     // Total lines for the menu box

	int paddingLeft = (consoleWidth - boxWidth) / 2; // Center horizontally
	int paddingTop = (consoleHeight - boxHeight) / 2; // Center vertically

	int choice;

	do {
		clearScreen(); // Clear the screen

		// Add vertical padding (empty lines)
		for (int i = 0; i < paddingTop; i++) {
			std::cout << std::endl;
		}

		// Top border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

		// Title inside the border
		std::cout << std::string(paddingLeft, ' ')
			<< " ||               PRINT PARTS MENU                 || " << std::endl;

		// Middle border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

		// Menu options inside the border
		std::cout << std::string(paddingLeft, ' ')
			<< " ||           1. Print Engine Parts                 || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||           2. Print Hydraulic Parts              || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||           3. Print Transmission Parts          || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||           4. Print Electrical Parts            || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||           5. Exit                             || " << std::endl;

		// Bottom border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

		std::cout << std::string(paddingLeft, ' ') << "Enter your choice: ";

		choice = _getch(); // Capture the input with _getch()
		std::cout << "\n"; // For clean output

		switch (choice) {
		case '1':
			std::cout << std::string(paddingLeft, ' ') << "\n--- Engine Parts ---\n";
			CAT_INV->PartFactory->printParts(Engines);
			break;

		case '2':
			std::cout << std::string(paddingLeft, ' ') << "\n--- Hydraulic Parts ---\n";
			CAT_INV->PartFactory->printParts(Hydraulics);
			break;

		case '3':
			std::cout << std::string(paddingLeft, ' ') << "\n--- Transmission Parts ---\n";
			CAT_INV->PartFactory->printParts(Transmissions);
			break;

		case '4':
			std::cout << std::string(paddingLeft, ' ') << "\n--- Electrical Parts ---\n";
			CAT_INV->PartFactory->printParts(ElectricalParts);
			break;

		case '5':
			std::cout << std::string(paddingLeft, ' ') << "Exiting print menu...\n";
			handleUserInput(userId);
			return; // Exit the menu

		default:
			std::cerr << std::string(paddingLeft, ' ') << "Invalid choice! Please enter a valid option.\n";
			std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause to display invalid choice
			break;
		}
	} while (choice != '5');
}

template<typename PartType>
void PartFactory::deletePartInFile(int partId) {

	std::string filename;
	if (std::is_same<PartType, Transmission>::value) filename = "TransmissionParts.txt";
	// Check if the part type is Engine and add specific fields
	else if (std::is_same<PartType, Engine>::value) filename = "EngineParts.txt";
	// Check if the part type is Hydraulic and add specific fields
	else if (std::is_same<PartType, Hydraulic>::value) filename = "HydraulicParts.txt";
	// Check if the part type is ElectricalPart and add specific fields
	else if (std::is_same<PartType, Electrical>::value) filename = "ElectricalParts.txt";

	std::ifstream inFile(filename);
	if (!inFile) {
		std::cerr << "Error: Unable to open " << filename << std::endl;
		return;
	}

	std::vector<std::string> lines;
	std::string line;
	bool partFound = false;

	while (std::getline(inFile, line)) {
		if (line.empty()) continue;

		std::istringstream iss(line);
		int PartId
;
		char delimiter;
		std::string SerialNumber, Name, Manufacturer, Weight, Category, ProductionDate;
		int Quantity, WarrantyPeriod;

		// Parse the common fields
		if (!(iss >> PartId >> delimiter) || delimiter != ',' ||
			!std::getline(iss, SerialNumber, ',') ||
			!std::getline(iss, Name, ',') ||
			!(iss >> Quantity >> delimiter) || delimiter != ',' ||
			!std::getline(iss, Manufacturer, ',') ||
			!std::getline(iss, Weight, ',') ||
			!std::getline(iss, Category, ',') ||
			!std::getline(iss, ProductionDate, ',') ||
			!(iss >> WarrantyPeriod >> delimiter) || delimiter != ',') {
			lines.push_back(line);  // If parsing fails, just add the original line
			continue;
		}

		// If part found, skip adding this line to the lines vector
		if (PartId == partId) {
			partFound = true;
			std::cout << "Part with ID " << partId << " has been deleted from " << filename << std::endl;
			continue; // Skip adding this part's line to the file
		}

		lines.push_back(line);  // If part not found, keep the line in the list
	}

	inFile.close();

	if (!partFound) {
		std::cerr << "Part with ID " << partId << " not found.\n";
		return;
	}

	// Rewrite the file without the deleted part's line
	std::ofstream outFile(filename, std::ios::trunc);
	if (!outFile) {
		std::cerr << "Error: Unable to open file for writing " << filename << std::endl;
		return;
	}

	for (auto it = lines.begin(); it != lines.end(); ++it) {
		outFile << *it;
		if (std::next(it) != lines.end()) { // Check if it's not the last line
			outFile << "\n";
		}
	}

	outFile.close();
}


void Inventory::DeletePartMenu(int& userId) {
	const int consoleWidth = 200;  // Console width for alignment
	const int consoleHeight = 50;  // Console height for vertical centering

	const int boxWidth = 58;      // Width of the box for menu
	const int boxHeight = 10;     // Total lines for the menu box

	int paddingLeft = (consoleWidth - boxWidth) / 2; // Center horizontally
	int paddingTop = (consoleHeight - boxHeight) / 2; // Center vertically

	int partTypeToDelete, partIdToDelete;

	do {
		clearScreen(); // Clear the screen

		// Add vertical padding (empty lines)
		for (int i = 0; i < paddingTop; i++) {
			std::cout << std::endl;
		}

		// Top border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

		// Title inside the border
		std::cout << std::string(paddingLeft, ' ')
			<< " ||                  DELETE PART MENU              || " << std::endl;

		// Middle border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

		// Menu options inside the border
		std::cout << std::string(paddingLeft, ' ')
			<< " ||            1. Delete Engine Part                || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||            2. Delete Electrical Part           || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||            3. Delete Hydraulic Part            || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||            4. Delete Transmission Part         || " << std::endl;
		std::cout << std::string(paddingLeft, ' ')
			<< " ||            5. Exit                             || " << std::endl;

		// Bottom border
		std::cout << std::string(paddingLeft, ' ')
			<< "  ==================================================  " << std::endl;

		std::cout << std::string(paddingLeft, ' ') << "Enter your choice: ";

		partTypeToDelete = _getch(); // Capture the input with _getch()
		std::cout << "\n"; // For clean output

		switch (partTypeToDelete) {
		case '1': {
			std::cout << std::string(paddingLeft, ' ') << "Enter Engine Part ID to delete: ";
			std::cin >> partIdToDelete;
			CAT_INV->PartFactory->deletePartInFile<Engine>(partIdToDelete);
			break;
		}
		case '2': {
			std::cout << std::string(paddingLeft, ' ') << "Enter Electrical Part ID to delete: ";
			std::cin >> partIdToDelete;
			CAT_INV->PartFactory->deletePartInFile<Electrical>(partIdToDelete);
			break;
		}
		case '3': {
			std::cout << std::string(paddingLeft, ' ') << "Enter Hydraulic Part ID to delete: ";
			std::cin >> partIdToDelete;
			CAT_INV->PartFactory->deletePartInFile<Hydraulic>(partIdToDelete);
			break;
		}
		case '4': {
			std::cout << std::string(paddingLeft, ' ') << "Enter Transmission Part ID to delete: ";
			std::cin >> partIdToDelete;
			CAT_INV->PartFactory->deletePartInFile<Transmission>(partIdToDelete);
			break;
		}
		case '5':
			std::cout << std::string(paddingLeft, ' ') << "Exiting delete menu...\n";
			handleUserInput(userId);
			return; // Exit the menu
		default:
			std::cout << std::string(paddingLeft, ' ') << "Invalid choice, please try again.\n";
			std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause to display invalid choice
			break;
		}
	} while (partTypeToDelete != '5');
}

template <typename PartType>
void PartFactory::SortMenuForParts( std::vector<std::shared_ptr<PartType>> parts) {
	system("cls");
	if (parts.empty()) {
		std::cout << "No parts available in this category.\n";
		return;
	}
	std::string type;
	std::cout << "1. PartId\n";
	std::cout << "2. SerialName\n";
	std::cout << "3. Name\n";
	std::cout << "4. Quantity\n";
	std::cout << "5. Manufacturer\n";
	std::cout << "6. Weight\n";
	std::cout << "7. Category\n";
	std::cout << "8. ProductionDate\n";
	std::cout << "9. WarrantyPeriod\n";

	// Check if the part type is Transmission and add specific fields
	if (typeid(PartType) == typeid(Transmission)) {
		std::cout << "10. Trans Type\n";
		std::cout << "11. Gear Count\n";
		std::cout << "12. Torque\n";
		std::cout << "13. Shift Pattern\n";
		type = "TRANS";
	}
	// Check if the part type is Engine and add specific fields
	else if (typeid(PartType) == typeid(Engine)) {
		std::cout << "10. Engine Type\n";
		std::cout << "11. Horse Power\n";
		std::cout << "12. Fuel Type\n";
		std::cout << "13. Fuel Capacity\n";
		type = "ENG";
	}
	// Check if the part type is Hydraulic and add specific fields
	else if (typeid(PartType) == typeid(Hydraulic)) {
		std::cout << "10. Pressure Rating\n";
		std::cout << "11. Fluid Type\n";
		std::cout << "12. Cylinder Bore\n";
		std::cout << "13. Stroke Length\n";
		type = "HYD";
	}
	// Check if the part type is Electrical and add specific fields
	else if (typeid(PartType) ==  typeid(Electrical)) {
		std::cout << "10. Trans Type\n";
		std::cout << "11. Gear Count\n";
		std::cout << "12. Torque\n";
		std::cout << "13. Shift Pattern\n";
		type = "ELE";
	}

	std::cout << "Enter your choice (1 to 13): ";
	int choice;
	std::cin >> choice;

	compareAndSortByAttribute<PartType>(parts, choice,type);
	CAT_INV->PartFactory->printParts(parts);
}

void Inventory::SortPartMenu(int& userId) {
    const int consoleWidth = 200;  // Console width for alignment
    const int consoleHeight = 50;  // Console height for vertical centering

    const int boxWidth = 58;      // Width of the box for menu
    const int boxHeight = 12;     // Total lines for the menu box

    // Calculate padding
    int paddingLeft = (consoleWidth - boxWidth) / 2; // Center horizontally
    int paddingTop = (consoleHeight - boxHeight) / 2; // Center vertically

    int choice;

	clearScreen();
    // Add vertical padding (empty lines)
    for (int i = 0; i < paddingTop; i++) {
        std::cout << std::endl;
    }

    std::cout << std::string(paddingLeft, ' ') << "  ==================================================  " << std::endl;

    // Title inside the border
    std::cout << std::string(paddingLeft, ' ') << " ||                  SORT PARTS MENU               || " << std::endl;

    // Middle border
    std::cout << std::string(paddingLeft, ' ') << "  ==================================================  " << std::endl;

    // Menu options inside the border
    std::cout << std::string(paddingLeft, ' ') << " ||               1. Sort Engine Parts            || " << std::endl;
    std::cout << std::string(paddingLeft, ' ') << " ||               2. Sort Hydraulic Parts         || " << std::endl;
    std::cout << std::string(paddingLeft, ' ') << " ||               3. Sort Transmission Parts      || " << std::endl;
    std::cout << std::string(paddingLeft, ' ') << " ||               4. Sort Electrical Parts       || " << std::endl;
    std::cout << std::string(paddingLeft, ' ') << " ||               5. Exit                        || " << std::endl;

    // Bottom border
    std::cout << std::string(paddingLeft, ' ') << "  ==================================================  " << std::endl;

    // Get user input for menu selection using _getch()
    std::cout << std::string(paddingLeft, ' ') << " Enter your choice: ";
    choice = _getch();  // Get the pressed key without needing Enter key

    // Check for valid input (make sure the input is numeric)
    switch (choice) {
        case '1':
            std::cout << std::string(paddingLeft, ' ') << "\n--- Engine Parts ---\n";
			CAT_INV->PartFactory->SortMenuForParts<Engine>(CAT_INV->Engines);
            break;

        case '2':
            std::cout << std::string(paddingLeft, ' ') << "\n--- Hydraulic Parts ---\n";
			CAT_INV->PartFactory->SortMenuForParts<Hydraulic>(CAT_INV->Hydraulics);
            break;

        case '3':
            std::cout << std::string(paddingLeft, ' ') << "\n--- Transmission Parts ---\n";
			CAT_INV->PartFactory->SortMenuForParts<Transmission>(CAT_INV->Transmissions);
            break;

        case '4':
            std::cout << std::string(paddingLeft, ' ') << "\n--- Electrical Parts ---\n";
			CAT_INV->PartFactory->SortMenuForParts<Electrical>(CAT_INV->ElectricalParts);
            break;

        case '5':
            std::cout << std::string(paddingLeft, ' ') << "Exiting sort menu.\n";
            handleUserInput(userId);
            break;

        default:
            std::cerr << std::string(paddingLeft, ' ') << "Invalid choice! Please enter a valid option.\n";
            break;
    }
}


// Function to check and overwrite the file if it exists
void Inventory::copyAndRenameFile(const std::string& sourceFile, const std::string& destinationFile)
{
	// Check if the destination file already exists
	std::ifstream destFile(destinationFile);
	if (destFile)
	{
		// File exists, so delete it
		std::cout <<std::setw(50)<< "File " << destinationFile << " already exists. Overwriting...\n";
		destFile.close();  // Close the file after checking
		std::remove(destinationFile.c_str());  // Remove the existing file
	}

	// Proceed with copying and renaming
	std::ifstream srcFile(sourceFile, std::ios::binary);
	std::ofstream destFileOut(destinationFile, std::ios::binary);

	// Copy the content of the source file to the destination file
	destFileOut << srcFile.rdbuf();  // Copy the content

	std::cout << std::setw(50)<<"File " << sourceFile << " copied to " << destinationFile << " successfully.\n";

	// Close both files
	srcFile.close();
	destFileOut.close();
}

void Inventory::ExportToCSV(int&  userId)
{
	const int consoleWidth = 150;  // Console width for alignment
	const int consoleHeight = 50;  // Console height for vertical centering
	const std::string successMessage = "Successfully Exported as CSV";

	const int boxWidth = 58;      // Width of the box for the message
	const int boxHeight = 5;      // Total lines for the message box

	int paddingLeft = (consoleWidth - boxWidth) / 2; // Center horizontally
	int paddingTop = (consoleHeight - boxHeight) / 2; // Center vertically

	// Center the screen vertically
	for (int i = 0; i < paddingTop; i++) {
		std::cout << std::endl;
	}
	clearScreen();
	// Top border
	std::cout << std::string(paddingLeft, ' ') << "  ==================================================  " << std::endl;

	// Title inside the border
	std::cout << std::string(paddingLeft, ' ') << " ||          Exporting Parts to CSV                || " << std::endl;

	// Middle border
	std::cout << std::string(paddingLeft, ' ') << "  ==================================================  " << std::endl;

	// Call the function to export the parts to CSV
	copyAndRenameFile("EngineParts.txt", "EngineParts.csv");
	copyAndRenameFile("ElectricalParts.txt", "ElectricalParts.csv");
	copyAndRenameFile("HydraulicParts.txt", "HydraulicParts.csv");
	copyAndRenameFile("TransmissionParts.txt", "TransmissionParts.csv");

	// Center the success message
	int paddingSuccessMessageLeft = (consoleWidth - successMessage.length() - 6) / 2; // For the borders around the message

	// Display the success message inside the border
	std::cout << std::string(paddingSuccessMessageLeft, ' ') << " || " << successMessage << " || " << std::endl;

	// Bottom border
	std::cout << std::string(paddingLeft, ' ') << "  ==================================================  " << std::endl;

	// Pause for a few seconds before returning to the main menu
	std::this_thread::sleep_for(std::chrono::seconds(3));

	// After showing the message, call the main menu again
	handleUserInput(userId);
}

void LoadParts()
{
	CAT_INV->loadParts<Engine>();
	CAT_INV->loadParts<Hydraulic>();
	CAT_INV->loadParts<Electrical>();
	CAT_INV->loadParts<Transmission>();

}



// Function to print the main menu with a proper border and centered in the console
void printMainMenu() {
	const int consoleWidth = 200;  // Console width for alignment
	const int consoleHeight = 50;  // Console height for vertical centering

	const int boxWidth = 58;      // Width of the box for menu
	const int boxHeight = 10;     // Total lines for the menu box

	// Calculate padding
	int paddingLeft = (consoleWidth - boxWidth) / 2; // Center horizontally
	int paddingTop = (consoleHeight - boxHeight) / 2; // Center vertically

	clearScreen(); // Clear the screen

	// Add vertical padding (empty lines)
	for (int i = 0; i < paddingTop; i++) {
		std::cout << std::endl;
	}

	// Top border
	std::cout << std::string(paddingLeft, ' ') << "  ==================================================  " << std::endl;

	// Title inside the border
	std::cout << std::string(paddingLeft, ' ') << " ||                     MAIN MENU                  || " << std::endl;

	// Middle border
	std::cout << std::string(paddingLeft, ' ') << "  ==================================================  " << std::endl;

	// Menu options inside the border
	std::cout << std::string(paddingLeft, ' ') << " ||                  1. Add Part                   || " << std::endl;
	std::cout << std::string(paddingLeft, ' ') << " ||                  2. Update Part                || " << std::endl;
	std::cout << std::string(paddingLeft, ' ') << " ||                  3. Delete Part                || " << std::endl;
	std::cout << std::string(paddingLeft, ' ') << " ||                  4. Print Part                 || " << std::endl;
	std::cout << std::string(paddingLeft, ' ') << " ||                  5. Export as CSV              || " << std::endl;
	std::cout << std::string(paddingLeft, ' ') << " ||                  6. Sort Parts                 || " << std::endl;
	std::cout << std::string(paddingLeft, ' ') << " ||                  7. Exit                       || " << std::endl;

	// Bottom border
	std::cout << std::string(paddingLeft, ' ') << "  ==================================================  " << std::endl;
}

// Main menu logic
void handleUserInput(int& userId) {
	char choice = '\0';  // Initialize choice as a character
	do {
		printMainMenu();  // Print the centered menu

		choice = _getch();  // Get the pressed key
		std::cout << "\n";  // For clean output

		switch (choice) {
		case '1':
			CAT_INV->AddPartMenu(userId);
			break;
		case '2':
			CAT_INV->UpdatePartMenu(userId);
			break;
		case '3':
			CAT_INV->DeletePartMenu(userId);
			break;
		case '4':
			CAT_INV->PrintPartMenu(userId);
			break;
		case '5':
			CAT_INV->ExportToCSV(userId);
			break;
		case '6':
			CAT_INV->SortPartMenu(userId);
			break;
		case '7':
			std::cout << "User " << userId << " is exiting the system...\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
			break;
		}

	} while (choice != '7');  // Exit loop if choice is '7'
}

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



// Function to create a delay
void delay(int milliseconds) {
	Sleep(milliseconds);
}

// Main loader function
void main_loader() {
	int loader;
	gotoxy(50, 15);
	printf("LOADING ");
	for (loader = 1; loader < 40; loader++) {
		delay(50);
		printf("%c", 219); // ASCII character 219 for a filled block
	}
}

// Function to display the welcome screen with the loader
void showLoadingScreen() {
	const int consoleWidth = 150;

	const char* welcomeMessage = "WELCOME TO CATERPILLAR INVENTORY MANAGEMENT SYSTEM";

	// Clear the screen
	clearScreen();
	std::cout << "\n\n\n\n\n\n\n";
	// Print the welcome message centered
	int paddingLeft = (consoleWidth - strlen(welcomeMessage)) / 2;
	for (int i = 0; i < 10; i++) printf("\n"); // Top padding
	gotoxy(paddingLeft, 10); // Center horizontally
	printf("%s\n\n", welcomeMessage);

	// Call the main loader function
	main_loader();

	// Hold for 1 second after loading
	delay(1000);
	clearScreen();
}

//// Function to simulate a loading screen with an alternative character set
//void showLoadingScreen() {
//	const int consoleWidth = 150;
//	
//	const std::string welcomeMessage = "WELCOME TO CATERPILLAR INVENTORY MANAGEMENT SYSTEM";
//
//	// Clear the screen
//	clearScreen();
//
//	// Print the welcome message centered
//	int paddingLeft = (consoleWidth - welcomeMessage.length()) / 2;
//	std::cout << "\n\n\n\n\n\n\n\n\n";
//	std::cout << std::string(paddingLeft, ' ') << welcomeMessage << "\n\n";
//
//	// Progress bar parameters
//	const int progressBarWidth = 50; // Width of the progress bar
//	const int totalSteps = 100;      // Total progress percentage
//
//	std::cout << std::string(paddingLeft, ' ') << "[";
//	for (int i = 0; i < progressBarWidth; i++) {
//		std::cout << "-"; // Placeholder for empty bar
//	}
//	std::cout << "]" << std::endl;
//
//	std::cout << std::string(paddingLeft, ' ') << " ";
//	for (int i = 0; i < progressBarWidth; i++) {
//		std::cout << " ";
//	}
//	std::cout << "\r" << std::flush;
//
//	// Animate the progress bar with alternative characters
//	for (int i = 0; i <= totalSteps; i++) {
//		std::this_thread::sleep_for(std::chrono::milliseconds(30)); // Delay to simulate loading
//		int currentPosition = (i * progressBarWidth) / totalSteps;
//
//		// Update progress bar
//		std::cout << "\r" << std::string(paddingLeft, ' ') << "[";
//		for (int j = 0; j < progressBarWidth; j++) {
//			if (j < currentPosition) {
//				std::cout << "*"; // Filled block for progress
//			}
//			else {
//				std::cout << "-"; // Dash for remaining space
//			}
//		}
//		std::cout << "] " << i << "%" << std::flush;
//	}
//
//	// Hold for 5 seconds
//	std::this_thread::sleep_for(std::chrono::seconds(5));
//	clearScreen();
//}


struct User {
	std::string username;
	std::string password;
};

// Simple user database (for demonstration)
std::unordered_map<std::string, User> userDatabase = {
	{"user1", {"user1", "password1"}},
	{"user2", {"user2", "password2"}},
	{"user3", {"user3", "password3"}}
};

std::mutex inventoryMutex;  // Mutex for synchronizing inventory access

// Function to convert std::string to std::wstring
std::wstring stringToWString(const std::string& str) {
	return std::wstring(str.begin(), str.end());
}

//
//void CreateNewConsole(const std::string& title) {
//	if (AllocConsole()) {
//		SetConsoleTitle(stringToWString(title).c_str());  // Convert and set the title
//		freopen("CONOUT$", "w", stdout);  // Redirect stdout to the new console
//		freopen("CONIN$", "r", stdin);   // Redirect stdin to the new console
//	}
//	else {
//		std::cerr << "Failed to allocate console for " << title << std::endl;
//	}
//}

void userLogin(int userId) {
	std::string username, password;
	bool isAuthenticated = false;

	//CreateNewConsole("User " + std::to_string(userId) + " Console");
	std::cout << "Welcome, User " << userId << "!\n";
	// User authentication loop
	while (!isAuthenticated) {
		std::cout << "User " << userId << ", please login.\n";
		std::cout << "Username: ";
		std::cin >> username;
		std::cout << "Password: ";
		std::cin >> password;

		// Check credentials against the user database
		if (userDatabase.find(username) != userDatabase.end() && userDatabase[username].password == password) {
			std::cout << "Login successful!\n";
			isAuthenticated = true;
		}
		else {
			std::cout << "Invalid username or password. Please try again.\n";
		}
	}

	// After successful login, show the main menu for this user
	handleUserInput(userId);  // Call function to handle menu options for this user
}




int main(int argc, char* argv[]) {

		// Check if command-line arguments are passed
		if (argc != 2) {
			std::cerr << "Usage: program <userId>\n";
			return 1;  // Exit with an error if arguments are not correct
		}

		// Parse the user ID from the command line argument
		int userId = std::stoi(argv[1]);  // Convert the first argument to an integer

	LoadParts();
	showLoadingScreen();
	userLogin(userId);
	
	return 0;
}


