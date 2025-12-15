#pragma once

#include <iostream>
#include <cstddef>   // size_t
#include <utility>   // std::move

/*
 * Array<T, N> — простой шаблон фиксированного массива.
 * - хранит N элементов типа T
 * - можно скопировать данные из указателя T* b
 * - show() печатает элементы
 * - minimum(m) записывает в m покоординатный минимум (min по каждому индексу)
 */
template <class T, std::size_t N>
class Array {
private:
    T array_[N];  // фиксированный массив из N элементов

public:
    // Пустой конструктор: элементы будут default-сконструированы (если возможно)
    Array() = default;

    // Конструктор копирования из "сырого" массива b длиной N
    explicit Array(const T* b) {
        for (std::size_t i = 0; i < N; ++i) {
            array_[i] = b[i];
        }
    }

    // Печать элементов массива
    void show() const {
        for (std::size_t i = 0; i < N; ++i) {
            std::cout << array_[i];
            if (i + 1 < N) std::cout << ' ';
        }
        std::cout << '\n';
    }

    /*
     * minimum(m): записывает в m минимум для каждого индекса:
     * m[i] = min(this[i], m[i]).
     * (То есть m становится "покомпонентным минимумом" двух массивов.)
     */
    void minimum(Array<T, N>& m) const {
        for (std::size_t i = 0; i < N; ++i) {
            if (array_[i] < m.array_[i]) {
                m.array_[i] = array_[i];
            }
        }
    }
};
