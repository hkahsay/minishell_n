#include "../../headers/minishell.h"

t_ppline *get_ppline(t_ppline *ppline)
{
	static t_ppline *save;

	if (ppline)
		save = ppline;
	return (save);
}

void* my_malloc(size_t size)
{
	void*		addr;
	t_malloc*	node;
	t_ppline *ppline;

	ppline = get_ppline(NULL);
	addr = malloc(size);
	if (addr == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	node = malloc(sizeof(t_malloc));
	node->addr = addr;
	printf("PPLINE: %p\n", ppline);
	node->next = ppline->malloc_head;
	ppline->malloc_head = node;
	get_ppline(ppline);
	return (addr);
}

void my_free_all(t_malloc **head)
{
	t_malloc	*node;

	node = *head;
	while (*head != NULL)
	{
		node = *head;
		*head = (*head)->next;
		free(node->addr);
		free(node);
	}
}

// void	my_free_all()
// {
// 	ListNode* node;

// 	while (head != NULL)
// 	{
// 		node = head;
// 		head = head->next;
// 		free(node->address);
// 		free(node);
// 	}
// }

// ListNode* head = NULL;

// void*	my_malloc(size_t size)
// {
// 	ListNode* node;
// 	void* address;

// 	address = malloc(size);
// 	if (address == NULL) {
// 		printf("Memory allocation failed!\n");
// 		exit(1);
// 	}
// 	node = malloc(sizeof(ListNode));
// 	node->address = address;
// 	node->next = head;
// 	head = node;
// 	return (address);
// }

// int main() {
//     // Example usage:
//     int* arr = my_malloc(sizeof(int) * 10);
//     double* mat = my_malloc(sizeof(double) * 100);
//     char* str = my_malloc(sizeof(char) * 20);

//     // ... do some work with arr, mat, and str ...

//     my_free_all();
//     return 0;
// }


