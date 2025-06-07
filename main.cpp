#include <iostream>
#include <cmath>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <string>
#include <limits>
#include <ctime>

// ANSI color codes for cross-platform terminals
const std::string RESET      = "\033[0m";
const std::string RED        = "\033[31m";
const std::string GREEN      = "\033[32m";
const std::string YELLOW     = "\033[33m";
const std::string CYAN       = "\033[36m";
const std::string WHITE      = "\033[97m";

#ifdef _WIN32
  #define CLEAR_CMD "cls"
#else
  #define CLEAR_CMD "clear"
#endif

const std::string LOG_FILE    = "program_log.txt";
const std::string DATA_FILE   = "calculations.txt";

// Helper functions
void logMessage(const std::string& message) {
    std::ofstream log(LOG_FILE, std::ios::app);
    if (log) {
        std::time_t now = std::time(nullptr);
        char buf[20];
        if (std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now))) {
            log << buf << " | " << message << "\n";
        } else {
            log << now << " | " << message << "\n";
        }
    }
}

void clearScreen() {
    std::system(CLEAR_CMD);
}

template<typename T>
T getValidNumericInput(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << YELLOW << prompt << RESET;
        if (std::cin >> value) {
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << RED << "Invalid input, please try again." << RESET << "\n";
        logMessage("Invalid numeric input");
    }
}

bool saveToFile(const std::string& data) {
    std::ofstream file(DATA_FILE, std::ios::app);
    if (!file) {
        logMessage("Failed to open data file for writing");
        return false;
    }
    file << data << "\n";
    return true;
}

void displayHeader(const std::string& title) {
    clearScreen();
    std::cout << CYAN
              << R"(
  __  __    ____  
 |  \/  |  / ___| 
 | |\/| | | |     
 | |  | | | |___  
 |_|  |_|  \____| 
)"
              << RESET
              << WHITE << "\n    " << title << "\n\n" << RESET;
}

void handleInvalidInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << RED << "Invalid selection, please try again." << RESET << "\n";
    logMessage("Invalid menu selection");
}

// Help & Instructions
void displayHelp() {
    displayHeader("Help & Instructions");

    // Option 1
    std::cout << CYAN << "1) Number Comparison" << RESET << "\n"
              << "   - Compares X and Y, reports which is larger or if equal.\n"
              << "   - Also reports if X is odd or even.\n"
              << "   Example: X=3, Y=5 -> \"Y > X | X is odd\"\n\n"
              << "   ASCII Preview:\n"
              << "     [ X ]   [ Y ]\n"
              << "     [ 3 ] > [ 5 ]\n\n";

    // Option 2
    std::cout << CYAN << "2) Function Calculation" << RESET << "\n"
              << "   - Computes:\n"
              << "     f(x) = -2x  if x<=-10 or x>=0\n"
              << "     f(x) = 2/3 x^2 + 1/2 x  if -10<x<0\n"
              << "     f(x) = 1/(sin x + 2)     if 0<x<=π\n"
              << "   Example: x=-12 -> f(x)=24\n\n"
              << "   ASCII Preview:\n"
              << "      f(x)\n"
              << "       ^      .\n"
              << "       |     / \\\n"
              << "       +----+---+---> x\n\n";

    // Option 3
    std::cout << CYAN << "3) Geometric Calculations" << RESET << "\n"
              << "   - Sphere volume: 4/3 π R^3\n"
              << "   - Cone volume:   1/3 π R^2 H\n"
              << "   - Rectangle area: A = a * b\n"
              << "   Example: R=2 sphere->33.51\n\n"
              << "   ASCII Shapes:\n"
              << "     Sphere:     Cone:        Rectangle:\n"
              << "      ***         /\\           +----+\n"
              << "     *   *       /__\\          |    |\n"
              << "      ***         ||           +----+\n\n";

    // Option 4
    std::cout << CYAN << "4) Triangle Area" << RESET << "\n"
              << "   - Area = 1/2 a b sin(θ)\n"
              << "   Example: a=3, b=4, θ=90° -> 6.00\n\n"
              << "   ASCII Shape:\n"
              << "        /|\n"
              << "       / |\n"
              << "      /  |  <-- b\n"
              << "     /_θ_|\n"
              << "      a\n\n";

    // Option 5
    std::cout << CYAN << "5) Shipping Calculator" << RESET << "\n"
              << "   - Calculates cost per 100km based on weight:\n"
              << "     <=2kg:1.1kr  <=6kg:2.2kr  <10kg:3.7kr  <=20kg:4.8kr\n"
              << "   - Distance buckets of 100km.\n"
              << "   Example: 5kg,150km -> 2.2 * 2 = 4.4kr\n\n"
              << "   ASCII Preview:\n"
              << "     _______\n"
              << "    | BOX   |\n"
              << "    |_______|\n\n";

    std::cout << CYAN << "Press any key to return to menu..." << RESET;
    _getch();
}

// Main menu display
void displayMenu() {
    displayHeader("MS - Mini System");
    std::cout << CYAN
              << "+--------------------------------+\n"
              << "|        CALCULATION MENU        |\n"
              << "+--------------------------------+\n"
              << RESET;
    std::cout << GREEN
              << " 1) Number Comparison\n"
              << " 2) Function Calculation\n"
              << " 3) Geometric Calculations\n"
              << " 4) Triangle Area\n"
              << " 5) Shipping Calculator\n"
              << " 6) Help & Instructions\n"
              << " 0) Exit\n"
              << RESET;
}

int main() {
    logMessage("Program started");

    while (true) {
        displayMenu();
        std::cout << "\nSelect task (0-6): ";
        int choice;
        if (!(std::cin >> choice)) {
            handleInvalidInput();
            continue;
        }

        if (choice == 0) {
            logMessage("Program exited by user");
            break;
        }

        switch (choice) {
            case 1: {
                displayHeader("Number Comparison");
                int x = getValidNumericInput<int>("Enter X: ");
                int y = getValidNumericInput<int>("Enter Y: ");
                std::string res;
                if (x == y)      res = "X and Y are equal";
                else if (x > y)  res = "X > Y";
                else             res = "Y > X";
                res += (x % 2 ? " | X is odd" : " | X is even");
                std::cout << WHITE << "\n" << res << "\n" << RESET;
                saveToFile("Comparison: " + res);
                break;
            }
            case 2: {
                displayHeader("Function Calculation");
                double x = getValidNumericInput<double>("Enter x: ");
                double y;
                if (x <= -10 || x >= 0)           y = -2 * x;
                else if (x < 0)                   y = (2.0/3)*x*x + 0.5*x;
                else if (x <= M_PI)               y = 1.0/(std::sin(x)+2);
                else { std::cout << RED << "x out of valid range\n" << RESET; logMessage("Invalid x"); break; }
                std::cout << WHITE << "\nf(x)=" << y << "\n" << RESET;
                saveToFile("f(" + std::to_string(x) + ")=" + std::to_string(y));
                break;
            }
            case 3: {
                displayHeader("Geometric Calculations");
                std::cout << "1) Sphere Volume  2) Cone Volume  3) Rectangle Area\n";
                int opt = getValidNumericInput<int>("Choice: ");
                if (opt==1) {
                    double R = getValidNumericInput<double>("Radius: ");
                    double v = (4.0/3)*M_PI*R*R*R;
                    std::cout << WHITE << "\nSphere vol: " << v << "\n" << RESET;
                    saveToFile("Sphere R=" + std::to_string(R) + " V=" + std::to_string(v));
                } else if (opt==2) {
                    double R = getValidNumericInput<double>("Radius: ");
                    double H = getValidNumericInput<double>("Height: ");
                    double v = (1.0/3)*M_PI*R*R*H;
                    std::cout << WHITE << "\nCone vol: " << v << "\n" << RESET;
                    saveToFile("Cone R=" + std::to_string(R) + " H=" + std::to_string(H)
                               + " V=" + std::to_string(v));
                } else if (opt==3) {
                    double a = getValidNumericInput<double>("Side a: ");
                    double b = getValidNumericInput<double>("Side b: ");
                    double area = a*b;
                    std::cout << WHITE << "\nRectangle area: " << area << "\n" << RESET;
                    saveToFile("Rect a=" + std::to_string(a) + " b=" + std::to_string(b)
                               + " A=" + std::to_string(area));
                } else {
                    std::cout << RED << "Invalid option\n" << RESET;
                    logMessage("Invalid geometric sub-choice");
                }
                break;
            }
            case 4: {
                displayHeader("Triangle Area");
                int deg = getValidNumericInput<int>("Angle (deg): ");
                double rad = deg*M_PI/180.0;
                double a = getValidNumericInput<double>("Side a: ");
                double b = getValidNumericInput<double>("Side b: ");
                double area = 0.5*a*b*std::sin(rad);
                std::cout << WHITE << "\nTriangle area: " << area << "\n" << RESET;
                saveToFile("Triangle α=" + std::to_string(deg)
                           + " a=" + std::to_string(a)
                           + " b=" + std::to_string(b)
                           + " A=" + std::to_string(area));
                break;
            }
            case 5: {
                displayHeader("Shipping Calculator");
                double w = getValidNumericInput<double>("Weight (kg): ");
                int d    = getValidNumericInput<int>("Distance (km): ");
                double rate;
                if      (w <= 2)  rate = 1.1;
                else if (w <= 6)  rate = 2.2;
                else if (w < 10)  rate = 3.7;
                else if (w <=20)  rate = 4.8;
                else { std::cout << RED<<"Weight too large\n"<<RESET; break; }
                if (d<=0) { std::cout<<RED<<"Invalid distance\n"<<RESET; break; }
                double cost = rate * ((d+99)/100);
                std::cout << WHITE << "\nPrice: " << cost << " kr\n" << RESET;
                saveToFile("Shipping w=" + std::to_string(w)
                           + " d=" + std::to_string(d)
                           + " cost=" + std::to_string(cost));
                break;
            }
            case 6:
                displayHelp();
                break;
            default:
                handleInvalidInput();
        }

        std::cout << "\nPress any key to continue...";
        _getch();
        clearScreen();
    }

    return 0;
}
