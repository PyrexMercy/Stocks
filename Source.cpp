#include <iostream>
#include <fstream>
#include "Header.h"

using std::cout;
using std::endl;
using std::cin;


Stock::Stock(const std::string& company_, long shares_, double share_val_)
{
    company = company_;
    shares = shares_;
    share_val = share_val_;
    user_shares = 0;
    cash = 0;
    brokerage_accout();
}

Stock::~Stock()
{}

void Stock::refill()
{
    double cash_;
    std::cout << "Please, top up your wallet: ";
    std::cin >> cash_;
    cash = cash_;
    std::cout << cash << std::endl;
}


void Stock::buy(long shares_, double share_val_)
{
    while (cash < (shares_ * share_val_))
    {
        double cash_;
        std::cout << "Please , top up your wallet: ";
        std::cin >> cash_;
        cash += cash_;
    }
    if (shares_ < 0)
    {
        std::cout << "Sorry, shares are over" << std::endl;
    }
    else
    {
        shares -= shares_;
        share_val = share_val_;
        user_shares += shares_;
        cash -= (user_shares * share_val);
        brokerage_accout();
    }

}

void Stock::sell(long shares_, double share_val_, double user_share_val_)
{
    if (shares_ < 0)
    {
        std::cout << "Sorry, you don't have shares" << std::endl;
    }
    else if (shares_ > shares)
    {
        std::cout << "You can't sell more than you have" << std::endl;
    }
    else
    {
        shares += shares_;
        user_share_val = user_share_val_;
        user_shares -= shares_;
        total_val += (user_share_val - share_val) * shares_;
        share_val = (share_val_ + user_share_val) / 2;
    }
}

void Stock::show()
{
    using std::cout;
    using std::endl;
    cout << "Wallet: " << cash << endl;
    cout << "Company: " << company << endl;
    cout << "Shares: " << shares << endl;
    cout << "Share Price: " << share_val << endl;
    cout << "User Shares: " << user_shares << endl;
    cout << "Brokerage accout: " << total_val << endl << endl;
}

void Stock::show2() 
{
    std::cout << share_val << std::endl;
}

void menu();
void mainMenu();
void buy_shares();
void optionsMenu();
void options();
int choice1 = 0;
int choice2 = 3;
  
struct Stock_records
{
    std::string company;
    long shares;
    double share_val;
};




void buy_shares(Stock_records* s_r)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Company:";
        cin >> (s_r + i)->company;
        cout << "Shares:";
        cin >> (s_r + i)->shares;
        cout << "Share Price:";
        cin >> (s_r + i)->share_val;
    }
 
}

void sell_shares(Stock_records *s_r)
{
    std::string company_c;
    long shares_s;
    double shares_val_s;
    cout << "Write the company name" << endl;
    cin >> company_c;
    while (company_c != s_r->company)
    {
        cout << "This company doesn't exist" << endl;
        cin >> company_c;
    }
	cout << "Write the number of shares: ";
	cin >> shares_s;
	while (shares_s > s_r->shares)
	{
		cout << "You can't sell more than you have" << endl;
        cin >> shares_s;
	}
	s_r->shares -= shares_s;
	cout << "Write the price of share: ";
	cin >> shares_val_s;
    
}


void show_shares(Stock_records *s_r)
{
    int i;
    for ( i = 0; i < 3; i++)
    {
        cout << "Company: " << (s_r + i)->company << endl;
        cout << "Shares: " << (s_r + i)->shares << endl;
        cout << "Share Price: " << (s_r + i)->share_val << endl;
    }
}


void mainMenu(void)
{
    cout << "Stocks" << endl;
    cout << "1. Show share list" << endl;
    cout << "2. Buy shares" << endl;
    cout << "3. Sell shares" << endl;
    cout << ">>";
    std::cin >> choice1;
}

void menu(Stock_records *s_r)
{
    do
    {
        choice2 = 0;
        mainMenu();
        switch (choice1)
        {
        case 1:
            show_shares(s_r);
            break;
        case 2:
            buy_shares(s_r);
            break;
        case 3:
            sell_shares(s_r);
            break;

        default:
            break;
        }
    } while (choice1 != 4);
}


int main()
{
    Stock_records *Stocks = new Stock_records [3];
    menu(Stocks);

    return 0;

}