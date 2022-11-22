// http://google.github.io/googletest/reference/testing.html
// https://www.youtube.com/watch?v=16FI1-d2P4E
// https://www.linuxembedded.fr/2014/09/introduction-a-google-c-testing-framework
// https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/

#ifndef _GTEST_EX_HPP
#define _GTEST_EX_HPP

#include <gtest/gtest.h>

#include <iostream>
#include <memory>

struct BankAccount
{
    int balance = 0;

    BankAccount()
    {
    }

    explicit BankAccount(const int balance)
            : balance(balance)
    {
    }

    void deposit(int amount)
    {
        this->balance += amount;
    }

    bool withdraw(int amount)
    {
        if(amount <= balance) {
            this->balance -= amount;
            return true;
        }
        return false;
    }
};

struct account_state
{
    int initial_balance;
    int withdraw_amount;
    int final_balance;
    bool success;

    friend std::ostream& operator<<(std::ostream& os, const account_state& obj)
    {
        return os
            << "initial_balance: " << obj.initial_balance
            << "withdraw_amount: " << obj.withdraw_amount
            << "final_balance: " << obj.final_balance
            << "success: " << obj.success;
    }
};

/***
 *
 * Test fixture
 *
 * Shared test suite environment
 */
struct BankAccountTest : testing::Test
{
    // BankAccount* account;
    std::unique_ptr<BankAccount> account;

    BankAccountTest()
    {
        // this->account = new BankAccount();
        this->account = std::make_unique<BankAccount>();
    }

    virtual ~BankAccountTest()
    {
        // delete this->account;
    }

};

/***
 *
 * Test parameterized fixture
 *
 * Shared parameterized test suite environment
 * @tparam T parameter type
 * @GetParam() get parameter
 */
struct WithdrawAccountTest : BankAccountTest, testing::WithParamInterface<account_state>
{
    WithdrawAccountTest()
    {
        account->balance = GetParam().initial_balance;
    }
};

#endif