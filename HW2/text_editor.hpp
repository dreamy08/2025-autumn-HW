#pragma once

#include <algorithm>
#include <string>

/*
 * Храню текст как две части:
 *  - left_: всё слева от курсора (обычный порядок)
 *  - right_: всё справа от курсора (как стек, right_.back() — символ сразу справа от курсора)
 *
 * Это позволяет эффективно:
 *  addText: O(|text|)
 *  deleteText: O(k)
 *  cursorLeft/cursorRight: O(k)
 */
class TextEditor {
public:
    TextEditor() = default;

    // Добавляет text в позицию курсора (в конец left_)
    void addText(const std::string& text) { left_ += text; }

    // Удаляет k символов слева от курсора (Backspace). Возвращает фактически удалённое число.
    int deleteText(int k) {
        int del = std::min<int>(k, static_cast<int>(left_.size()));
        left_.erase(left_.size() - del, del);
        return del;
    }

    // Сдвигает курсор на k символов влево.
    // Возвращает все символы слева от курсора (в порядке текста).
    std::string cursorLeft(int k) {
        int mv = std::min<int>(k, static_cast<int>(left_.size()));
        while (mv--) {
            right_.push_back(left_.back());
            left_.pop_back();
        }
        return left_;
    }

    // Сдвигает курсор на k символов вправо.
    // Возвращает все символы справа от курсора (в порядке текста).
    std::string cursorRight(int k) {
        int mv = std::min<int>(k, static_cast<int>(right_.size()));
        while (mv--) {
            left_.push_back(right_.back());
            right_.pop_back();
        }
        return rightString();
    }

    // Удобно для тестов/отладки: полный текст
    std::string getText() const { return left_ + rightString(); }

private:
    std::string left_;
    std::string right_; // стек: back() ближе всего к курсору

    // Правая часть в норм порядке (от курсора к концу)
    std::string rightString() const {
        return std::string(right_.rbegin(), right_.rend());
    }
};
