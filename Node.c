#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

class Node {
  public:
    int number;
  Node * last;
};

int main() {
    Node * ptrLast = NULL;
    Node * top = NULL;
    short action = -1;
    while (1) {
      printf("1. Затолкнуть В Стек\n");
      printf("2. Вытолкнуть Из Стека\n");
      printf("3. Вершина Стека\n");
      printf("4. Содержимое Стека\n");
      printf("0. Выход\n\n");
      printf("Ваш Выбор: ");
      cin >> action;
      if (action == 0) {
        system("CLS");
        break;
      }
      if (action == 1) {
        system("CLS");
        int numb = -1;
        printf("Введите Число: ");
        cin >> numb;
        Node * ptr = new Node;
        ptr -> number = numb;
        if (top == NULL) {
          ptr -> last = NULL;
          top = ptr;
          ptrLast = ptr;
          system("CLS");
          continue;
        }
        top = ptr;
        ptr -> last = ptrLast;
        ptrLast = ptr;
        system("CLS");
        continue;
      }
      if (action == 2) {
        system("CLS");
        Node * ptrDelete = NULL;
        if (top == NULL) {
          printf("\t!!! СТЕК ПУСТ !!!\n\n");
          system("PAUSE");
          system("CLS");
          continue;
        }
        ptrDelete = top;
        if (ptrDelete -> last == NULL) {
          top = NULL;
          delete ptrDelete;
          system("CLS");
          continue;
        }
        top = ptrDelete -> last;
        ptrLast = top;
        delete ptrDelete;
        continue;
      }
      if (action == 3) {
        system("CLS");
        if (top == NULL) {
          printf("\t!!! СТЕК ПУСТ !!!\n\n");
          system("PAUSE");
          system("CLS");
          continue;
        }
        printf("Вершина Стека: ");
        cout << top -> number << "\n\n";
        system("PAUSE");
        system("CLS");
        continue;
      }
      if (action == 4) {
        system("CLS");
        Node * ptr = NULL;
        if (top == NULL) {
          printf("\t!!! СТЕК ПУСТ !!!\n\n");
          system("PAUSE");
          system("CLS");
          continue;
        }
        printf("* * * * * СОДЕРЖИМОЕ СТЕКА * * * * *          \n\n ");
          ptr = top;
          while (1) {
            cout << ptr -> number << endl;
            if (ptr -> last == NULL) {
              system("PAUSE");
              system("CLS");
              break;
            }
            ptr = ptr -> last;
          }
        }
        if (action > 4) {
          system("CLS");
          printf("\t!!! НЕВЕРНЫЙ ВЫБОР. ПОВТОРИТЕ       ВВОД!!!\n\n ");
            system("PAUSE"); system("CLS");
            continue;
          }
        }
      }