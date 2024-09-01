#include "../header/terminal.h"
#include "../header/Player.h"
#include "../header/InputSelection.h"

int hubInput;
std::vector<std::string> options;
auto color = "\033[32m";  // Green color

void Terminal::initializeHub() {

    std::cout << "\rPlease choose an option:\n";
    options = {"Explore", "Enter combat mode", "Steal valuable resources",
               "View available commands","options", "Quit"};
    for (int i = 1; i <= 6; ++i) {
        std::cout << "[" << i << "] " << options[i - 1] << "\n";
    }

    while (!(std::cin >> hubInput) || hubInput < 1 || hubInput > 6) {
        std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    InputSelection::HandleInputSelection(hubInput);
}
void Terminal::animate(const int duration) {
    for (int i = 0; i <= 100; ++i) {
        std::cout << "\033[K\r" << color << "Loading... " << i << "%" << color << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(duration));
        if (std::cin.rdbuf()->in_avail()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Terminal::drawOptions() {
    std::cout << "\r" << color << "your available commands are:" << color << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::cout << "[" << i << "] " << options[i - 1] << "\n";
    }

}

int main() {
    std::cout << color<< "\rWelcome to Pip-Boy 3000!\n";
    Terminal terminal;
    Terminal::animate(50);
    Terminal::initializeHub();
    Player::getHealth();
       return 200;
}

