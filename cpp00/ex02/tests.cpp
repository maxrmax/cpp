// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {
// typedef = nickname for readability or maintainability
	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	// define the amounts
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	// define size
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	// ____________________________________________________________________________
	// The ( ) is calling the constructor of std::vector<Account>.
	// creates a vector by copying elements
	// amounts is first element, amounts + amounts_size is NULL (one past last)
	// basically copies all values in this range (first to last)
	// ClassName objectName(constructor_arguments);
	// vector(InputIterator first, InputIterator last);
	// what happens step by step:
	// create vector of Accounts
	// for each int in amounts array -> call Account(int initial_deposit) constructor with that int
	// add that Account object to the vector
	// its not accessing/calling the class, its calling the constructor, which internally calls Account(int)
	accounts_t				accounts( amounts, amounts + amounts_size );
	// ____________________________________________________________________________
	// ::iterator is included in the vector library
	// here we just tell it the begin and end
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	// same as accounts, except its all ints instead of a class
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	// same as d (not a class)
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	// first call
	// calls the display infos function
	Account::displayAccountsInfos();
	// mem_fun_ref -> member function reference
	// so for_each can use it
	// "when you give me an Account object, call .displayStatus() on it"
	// address of the member function
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		// dereference to get account object
		// deposit the int (second) into the current account object
		// it.first->makeDeposit( *(it.second) ); is the same
		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
