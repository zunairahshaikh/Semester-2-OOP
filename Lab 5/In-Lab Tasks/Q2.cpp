/*Create a class called LoanHelper, which helps the user calculate their loan payments. The class
should have a variable that stores interest rate for the loan as a user defined constant value. Aside
from the that, it also stores the amount for the loan taken and amount of months that the user will
repay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rate
should be applied over the monthly return amount. The output should be something like:
“You have to pay 999 every month for 12 monthsto repay your loan”
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate
should be a value between 0-0.5%*/

#include <iostream>
using namespace std;

class LoanHelper{
        const float interestRate;
        float loanAmount;
        int months;
    public:
        LoanHelper(float interestRate, float loanAmount, int months):interestRate(interestRate){
            this->loanAmount = loanAmount;
            this->months = months;
        }
        void calculatePayment(){
            float monthlyPayment = loanAmount / months;
            float interest = monthlyPayment * interestRate;
            monthlyPayment += interest;
            cout << "You have to pay $" << monthlyPayment << " every month for " << months << " months to repay your loan" << endl;
        }
};

int main(){
    LoanHelper lh(0.005, 12000, 12);
    lh.calculatePayment();
    return 0;
}