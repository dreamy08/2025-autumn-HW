#pragma once
#include <string>

// Базовый String (обёртка над std::string)
class String {
public:
    String() = default;
    String(const char* s) : data_(s ? s : "") {}
    String(std::string s) : data_(std::move(s)) {}

    String substr(std::size_t pos, std::size_t len) const {
        return String(data_.substr(pos, len));
    }

    const std::string& std() const { return data_; }

private:
    std::string data_;
};

// Наследник, добавляющий str[i][j]
class SliceString : public String {
public:
    using String::String; // наследуем конструкторы

    class Slice {
    public:
        Slice(const SliceString& owner, std::size_t i) : owner_(owner), i_(i) {}
        String operator[](std::size_t j) const {
            return owner_.substr(i_, j - i_);
        }
    private:
        const SliceString& owner_;
        std::size_t i_;
    };

    Slice operator[](std::size_t i) const { return Slice(*this, i); }
};
