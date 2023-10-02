#include "datatypes.h"

#include "stdio.h"

void print_sl(const StringedList *sl)
{
    const StringedList *head = sl;

    while (head != NULL)
    {
        printf("%s", head->value);
        head = head->next;
    }
}