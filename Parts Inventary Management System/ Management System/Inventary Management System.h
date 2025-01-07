#include <iostream>
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
#include<set>
#include <fstream>
#include <iostream>
#include <string>
#include<chrono>
#include<thread>

static std::set<int> EnginePartIDs;
static std::set<int> HydraulicPartIDs;
static std::set<int> TransmissionPartIDs;
static std::set<int> ElectricalPartIDs;


void UniqueHandler(int& PartId, std::string& Prefix);
// Base Class


class Observer {
public:
	virtual void Update(int partId, const std::string& name, int quantity) = 0;
	virtual ~Observer() = default;
};

class Interface
{
private:
	std::vector<std::shared_ptr<Observer>> Observers;

public:
	void AddObserver(std::shared_ptr<Observer> Observer)
	{
		Observers.push_back(Observer);
	}

	void RemoveObserver(std::shared_ptr<Observer> Observer)
	{
		Observers.erase(std::remove(Observers.begin(), Observers.end(), Observer), Observers.end());
	}

	void Notify(int partId, const std::string& name, int quantity)
	{
		for (const auto& Obs : Observers)
		{
			Obs->Update(partId, name, quantity);
		}
	}


};

class LowStockAlert : public Observer {
public:
	void Update(int partId, const std::string& name, int quantity) override {
		std::cout << "ALERT: Stock for part '" << name << "' (ID: " << partId
			<< ") is low. Current quantity: " << quantity << ".\n";
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
	
};

class Part : public Interface {
protected:
	int PartId;
	std::string SerialName;
	std::string Name;
	int Quantity;
	std::string Manufacturer;
	double Weight;
	std::string Category;
	std::string ProductionDate;
	int WarrantyPeriod;

public:
	// Constructor
	Part();
	Part(int partId, const std::string& SerialNumber, const std::string& name, int quantity, const std::string& manufacturer,
		double weight, const std::string& category, const std::string& productionDate, int warrantyPeriod)
		: PartId(partId), SerialName(SerialNumber),Name(name), Quantity(quantity), Manufacturer(manufacturer),
		Weight(weight), Category(category), ProductionDate(productionDate), WarrantyPeriod(warrantyPeriod) {}

	// Getters
	int GetPartId() const { return PartId; }
	std::string GetSerialNumber() const { return SerialName; }
	std::string GetName() const { return Name; }
	int GetQuantity() const { return Quantity; }
	std::string GetManufacturer() const { return Manufacturer; }
	double GetWeight() const { return Weight; }
	std::string GetCategory() const { return Category; }
	std::string GetProductionDate() const { return ProductionDate; }
	int GetWarrantyPeriod() const { return WarrantyPeriod; }


	// Setters
	void SetPartId(int partId) { PartId = partId; }
	void SetSerialName(const std::string& SerialNumber) { SerialName = SerialNumber; }
	void SetName(const std::string& name) { Name = name; }
	//void SetQuantity(int quantity) { Quantity = quantity; }
	void SetQuantity(int quantity) {
		Quantity = quantity;
		if (Quantity < 10) { // Threshold for low stock
			Notify(PartId, Name, Quantity);
		}
	}

	void SetManufacturer(const std::string& manufacturer) { Manufacturer = manufacturer; }
	void SetWeight(double weight) { Weight = weight; }
	void SetCategory(const std::string& category) { Category = category; }
	void SetProductionDate(const std::string& productionDate) { ProductionDate = productionDate; }
	void SetWarrantyPeriod(int warrantyPeriod) { WarrantyPeriod = warrantyPeriod; }


	// Common attributes initializer
	 virtual void initializeAttributes(std::string &Prefix ) {
		
		UniqueHandler(PartId, Prefix);


		std::cout << "Enter Serial Number: ";
		std::getline(std::cin, SerialName);

		std::cout << "Enter Name: ";
		std::getline(std::cin, Name);

		std::cout << "Enter Quantity: ";
		std::cin >> Quantity;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter Manufacturer: ";
		std::getline(std::cin, Manufacturer);

		std::cout << "Enter Weight: ";
		std::cin >> Weight;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter Category: ";
		std::getline(std::cin, Category);

		std::cout << "Enter Production Date: ";
		std::getline(std::cin, ProductionDate);

		std::cout << "Enter Warranty Period (months): ";
		std::cin >> WarrantyPeriod;

	}

	virtual void saveToFile(const std::string& fileName) const = 0;

	virtual void Display() const {
		std::cout << std::left << std::setw(7) << PartId << " | "
			<< std::setw(13) << SerialName << " | "
			<< std::setw(20) << Name << " | "
			<< std::setw(8) << Quantity << " | "
			<< std::setw(16) << Manufacturer << " | "
			<< std::setw(6) << Weight << " | "
			<< std::setw(10) << Category << " | "
			<< std::setw(10) << ProductionDate << " | "
			<< std::setw(8) << WarrantyPeriod;
	}


	virtual int UpdatePart() 
	{
		system("cls");
		// Display update options
		std::cout << "Update Options:\n";
		std::cout << "1. Name\n2. SerialNumber\n3. Quantity\n4. Manufacturer\n5. Weight\n6. Category\n7. ProductionDate\n8. WarrantyPeriod\n";
		std::cout << "\nEnter 0  to Update Part Specific Update";

		int choice;
		std::cout << "\nEnter the field number to update: ";
		std::cin >> choice;
		if (!choice) return 1;

		// Get the new value
		std::cout << "Enter the new value: ";
		std::string newValue;
		std::cin.ignore();
		std::getline(std::cin, newValue);

		if (choice < 1 || choice > 8) {
			std::cout << "Invalid field choice. Please select a valid option (1 to 4).\n";
			return 0; // Exit the function without prompting for a new value
		}
		// Update fields based on user input
		switch (choice) {
		case 1: this->SetName(newValue); break;
		case 2: this->SetSerialName(newValue); break;
		case 3: this->SetQuantity(std::stoi(newValue)); break;
		case 4: this->SetManufacturer(newValue); break;
		case 5: this->SetWeight(stod(newValue)); break;
		case 6: this->SetCategory(newValue); break;
		case 7: this->SetProductionDate(newValue); break;
		case 8: this->SetWarrantyPeriod(std::stoi(newValue)); break;
		default:
			break;
		}

		return 0;
	}


	virtual ~Part() = default;


};



// Derived Class: Engine
class Engine : public Part {
private:
	std::string EngineType;
	int HorsePower;
	std::string FuelType;
	double FuelCapacity;


public:
	Engine();
	Engine(int partId, const std::string& SerialNumber, const std::string& name, int quantity, const std::string& manufacturer,
		double weight, const std::string& category, const std::string& productionDate, int warrantyPeriod,
		const std::string& engineType, int horsePower, const std::string& fuelType, double fuelCapacity)
		: Part(partId, SerialNumber,name, quantity, manufacturer, weight, category, productionDate, warrantyPeriod),
		EngineType(engineType), HorsePower(horsePower), FuelType(fuelType), FuelCapacity(fuelCapacity) {}

	// Getters and Setters
	std::string GetEngineType() const { return EngineType; }
	int GetHorsePower() const { return HorsePower; }
	std::string GetFuelType() const { return FuelType; }
	double GetFuelCapacity() const { return FuelCapacity; }

	void SetEngineType(const std::string& engineType) { EngineType = engineType; }
	void SetHorsePower(int horsePower) { HorsePower = horsePower; }
	void SetFuelType(const std::string& fuelType) { FuelType = fuelType; }
	void SetFuelCapacity(double fuelCapacity) { FuelCapacity = fuelCapacity; }

	void initializeAttributes(std::string &Prefix)  {
		Part::initializeAttributes(Prefix);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter Engine Type: ";
		std::getline(std::cin, EngineType);

		std::cout << "Enter Horse Power: ";
		std::cin >> HorsePower;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter Fuel Type: ";
		std::getline(std::cin, FuelType);

		std::cout << "Enter Fuel Capacity: ";
		std::cin >> FuelCapacity;
	}



	void saveToFile(const std::string& fileName) const override{
		std::ofstream outFile(fileName, std::ios::app); // Open file in append mode
		if (outFile.is_open()) {
			outFile << "\n" << PartId << "," << SerialName << "," << Name << "," << Quantity << "," << Manufacturer << ","
				<< Weight << "," << Category << "," << ProductionDate << "," << WarrantyPeriod << "," << EngineType
				<< "," << HorsePower << "," << FuelType << "," << FuelCapacity ;
		}
	}

	
	void Display() const override {
		Part::Display();
		std::cout << " | " << std::setw(12) << EngineType
			<< " | " << std::setw(12) << HorsePower
			<< " | " << std::setw(10) << FuelType
			<< " | " << std::setw(12) << FuelCapacity << "\n";
		std::cout  << std::string(185, '-') ;
	}


	int UpdatePart() override {
		system("cls");
		if (Part::UpdatePart())
		{
			system("cls");
			std::cout << "1. EngineType\n2. HorsePower\n3. FuelType\n4. FuelCapacity\n";
			int choice;
			std::cout << "Enter the field number to update: ";
			std::cin >> choice;

			if (choice < 1 || choice > 4) {
				std::cout << "Invalid field choice. Please select a valid option (1 to 4).\n";
				return 0; // Exit the function without prompting for a new value
			}

			// Get the new value
			std::cout << "Enter the new value: ";
			std::string newValue;
			std::cin.ignore();
			std::getline(std::cin, newValue);

			switch (choice) {
			case 1: this->SetEngineType(newValue); break;
			case 2: this->SetHorsePower(std::stoi(newValue)); break;
			case 3: this->SetFuelType(newValue); break;
			case 4: this->SetFuelCapacity(std::stod(newValue)); break;
			default: std::cout << "Invalid field choice.\n"; break;

			}
		}
		return 1;
	}


	
};


// Derived Class: Hydraulic
class Hydraulic : public Part {
private:
	int PressureRating;
	std::string FluidType;
	double CylinderBore;
	double StrokeLength;

public:
	Hydraulic();
	Hydraulic(int partId, const std::string& SerialNumber, const std::string& name, int quantity, const std::string& manufacturer,
		double weight, const std::string& category, const std::string& productionDate, int warrantyPeriod,
		int pressureRating, const std::string& fluidType, double cylinderBore, double strokeLength)
		: Part(partId, SerialNumber,name, quantity, manufacturer, weight, category, productionDate, warrantyPeriod),
		PressureRating(pressureRating), FluidType(fluidType), CylinderBore(cylinderBore), StrokeLength(strokeLength) {}

	// Getters and Setters
	int GetPressureRating() const { return PressureRating; }
	std::string GetFluidType() const { return FluidType; }
	double GetCylinderBore() const { return CylinderBore; }
	double GetStrokeLength() const { return StrokeLength; }

	void SetPressureRating(int pressureRating) { PressureRating = pressureRating; }
	void SetFluidType(const std::string& fluidType) { FluidType = fluidType; }
	void SetCylinderBore(double cylinderBore) { CylinderBore = cylinderBore; }
	void SetStrokeLength(double strokeLength) { StrokeLength = strokeLength; }

	void initializeAttributes(std::string &Prefix) override {
		Part::initializeAttributes(Prefix);
		std::cout << "Enter Pressure Rating: ";
		std::cin >> PressureRating;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter Fluid Type: ";
		std::getline(std::cin, FluidType);

		std::cout << "Enter Cylinder Bore: ";
		std::cin >> CylinderBore;

		std::cout << "Enter Stroke Length: ";
		std::cin >> StrokeLength;
	}

	void saveToFile(const std::string& fileName) const override{
		std::ofstream outFile(fileName, std::ios::app); // Open file in append mode
		if (outFile.is_open()) {
			outFile << "\n" << PartId << "," << SerialName << "," << Name << "," << Quantity << "," << Manufacturer << ","
				<< Weight << "," << Category << "," << ProductionDate << "," << WarrantyPeriod << "," << PressureRating
				<< "," << FluidType << "," << CylinderBore << "," << StrokeLength;
		}
	}



	void Display() const override {
		Part::Display();
		std::cout<< " | " << std::setw(15) << PressureRating
			<< " | " << std::setw(12) << FluidType
			<< " | " << std::setw(12) << CylinderBore
			<< " | " << std::setw(12) << StrokeLength << "\n";
		std::cout << std::string(185, '-') ;
	}


	int UpdatePart() override {
		system("cls");
		if (Part::UpdatePart()) {
			system("cls");
			std::cout << "1. PressureRating\n2. FluidType\n3. CylinderBore\n4. StrokeLength\n";
			int choice;
			std::cout << "Enter the field number to update: ";
			std::cin >> choice;

			if (choice < 1 || choice > 4) {
				std::cout << "Invalid field choice. Please select a valid option (1 to 4).\n";
				return 0; // Exit the function without prompting for a new value
			}

			// Get the new value
			std::cout << "Enter the new value: ";
			std::string newValue;
			std::cin.ignore();
			std::getline(std::cin, newValue);

			switch (choice) {
			case 1: this->SetPressureRating(stoi(newValue)); break;
			case 2: this->SetFluidType(newValue); break;
			case 3: this->SetCylinderBore(std::stod(newValue)); break;
			case 4: this->SetStrokeLength(std::stod(newValue)); break;
			default: std::cout << "Invalid field choice.\n"; break;
			}
		}

		return 1;
	}
	


};


// Derived Class: Electrical
class Electrical : public Part {
private:
	int Voltage;
	int Current;
	std::string InsulationType;
	double PowerRating;

public:
	Electrical();
	Electrical(int partId, const std::string& SerialNumber, const std::string& name, int quantity, const std::string& manufacturer,
		double weight, const std::string& category, const std::string& productionDate, int warrantyPeriod,
		int voltage, int current, const std::string& insulationType, double powerRating)
		: Part(partId, SerialNumber,name, quantity, manufacturer, weight, category, productionDate, warrantyPeriod),
		Voltage(voltage), Current(current), InsulationType(insulationType), PowerRating(powerRating) {}

	// Getters and Setters
	int GetVoltageRating() const { return Voltage; }
	int GetCurrentRating() const { return Current; }
	std::string GetInsulationType() const { return InsulationType; }
	double GetPowerConsumption() const { return PowerRating; }

	void SetVoltage(int voltage) { Voltage = voltage; }
	void SetCurrent(int current) { Current = current; }
	void SetInsulationType(const std::string& insulationType) { InsulationType = insulationType; }
	void SetPowerRating(double powerRating) { PowerRating = powerRating; }


	void initializeAttributes(std::string &Prefix) override {
		Part::initializeAttributes(Prefix);
		std::cout << "Enter Voltage Rating: ";
		std::cin >> Voltage;

		std::cout << "Enter Current Rating: ";
		std::cin >> Current;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter Insulation Type: ";
		std::getline(std::cin, InsulationType);

		std::cout << "Enter Power Consumption: ";
		std::cin >> PowerRating;
	}

	void saveToFile(const std::string& fileName) const override {
		std::ofstream outFile(fileName, std::ios::app); // Open file in append mode
		if (outFile.is_open()) {
			outFile << "\n" << PartId << "," << SerialName << "," << Name << "," << Quantity << "," << Manufacturer << ","
				<< Weight << "," << Category << "," << ProductionDate << "," << WarrantyPeriod << "," << Voltage
				<< "," << Current << "," << InsulationType << "," << PowerRating;
		}
	}


	void Display() const override {
		Part::Display();
		std::cout << " | " << std::setw(13) << Voltage
			<< " | " << std::setw(13) << Current
			<< " | " << std::setw(11) << PowerRating
			<< " | " << std::setw(14) << InsulationType << "\n";
		std::cout << std::string(185, '-');
	}

	int UpdatePart() override {
		system("cls");
		if (Part::UpdatePart())
		{
			system("cls");
			std::cout << "1. Voltage\n2. Current\n3. InsulationType\n4. PowerRating\n";
			int choice;
			std::cout << "Enter the field number to update: ";
			std::cin >> choice;


			if (choice < 1 || choice > 4) {
				std::cout << "Invalid field choice. Please select a valid option (1 to 4).\n";
				return 0; // Exit the function without prompting for a new value
			}

			// Get the new value
			std::cout << "Enter the new value: ";
			std::string newValue;
			std::cin.ignore();
			std::getline(std::cin, newValue);

			switch (choice) {
			case 1: this->SetVoltage(std::stoi(newValue)); break;
			case 2: this->SetCurrent(std::stoi(newValue)); break;
			case 3: this->SetInsulationType(newValue); break;
			case 4: this->SetPowerRating(std::stod(newValue)); break;
			default: std::cout << "Invalid field choice.\n"; break;

			}
		}
		return 1;
	}

	
};


// Derived Class: Transmission
class Transmission : public Part {
	private:
		std::string TransmissionType;
		int GearCount;
		int TorqueRating;
		std::string ShiftPattern;

	public:
		// Constructor
		Transmission();

		Transmission(int partId, const std::string& SerialNumber, const std::string& name, int quantity, const std::string& manufacturer,
			double weight, const std::string& category, const std::string& productionDate, int warrantyPeriod,
			const std::string& transmissionType, int gearCount, int torqueRating, const std::string& shiftPattern)
			: Part(partId, SerialNumber, name, quantity, manufacturer, weight, category, productionDate, warrantyPeriod),
			TransmissionType(transmissionType), GearCount(gearCount), TorqueRating(torqueRating), ShiftPattern(shiftPattern) {}

		// Getters and Setters
		std::string GetTransmissionType() const { return TransmissionType; }
		int GetGearCount() const { return GearCount; }
		int GetTorqueRating() const { return TorqueRating; }
		std::string GetShiftPattern() const { return ShiftPattern; }

		void SetTransmissionType(const std::string& transmissionType) { TransmissionType = transmissionType; }
		void SetGearCount(int gearCount) { GearCount = gearCount; }
		void SetTorqueRating(int torqueRating) { TorqueRating = torqueRating; }
		void SetShiftPattern(const std::string& shiftPattern) { ShiftPattern = shiftPattern; }

		void initializeAttributes(std::string &Prefix) override {
			Part::initializeAttributes(Prefix);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter Transmission Type: ";
			std::getline(std::cin, TransmissionType);

			std::cout << "Enter Gear Count: ";
			std::cin >> GearCount;

			std::cout << "Enter Torque Rating: ";
			std::cin >> TorqueRating;

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter Shift Pattern: ";
			std::getline(std::cin, ShiftPattern);
		}

		void saveToFile(const std::string& fileName) const override {
			std::ofstream outFile(fileName, std::ios::app); // Open file in append mode
			if (outFile.is_open()) {
				outFile << "\n" << PartId << "," << SerialName << "," << Name << "," << Quantity << "," << Manufacturer << ","
					<< Weight << "," << Category << "," << ProductionDate << "," << WarrantyPeriod << "," << TransmissionType
					<< "," << GearCount << "," << TorqueRating << "," << ShiftPattern;
			}
		}

		void Display() const override {
			Part::Display();
			std::cout << " | " << std::setw(12) << TransmissionType
				<< " | " << std::setw(12) << GearCount
				<< " | " << std::setw(7) << TorqueRating
				<< " | " << std::setw(14) << ShiftPattern << "\n";
			std::cout << std::string(185, '-');
		}

		int UpdatePart() override {
			system("cls");
			if (Part::UpdatePart())
			{
				system("cls");
				std::cout << "1. TransmissionType\n2. GearCount\n3. TorqueRating\n4. ShiftPattern\n";
				int choice;
				std::cout << "Enter the field number to update: ";
				std::cin >> choice;

				if (choice < 1 || choice > 4) {
					std::cout << "Invalid field choice. Please select a valid option (1 to 4).\n";
					return 0; // Exit the function without prompting for a new value
				}


				// Get the new value
				std::cout << "Enter the new value: ";
				std::string newValue;
				std::cin.ignore();
				std::getline(std::cin, newValue);

				switch (choice) {
				case 1: this->SetTransmissionType(newValue); break;
				case 2: this->SetGearCount(std::stoi(newValue)); break;
				case 3: this->SetTorqueRating(stoi(newValue)); break;
				case 4: this->SetShiftPattern(newValue); break;
				default: std::cout << "Invalid field choice.\n"; break;

				}
			}
			return 1;
		}

};

class PartFactory {
		public:
			// Create a part of type Engine

			static std::shared_ptr<Engine> CreateEngine(int partId, const std::string& SerialNumber, const std::string& Name, int quantity,
				const std::string& manufacturer, double weight, const std::string& category, const std::string& productionDate,
				int warrantyPeriod, const std::string& engineType, int horsePower, const std::string& fuelType, double fuelCapacity) {

				return std::make_shared<Engine>(partId, SerialNumber, Name, quantity, manufacturer, weight, category, productionDate, warrantyPeriod,
					engineType, horsePower, fuelType, fuelCapacity);
			}

			static std::shared_ptr<Engine> CreateEngine() {

				return std::make_shared<Engine>();
			}


			// Create a part of type Hydraulic
			static std::shared_ptr<Hydraulic> CreateHydraulic(int partId, const std::string& SerialNumber, const std::string& Name, int quantity,
				const std::string& manufacturer, double weight, const std::string& category, const std::string& productionDate,
				int warrantyPeriod, int pressureRating, const std::string& fluidType, double cylinderBore, double strokeLength) {

				return std::make_shared<Hydraulic>(partId, SerialNumber, Name, quantity, manufacturer, weight, category, productionDate, warrantyPeriod,
					pressureRating, fluidType, cylinderBore, strokeLength);
			}

			// Create a part of type Hydraulic
			static std::shared_ptr<Hydraulic> CreateHydraulic() {

				return std::make_shared<Hydraulic>();
			}

			// Create a part of type Electrical
			static std::shared_ptr<Electrical> CreateElectrical(int partId, const std::string& SerialNumber, const std::string& Name, int quantity,
				const std::string& manufacturer, double weight, const std::string& category, const std::string& productionDate,
				int warrantyPeriod, int voltage, int current, const std::string& insulationType, double powerRating) {

				return std::make_shared<Electrical>(partId, SerialNumber, Name, quantity, manufacturer, weight, category, productionDate, warrantyPeriod,
					voltage, current, insulationType, powerRating);
			}

			static std::shared_ptr<Electrical> CreateElectrical() {

				return std::make_shared<Electrical>();
			}

			// Create a part of type Transmission
			static std::shared_ptr<Transmission> CreateTransmission(int partId, const std::string& SerialNumber, const std::string& Name, int quantity,
				const std::string& manufacturer, double weight, const std::string& category, const std::string& productionDate,
				int warrantyPeriod, const std::string& transmissionType, int gearCount, int torqueRating, const std::string& shiftPattern) {

				return std::make_shared<Transmission>(partId, SerialNumber, Name, quantity, manufacturer, weight, category, productionDate, warrantyPeriod,
					transmissionType, gearCount, torqueRating, shiftPattern);
			}

			static std::shared_ptr<Transmission> CreateTransmission() {

				return std::make_shared<Transmission>();
			}

			template<typename PartType>
			void AddPart();

			template<typename PartType>
			void printParts(const std::vector<std::shared_ptr<PartType>>& parts) const;

			template<typename PartType>
			void updatePartDetails(std::vector<std::shared_ptr<PartType>>& parts, int partId);
			template<typename PartType>
			void updatePartInFile(int partId, std::shared_ptr<PartType> updatedPart);

			template<typename PartType>
			void deletePartInFile(int partId);

			template <typename PartType>
			void SortMenuForParts(std::vector<std::shared_ptr<PartType>> parts);

			
};


class Inventory
{
private:
	static Inventory* InventoryObj;

	static std::mutex mtx;
	Inventory() {};

public:
	Inventory(const Inventory&) = delete;
	Inventory& operator=(const Inventory&) = delete;

	static Inventory* getInventory() {
		if (InventoryObj == nullptr) {
			std::lock_guard<std::mutex> lock(mtx);
			if (InventoryObj == nullptr) {
				InventoryObj = new Inventory();
			}
		}
		return InventoryObj;
	}


	std::vector<std::shared_ptr<Engine>> Engines;
	std::vector<std::shared_ptr<Hydraulic>>Hydraulics;
	std::vector<std::shared_ptr<Electrical>> ElectricalParts;
	std::vector<std::shared_ptr<Transmission>>Transmissions;

	std::shared_ptr<PartFactory> PartFactory;

	std::shared_ptr<LowStockAlert> alert = std::make_shared<LowStockAlert>();


	
	void AddPartMenu(int &userId);
	template<typename PartType>
	void loadParts();
	void UpdatePartMenu(int& userId);
	void PrintPartMenu(int& userId) const;
	void DeletePartMenu(int& userId);
	void copyAndRenameFile(const std::string & sourceFile, const std::string & destinationFile);
	void ExportToCSV(int& userId);
	void SortPartMenu(int&userId);


	//void deleteMenu();

	void displayMessage() {
		std::cout << "Hello from Thread-Safe Inventary!" << std::endl;
	}

	~Inventory() {
		std::cout << "Inventory Instance Destroyed!" << std::endl;
	}

};