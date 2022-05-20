#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Header.h"

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::to_string;
using std::vector;

int choice0 = 0;
int choice1 = 3;


Stock::Stock() {}

Stock::~Stock() {}

void AllStocks()
{
    ifstream as("AllStocks.csv", std::ios::app);
    string index;
    string company_name;
    string shares;
    string share_val;

    while (as.peek() != EOF)
    {
        getline(as, index, ',');
        getline(as, company_name, ',');
        getline(as, shares, ',');
        getline(as, share_val, '\n');

        cout << index << ". Company: " << company_name << "; Shares: " << shares << "; Share Value: " << share_val << endl;
    }
    as.close();
}


void Stock::refill()
{
    double cash_;
    std::cout << "Please, top up your wallet: ";
    std::cin >> cash_;
    cash = cash_;
    std::cout << cash << std::endl;
}


void Stock::buy()
{
    string selected_index;
    string shares_b;
    string shares_val_b;
    AllStocks();
    cout << "Enter the number of requirement company" << endl;
    cout << ">>";
    cin >> selected_index;

    ifstream as("AllStocks.csv", std::ios::app);
    ofstream asnew("AllStocksNew.csv");
    string index;
    string company_name;
    string shares;
    string share_val;
    string line;
    string word;
    string roll;
    vector<string> row;


    while (as.peek() != EOF)
    {
        getline(as, index, ',');
        getline(as, company_name, ',');
        getline(as, shares, ',');
        getline(as, share_val, '\n');

        if (selected_index == index)
        {
            cout << index << ". Company: " << company_name << "; Shares: " << shares << "; Share Value: " << share_val << endl;
            cout << "Write the number of shares: ";
            cin >> shares_b;
            if (stol(shares_b) > stol(shares))
            {
                cout << "Sorry, the number of shares exceeds the current value" << endl;
            }
            else if (stol(shares_b) < 0)
            {
                cout << "Sorry, shares are over" << endl;
            }
            else
            {
                long shares_b2 = stol(shares_b);
                long shares2 = stol(shares);
                shares2 -= shares_b2;
                shares = to_string(shares2);
            }
            cout << "Write the share price" << endl;
            cin >> shares_val_b;
            if (stol(shares_val_b) < stol(share_val))
            {
                cout << "Sorry, share price cannot be less than the current" << endl;
            }
            else
            {

            }
            while (!as.eof())
            {
                row.clear();
                getline(as, line);
                std::stringstream s(line);
                while (getline(s, word, ','))
                {
                    row.push_back(word);
                }
                roll = row[0];
                int row_size = row.size();

                if (roll == selected_index)
                {
                    std::stringstream convert;
                    convert << shares;
                    row[3] = convert.str();
                    if (!as.eof())
                    {
                        for (int i = 0; i < row_size - 1; i++)
                        {
                            asnew << row[i] << ", ";
                        }
                        asnew << row[row_size - 1] << "\n";
                    }

                }
                else
                {
                    if (!as.eof())
                    {
                        for (int i = 0; i < row_size - 1; i++)
                        {
                            asnew << row[row_size - 1] << "\n";
                        }
                    }
                    if (as.eof())
                        break;
                }
                as.close();
                asnew.close();
                remove("AllStocks.csv");
                rename("AllStocksNew.csv", "AllStocks.csv");
            }
        }

    }
    as.close();
}

void Stock::sell()
{}

void Stock::show()
{}


void Stock::mainMenu(void)
{
    cout << "Stocks" << endl;
    cout << "1. Show share list" << endl;
    cout << "2. Buy shares" << endl;
    cout << "3. Sell shares" << endl;
    cout << ">>";
    std::cin >> choice1;
}

void Stock::menu()
{
    do
    {
        choice1 = 0;
        mainMenu();
        switch (choice1)
        {
        case 1:
            show();
            break;
        case 2:
            buy();
            break;
        case 3:
            sell();
            break;
        default:
            break;
        }
    } while (choice0 != 4);

}
int main()
{
    Stock obj1;
    obj1.menu();
}


/*void menu();
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

}*/