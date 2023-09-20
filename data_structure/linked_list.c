#include<stdio.h>
#include<stdlib.h>			/*general purpose standard library*/

struct Node {
	int value;
	struct Node *next;
};

void Travelse (struct Node *head) {
	struct Node *temp = head;
	printf("\nList element are: ");
	while (temp != NULL) {
		if(temp -> next != NULL) {
			printf("%d --> ", temp->value);
		}
		else {
			printf("%d", temp->value);
		}
		temp = temp->next;
	}
}

void InsertNodeAtBeginning (struct Node** head, int _value) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	new_node->value = _value;
	
	new_node->next = *head;
	
	*head = new_node;
}

void InsertNodeAtEnd (struct Node** head, int _value) {
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *head;
	
	new_node->value = _value;
	
	new_node->next = NULL;
	
	while (1) {
		if (*head == NULL) {
			*head = new_node;
			break;
		}
		
		while (last->next != NULL) {
			last = last->next;
		}
		
		last->next = new_node;
		break;
	}
}

void InsertAfter(struct Node* prev_node, int _value) {
	while (1) {
		if (prev_node == NULL) {
			printf("the given previous node cannot be NULL");
	  		break;
	  	}
		
		struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
		
		new_node->value = _value;
		new_node->next = prev_node->next;
		prev_node->next = new_node;
		break;
	}
}

int main() {
	struct Node *head = NULL;
	
	InsertNodeAtBeginning(&head, 3);
	
	InsertNodeAtEnd(&head, 5);
	
	InsertAfter(head, 4);
	
	Travelse(head);
	
	return 0;
}
