#ifndef      __USER_H__
#define      __USER_H__
#include <cstdlib>

class USER{
    // USER IN 0th DAY
    private:
        double total_money = 22;
    public:
        USER(){
            total_money = RandomDouble(double(minStartMoney),double(maxStartMoney));
            cout<<"TOTAL_MONEY:"<<total_money<<endl;
            cout << "CREATE RANDOM TOTAL MONEY OF USER!"<<endl;
        }
        ~USER(){
            
        }
        
        double get_money(){
            return total_money;
        }
};

#endif