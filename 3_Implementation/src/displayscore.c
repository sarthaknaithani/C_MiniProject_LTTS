#include <ncurses.h>
#include<stdio.h>
#include "../inc/logic.h"
#include "../inc/displayscore.h"

void display_points(plist* snake, const chtype symbol) {
  while(snake) {
    mvaddch(snake->y, snake->x, symbol);
    snake = snake->next;
  }
}

enum command get_turn_next(enum command prev) {
  int ch = getch();
  switch (ch) {
    case KEY_LEFT:
      if (prev != RIGHT) return LEFT;
    case KEY_RIGHT:
      if (prev != LEFT) return RIGHT;
    case KEY_DOWN:
      if (prev != UP) return DOWN;
    case KEY_UP:
      if (prev != DOWN) return UP;
    default:
      return prev;
  }
}


