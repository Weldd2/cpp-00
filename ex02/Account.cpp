#include "Account.hpp"
#include <chrono>
#include <ctime>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_nbAccounts++;
	Account::_accountIndex = _nbAccounts;
	Account::_amount = initial_deposit;
	Account::_totalAmount += _amount;
	Account::_nbDeposits = 1;
	Account::_totalNbDeposits++;
	Account::_nbWithdrawals = 0;
}

static void	_displayTimestamp( void )
{
	auto now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);
	std::cout << std::ctime(&now_time);
}
