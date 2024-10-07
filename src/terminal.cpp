#include "../header/terminal.h"
#include "../header/ManagerHeaders/ExplorationManager.h"
#include "../header/InputSelection.h"
#include<memory>
#include <array>


struct AllocationMetrics
{
    uint32_t TotalAllocated =0;
    uint32_t TotalFreed =0;

    [[nodiscard]] uint32_t CurrentUsage() const {return TotalAllocated - TotalFreed;}
};
static AllocationMetrics s_allocationMetrics;
std::ostringstream oss;

constexpr int MAX_OPTIONS = 6;
constexpr int ANIMATION_DURATION = 50;

std::array<std::string, MAX_OPTIONS> options = {"Explore", "Enter combat mode", "Steal valuable resources",
                                               "View available commands", "options", "Quit"};
std::string color = "\033[32m";  // Green color

Terminal::Terminal() : oss(""), hubInput(0) {
}

 void* operator new(const size_t size) {
   s_allocationMetrics.TotalAllocated += size;
    return malloc(size);
}
void operator delete(void* ptr, const size_t size) {
    s_allocationMetrics.TotalFreed += size;
    free(ptr);
}


void Terminal::initializeHub() const {
    std::cout << "\rPlease choose an option:\n";
    for (int i = 0; i < MAX_OPTIONS; ++i) {
        std::cout << "[" << i + 1 << "] " << options[i] << "\n";
    }

    int hubInput;
    while (!(std::cin >> hubInput) || hubInput < 1 || hubInput > MAX_OPTIONS) {
        std::cout << "Invalid input. Please enter a number between 1 and " << MAX_OPTIONS << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}

void Terminal::animate(const int duration) {
    oss.str("");
    for (int i = 0; i <= 100; ++i) {
        std::ostringstream oss;
        oss << "\033[K\r" << color << "Loading... " << i << "%" << color;
        std::cout << oss.str() << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(duration));
        if (std::cin.rdbuf()->in_avail()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Terminal::drawOptions() {
    std::cout << "\r" << color << "Your available commands are:" << color << std::endl;
    for (const auto& option : options) {
        std::cout << "[" << (&option - &options[0]) + 1 << "] " << option << "\n";
    }
    InputSelection().HandleInputSelection(hubInput);
}

int main() {
    std::cout << color << "\rWelcome to Pip-Boy 3000!\n";
    Terminal terminal;
    ExplorationManager().InitializeDirections();
    terminal.animate(ANIMATION_DURATION);


    terminal.initializeHub();
    std::cout << "Memory Usage: " << s_allocationMetrics.CurrentUsage() << " bytes\n";

    return 0;
}

