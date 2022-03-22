#ifndef      __TRANSACTION_H__
#define      __TRANSACTION_H__
#include <cstdlib>
#include <math.h>

const double EPSILON = 0.00001;

bool Equality(double a, double b, double epsilon);
bool Equality(double a, double b, double epsilon = EPSILON)
{
  return fabs(a - b) < epsilon;
}


class TRANSACTION{
    private:
        double moneyOfMonth[31];
        
    public:
        
        TRANSACTION() {     // Constructor
            char _lenArr = *(&moneyOfMonth + 1) - moneyOfMonth;
            for (char index = 0; index < _lenArr; index +=1){
                moneyOfMonth[index] = RandomDouble( -1* double(minStartMoney),double(minStartMoney));
            }
            cout << "CREATE RANDOM TRANSACTION IN MONTH!"<<endl;
        }
        ~TRANSACTION() {
            //delete moneyOfMonth;
        }
        void print_moneyOfMonth(){
            char _lenArr = *(&moneyOfMonth + 1) - moneyOfMonth;
            for (int index = 0; index < _lenArr; index +=1){
                cout<< "Day "<< index+1 << ":" <<moneyOfMonth[index] << endl;
            }
        }
        void adjTransaction(double startMoneyUser){
            //MUST ALWAYS POSIBLE FOR WITHDRAW MONEY 
            char _lenArr = *(&moneyOfMonth + 1) - moneyOfMonth;
            double changedMoney;
            double tmp_total_money = startMoneyUser;
            bool flagChange = false;
            for (int index = 0; index <_lenArr; index+=1){
                tmp_total_money += moneyOfMonth[index];
                while(true){
                    if (tmp_total_money < 0){
                        //change imposible withdraw value
                        //cout<<"adjust at index: "<<(index)<<endl;
                        //cout<<"tmp_total_money:"<<tmp_total_money<<endl;
                        tmp_total_money -= moneyOfMonth[index];
                        changedMoney = RandomDouble( -1* double(minStartMoney),double(minStartMoney));
                        tmp_total_money += changedMoney;
                        flagChange = true;
                        
                    }
                    else{
                        if (flagChange == true){
                            //cout<<"=>tmp_total_money:"<<tmp_total_money<<endl;
                            moneyOfMonth[index] = changedMoney;
                            flagChange = false;
                            //cout<<"!!!!!!!!!!!!!!"<<endl;//BUG
                        }
                        break;
                    }
                }
            }
        }
};

#endif