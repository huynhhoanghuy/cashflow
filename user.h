#ifndef      __USER_H__
#define      __USER_H__
#include <cstdlib>

struct INFO_CARD_USER{
    //char id_card;
    char type_card;
    double money;
    unsigned short remaining_time;
    

    INFO_CARD_USER(char _type_card = '?', double _money = '0', unsigned short _remaining_time = '0'){
        type_card = _type_card;
        money = _money;
        remaining_time = _remaining_time;
    }

    void show_info(){
        cout<<"type_card: "<<type_card<<endl;
        cout<<"money: "<<money<<endl;
        cout<<"remaining_time: "<<remaining_time<<endl;
    }
};

struct LIST_CARD_USER{
    short id_card;
    INFO_CARD_USER info_card;
    LIST_CARD_USER* p_next;
    
    
    
    LIST_CARD_USER(){
        info_card = INFO_CARD_USER();
        id_card = 0;
        p_next = NULL;
    }
    short get_idCARD(){
        return id_card;
    }
    bool is_empty(){
        if (id_card == 0){
            return true;
        }
        return false;
    }
    
    void addCARDtoTail(LIST_CARD_USER *l, INFO_CARD_USER _card){

        if (l->info_card.type_card == '?'){
            l->info_card = _card;
            l->id_card = 1;
            cout<<"ADDED!"<<endl;
        }
        else{
            
            
            LIST_CARD_USER *head = l;
            while(head->p_next != NULL){
                head = head->p_next;
                
            }

            head->p_next = new LIST_CARD_USER();
            
            head->p_next->info_card = _card;
            head->p_next->id_card = head->id_card + 1;
            
            
            cout<<"ADDED!"<<endl;
        }
    }
    

};


class USER{
    // USER IN 0th DAY
    private:
        double total_money_ATM;
        double profit_30_days = 0;
        LIST_CARD_USER *card_list; 
    public:
        USER(){
            card_list = new LIST_CARD_USER();
            total_money_ATM = RandomDouble(double(minStartMoney),double(maxStartMoney));
            cout<<"total_money_ATM:"<<total_money_ATM<<endl;
            cout << "CREATE RANDOM TOTAL MONEY OF USER!"<<endl;

        }
        ~USER(){
            
        }
        
        double get_money_ATM(){
            return total_money_ATM;
        }
        

        void createCardList(TRANSACTION trans){

        }
        
        LIST_CARD_USER* sort(){

        }

        double withdraw(double withdrawMoney){
            // if transaction[i] <0 => This is withdraw money. If ATM has not money, must use money from card_list.
            total_money_ATM -=  withdrawMoney;
            if (total_money_ATM < 0){
                //chose card_list to withdraw
                //I chose the card has longest reamining_time
                //Sort card list by remaining time
                LIST_CARD_USER *ordered_list = card_list.sort();
                while ((not Equality(total_money_ATM, 0)) && (not ordered_list.is_empty())){
                    //withdraw the card where has largest money, then seccond, third, ...
                }
            }
        }
};

#endif