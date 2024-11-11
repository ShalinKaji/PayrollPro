#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

// Function to check if a string starts with a digit
bool startsWithDigit(const string &word) {
    return !word.empty() && isdigit(word[0]);
}

// Function to convert total minutes to rounded hours using ceiling logic for nearest half-hour
double calculateRoundedHours(int hours, int minutes) {
    hours += minutes / 60;
    minutes = minutes % 60;

    if (minutes > 0 && minutes <= 29) {
        return hours + 0.5;  // Round up to the nearest half hour
    } else if (minutes >= 30) {
        return hours + 1.0;  // Round up to the next whole hour
    } else {
        return hours;  // No rounding needed if there are no extra minutes
    }
}

// Weekly pay calculation functions
double calculateF1Pay(double hours) {
    return hours * 12.15;
}

double calculateF2Pay(double hours) {
    return (hours - 35) * 18.95 + 500;
}

double calculateF3Pay(int salesAmount, double commissionRate) {
    return salesAmount * commissionRate;
}

double calculateF4Pay(double weekdayHours, double weekendHours) {
    return (weekdayHours * 26.55) + (weekendHours * 39.75);
}

int convertCurrencyStringToInt(const std::string& currency) {
    std::string cleanedString;

    // Remove any characters that aren't digits
    for (char c : currency) {
        if (isdigit(c)) {
            cleanedString += c;
        }
    }

    // Convert the cleaned string to an integer
    std::stringstream ss(cleanedString);
    int result;
    ss >> result;
    return result;
}

int main() {
    ifstream file("input.txt"); // Replace with the actual filename

    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        // Step 1: Display employee categorization
        if (line.find("The") == 0) {
            cout << "Department Found: " << line << endl;  // Output department names
        } else {
            // Check for pay grade at the end of the line
            if (line.find("F1") != string::npos) {
                cout << "Employee (F1): " << line << endl;
            } else if (line.find("F2") != string::npos) {
                cout << "Employee (F2): " << line << endl;
            } else if (line.find("F3") != string::npos) {
                cout << "Employee (F3): " << line << endl;
            } else if (line.find("F4") != string::npos) {
                cout << "Employee (F4): " << line << endl;

                // Process F4 to separate weekday and weekend hours
                vector<pair<int, int>> timeEntries;  // Store each timestamp as a pair (hours, minutes)
                istringstream iss(line);
                string word;
                int tempNumber = -1;  // Temporary storage for standalone numbers

                // Extract all time entries for F4 employees as pairs
                while (iss >> word) {
                    if (startsWithDigit(word) && (word.find("hour") != string::npos || word.find("hrs") != string::npos)) {
                        int hours = stoi(word.substr(0, word.find_first_of("h")));
                        timeEntries.push_back({hours, 0});  // Add hours with 0 minutes
                    } else if (startsWithDigit(word) && (word.find("min") != string::npos || word.find("minutes") != string::npos)) {
                        int minutes = stoi(word.substr(0, word.find_first_of("m")));
                        if (!timeEntries.empty() && timeEntries.back().second == 0) {
                            timeEntries.back().second = minutes;  // Update last entry with minutes
                        } else {
                            timeEntries.push_back({0, minutes});  // Add standalone minutes as (0, minutes)
                        }
                    } else if (isdigit(word[0])) {
                        tempNumber = stoi(word);  // Store the number if it's a standalone number
                    } else if ((word.find("hour") != string::npos || word.find("hrs") != string::npos) && tempNumber != -1) {
                        timeEntries.push_back({tempNumber, 0});  // Add standalone hours with 0 minutes
                        tempNumber = -1;
                    } else if ((word.find("min") != string::npos || word.find("minutes") != string::npos) && tempNumber != -1) {
                        if (!timeEntries.empty() && timeEntries.back().second == 0) {
                            timeEntries.back().second = tempNumber;  // Update last entry with minutes
                        } else {
                            timeEntries.push_back({0, tempNumber});  // Add standalone minutes
                        }
                        tempNumber = -1;
                    }
                }

                // Calculate weekday and weekend hours from the entries
                int weekdayHours = 0, weekdayMinutes = 0;
                int weekendHours = 0, weekendMinutes = 0;

                // First 5 timestamps for weekdays
                for (int i = 0; i < 5 && i < timeEntries.size(); ++i) {
                    weekdayHours += timeEntries[i].first;
                    weekdayMinutes += timeEntries[i].second;
                }

                // Last 2 timestamps for weekends
                if (timeEntries.size() >= 7) {
                    for (int i = 5; i < 7; ++i) {
                        weekendHours += timeEntries[i].first;
                        weekendMinutes += timeEntries[i].second;
                    }
                }

                // Calculate rounded hours for weekday and weekend
                double roundedWeekdayHours = calculateRoundedHours(weekdayHours, weekdayMinutes);
                double roundedWeekendHours = calculateRoundedHours(weekendHours, weekendMinutes);

                cout << "Weekday Hours (rounded): " << roundedWeekdayHours << " hours" << endl;
                cout << "Weekend Hours (rounded): " << roundedWeekendHours << " hours" << endl;
                cout << "Weekly Pay for F4: $" << calculateF4Pay(roundedWeekdayHours, roundedWeekendHours) << endl;

            } else {
                cout << "Unknown Employee Format: " << line << endl;
            }
        }

        // Step 2: Calculate and display total rounded hours for F1.
        if (line.find("F1") != string::npos) {
            int totalHours = 0;
            int totalMinutes = 0;
            istringstream iss(line);
            string word;
            int tempNumber = -1;  // Temporary storage for standalone numbers

            while (iss >> word) {
                if (startsWithDigit(word) && (word.find("hour") != string::npos || word.find("hrs") != string::npos)) {
                    int hours = stoi(word.substr(0, word.find_first_of("h")));
                    totalHours += hours;
                } else if (startsWithDigit(word) && (word.find("min") != string::npos || word.find("minutes") != string::npos)) {
                    int minutes = stoi(word.substr(0, word.find_first_of("m")));
                    totalMinutes += minutes;
                } else if (isdigit(word[0])) {
                    tempNumber = stoi(word);  // Store the number if it's a standalone number
                } else if ((word.find("hour") != string::npos || word.find("hrs") != string::npos) && tempNumber != -1) {
                    totalHours += tempNumber;
                    tempNumber = -1;
                } else if ((word.find("min") != string::npos || word.find("minutes") != string::npos) && tempNumber != -1) {
                    totalMinutes += tempNumber;
                    tempNumber = -1;
                }
            }

            // Calculate rounded total hours
            double roundedHours = calculateRoundedHours(totalHours, totalMinutes);
            cout << "Calculated Total Hours (rounded): " << roundedHours << " hours" << endl;
            cout << "Weekly Pay for F1: $" << calculateF1Pay(roundedHours) << endl;
        }

        // Step 2B: Calculate and display total rounded hours for F2.
        else if (line.find("F2") != string::npos) {
            int totalHours = 0;
            int totalMinutes = 0;
            istringstream iss(line);
            string word;
            int tempNumber = -1;  // Temporary storage for standalone numbers

            while (iss >> word) {
                if (startsWithDigit(word) && (word.find("hour") != string::npos || word.find("hrs") != string::npos)) {
                    int hours = stoi(word.substr(0, word.find_first_of("h")));
                    totalHours += hours;
                } else if (startsWithDigit(word) && (word.find("min") != string::npos || word.find("minutes") != string::npos)) {
                    int minutes = stoi(word.substr(0, word.find_first_of("m")));
                    totalMinutes += minutes;
                } else if (isdigit(word[0])) {
                    tempNumber = stoi(word);  // Store the number if it's a standalone number
                } else if ((word.find("hour") != string::npos || word.find("hrs") != string::npos) && tempNumber != -1) {
                    totalHours += tempNumber;
                    tempNumber = -1;
                } else if ((word.find("min") != string::npos || word.find("minutes") != string::npos) && tempNumber != -1) {
                    totalMinutes += tempNumber;
                    tempNumber = -1;
                }
            }

            // Calculate rounded total hours
            double roundedHours = calculateRoundedHours(totalHours, totalMinutes);
            cout << "Calculated Total Hours (rounded): " << roundedHours << " hours" << endl;
            cout << "Weekly Pay for F2: $" << calculateF2Pay(roundedHours) << endl;
        }

        else if (line.find("F3") != string::npos) {
                cout << "Employee (F3): " << line << endl;

                // Parse sales amount and commission rate for F3
                istringstream iss(line);
                string word;
                int salesAmount = 0;
                double commissionRate = 0.0;

                while (iss >> word) {
                    if (word[0] == '$') {
                        salesAmount = convertCurrencyStringToInt(word); // Convert string to integer without '$'
                    } else if (word.find('.') != string::npos) {
                        commissionRate = stod(word);
                    }
                }

                cout << "Sales Amount: $" << salesAmount << ", Commission Rate: " << commissionRate << endl;
                cout << "Weekly Pay for F3: $" << calculateF3Pay(salesAmount, commissionRate) << endl;

            }
    }

    file.close();
    return 0;
}


