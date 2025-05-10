#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <limits>
#include <ctime>  // Add this header for time functions

// Constants
const std::string LOG_FILE = "program_log.txt";
const std::string DATA_FILE = "calculations.txt";

// Function declarations
void logMessage(const std::string& message);
void clearScreen();
void displayMenu();
bool saveToFile(const std::string& data);
void handleInvalidInput();
void displayHeader(const std::string& title);

template<typename T>
T getValidNumericInput(const std::string& prompt);

int main() {
    std::ofstream logFile(LOG_FILE, std::ios::app);
    logMessage("Program started");

    while (true) {
        displayMenu();
        int choice;
        std::cout << "Select task (1-5, 0 to exit): ";
        if (!(std::cin >> choice)) {
            handleInvalidInput();
            continue;
        }

        if (choice == 0) break;

        switch (choice) {
        case 1: {
            displayHeader("Number Comparison");
            int x = getValidNumericInput<int>("Enter the first number (X): ");
            int y = getValidNumericInput<int>("Enter the second number (Y): ");

            if (x == y)
                std::cout << "\nThe numbers are equal \n";
            else if (x > y)
                std::cout << "\nX is greater than Y \n";
            else
                std::cout << "\nY is greater than X \n";

            int modulo = x % 2;
            if (modulo == 1)
                std::cout << "and the number X is odd \n" << std::endl;
            else
                std::cout << "and the number X is even \n" << std::endl;
            break;
        }
        case 2: {
            displayHeader("Function Calculation");
            float x = getValidNumericInput<float>("Enter the value of x: ");
            float y;

            if (x <= -10 || x >= 0) {
                y= (-2)*x ;
            } else if ((-10 <= x) && (x < 0)) {
                y=(2.0/3) * x * x +((1.0/2) * x);
            } else if ((0 < x) && ( x <= M_PI)) {
                y=1/(sin (x) + 2);
            } else {
                std::cout << "An invalid value for x was entered" << std::endl;
            }
            std::cout << "The value of the function for x = " << x << " is " << y << std::endl;
            break;
        }
        case 3: {
            displayHeader("Geometric Calculations");
            double objetosc_Kuli, objetosc_Stozka, pole, R, H, boka, bokb;
            int i = getValidNumericInput<int>("Please select below what you want to calculate: \n 1 - Sphere volume\n 2 - Cone volume \n 3 - Rectangle area \n");

            switch(i) {
            case 1:
                R = getValidNumericInput<double>("Enter the radius of the sphere: ");
                objetosc_Kuli = (4/3.0)*M_PI*R*R*R;
                std::cout<<"The volume of your sphere is: \n"<<objetosc_Kuli<<std::endl;
                break;

            case 2:
                R = getValidNumericInput<double>("First enter the radius of the cone: ");
                H = getValidNumericInput<double>("Now write the height of the cone: ");
                objetosc_Stozka = (1/3.0)*M_PI*R*R*H;
                std::cout<<"The volume of your cone is: \n"<<objetosc_Stozka<<std::endl;
                break;

            case 3:
                boka = getValidNumericInput<double>("Enter the length of the first side of the rectangle: ");
                bokb = getValidNumericInput<double>("Enter the length of the second side of the rectangle: ");
                pole = boka * bokb;
                std::cout<<"The area of your rectangle is: \n"<<pole<<std::endl;
                break;

            default:
                std::cout<<"The entered data is incorrect \n"<<std::endl;
                break;
            }
            break;
        }
        case 4: {
            displayHeader("Triangle Area Calculation");
            int stopnie = getValidNumericInput<int>("First enter the angle to calculate the area of the triangle: ");
            double radiany = stopnie * M_PI / 180;
            double a = getValidNumericInput<double>("Enter the length of side a: ");
            double b = getValidNumericInput<double>("Enter the length of side b: ");

            double pole = ((a * b) / 2) * sin(radiany);
            std::cout << "\nThe area of the triangle is: " << pole << std::endl;
            break;
        }
        case 5: {
            displayHeader("Shipping Calculator");
            float waga = getValidNumericInput<float>("Enter the weight of the package: ");
            int odleglosc = getValidNumericInput<int>("Enter the distance in km: ");
            float oplata, cena;

            if (waga <= 2) {
                oplata = 1.1;
            } else if (waga > 2 && waga <= 6) {
                oplata = 2.2;
            } else if (waga > 6 && waga < 10) {
                oplata = 3.7;
            } else if (waga > 10 && waga <= 20) {
                oplata = 4.8;
            } else {
                std::cout << "\nIt is not possible to send a package weighing more than 20 kg over such a distance\n";
                return 0;
            }

            if (odleglosc <= 0) {
                std::cout << "\nThe specified distance must be greater than zero\n";
                return 0;
            } else if (odleglosc <= 100) {
                cena = oplata;
            } else if (odleglosc <= 200) {
                cena = oplata * 2;
            } else if (odleglosc <= 300) {
                cena = oplata * 3;
            } else if (odleglosc <= 400) {
                cena = oplata * 4;
            } else {
                std::cout << "\nWe do not handle shipments over such long distances\n";
                return 0;
            }

            std::cout << "Price: " << cena << " kr\n";
            break;
        }
        default:
            std::cout << "Invalid choice! Please select a valid task.\n";
            logMessage("Invalid task selection");
            break;
        }

        std::cout << "\nPress any key to continue...";
        _getch();
        clearScreen();
    }

    logMessage("Program ended");
    return 0;
}

void displayMenu() {
    std::cout << "+--------------------------------+\n";
    std::cout << "|        CALCULATION MENU        |\n";
    std::cout << "+--------------------------------+\n";
    std::cout << "| 1. Number Comparison          |\n";
    std::cout << "| 2. Function Calculation       |\n";
    std::cout << "| 3. Geometric Calculations     |\n";
    std::cout << "| 4. Triangle Area              |\n";
    std::cout << "| 5. Shipping Calculator        |\n";
    std::cout << "| 0. Exit                       |\n";
    std::cout << "+--------------------------------+\n";
}

void logMessage(const std::string& message) {
    std::ofstream log(LOG_FILE, std::ios::app);
    if (log.is_open()) {
        std::time_t now = std::time(nullptr);
        log << std::ctime(&now) << ": " << message << "\n";
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void handleInvalidInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input! Please try again.\n";
    logMessage("Invalid input detected");
}

void displayHeader(const std::string& title) {
    std::cout << "\n+--------------------------------+\n";
    std::cout << "  " << title << "\n";
    std::cout << "+--------------------------------+\n\n";
}

bool saveToFile(const std::string& data) {
    std::ofstream file(DATA_FILE, std::ios::app);
    if (!file.is_open()) {
        logMessage("Error: Unable to open data file");
        return false;
    }
    file << data << "\n";
    return true;
}

template<typename T>
T getValidNumericInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        }
        handleInvalidInput();
    }
}
