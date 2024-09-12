#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

/**
 * @brief Converts minutes to seconds
 * @param minutes The number of minutes
 * @return Number of seconds
 */
int minutes_to_seconds(int minutes) {
    return minutes * 60;
}

/**
 * @brief Validates input for seconds
 * @param seconds The number of seconds
 * @return True if valid, False otherwise
 */
bool validate_seconds(int seconds) {
    return seconds >= 0 && seconds <= 59;
}

/**
 * @brief Validates input for minutes
 * @param minutes The number of minutes
 * @return True if valid, False otherwise
 */
bool validate_minutes(int minutes) {
    return minutes >= 0 && minutes <= 59;
}

void print_color(const char* text, const char* color) {
    switch(color[0]) {
        case 'R': std::cout << "\033[31m"; break;
        case 'G': std::cout << "\033[32m"; break;
        case 'B': std::cout << "\033[34m"; break;
        case 'C': std::cout << "\033[36m"; break;
        case 'W': std::cout << "\033[37m"; break;
        default: return; // Invalid color code
    }
    std::cout << text << "\033[0m";
}

int main() {
    short minutes, seconds;
    int total_time;

    // Input validation loop for seconds
    do {
        std::cout << "Enter Seconds (0-59): ";
        std::cin >> seconds;
    } while (!validate_seconds(seconds));

    // Input validation loop for minutes
    do {
        std::cout << "Enter Minutes (0-59): ";
        std::cin >> minutes;
    } while (!validate_minutes(minutes));

    // Calculate total time in seconds
    total_time = minutes_to_seconds(minutes) + seconds;

    // Countdown timer logic
    for (int i = total_time; i > 0; --i) {
        system("cls");
        
        // Print colored header
        std::cout << "\033[1m\033[34mTime remaining:\033[0m ";
        
        // Print time in color
        std::cout << "\033[31m" << (i / 60) << ":" 
                  << "\033[32m" << (i % 60) << "\033[0m";
        
        std::cout << std::endl;
        
        // Short delay between updates
        Sleep(1000); // 1 second delay
    }

    // Clear screen one last time
    system("cls");

    // Display timer end message
    std::cout << "\033[1m\033[36m*****************\033[0m\n"
              << "\033[33mTimer Ended!\a\033[0m\n"
              << "Lasted for \033[31m" << total_time << "\033[0m seconds\n"
              << "\033[36m*****************\033[0m\n" << std::endl;

    getch(); // Wait for user to press a key before closing

    return 0;
}
