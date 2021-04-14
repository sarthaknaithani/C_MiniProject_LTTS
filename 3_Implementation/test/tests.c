#include "unity.h"
#include <stdio.h>
#include "../inc/backend.h"
#include "../inc/frontend.h"

void setUp(void)
{
}
void tearDown(void)
{
}
void test_board(void)
{
PointList *snake =create_cell(0,0);
Board *board =create_board(snake,NULL,2,3);
TEST_ASSERT_EQUAL(2,board->xmax);
TEST_ASSERT_EQUAL(3,board->ymax);
TEST_ASSERT_EQUAL(0,board->snake->x);

}

void test_back(void)
{
    PointList* snake = create_cell(2, 2);
    snake->next = create_cell(2, 3);
    Board* board = create_board(snake, NULL, 2, 2);
    move_snake(board, DOWN);
    TEST_ASSERT_EQUAL(2,board->snake->x);
    TEST_ASSERT_EQUAL(2,board->snake->y);
}

void test_collision(void)
{
    PointList* snake = create_cell(2, 2);
    snake->next = create_cell(2, 3);
    snake->next->next = create_cell(3, 3);
    snake->next->next->next = create_cell(3, 2);
    Board* board = create_board(snake, NULL, 4, 4);
    TEST_ASSERT_EQUAL(FAILURE,move_snake(board, RIGHT));
}
void test_move_corner(void)
{

    PointList* snake = create_cell(0, 1);
    Board* board = create_board(snake, NULL, 2, 2);
    TEST_ASSERT_EQUAL(NULL,next_move(board, LEFT));
    TEST_ASSERT_EQUAL(NULL,next_move(board, DOWN));

}
void test_move_left(void)
{

    PointList* snake = create_cell(1, 2);
    Board* board = create_board(snake, NULL, 4, 4);
    PointList *moved =next_move(board,LEFT);
    TEST_ASSERT_EQUAL(0,moved->x);
    TEST_ASSERT_EQUAL(2,moved->y);

}
void test_move_up(void)
{

    PointList* snake = create_cell(2, 2);
    Board* board = create_board(snake, NULL, 4, 4);
    PointList *moved =next_move(board,UP);
    TEST_ASSERT_EQUAL(2,moved->x);
    TEST_ASSERT_EQUAL(1,moved->y);
}
void test_add_new_food(void)
{
PointList* snake = create_cell(4, 2);
    snake->next = create_cell(4,3);
    PointList* foods = create_cell(3, 3);
    Board* board = create_board(snake, foods, 20, 10);
    add_new_food(board);
    TEST_ASSERT_EQUAL(NULL,board->foods->next->next);
}
void test_create_random_cell(void)
{
   PointList* cell1 = create_random_cell(20, 10);
    PointList* cell2 = create_random_cell(20, 10);
    TEST_ASSERT(!(cell1->x == cell2->x && cell1->y == cell2->y));
    TEST_ASSERT(cell1->x < 20);
    TEST_ASSERT(cell2->x < 20);
    TEST_ASSERT(cell1->y < 10);
    TEST_ASSERT(cell2->y < 10);
}
int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_board);
RUN_TEST(test_back);
RUN_TEST(test_collision);
RUN_TEST(test_move_corner);
RUN_TEST(test_move_left);
RUN_TEST(test_move_up);
RUN_TEST(test_add_new_food);
RUN_TEST(test_create_random_cell);
return UNITY_END();
}



