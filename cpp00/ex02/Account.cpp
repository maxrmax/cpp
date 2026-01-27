#include "Account.hpp"
#include <iostream>
#include <ctime>

/*
flow:
	accounts_t				accounts( amounts, amounts + amounts_size );
should print every index:X;amount:XXX;created
then
	Account::displayAccountsInfos();
should display accounts:X;total:X;deposits:X;withdrawals:0
then
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
display each account status index:X;amount:X;deposits:X;withdrawals:X
then
first for loop:
: index:X;p_amount:X;deposit:X;amount:X;nb_deposits:X
then
	Account::displayAccountsInfos();
and
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
again (display status of total then each acc)
then
2nd for loop
index:0;p_amount:47;withdrawal:refused
then: status again

then deconstructor prints:
index:0;amount:47;closed

*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout
	<< "index:"
	<< _accountIndex
	<< ";amount:"
	<< initial_deposit
	<< ";created"
	<< std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout
	<< "index:"
	<< _accountIndex
	<< ";amount:"
	<< _amount
	<< ";closed"
	<< std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
	<< "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";deposit:" << deposit
	<< ";amount:" << _amount + deposit
	<< ";nb_deposits:" << ++_nbDeposits
	<< std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal <= _amount)
	{
		std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount - withdrawal
		<< ";nb_withdrawals:" << ++_nbWithdrawals
		<< std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return 1;
	}
	else
	{
		std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:" << "refused"
		<< std::endl;
		return 0;
	}
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t current = time(NULL);
	struct tm *timeinfo = localtime(&current);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << buffer << "] ";
}