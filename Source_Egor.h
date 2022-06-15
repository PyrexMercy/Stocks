#pragma once
#include "Wallet.h"
#include "Transaction.h"

class Stock
{
public:
	static void allStock();
	static void userShares();
	static void totalValue();
	static void buy();
	static void sell();
	static void menu();
	static string selected_user;
};

