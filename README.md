# 2025-autumn-HW
# 2025-autumn-HW

![CI](https://github.com/dreamy08/2025-autumn-HW/actions/workflows/ci.yml/badge.svg?branch=ci_test)

Репозиторий с домашними заданиями по C++ (осень 2025).  
Каждая домашка лежит в своей папке `HW<N>/`.

## Структура репозитория

- `HW1/` — ДЗ1 (консольная программа, запуск через input.txt)
- `HW2/` — ДЗ2 (TextEditor + курсор)
- `HW3/` — ДЗ3 (BankAccount + Bank)
- `HW4/` — ДЗ4 (оператор `[][]` для подстроки в `String`)
- `HW5/` — ДЗ5 (шаблонный класс `Array<T, N>`)
- `tests/` — модульные тесты (GTest) для ДЗ2 и ДЗ3
- `.github/workflows/ci.yml` — GitHub Actions CI
- `.clang-format` — форматирование кода
- `Makefile` — сборка/запуск/тесты
- `.gitignore` — исключения (build-артефакты не коммитятся)

## Требования

- `g++` с поддержкой C++20
- `make`
- Для тестов: GoogleTest (в CI ставится автоматически)

## Быстрый старт

Сборка любой домашки:
```bash
make build HW=1
