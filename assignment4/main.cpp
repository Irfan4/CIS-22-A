/*Irfan Ahmad, 11-01-2018
 This program will take a choice for a cell phone
 plan from the user as well as how many minutes were used, and calculate
 it into a monthly bill as well as determine how much would or would
 not have been saved if the user chose the other two plans. */

#include <iostream>
#include <iomanip>
// iomanip included to set each value to two numbers after the decimal point.
// setprecision and fixed will make every output in the form of 0.00.

using namespace std;

int main()
{
// Each plan's savings has it's own variable so each of them can be
// recalculated for each case.
// Menu choice can only be from 1-4, integers only.
    float minutes = 0;
    float savingsA, savingsB, savingsC;
    int menuChoice;
    float TOTAL_AMOUNT = 0.00;
// Constant values used for the rates and package prices
    const float PACKAGE_A = 39.99;
    const float PACKAGE_B = 59.99;
    const float PACKAGE_C = 69.99;
    const float ADDITIONAL_A = 0.45;
    const float ADDITIONAL_B = 0.40;

    cout << "Select a subscription package:\n" << "1. Package A\n"
        << "2. Package B\n" << "3. Package C\n" << "4. Quit\n";
    cin >> menuChoice;
    // Since negative numbers won't be put, anything above 4 will be
    // rejected.
    if ( menuChoice > 4 )
    {
      cout << "The valid choices are 1 through 4.";
      cout << " Run the program again and select one of those.";
    }
    else if (menuChoice == 4)
        	return 0;
    else
    cout << "How many minutes were used? ";
    cin >> minutes;

    int REMAINDER_MINUTES = 0;

    switch ( menuChoice )
    {
    case 1:
    		REMAINDER_MINUTES = minutes - 450;
    		// Anything past 450 minutes requires a special rate per additional minute
         	if( minutes > 450 )
            {
         		cout << "The total amount due is $" << 39.99 + (REMAINDER_MINUTES * ADDITIONAL_A) << "\n";
         		TOTAL_AMOUNT = 39.99 + (REMAINDER_MINUTES * ADDITIONAL_A);
         	}
                else
         	{
         		cout << "The total amount due is $" << 39.99 << "\n";
         		TOTAL_AMOUNT = 39.99;
         	}

         	//No savings for B from A
         	if(minutes <= 494)
            {

         		cout << "No savings with Package B" << "\n";

         	}
                // Savings for B from A
                else if (minutes > 494 && minutes <= 900)

                {
         		savingsB = TOTAL_AMOUNT - PACKAGE_B;
         		cout << "Savings with Package B: $" << std::fixed << std::setprecision(2) << savingsB << "\n";
                }

                else if(minutes > 900)

                {
         		savingsB = ((minutes - 900) * 0.40) + PACKAGE_B;
         		cout << "Savings with Package B: $" << std::fixed << std::setprecision(2) << TOTAL_AMOUNT - savingsB << "\n";
                }

         	//No savings for C from A
            if(minutes <= 516)
            {
         		cout << "No savings with Package C" << "\n";
         	}

         	// Savings for C from A
         	else if (minutes > 516)
            {
         		savingsC = TOTAL_AMOUNT - PACKAGE_C;
         		cout << "Savings with Package C: $" << std::fixed << std::setprecision(2) << savingsC << "\n";
         	}

            break;

        case 2:

            // Calculating total amount B
        	REMAINDER_MINUTES = minutes - 900;

        	if(minutes > 900)
            {
        		cout << "The total amount due is $" << 59.99 + (REMAINDER_MINUTES * ADDITIONAL_B) << "\n";
         		TOTAL_AMOUNT = 59.99 + (REMAINDER_MINUTES * ADDITIONAL_B);
        	}

        	else
        	{
        		cout << "The total amount due is $" << 59.99 << "\n";
         		TOTAL_AMOUNT = 59.99;
        	}


        	//No savings for A from B
         	if(minutes >= 494)
            {
         		cout << "No savings with Package A" << "\n";
         	}

         	// First savings for A from B
         	else if (minutes < 494)
            {
         		savingsA = TOTAL_AMOUNT - PACKAGE_A;

         		cout << "Savings with Package A: $" << std::fixed << std::setprecision(2) << savingsA << "\n";
         	}
            // Second savings sets a limit of 900 so C can be calculated too
         	else if(minutes > 900)

         	{
         		savingsA = ((minutes - 900) * 0.45) + PACKAGE_A;
         		cout << "Savings with Package A: $" << std::fixed << std::setprecision(2) << TOTAL_AMOUNT - savingsA << "\n";
         	}

         	//No savings for C from B
            if(minutes <= 925)

            {

         		cout << "No savings with Package C" << "\n";

         	}

         	else if (minutes > 925)

            //Savings for C from B
            {
         		savingsC = TOTAL_AMOUNT - PACKAGE_C;

         		cout << "Savings with Package C: $" << std::fixed << std::setprecision(2) << savingsC << "\n";
         	}

        	break;

        case 3:

         	TOTAL_AMOUNT = 69.99;
        	cout << "The total amount due is $" << TOTAL_AMOUNT << "\n";

        	// Everything less than 516 minutes is cheaper than Package C.
         	if(minutes <= 516)
            // Savings for A from C
            {

         		savingsA = ((minutes - 450) * 0.45) + PACKAGE_A;
         		cout << "Savings with Package A: $" << std::fixed << std::setprecision(2) << TOTAL_AMOUNT - savingsA << "\n";
            // If minutes are higher than 516, using Package C is cheaper

         	}
            // No savings for A from C
         	else if (minutes > 516)

         	{
         		cout << "No savings with Package A" << "\n";

         	}

         	// No savings for B from C
         	if(minutes > 925)

            {
                cout << "No savings with Package B" << "\n";

         	}
            // The point where C is more expensive than B
         	else if (minutes <= 925)

            {
         		savingsB = TOTAL_AMOUNT - PACKAGE_B;

         		cout << "Savings with Package B: $" << std::fixed << std::setprecision(2) << savingsB << "\n";

         	}

        	break;

        case 4:
        // If 4 is pressed, exit.
            if ( menuChoice == 4 )
        	return 0;
        	break;

        default:
        	cout << "The valid choices are 1 through 4. Run the program again and select one of those.";
        	break;
    }
    /* Select a subscription package:
1. Package A
2. Package B
3. Package C
4. Quit
1
How many minutes were used? 650
The total amount due is $129.99
Savings with Package B: $70.00
Savings with Package C: $60.00

Process returned 0 (0x0)   execution time : 3.984 s
Press any key to continue.
    */
}

