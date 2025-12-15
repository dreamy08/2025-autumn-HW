#include <gtest/gtest.h>
#include "HW2/text_editor.hpp"

// 1) Добавление в пустой редактор
TEST(TextEditorHW2, AddTextToEmpty) {
    TextEditor ed;
    ed.addText("abc");
    EXPECT_EQ(ed.getText(), "abc");
    EXPECT_EQ(ed.cursorLeft(0), "abc");
    EXPECT_EQ(ed.cursorRight(0), "");
}

// 2) Сдвиг курсора влево и корректность правой части
TEST(TextEditorHW2, CursorLeftMovesAndRightPartCorrect) {
    TextEditor ed;
    ed.addText("hello");                // hello|
    EXPECT_EQ(ed.cursorLeft(2), "hel"); // hel|lo
    EXPECT_EQ(ed.cursorRight(0), "lo"); // правая часть без движения
    EXPECT_EQ(ed.getText(), "hello");
}

// 3) Вставка текста в середину
TEST(TextEditorHW2, InsertInMiddle) {
    TextEditor ed;
    ed.addText("hello");     // hello|
    ed.cursorLeft(2);        // hel|lo
    ed.addText("X");         // helX|lo
    EXPECT_EQ(ed.getText(), "helXlo");
}

// 4) Удаление (Backspace) в середине, удаляем несколько символов
TEST(TextEditorHW2, DeleteInMiddle) {
    TextEditor ed;
    ed.addText("hello");     // hello|
    ed.cursorLeft(2);        // hel|lo
    ed.addText("XY");        // helXY|lo
    EXPECT_EQ(ed.deleteText(2), 2); // hel|lo
    EXPECT_EQ(ed.getText(), "hello");
}

// 5) Граница: cursorLeft больше доступного — упираемся в начало
TEST(TextEditorHW2, CursorLeftPastBegin) {
    TextEditor ed;
    ed.addText("abc");                // abc|
    EXPECT_EQ(ed.cursorLeft(100), ""); // |abc
    EXPECT_EQ(ed.cursorRight(0), "abc");
    EXPECT_EQ(ed.getText(), "abc");
}

// 6) Граница: deleteText больше доступного — удаляет всё
TEST(TextEditorHW2, DeletePastAvailable) {
    TextEditor ed;
    ed.addText("abc");
    EXPECT_EQ(ed.deleteText(10), 3);
    EXPECT_EQ(ed.getText(), "");
    EXPECT_EQ(ed.deleteText(1), 0);
}
