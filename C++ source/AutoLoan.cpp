#include <iostream>
using namespace std;

class AutoLoan
{
  public:
    // 한달 단위 이자율
    double rateFront = 0;
    double rateEnd = 1;
    double rateCurrent = 0;

    double interestRate(double price, double monthlyPayment, int loanTerm)
    {
        double balance = price;
        while ((rateEnd - rateFront > 1e-9) && ((rateEnd - rateFront) / rateEnd > 1e-9)) // 절대오차, 상대오차
        {
            balance = price;
            rateCurrent = (rateFront + rateEnd) / 2.0;
            for (int i = 0; i < loanTerm; i++)
            {
                double rateFee = balance * (rateCurrent);
                balance = balance + rateFee;
                balance -= monthlyPayment;
            }

            if (balance > 0)
            {
                rateEnd = rateCurrent;
            }
            else
            {
                rateFront = rateCurrent;
            }
        }

        return rateCurrent * 100 * 12; // 년 단위, %로 표현하기 위함
    }
};

int main()
{
    AutoLoan ir = AutoLoan();
    // cout << ir.interestRate(6800, 100, 68) << '\n';
    cout << ir.interestRate(2000, 510, 4) << '\n';
    // cout << ir.interestRate(15000, 364, 48) << '\n';
    return 0;
}