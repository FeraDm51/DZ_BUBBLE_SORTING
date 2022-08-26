#include <iostream>
#include <string>
#include <algorithm>

#include "headers/graphics.h"

/*
Визуализация пузырьковой сортировки.
Давайте хранить массив случайных чисел, каждое число - высота прямоугольника. Ширина каждого прямоугольника - фиксированная.
В зависимости от того, какое число в массиве - рисуем прямоугольник той или иной высоты
*/

const int MAX_RECTANGLES = 15;              // число прямоугольников
const int x_start = 100;                    //Левая граница прямоугольников
const int y_start = 400;                    //Нижняя граница прямоугольников
const int RECT_WIDTH = 20;                  //Ширина прямоугольника
const int MAX_HEIGHT = 200;                 //Максимальная высота прямоугольника

const int WIDTH = 800;                      //Ширина окна
const int HEIGHT = 700;                     //Высота окна

int arr[MAX_RECTANGLES];                //Массив высот прямоугольников

const int BUTTON_1_LEFT = 22;                 //Границы кнопк 1 левая по Х
const int BUTTON_1_TOP = HEIGHT - 100;       // верх по У
const int BUTTON_1_RIGHT = 144;             // Гр кн правая по х
const int BUTTON_1_BOTTOM = HEIGHT - 22;     // низ по Х


const int BUTTON_2_LEFT = 188;                  //Границы кнопк 2
const int BUTTON_2_TOP = HEIGHT - 100;         //
const int BUTTON_2_RIGHT = 310;               //
const int BUTTON_2_BOTTOM = HEIGHT - 22;     //

const int BUTTON_3_LEFT = 354;                  //Границы кнопк 3
const int BUTTON_3_TOP = HEIGHT - 100;         //
const int BUTTON_3_RIGHT = 476;               //
const int BUTTON_3_BOTTOM = HEIGHT - 22;     //



void draw_rectangles(int color);            //Рисует все прямоугольники
bool is_sorted();                           //Проверяет, отсортирован массив или нет
void bubble_sort_iteration(int j);          //Делает одну итерацию сортировки пузырьком (если arr[j] > arr[j + 1] - меняет местами)
void random_fill_array();                   //Заполняет массив случайными числами от 0 до MAX_HEIGHT
void draw_button_1_();                         //Отрисовка кнопки 1(предстаавление фунлции)
void draw_button_2_();                         //Отрисовка кнопки 2 (предстаавление фунлции)
void draw_button_3_();                         //Отрисовка кнопки 3 (предстаавление фунлции)
bool is_clicked_1_();                          //Возвращает true, если кнопка 1 нажата
bool is_clicked_2_();                          //Возвращает true, если кнопка 2 нажата
bool is_clicked_3_();                          //Возвращает true, если кнопка 3 нажата

void random_shuffle();                      //Перемешивание массива
void random_color(int r, int g, int b);                         //Функция возвращает случайный цвет

//Отрисовка кнопок 1..2..3 1(ОПИСАНИЕ фунлции)
void draw_button_1_() {
    setfillstyle(INTERLEAVE_FILL, WHITE);
    bar(BUTTON_1_LEFT, BUTTON_1_TOP, BUTTON_1_RIGHT, BUTTON_1_BOTTOM);
}
void draw_button_2_() {
    setfillstyle(INTERLEAVE_FILL, WHITE);
    bar(BUTTON_2_LEFT, BUTTON_2_TOP, BUTTON_2_RIGHT, BUTTON_2_BOTTOM);
}
void draw_button_3_() {
    setfillstyle(INTERLEAVE_FILL, WHITE);
    bar(BUTTON_3_LEFT, BUTTON_3_TOP, BUTTON_3_RIGHT, BUTTON_3_BOTTOM);
}

// проверка нажатия "Кнопок" 1..2..3
bool is_clicked_1_() {
    int x = mousex();
    int y = mousey();
    return x >= BUTTON_1_LEFT && x <= BUTTON_1_RIGHT && y >= BUTTON_1_TOP && y <= BUTTON_1_BOTTOM && mousebuttons() == 1;
}
bool is_clicked_2_() {
    int x = mousex();
    int y = mousey();
    return x >= BUTTON_2_LEFT && x <= BUTTON_2_RIGHT && y >= BUTTON_2_TOP && y <= BUTTON_2_BOTTOM && mousebuttons() == 1;
}
bool is_clicked_3_() {
    int x = mousex();
    int y = mousey();
    return x >= BUTTON_3_LEFT && x <= BUTTON_3_RIGHT && y >= BUTTON_3_TOP && y <= BUTTON_3_BOTTOM && mousebuttons() == 1;
}


// описание фунции отрисовки квадрата
void draw_rectangles(int color) {
    setfillstyle(SOLID_FILL, color);
    int x = x_start;
    for (int i = 0; i < MAX_RECTANGLES; ++i) {
        bar(x, y_start - arr[i], x + RECT_WIDTH, y_start);
        x += RECT_WIDTH;
    }
}

//Заполни массив arr[i] случайными значенем  
void random_fill_array() {
    for (int i = 0; i < MAX_RECTANGLES; ++i) {
        arr[i] = rand() % MAX_HEIGHT;
    }
}

bool is_sorted() {
    for (int i = 0; i < MAX_RECTANGLES - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void random_shuffle() {
    for (int i = 0; i < MAX_RECTANGLES - 1; ++i) {
        int shufl;
        shufl = rand() % MAX_RECTANGLES;
        std::swap(arr[i], arr[shufl]);

    }
}

int random_color() {
    int r, g, b;
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
    return RGB(r, g, b);
}
void bubble_sort_iteration(int j) {
    if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
    }
}

/*
TODO:
Сделать 3 кнопки.
При нажатии на 1 кнопку - должен меняться цвет на случайный
При нажатии на 2 кнопку - массив перемешивается
При нажатии на 3 кнопку - массив заново заполняется
Для каждой кнопки нужна своя функция is_clicked.
is_clicked_1()
is_clicked_2()
is_clicked_3()
*/


int main() {
    srand(time(0));
    random_fill_array();

    initwindow(WIDTH, HEIGHT, "Анимация", 0, 0, true); // режим 2-страниц

    int pos = 0;        //Текущая позиция
    int color = RED;

    while (true) {
        setbkcolor(BLACK); // цвет фона
        clearviewport(); // закраска текущей страницы цветом фона

        // рисование изображения
        draw_rectangles(color);
        draw_button_1_();
        draw_button_2_();
        draw_button_3_();

        if (is_clicked_3_()) {
            std::cout << "Clicked button 3 ";
            random_fill_array();
            pos = 0;
        }

        if (is_clicked_2_()) {
            std::cout << "Clicked button 2 ";
            random_shuffle();
        }

        if (is_clicked_1_()) {
            std::cout << "Clicked button 1 ";
            //random_color();
            color = random_color();
        }

        if (!is_sorted()) {
            bubble_sort_iteration(pos);
            pos = (pos + 1) % (MAX_RECTANGLES - 1);
        }


        swapbuffers();
        delay(30);


        //Определяет, была ли нажата клавиша но не ожидает ее считывания
        if (kbhit()) {
            int key = getch();
            if (key == KEY_ESC) {
                break;
            }
        }
    }


    closegraph();


    return 0;
}



