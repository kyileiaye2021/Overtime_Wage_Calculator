//CS002: #77215
//Kyi_Lei_Aye
//kaye_programming_project2
//Overtime Wage Calculator

#include <iostream>
#include <string>

//initializing constant variable for calculating the overtime hours
const double STANDARD_HOUR = 40.00;

int main()
{
    using namespace std;

    //declaring variables to store user input
    int option;
    double hours, grossPay, netPay, deductionAmount, percentage;
    char answer;

    //taking the number of hours that the user work as an input value
    cout << "How many hours did you work this week?: ";
    cin >> hours;
    cout << endl;

    //asking the user what option of health insurance they want
    cout << "Choose Health Insurance Options:\n"; 
    cout << "1.Self\n";
    cout << "2.Self and Other\n";
    cout << "Fill 1 or 2: ";
    cin >> option;
    cout << endl;

    //asking user to put their money into 401k retirement plan
    cout << "Do you want to put money into 401k retirement plan?\n";
    cout << "Answer 'Y' or 'y' for \"Yes\" and 'N' or 'n' for \"No\": ";
    cin >> answer;
    cout << endl;

    //calculating Gross Payment by using if-else statement
    if(hours <= 40 )
    {
        grossPay = hours * 17.87;
    }
    else 
    {
        grossPay = (STANDARD_HOUR * 17.87) + (26.81 * (hours - STANDARD_HOUR));
    }

    //calculating Net Payment for 401k planner by using switch statements
    if((answer == 'Y') || (answer == 'y'))
    {
        cout << "How much percentage do you want to put in?: ";
        cin >> percentage;

        switch (option)
        {
            case 1:
                netPay = (grossPay - 10) * (100 - (6.2 + 22.00 + 9.3 + percentage))/100;
                break;
            case 2:
                netPay = ((grossPay - 10.00 - 251.63) * (100 - (6.2 + 22.00 + 9.3 + percentage))/100) + 251.63;
                break;
            default:
                cout << endl;
                break;
         }

    }
    //calculating Net Payment for regular employees by using switch statements
    else
    {
        switch (option)
        {
            case 1:
                netPay = (grossPay - 10.00) * (100 - (6.2 + 22.00 + 9.3))/100;
                break;
            case 2:
                netPay = ((grossPay - 10.00 - 251.63) * (100 - (6.2 + 22.00 + 9.3))/100) + 251.63;
            default:
                cout << endl;
                break;
        }
    }
    //calculating Weekly Deduction amounts
    deductionAmount = grossPay - netPay;

    //using Magic Formula to get the exact 2 decimal output
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //output of the program
    cout << "Weekly Gross Payment: $" << grossPay << endl;
    cout << "Weekly Net Payment: $" << netPay << endl;
    cout << "Weekly Deduction Amount: $" << deductionAmount << endl;
    
    return 0;
}




