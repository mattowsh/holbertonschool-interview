# <a> <img src="https://cdn-icons-png.flaticon.com/512/6747/6747010.png" alt="flaticon" width=5%></img></a> **Linked list cycle**

`Topic:` **Interview task practice**

`Type of files:` tasks and projects


## Challenge
Write a function in C that checks if a singly linked list has a cycle in it.

- Prototype: `int check_cycle(listint_t *list)`

- Return: `0` if there is no cycle, `1` if there is a cycle

## Requirements

Only these functions are allowed: `write`, `printf`, `putchar`, `puts`, `malloc`, `free`

### Example
```
carrie@ubuntu:~/$ cat 0-main.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;
    listint_t *current;
    listint_t *temp;
    int i;

    head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint(head);

    if (check_cycle(head) == 0)
        printf("Linked list has no cycle\n");
    else if (check_cycle(head) == 1)
        printf("Linked list has a cycle\n");

    current = head;
    for (i = 0; i < 4; i++)
        current = current->next;
    temp = current->next;
    current->next = head;

    if (check_cycle(head) == 0)
        printf("Linked list has no cycle\n");
    else if (check_cycle(head) == 1)
        printf("Linked list has a cycle\n");

    current = head;
    for (i = 0; i < 4; i++)
        current = current->next;
    current->next = temp;

    free_listint(head);

    return (0);
}
carrie@ubuntu:~/$
carrie@ubuntu:~/$ gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
carrie@ubuntu:~/$$ ./cycle 
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
carrie@ubuntu:~/$
```

<hr><br>
<div align="center">
    <img src="https://apply.holbertonschool.com/holberton-logo.png" alt="Holberton logo" width=15%></img>
</div>

<p align="center">Montevideo, Uruguay | 2023</p>