#pragma once
#include <xhash>

# define StackSize 10000

struct Stack 
{
	char para[StackSize];
	int length = -1;
};

char top(Stack* s)
{
	if (s->length == -1) return '\0';
	return s->para[s->length];
}

void pop(Stack *s)
{
	if ( s->length > -1 ) s->length--;
}

void insert(Stack* s, char c)
{
	s->length++;
	s->para[s->length] = c;
}

bool isValid(char* s) {
	int length = strlen(s);
	char target;
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->length = -1;
	for (int i = 0; i < length; i++)
	{
		target = *(s + i);
		if (target == '(' || target == '[' || target == '{')
		{
			if (target == '(') insert(stack, ')');
			else if (target == '[') insert(stack, ']');
			else insert(stack, '}');
		}
		else if (target == ')' || target == ']' || target == '}')
		{
			if (target != top(stack)) return false;
			else pop(stack);
		}
	}
	if (stack->length == -1) return true;
	else return false;
}
