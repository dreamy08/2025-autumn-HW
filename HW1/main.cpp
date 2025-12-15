// Поддерживаемые операции: +, -, *, /
// Разделитель токенов: пробелы
//
// Использование:
//   hw1                -> читает "HW1/input.txt", пишет "HW1/output.txt"
//   hw1 in.txt out.txt -> читает in.txt, пишет out.txt
//
// Примечание про деление: используется целочисленное деление C++ (как в твоём коде).

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

// Проверяем, что токен — целое число (включая отрицательные)
static bool isNumber(const string& s) {
    if (s.empty()) return false;

    size_t i = 0;
    if (s[0] == '-' && s.size() > 1) i = 1;

    for (; i < s.size(); ++i) {
        if (!isdigit(static_cast<unsigned char>(s[i]))) return false;
    }
    return true;
}

// Вычисляет одно RPN-выражение из строки.
// Если строка некорректная (не хватает операндов/неизвестный токен),
// возвращаем 0 (так не падаем на странных строках).
static long long evalRPN(const string& line) {
    istringstream iss(line);
    stack<long long> st;

    string tok;
    while (iss >> tok) {
        if (isNumber(tok)) {
            st.push(stoll(tok));
            continue;
        }

        // Ожидаем операцию: для неё нужны 2 операнда на стеке
        if (st.size() < 2) return 0;

        long long b = st.top(); st.pop();
        long long a = st.top(); st.pop();

        if (tok == "+") st.push(a + b);
        else if (tok == "-") st.push(a - b);
        else if (tok == "*") st.push(a * b);
        else if (tok == "/") {
            // Защита от деления на 0: возвращаем 0, чтобы не падать
            if (b == 0) return 0;
            st.push(a / b); // целочисленное деление
        } else {
            // Неизвестный токен
            return 0;
        }
    }

    // Корректное RPN должно оставить ровно одно число
    if (st.size() != 1) return 0;
    return st.top();
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Пути по умолчанию (как в структуре твоего проекта)
    string inPath  = "HW1/input.txt";
    string outPath = "HW1/output.txt";

    // Если дали аргументы — используем их
    if (argc >= 2) inPath  = argv[1];
    if (argc >= 3) outPath = argv[2];

    ifstream fin(inPath);
    if (!fin) {
        cerr << "Cannot open input file: " << inPath << "\n";
        return 1;
    }

    ofstream fout(outPath);
    if (!fout) {
        cerr << "Cannot open output file: " << outPath << "\n";
        return 1;
    }

    // Читаем файл построчно и пишем результат в выходной файл
    string line;
    bool firstLineWritten = false;

    while (getline(fin, line)) {
        if (line.empty()) continue; // пустые строки пропускаем

        long long value = evalRPN(line);

        // Чтобы не добавлять лишнюю пустую строку в начале файла
        if (firstLineWritten) fout << '\n';
        fout << line << " = " << value;

        firstLineWritten = true;
    }

    return 0;
}
