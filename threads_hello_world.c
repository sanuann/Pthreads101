#include <stdio.h>
#include <pthread.h>

void task_one(int *);
void task_two(int *);
void do_wrap_up(int, int);

int r1 = 0, r2 = 0;

extern int
main(void)
{
  pthread_t thread1, thread2;

  pthread_create(&thread1,
          NULL,
          (void *) task_one,
          (void *) &r1);

  pthread_create(&thread2,
          NULL,
          (void *) task_two,
          (void *) &r2);

  pthread_join(thread1,  NULL);
  pthread_join(thread2,  NULL);

  do_wrap_up(r1, r2);
  return 0;
}

void task_one(int *pnum_times)
{
  int i, j, x;

  for (i = 0;    i  <  4;  i++) {
    printf("hello world one\n");
    for (j = 0; j < 10000; j++) x = x + i;
    (*pnum_times)++;
  }
}

void task_two(int *pnum_times)
{
  int i, j, x;

  for (i = 0;    i  <  4;  i++) {
    printf("hello world two \n");
    for (j = 0; j < 10000; j++) x = x + i;
    (*pnum_times)++;
  }
}

void do_wrap_up(int one_times, int another_times)
{
 int total;

 total = one_times + another_times;
 printf("wrap up: task one %d, task two %d, total %d\n",

 one_times, another_times, total);
}