#include <iostream>
#include <string>
#include <algorithm>

#include "headers/graphics.h"

/*
������������ ����������� ����������.
������� ������� ������ ��������� �����, ������ ����� - ������ ��������������. ������ ������� �������������� - �������������.
� ����������� �� ����, ����� ����� � ������� - ������ ������������� ��� ��� ���� ������
*/

const int MAX_RECTANGLES = 15;              // ����� ���������������
const int x_start = 100;                    //����� ������� ���������������
const int y_start = 400;                    //������ ������� ���������������
const int RECT_WIDTH = 20;                  //������ ��������������
const int MAX_HEIGHT = 200;                 //������������ ������ ��������������

const int WIDTH = 800;                      //������ ����
const int HEIGHT = 700;                     //������ ����

int arr[MAX_RECTANGLES];                //������ ����� ���������������

const int BUTTON_1_LEFT = 22;                 //������� ����� 1 ����� �� �
const int BUTTON_1_TOP = HEIGHT - 100;       // ���� �� �
const int BUTTON_1_RIGHT = 144;             // �� �� ������ �� �
const int BUTTON_1_BOTTOM = HEIGHT - 22;     // ��� �� �


const int BUTTON_2_LEFT = 188;                  //������� ����� 2
const int BUTTON_2_TOP = HEIGHT - 100;         //
const int BUTTON_2_RIGHT = 310;               //
const int BUTTON_2_BOTTOM = HEIGHT - 22;     //

const int BUTTON_3_LEFT = 354;                  //������� ����� 3
const int BUTTON_3_TOP = HEIGHT - 100;         //
const int BUTTON_3_RIGHT = 476;               //
const int BUTTON_3_BOTTOM = HEIGHT - 22;     //



void draw_rectangles(int color);            //������ ��� ��������������
bool is_sorted();                           //���������, ������������ ������ ��� ���
void bubble_sort_iteration(int j);          //������ ���� �������� ���������� ��������� (���� arr[j] > arr[j + 1] - ������ �������)
void random_fill_array();                   //��������� ������ ���������� ������� �� 0 �� MAX_HEIGHT
void draw_button_1_();                         //��������� ������ 1(�������������� �������)
void draw_button_2_();                         //��������� ������ 2 (�������������� �������)
void draw_button_3_();                         //��������� ������ 3 (�������������� �������)
bool is_clicked_1_();                          //���������� true, ���� ������ 1 ������
bool is_clicked_2_();                          //���������� true, ���� ������ 2 ������
bool is_clicked_3_();                          //���������� true, ���� ������ 3 ������

void random_shuffle();                      //������������� �������
void random_color(int r, int g, int b);                         //������� ���������� ��������� ����

//��������� ������ 1..2..3 1(�������� �������)
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

// �������� ������� "������" 1..2..3
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


// �������� ������ ��������� ��������
void draw_rectangles(int color) {
    setfillstyle(SOLID_FILL, color);
    int x = x_start;
    for (int i = 0; i < MAX_RECTANGLES; ++i) {
        bar(x, y_start - arr[i], x + RECT_WIDTH, y_start);
        x += RECT_WIDTH;
    }
}

//������� ������ arr[i] ���������� ��������  
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
������� 3 ������.
��� ������� �� 1 ������ - ������ �������� ���� �� ���������
��� ������� �� 2 ������ - ������ ��������������
��� ������� �� 3 ������ - ������ ������ �����������
��� ������ ������ ����� ���� ������� is_clicked.
is_clicked_1()
is_clicked_2()
is_clicked_3()
*/


int main() {
    srand(time(0));
    random_fill_array();

    initwindow(WIDTH, HEIGHT, "��������", 0, 0, true); // ����� 2-�������

    int pos = 0;        //������� �������
    int color = RED;

    while (true) {
        setbkcolor(BLACK); // ���� ����
        clearviewport(); // �������� ������� �������� ������ ����

        // ��������� �����������
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


        //����������, ���� �� ������ ������� �� �� ������� �� ����������
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



