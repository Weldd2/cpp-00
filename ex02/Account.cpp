#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += _amount;
	this->_nbWithdrawals = 0;
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl
	;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl
	;
}

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);
	std::cout << "[" 
		<< 1900 + ltm->tm_year
		<< (ltm->tm_mon < 9 ? "0" : "") << 1 + ltm->tm_mon
		<< (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday
		<< "_"
		<< (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
		<< (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
		<< (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec
		<< "] ";
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << "deposit:" << deposit << ";";
	this->_nbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount || withdrawal < 0) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	Account::_totalNbWithdrawals++;
	return true;
}
int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals
		<< std::endl
	;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout
		<< "accounts:" << Account::_nbAccounts << ";"
		<< "total:" << Account::_totalAmount << ";"
		<< "deposits:" << Account::_totalNbDeposits << ";"
		<< "withdrawals:" << Account::_totalNbWithdrawals
		<< std::endl
	;
}