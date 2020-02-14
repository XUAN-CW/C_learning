#include "DataElement.h"

void InitLinkQueue(LinkQueue *linkQueue);

void OfferLinkQueue(LinkQueue *linkQueue, ElementType *offerElement);

void PollLinkQueue(LinkQueue *linkQueue, ElementType *receivePollElement);

void printfLinkQueue(LinkQueue *linkQueue);

void ClearLinkQueue(LinkQueue *linkQueue);

int IsLinkQueueEmpty(LinkQueue *linkQueue);