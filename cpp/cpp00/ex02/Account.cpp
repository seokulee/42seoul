#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts( void ) {
	return _nbAccounts;
}
int Account::getTotalAmount( void ) {
	return _totalAmount;
}
int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}
int Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void) {
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[20];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 20, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << buffer << "]";
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits() << ";withdrawls:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	bool approval = true;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount - withdrawal < 0) {
		approval = false;
		std::cout << "refused" << std::endl;
	} else {
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbDeposits++;
		_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawl:" << _nbWithdrawals << std::endl;
	}
	return (approval);
}

int		Account::checkAmount( void ) const {
	return _amount;
}
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
