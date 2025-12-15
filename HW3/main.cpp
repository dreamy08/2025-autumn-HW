#include "bank.hpp"

int main() {
    // Создаём несколько счетов
    BankAccount a1("ACC-001", 1000.0, "Alice");
    BankAccount a2("ACC-002", 250.0, "Bob");
    BankAccount a3("ACC-003", 500.0, "Charlie");

    // Проводим несколько операций
    a1.Deposit(200.0);     // пополнение
    a2.Withdraw(50.0);     // успешное снятие
    a3.Withdraw(1000.0);   // неуспешно (денег недостаточно) -> будет сообщение в stderr

    // Складываем счета в банк
    Bank bank;
    bank.AddAccount(a1);
    bank.AddAccount(a2);
    bank.AddAccount(a3);

    // Печатаем информацию о каждом счёте и общий баланс банка
    bank.PrintAllAccounts();
    std::cout << "Total balance: " << bank.GetTotalBalance() << "\n";

    return 0;
}
