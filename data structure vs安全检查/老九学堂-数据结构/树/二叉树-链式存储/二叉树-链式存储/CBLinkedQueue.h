#pragma once

#include "CBLQElement.h"

void CB_InitLinkedQueue(CBLQueue * linkedQueue);

void enCBLQueue(CBLQueue * linkedQueue, CBNode * data);

CBNode * deCBLQueue(CBLQueue * linkedQueue);


int CB_IsLinkedQueueEmpty(CBLQueue * linkedQueue);



