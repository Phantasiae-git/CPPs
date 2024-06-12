/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:22:12 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 14:28:21 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts=0;
int	Account::_totalAmount=0;
int	Account::_totalNbDeposits=0;
int	Account::_totalNbWithdrawals=0;

Account::Account( int initial_deposit )
{
    this->_accountIndex=Account::_nbAccounts;
    this->_amount=initial_deposit;
    this->_nbDeposits=0;
    this->_nbWithdrawals=0;
    Account::_nbAccounts++;
    Account::_totalAmount+=initial_deposit;
    Account::_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";created" << std::endl;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";closed" << std::endl;
}

int Account::getNbAccounts(void) {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void) {
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void) {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return (Account::_totalNbWithdrawals);
}

void    Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<this->_amount<<";deposit:"<< deposit;
    this->_amount+=deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout<<";amount:"<<this->_amount<<";nb_deposits:"<<this->_nbDeposits<<std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";p_amount:"<<this->_amount << ";withdrawal:";
    if (this->_amount >= withdrawal) 
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        std::cout<<withdrawal<<";amount:"<<this->_amount<<";nb_withdrawals:"<<Account::_nbWithdrawals<<std::endl;
        return(true);
    }
    else
    {
        std::cout<<"refused"<<std::endl;
        return(false);
    }
}

int		Account::checkAmount( void ) const
{
    return(this->_amount);
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->_amount<<";deposits:"<<this->_nbDeposits<<";withdrawals:"<<this->_nbWithdrawals<<std::endl;
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout<<"accounts:"<<Account::_nbAccounts<<";total:"<<Account::_totalAmount<<";deposits:"<<Account::_totalNbDeposits<<";withdrawals:"<<Account::_totalNbWithdrawals<<std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t t_stmp_ptr;
    struct tm* t_stmp;

    std::time(&t_stmp_ptr);
    t_stmp = localtime(&t_stmp_ptr);
    std::cout<<"["<<(t_stmp->tm_year + 1900)<<std::setw(2)<<std::setfill('0')
    <<(t_stmp->tm_mon + 1)<<std::setw(2)<<std::setfill('0')<<t_stmp->tm_mday<<"_"<<std::setw(2)<<std::setfill('0')<<t_stmp->tm_hour
    <<std::setw(2)<<std::setfill('0')<<t_stmp->tm_min<<std::setw(2)<<std::setfill('0')<<t_stmp->tm_sec<<"] ";
}
