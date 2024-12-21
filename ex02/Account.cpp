#include "Account.hpp"
#include <ctime>
#include <iostream>
	
int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << " account:"    << Account::getNbAccounts();
	std::cout << ";total:"      << Account::getTotalAmount();
	std::cout << ";deposits:"   << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

//[19920104_091532] index:4;amount:1234;created
Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts +=1;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:"       << this->_accountIndex;
	this->_amount = initial_deposit;
	std::cout << ";amount:"      << this->_amount;
	std::cout << "created" << std::endl;
}

//[19920104_091532] index:2;amount:864;closed
Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << " index:"       << this->_accountIndex;
	std::cout << ";amount:"      << this->_amount;
	std::cout << "closed" << std::endl;
	Account::_nbAccounts -=1;
}

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << " index:"       << this->_accountIndex;
	std::cout << ";p_amount:"      << this->_amount;
	std::cout << ";deposit:"      << deposit;
	this->_amount += deposit;
	std::cout << ";amount:"      << this->_amount;
	this->_nbDeposits +=1;
	std::cout << ";deposits:"    << this->_nbDeposits;
	std::cout << std::endl;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
}

//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
	bool result = false;

	Account::_displayTimestamp();
	std::cout << " index:"       << this->_accountIndex;
	std::cout << ";p_amount:"      << this->_amount;
	std::cout << ";withdrawal:";
	if (withdrawal <= this->_amount)
	{
		this->_amount -= withdrawal;
		std::cout << this->_amount;
		std::cout << ";amount:"      << this->_amount;
		std::cout << ";withdrwals:"  << this->_nbWithdrawals;
		std::cout << std::endl;
		this->_nbWithdrawals +=1;
		Account::_totalAmount -= withdrawal;
		result = true;
	}
	else
	{
		std::cout << "refused" << std::endl;
	}
	return result;
}


int		Account::checkAmount( void ) const
{
	return 0 ;
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:"       << this->_accountIndex;
	std::cout << ";amount:"      << this->_amount;
	std::cout << ";deposits:"    << this->_nbDeposits;
	std::cout << ";withdrwals:"  << this->_nbWithdrawals;
	std::cout << std::endl;

}

void	Account::_displayTimestamp( void )
{
	size_t		length = 15;
	std::time_t now;
	std::tm 	*timeinfo;
	char		*timetext = NULL;

	std::time(&now);
	timeinfo = localtime(&now);
	std::strftime (timetext, length, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[ << timetext << ]" ;
};

Account::Account( void )
{
	this->_accountIndex = Account::_nbAccounts;
	std::cout << "account_creado" << std::endl;
	Account::_nbAccounts +=1;
}


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
