
#include "main.h"
#include "transaction.h"
#include "user.h"
#include "bank.h"

double RandomDouble(double min, double max)
{
    static bool first = true;
    if (first) 
    {  
      srand(SEED); //seeding for the first time only!
      first = false;
    }
    double r = (double)rand() / (double)RAND_MAX;

    return min + r * (max - min);
}

int main()
{

    USER user = USER();
    TRANSACTION transaction = TRANSACTION();
    BANK bank = BANK();
    cout<<"START MONEY OF USER:"<<user.get_money_ATM()<<endl;
    //transaction.print_moneyOfMonth();
    //cout<<"adj transaction!"<<endl;
    transaction.adjTransaction(user.get_money_ATM());
    transaction.print_moneyOfMonth();
    bank.print_bank_info();
    cout<<"DONE";
    return 0;
}

