#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Element.h"



void InitLinkedStack(LinkedStack * linkedStack);

int PushLinkedStack(LinkedStack * linkedStack, ElementType pushElement);

int PopLinkedStack(LinkedStack * linkedStack, ElementType * popElement);

void printLinkedStack(LinkedStack * linkedStack);

void ClearLinkedStack(LinkedStack * linkedStack);

void DestroyLinkedStack(LinkedStack * linkedStack);






#endif // LINKEDSTACK_H_INCLUDED
