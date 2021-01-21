#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 50
#define OPERAND 10
#define OPERATOR 20

typedef struct prexp
{
  int top;
  int stack[MAX];
} stck;

void init(stck *);
void push(stck *, int);
int pop(stck *);
void eval(stck *, char, int, int);
int gettype(char);
void main()
{
  char pre[MAX];
  int num1, num2, item, l, i, pr;
  stck stk;

  fflush(stdin);

  init(&stk);
  printf(" ENTER THE PREFIX EXPRESSION ");
  gets(pre);
  l = strlen(pre);
  printf("EVALUATION:");

  for (i = l - 1; i >= 0; i--)
  {
    if (pre[i] == ' ' || pre[i] == '\0')
      continue;
    switch (gettype(pre[i]))
    {
    case OPERAND:
      item = pre[i] - '0';
      push(&stk, item);
      break;
    case OPERATOR:
      num1 = pop(&stk);
      num2 = pop(&stk);
      eval(&stk, pre[i], num1, num2);
    }
  }
  printf("%d", stk.stack[0]);
  getch();
}

void init(stck *st)
{
  st->top = -1;
}

void push(stck *st, int num)
{
  st->top++;
  st->stack[st->top] = num;
}

int pop(stck *st)
{
  int num;
  num = st->stack[st->top];
  st->top--;
  return num;
}

void eval(stck *st, char op, int num1, int num2)
{
  int res;
  switch (op)
  {
  case '+':
    res = num1 + num2;
    break;
  case '-':
    res = num1 - num2;
    break;
  case '*':
    res = num1 * num2;
    break;
  case '/':
    res = num1 / num2;
    break;
  case '%':
    res = num1 % num2;
    break;
  case '$':
    res = pow(num1, num2);
    break;
  }
  push(st, res);
}

int gettype(char c)
{
  switch (c)
  {
  case '+':
  case '-':
  case '*':
  case '/':
  case '$':
  case '%':
    return OPERATOR;
  default:
    return OPERAND;
  }
}
