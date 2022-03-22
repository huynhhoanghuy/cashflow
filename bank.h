#ifndef      __BANK_H__
#define      __BANK_H__
#include <map>
#include <unordered_map>




struct INFO_CARD{
    float profit_rate; // range [0,1]
    unsigned short duration; //follow by days.
    double rate_punish_money; //rate_punish_money * current_money == punish_money
    //After duration, profit will be add to account.
    //Withdraw before duration, will be punish by minus money
    INFO_CARD(float _profit_rate, unsigned short _duration, double _rate_punish_money){
        profit_rate = _profit_rate;
        duration = _duration;
        rate_punish_money = _rate_punish_money;
    }
};

class BANK{
    private:
        //accumulation card
        //<card_ID_list, (profit_rate, duration)>
        
        //dynamic card_list
        map<char, INFO_CARD> card_list = {
                                    {'A', INFO_CARD(0.03, 0, 0)},
                                    {'B', INFO_CARD(0.07, 60, 0.01)},
                                    {'C', INFO_CARD(0.09, 90, 0.03)},
                                    {'D', INFO_CARD(0.11, 150, 0.05)}
                                };

    public:
        BANK(){
            
        }
        ~BANK(){
            
        }
        void print_bank_info(){
            cout<<"THIS IS BANK INFO:"<<endl;
            for (auto const &t: card_list){
                std::cout << t.first << " " << "profit rate: " <<t.second.profit_rate << " duration:" <<  t.second.duration << " rate punish money: "<<t.second.rate_punish_money<<endl;
            }
        }

        // void print_bank_info(card_list)
        // {
        //     // cout<<"THIS IS BANK INFO:"<<endl;
        //     // for (auto const &pair: card_list) {
        //     //     std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        //     // }
        // }
        
};

#endif