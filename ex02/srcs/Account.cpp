#include <Account.hpp>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	Account::_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_accountIndex = getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account( void ){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
	Account::_nbAccounts--;
}

int	Account::getNbAccounts( void ){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::getTotalAmount() << ";deposits:" << \
		Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ){
	Account::_displayTimestamp();
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";deposit:" << deposit << \
		";amount:" << this->checkAmount() + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
	if (this->checkAmount() > withdrawal)
	{
		Account::_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->checkAmount() - withdrawal << \
			";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		this->_amount -= withdrawal;
		Account::_totalAmount -=withdrawal;
		return (true);
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const{
	return (this->_amount);
}

void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:" << \
		this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ){
	char	buffer[19];
	std::time_t present;

	std::time(&present);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", std::localtime(&present));
	std::cout << buffer;
}