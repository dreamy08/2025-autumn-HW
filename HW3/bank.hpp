#pragma once

#include <iostream>
#include <string>
#include <vector>

/*
 * BankAccount — модель банковского счёта.
 * Инкапсулирует основные данные (номер, владелец, баланс) и операции:
 * - Deposit: пополнение
 * - Withdraw: снятие (с проверкой достаточности средств)
 * - getters: получить текущие данные
 * - PrintAccountInfo: вывести информацию о счёте
 */
class BankAccount {
private:
    std::string accountNumber_;  // номер счёта
    double balance_;             // текущий баланс
    std::string accountHolder_;  // имя владельца

public:
    // Конструктор инициализирует ВСЕ поля счёта
    BankAccount(std::string accountNumber, double balance, std::string accountHolder)
        : accountNumber_(std::move(accountNumber)),
          balance_(balance),
          accountHolder_(std::move(accountHolder)) {}

    /*
     * Deposit(amount) — пополнение счёта.
     * В простейшей модели считаем, что пополнение должно быть положительным.
     */
    void Deposit(double amount) {
        if (amount <= 0) {
            std::cerr << "Error: deposit amount must be positive\n";
            return;
        }
        balance_ += amount;
    }

    /*
     * Withdraw(amount) — снятие средств со счёта.
     * Проверяем:
     *  - amount > 0
     *  - на балансе достаточно денег
     * Если денег недостаточно — выводим сообщение об ошибке и НЕ меняем баланс.
     */
    void Withdraw(double amount) {
        if (amount <= 0) {
            std::cerr << "Error: withdraw amount must be positive\n";
            return;
        }
        if (balance_ < amount) {
            std::cerr << "Error: insufficient funds\n";
            return;
        }
        balance_ -= amount;
    }

    // Получить текущий баланс
    double GetBalance() const { return balance_; }

    // Получить имя владельца
    std::string GetAccountHolder() const { return accountHolder_; }

    // Получить номер счёта
    std::string GetAccountNumber() const { return accountNumber_; }

    /*
     * Выводит информацию о счёте в stdout.
     * Формат можно менять, но важно вывести все ключевые поля.
     */
    void PrintAccountInfo() const {
        std::cout << "Account number: " << accountNumber_ << "\n";
        std::cout << "Account holder: " << accountHolder_ << "\n";
        std::cout << "Balance: " << balance_ << "\n";
    }
};

/*
 * Bank — класс для управления несколькими счетами.
 * Хранит список счетов и умеет:
 * - AddAccount: добавить счёт
 * - GetTotalBalance: посчитать суммарный баланс по всем счетам
 * - PrintAllAccounts: вывести информацию о всех счетах
 */
class Bank {
private:
    std::vector<BankAccount> accounts_;  // список счетов в банке

public:
    // Добавляем новый счёт в список
    void AddAccount(const BankAccount& account) { accounts_.push_back(account); }

    // Сумма балансов всех счетов
    double GetTotalBalance() const {
        double sum = 0.0;
        for (const auto& acc : accounts_) {
            sum += acc.GetBalance();
        }
        return sum;
    }

    // Вывод информации обо всех счетах (каждый счёт отдельно)
    void PrintAllAccounts() const {
        for (const auto& acc : accounts_) {
            acc.PrintAccountInfo();
            std::cout << "----\n";
        }
    }
};
