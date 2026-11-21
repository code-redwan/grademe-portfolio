#include <stddef.h>

typedef struct ListNode
{
	void          *data;
	struct ListNode *next;
} ListNode;

int	list_node_count(ListNode *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}



