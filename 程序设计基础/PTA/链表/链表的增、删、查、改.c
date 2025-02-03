#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ��
typedef struct Node {
    int data;  
    struct Node* next;
} Node;

// ���������µĽڵ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ͷ�巨��������ͷ�������µĽڵ�
void prepend(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// β�巨��������β�������µĽڵ�
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// ɾ��ɾ��ָ��ֵ�Ľڵ�
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    // ���ͷ�ڵ����Ŀ��ڵ�
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // ����Ҫɾ���Ľڵ�
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // ���δ�ҵ��ýڵ�
    if (temp == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    // ɾ���ڵ�
    prev->next = temp->next;
    free(temp);
}

// �飺���ҽڵ㣬���ؽڵ��ָ�루����ҵ��Ļ���
Node* findNode(Node* head, int data) {
    Node* temp = head;
    while (temp) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;  // û���ҵ�
}

// �ģ��޸�ָ���ڵ������
void modifyNode(Node* head, int oldData, int newData) {
    Node* target = findNode(head, oldData);
    if (target) {
        target->data = newData;
    }
    else {
        printf("Node with data %d not found.\n", oldData);
    }
}

// ��ӡ����
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    Node* head = NULL;

    // ʹ��ͷ�巨����ڵ�
    prepend(&head, 10);
    prepend(&head, 20);
    prepend(&head, 30);
    printf("List after using prepend (head insertion): ");
    printList(head);

    // ʹ��β�巨����ڵ�
    append(&head, 40);
    append(&head, 50);
    printf("List after using append (tail insertion): ");
    printList(head);

    // ɾ���ڵ�
    deleteNode(&head, 20);
    printf("After deleting 20: ");
    printList(head);

    // ���ҽڵ�
    Node* foundNode = findNode(head, 30);
    if (foundNode) {
        printf("Found node with data: %d\n", foundNode->data);
    }
    else {
        printf("Node with data 30 not found.\n");
    }

    // �޸Ľڵ�
    modifyNode(head, 30, 35);
    printf("After modifying 30 to 35: ");
    printList(head);

    return 0;
}