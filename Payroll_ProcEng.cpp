#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

// int main() {
//     ifstream file("input.txt"); // Replace with the actual filename

//     if (!file.is_open()) {
//         cerr << "Error: Could not open the file." << endl;
//         return 1;
//     }

//     string line;
//     while (getline(file, line)) {
//         // Check if the line starts with "The" to identify departments
//         if (line.find("The") == 0) {
//             cout << "Department Found: " << line << endl;  // Output department names
//         } else {
//             // Check for pay grade at the end of the line
//             if (line.find("F1") != string::npos) {
//                 cout << "Employee (F1): " << line << endl;
//             } else if (line.find("F2") != string::npos) {
//                 cout << "Employee (F2): " << line << endl;
//             } else if (line.find("F3") != string::npos) {
//                 cout << "Employee (F3): " << line << endl;
//             } else if (line.find("F4") != string::npos) {
//                 cout << "Employee (F4): " << line << endl;
//             } else {
//                 cout << "Unknown Employee Format: " << line << endl;
//             }
//         }
//     }

//     file.close();
//     return 0;
// }












/*

    Shalin

*/






//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//#include <cmath>
//using namespace std;
//
//// Function to check if a string starts with a digit
//bool startsWithDigit(const string &word) {
//    return !word.empty() && isdigit(word[0]);
//}
//
//// Function to convert total minutes to rounded hours
//double calculateRoundedHours(int hours, int minutes) {
//    hours += minutes / 60;
//    minutes = minutes % 60;
//    double totalHours = hours + minutes / 60.0;
//    return round(totalHours * 2) / 2.0;
//}
//
//int main() {
//    ifstream file("input.txt"); // Replace with the actual filename
//
//    if (!file.is_open()) {
//        cerr << "Error: Could not open the file." << endl;
//        return 1;
//    }
//
//    string line;
//    while (getline(file, line)) {
//        if (line.find("The") == 0) {
//            cout << "Department Found: " << line << endl;
//        } else if (line.find("F1") != string::npos || line.find("F2") != string::npos || line.find("F4") != string::npos) {
//            int totalHours = 0;
//            int totalMinutes = 0;
//            istringstream iss(line);
//            string word;
//            int tempNumber = -1;  // Temporary storage for standalone numbers
//
//            while (iss >> word) {
//                // Check if word is in format "xhrs" or "xmin" directly attached
//                if (startsWithDigit(word) && (word.find("hour") != string::npos || word.find("hrs") != string::npos)) {
//                    int hours = stoi(word.substr(0, word.find_first_of("h")));
//                    totalHours += hours;
//                    cout << "Adding " << hours << " hours. Total hours so far: " << totalHours << endl;
//                } else if (startsWithDigit(word) && (word.find("min") != string::npos || word.find("minutes") != string::npos)) {
//                    int minutes = stoi(word.substr(0, word.find_first_of("m")));
//                    totalMinutes += minutes;
//                    cout << "Adding " << minutes << " minutes. Total minutes so far: " << totalMinutes << endl;
//                } else if (isdigit(word[0])) {
//                    // Store the number if it's a standalone number
//                    tempNumber = stoi(word);
//                } else if ((word.find("hour") != string::npos || word.find("hrs") != string::npos) && tempNumber != -1) {
//                    // Use tempNumber if we find "hours" or "hrs" after a standalone number
//                    totalHours += tempNumber;
//                    cout << "Adding " << tempNumber << " hours. Total hours so far: " << totalHours << endl;
//                    tempNumber = -1;
//                } else if ((word.find("min") != string::npos || word.find("minutes") != string::npos) && tempNumber != -1) {
//                    // Use tempNumber if we find "minutes" or "min" after a standalone number
//                    totalMinutes += tempNumber;
//                    cout << "Adding " << tempNumber << " minutes. Total minutes so far: " << totalMinutes << endl;
//                    tempNumber = -1;
//                }
//            }
//
//            // Calculate rounded total hours
//            double roundedHours = calculateRoundedHours(totalHours, totalMinutes);
//            cout << "Employee: " << line << endl;
//            cout << "Calculated Hours (rounded): " << roundedHours << " hours" << endl;
//        } else {
//            // Skipping F3 employees for now
//            cout << "Skipping F3 employee for now." << endl;
//        }
//    }
//
//    file.close();
//    return 0;
//}

// --------------------------------------------------------------------------------------------------------------------------------

/*


                    Brandon M


*/


// F1 = The total number of hours * 12.15
double calculationF1(int hours) {
    double f1 = hours * 12.15;
    return f1;
}



// F2 = (The total number of hours – 35) * 18.95 + 500
double calculationF2(int hours) {
    double f2 = (hours - 35) * 18.95 + 500;
    return f2;
}



// F3 = The total sales amount * the commission rate
double calculationF3(int saleAmount, int commissionRate) {
    int f3 = saleAmount * commissionRate;
    return f3;
}



// F4 = The first 5 hourly totals * 26.55 + Any weekend hourly totals (the last 2) * 39.75
double calculationf4(double hours[7]) {
    double weekdayTotal = 0, weekendTotal = 0;
    for (int i = 0; i < 5; ++i) weekdayTotal += hours[i];
    for (int i = 5; i < 7; ++i) weekendTotal += hours[i];
    return (weekdayTotal * 26.55) + (weekendTotal * 39.75);
}



// still abit wary about this "isdigit fucntion"
bool startsWithDigit(const string& word) {
    return !word.empty() && isdigit(word[0]);
}



// Round the final total time to the nearest half hour 
double calculateRoundedHours(int hours, int minutes) {
    hours += minutes / 60;
    minutes = minutes % 60;
    double totalHours = hours + minutes / 60.0;
    return round(totalHours * 2) / 2.0;
}


// shalin code but in a function
void processWords(const string& line, int& totalHours, int& totalMinutes) {
    int tempNumber = -1;
    string word;
    for (size_t i = 0; i <= line.size(); ++i) {
        if (i < line.size() && !isspace(line[i])) {
            word += line[i];
        }
        else {
            if (!word.empty()) {
                if (startsWithDigit(word) && (word.find("hour") != string::npos || word.find("hrs") != string::npos || word.find("hr") != string::npos)) {
                    int hours = stoi(word.substr(0, word.find_first_of("h")));
                    totalHours += hours;
                }
                else if (startsWithDigit(word) && (word.find("min") != string::npos || word.find("minutes") != string::npos)) {
                    int minutes = stoi(word.substr(0, word.find_first_of("m")));
                    totalMinutes += minutes;
                }
                else if (isdigit(word[0])) {
                    tempNumber = stoi(word);
                }
                else if ((word.find("hour") != string::npos || word.find("hrs") != string::npos || word.find("hr") != string::npos) && tempNumber != -1) {
                    totalHours += tempNumber;
                    tempNumber = -1;
                }
                else if ((word.find("min") != string::npos || word.find("minutes") != string::npos) && tempNumber != -1) {
                    totalMinutes += tempNumber;
                    tempNumber = -1;
                }
                word.clear();
            }
        }
    }
}

int main()
{

    ifstream file("input.txt");
    string line, name;
    double f1TotalHours = 0;
    double f2TotalHours = 0;
    double f3TotalHours = 0;
    double f4TotalHours = 0;

    string departmentName;
    string roster;
    int totalEmployees = 0;
    double totalSalary = 0;
    double f1Salary = 0, f2Salary = 0, f3Salary = 0, f4Salary = 0;
    int f1Employees = 0, f2Employees = 0, f3Employees = 0, f4Employees = 0;


    if (!file) {
        cerr << "Error: Could not open file. ";
        return 1;
    }

    while (getline(file, line))
    {


        if (line.find("Department") != string::npos)
        {
            cout << line << endl;
            f1TotalHours = 0;
            f2TotalHours = 0;
            f3TotalHours = 0;
            f4TotalHours = 0;

            f1Salary = 0;
            f2Salary = 0;
            f3Salary = 0;
            f4Salary = 0;

        }
        else if (line.find("F1") != string::npos || line.find("F2") != string::npos || line.find("F3") != string::npos || line.find("F4") != string::npos)
        {
            int totalHours = 0;
            int totalMinutes = 0;
            cout << "Employee: " << line << endl;
            processWords(line, totalHours, totalMinutes);
            double roundedHours = calculateRoundedHours(totalHours, totalMinutes);
            if (line.find("F1") != string::npos)
            {
                f1TotalHours += roundedHours;
                cout << "f1 hours: " << f1TotalHours << endl;
                f1Salary += calculationF1(roundedHours);
                cout << "f1 salary: " << f1Salary << endl;
                f1Employees++;
            }
            else if (line.find("F2") != string::npos) {
                f2TotalHours += roundedHours;
                cout << "f2 hours: " << f2TotalHours << endl;
                f2Salary += calculationF2(roundedHours);
                cout << "f2 salary: " << f2Salary << endl;
                f2Employees++;

            }
            else if (line.find("F3") != string::npos) {
                double sales = 0;
                double commissionRate = 0;
                f3TotalHours += (commissionRate > 0.1) ? 40 : 30;
                f3Employees++;
                /*
                    F3s are also assumed to work 30 hours if their commission is 10% or below and 40 hours if their commission is above 10%.

                                   $24,000   *  0.105

                     F3 = The total sales amount * the commission rate
                */

            }
            else if (line.find("F4") != string::npos) {
                f4TotalHours += roundedHours;


                f4Employees++;
                /*


                    F4s will have 7 numbers (as they are on-call during the weekend).
                    Brad Monday(9hrs) Tuesday(8hrs) Wednesday(10hrs 12min) Thurdsay(9hrs 4min) Friday(8hours 6min) Satruday(3hrs 24min) Sunday(1hr 6min) F4
                    Kent Monday(9hrs) Tuesday(8hrs 1min) Wednesday(9 hrs) Thurdsay(7hrs 5 min) Friday(8 hrs 55min) Satruday(6min) Sunday(1hr) F4


                    double calculationf4(double hours[7]) {
                    double weekdayTotal = 0, weekendTotal = 0;
                    for (int i = 0; i < 5; ++i) weekdayTotal += hours[i];
                    for (int i = 5; i < 7; ++i) weekendTotal += hours[i];
                    return (weekdayTotal * 26.55) + (weekendTotal * 39.75);
}

                */

            }
            totalSalary = f1Salary + f2Salary + f3Salary + f4Salary;
            totalHours = f1TotalHours + f2TotalHours + f3TotalHours + f4TotalHours;
            totalEmployees = f1Employees + f2Employees + f3Employees + f4Employees;

            cout << "Total Number of Employees " << totalEmployees << endl;

            cout << endl << endl;
            cout << "f1 total Hours: " << f1TotalHours << endl;
            cout << "f1 salary: " << f1Salary << endl;
            cout << "f1 emp: " << f1Employees << endl << endl;

            cout << "f2 total Hours: " << f2TotalHours << endl;
            cout << "f2 salary: " << f2Salary << endl;
            cout << "f2 emp: " << f2Employees << endl << endl;



            cout << "f3 total Hours: " << f3TotalHours << endl;
            cout << "f3 salary: " << f3Salary << endl;
            cout << "f3 emp: " << f3Employees << endl << endl;


            cout << "f4 total Hours: " << f4TotalHours << endl << endl;
            cout << "f4 salary: " << f4Salary << endl;
            cout << "f4 emp: " << f4Employees << endl << endl;
            cout << "_________________________________" << endl;

        }

        /*



            when new department found print the stats for the previous department and category
            resetign all the values
            starting again on new department


        */
    }
    file.close();
    return 0;

}