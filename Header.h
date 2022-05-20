#pragma once
#ifndef HEADER_H_
#define HEADER_H_
#include <string>

class Stock
{
private:
    std::string company; //Название компании
    long shares; //Количество акций
    double share_val; //Цена за акцию
    double cash; //Кошелек
    long user_shares; //Количество акций пользователя
    double user_share_val; //Цена за акцию, которую продает пользователь
    double total_val; //Брокерский счет
    void brokerage_accout() { total_val = user_shares * share_val; }
public:
    Stock();
    ~Stock();
    void refill();
    void buy();
    void sell();
    void show();
    void menu();
    void mainMenu(void);
};

#endif HEADER_H_