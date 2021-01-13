#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char **argv) {
    const int MAX_REGULAR_HOURS = 40;
    const double REGULAR_PAY_PER_HOUR = 16.0;
    const double OVERTIME_MULTIPLIER = 1.5;
    const double SOCIAL_SECURITY_TAX = 0.06;
    const double FED_INCOME_TAX = 0.14;
    const double STATE_INCOME_TAX = 0.05;
    const double MEDICAL_INSURANCE_TAX_FLAT = 10.0;

    double hoursWorked;

    cout << "Please input the number of hours worked: ";
    cin >> hoursWorked;

    if(hoursWorked < 0) {
        cout << "Invalid number of hours worked!" << endl;
        return 1;
    }

    double grossPay;
    if(hoursWorked > MAX_REGULAR_HOURS) {
        // Calculate overtime hours
        grossPay = (MAX_REGULAR_HOURS * REGULAR_PAY_PER_HOUR)
            + ((hoursWorked - MAX_REGULAR_HOURS)
                * REGULAR_PAY_PER_HOUR * OVERTIME_MULTIPLIER);
    } else {
        // No overtime
        grossPay = hoursWorked * REGULAR_PAY_PER_HOUR;
    }

    double takeHomePay = grossPay;

    double socialSecurityTaxed = SOCIAL_SECURITY_TAX * grossPay;
    takeHomePay -= socialSecurityTaxed;

    double federalIncomeTaxed = FED_INCOME_TAX * grossPay;
    takeHomePay -= federalIncomeTaxed;

    double stateIncomeTaxed = STATE_INCOME_TAX * grossPay;
    takeHomePay -= stateIncomeTaxed;

    // If there is less than $10 left, Medical Insurance Tax takes everything
    double medicalInsuranceTaxed;
    if(takeHomePay >= MEDICAL_INSURANCE_TAX_FLAT) {
        medicalInsuranceTaxed = MEDICAL_INSURANCE_TAX_FLAT;
        takeHomePay -= medicalInsuranceTaxed;
    } else {
        medicalInsuranceTaxed = takeHomePay;
        takeHomePay = 0.0;
    }

    if(takeHomePay < 0.0) {
        takeHomePay = 0.0;
    }

    cout << fixed << setprecision(2);
    cout << "Gross Pay: $" << grossPay << endl;
    cout << "Social Security Tax: $" << socialSecurityTaxed << endl;
    cout << "Federal Income Tax: $" << federalIncomeTaxed << endl;
    cout << "State Income Tax: $" << stateIncomeTaxed << endl;
    cout << "Medical Insurance Tax: $" << medicalInsuranceTaxed << endl;
    cout << "Net Take-Home Profit: $" << takeHomePay << endl;

    return 0;
}
