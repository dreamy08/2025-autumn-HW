#include <gtest/gtest.h>
#include "HW3/bank.hpp"

#include <string>

/* 1) Пополнение увеличивает баланс на сумму пополнения */
TEST(BankHW3, DepositIncreasesBalance) {
    BankAccount acc("A1", 100.0, "User");
    acc.Deposit(50.0);
    EXPECT_DOUBLE_EQ(acc.GetBalance(), 150.0);
}

/* 2) Снятие при достаточном балансе уменьшает баланс */
TEST(BankHW3, WithdrawDecreasesBalanceWhenEnough) {
    BankAccount acc("A1", 100.0, "User");
    acc.Withdraw(40.0);
    EXPECT_DOUBLE_EQ(acc.GetBalance(), 60.0);
}

/* 3) Если денег недостаточно — баланс не меняется и печатается ошибка */
TEST(BankHW3, WithdrawInsufficientFundsKeepsBalanceAndPrintsError) {
    BankAccount acc("A1", 10.0, "User");

    testing::internal::CaptureStderr();
    acc.Withdraw(100.0);
    std::string err = testing::internal::GetCapturedStderr();

    EXPECT_NE(err.find("insufficient funds"), std::string::npos);
    EXPECT_DOUBLE_EQ(acc.GetBalance(), 10.0);
}

/* 4) Геттеры возвращают корректные данные (номер, владелец, баланс) */
TEST(BankHW3, GettersReturnCorrectData) {
    BankAccount acc("ACC-777", 123.0, "Alice");
    EXPECT_EQ(acc.GetAccountNumber(), "ACC-777");
    EXPECT_EQ(acc.GetAccountHolder(), "Alice");
    EXPECT_DOUBLE_EQ(acc.GetBalance(), 123.0);
}

/* 5) Bank корректно считает суммарный баланс по всем счетам */
TEST(BankHW3, BankTotalBalanceIsSum) {
    Bank bank;
    bank.AddAccount(BankAccount("A1", 10.0, "U1"));
    bank.AddAccount(BankAccount("A2", 20.5, "U2"));
    bank.AddAccount(BankAccount("A3", 0.0, "U3"));

    EXPECT_DOUBLE_EQ(bank.GetTotalBalance(), 30.5);
}

/* 6) PrintAccountInfo выводит всю ключевую информацию */
TEST(BankHW3, PrintAccountInfoContainsFields) {
    BankAccount acc("ACC-001", 1000.0, "Alice");

    testing::internal::CaptureStdout();
    acc.PrintAccountInfo();
    std::string out = testing::internal::GetCapturedStdout();

    EXPECT_NE(out.find("ACC-001"), std::string::npos);
    EXPECT_NE(out.find("Alice"), std::string::npos);
    EXPECT_NE(out.find("1000"), std::string::npos);
}
