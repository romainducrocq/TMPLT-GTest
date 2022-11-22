#include "gtest_ex.hpp"

/***
 *
 * Asserts & Expects
 *
 * ASSERT_TRUE(condition)
 * ASSERT_EQ(expected, actual)
 * ASSERT_STREQ(expected_str, actual_str)
 *
 * EXPECT_TRUE(condition)
 * EXPECT_EQ(expected, actual)
 * EXPECT_STREQ(expected_str, actual_str)
 */

/***
 *
 * Unit test
 *
 * @param TestSuiteName the test suite name
 * @param TestName the test name
 */
TEST(AccountTest, BankAccountStartsEmpty)
{
    BankAccount account;
    EXPECT_EQ(0, account.balance);
}

/***
 *
 * Unit test with fixture
 *
 * @param TestFixtureName the test fixture name
 * @param TestName the test name
 */
TEST_F(BankAccountTest, BankAccountStartsEmpty_F)
{
    EXPECT_EQ(0, account->balance);
}

TEST_F(BankAccountTest, CanDepositMoney_F)
{
    account->deposit(100);
    EXPECT_EQ(100, account->balance);
}

/***
 *
 * Unit parameterized test with fixture
 *
 * @param TestFixtureName the test fixture name
 * @param TestName the test name
 */
TEST_P(WithdrawAccountTest, FinalBalance_P)
{
    auto as = GetParam();
    auto success = account->withdraw(as.withdraw_amount);
    EXPECT_EQ(as.final_balance, account->balance);
    EXPECT_EQ(as.success, success);
}

/***
 *
 * Instantiate unit parameterized test fixture
 *
 * @param InstantiationName the test instanciation name
 * @param TestFixtureName the test fixture name
 * @param param_generator the parameters to test
 */
INSTANTIATE_TEST_SUITE_P(WithdrawAccountInstanciation, WithdrawAccountTest,
                         testing::Values(
                                 account_state{100,50,50,true},
                                 account_state{100,200,100,false}
                                 ));
