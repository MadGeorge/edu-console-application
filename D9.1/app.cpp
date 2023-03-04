//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 04.03.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double home_value, down_payment, interest_rate;
    int loan_term;
    cout << "Enter Home Value: ";
    cin >> home_value;
    cout << "Enter Down Payment: ";
    cin >> down_payment;
    cout << "Enter Interest Rate (%): ";
    cin >> interest_rate;
    cout << "Enter Loan Term (months): ";
    cin >> loan_term;

    double loan_amount = home_value - down_payment;

    double monthly_interest_rate = interest_rate / 12 / 100.0;

    double monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -loan_term));

    cout << setw(10) << "Month" << setw(15) << "Payment" << setw(20) << "Ending Balance" << setw(15) << "Interest" << endl;

    double balance = loan_amount;
    for (int month = 1; month <= loan_term; month++) {
        double interest = balance * monthly_interest_rate;
        double principal = monthly_payment - interest;

        balance -= principal;

        cout << setw(10) << month << setw(15) << fixed << setprecision(2)
             << monthly_payment << setw(20) << balance << setw(15)
             << interest << endl;
    }

    return 0;
}

