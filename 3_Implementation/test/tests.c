#include "unity.h"
#include <stdio.h>
#include "../inc/logic.h"
#include "../inc/displayscore.h"

void setUp(void)
{
}
void tearDown(void)
{
}
void test_game(void)
{
plist *snake =create_point(0,0);
Game *game =draw(snake,NULL,2,3);
TEST_ASSERT_EQUAL(2,game->xmax);
TEST_ASSERT_EQUAL(3,game->ymax);
TEST_ASSERT_EQUAL(0,game->snake->x);

}

void test_back(void)
{
    plist* snake = create_point(2, 2);
    snake->next = create_point(2, 3);
    Game* game = draw(snake, NULL, 2, 2);
    move_snake(game, DOWN);
    TEST_ASSERT_EQUAL(2,game->snake->x);
    TEST_ASSERT_EQUAL(2,game->snake->y);
}

void test_collision(void)
{
    plist* snake = create_point(2, 2);
    snake->next = create_point(2, 3);
    snake->next->next = create_point(3, 3);
    snake->next->next->next = create_point(3, 2);
    Game* game = draw(snake, NULL, 4, 4);
    TEST_ASSERT_EQUAL(FAILURE,move_snake(game, RIGHT));
}
void test_move_corner(void)
{

    plist* snake = create_point(0, 1);
    Game* game = draw(snake, NULL, 2, 2);
    TEST_ASSERT_EQUAL(NULL,turn_next(game, LEFT));
    TEST_ASSERT_EQUAL(NULL,turn_next(game, DOWN));

}
void test_move_left(void)
{

    plist* snake = create_point(1, 2);
    Game* game = draw(snake, NULL, 4, 4);
    plist *moved =turn_next(game,LEFT);
    TEST_ASSERT_EQUAL(0,moved->x);
    TEST_ASSERT_EQUAL(2,moved->y);

}
void test_move_up(void)
{

    plist* snake = create_point(2, 2);
    Game* game = draw(snake, NULL, 4, 4);
    plist *moved =turn_next(game,UP);
    TEST_ASSERT_EQUAL(2,moved->x);
    TEST_ASSERT_EQUAL(1,moved->y);
}
void test_add_new_fruit(void)
{
plist* snake = create_point(4, 2);
    snake->next = create_point(4,3);
    plist* fruits = create_point(3, 3);
    Game* game = draw(snake, fruits, 20, 10);
    add_new_fruit(game);
    TEST_ASSERT_EQUAL(NULL,game->fruits->next->next);
}
void test_create_random_point(void)
{
   plist* point1 = create_random_point(20, 10);
    plist* point2 = create_random_point(20, 10);
    TEST_ASSERT(!(point1->x == point2->x && point1->y == point2->y));
    TEST_ASSERT(point1->x < 20);
    TEST_ASSERT(point2->x < 20);
    TEST_ASSERT(point1->y < 10);
    TEST_ASSERT(point2->y < 10);
}
int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_game);
RUN_TEST(test_back);
RUN_TEST(test_collision);
RUN_TEST(test_move_corner);
RUN_TEST(test_move_left);
RUN_TEST(test_move_up);
RUN_TEST(test_add_new_fruit);
RUN_TEST(test_create_random_point);
return UNITY_END();
}



