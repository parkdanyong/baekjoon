#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


/*
    Stack sequence is one that can be created using stack.
    Let's say we have the following sequence [2, 3, 5, 4, 1]
    We will prove that it is a stack sequence.

    The size is 5, so we will compare from 1 to 5.
    sequence to compare: [1, 2, 3, 4, 5]
    stack sequence: [2, 3, 5, 4, 1]

    stack is empty -> push(1) // stack: 1 (top) // output:
    1 (top) == 2: false -> push(2) // stack: 1 2 (top) // output:
    2 (top) == 2: true -> pop // stack: 1 (top) // output: 2
    1 (top) == 3: false -> push(3) // stack: 1 3 (top) // output: 2
    3 (top) == 3: true -> pop // stack: 1 (top) // output: 2 3
    1 (top) == 5: false -> push(4) // stack: 1 4 (top) // output: 2 3
    4 (top) == 5: false -> push(5) // stack: 1 4 5 (top) // output: 2 3

    Sequence to compare is empty, so pop() all // output: 2 3 5 4 1
    It is stack sequence!
    
    At this problem, the output is that.
    +
    +
    -
    +
    -
    +
    +
    -
    -
    -

*/

typedef struct Node {
    int data;
    struct Node* next;
} Node;




Node* create(data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode; // if malloc error occured then return NULL
}



int push(Node** top, int data) {
    Node* newNode = create(data);
    if (newNode == NULL) return -1; // malloc error

    newNode->next = *top;
    *top = newNode;
    return 0;
}


int pop(Node** top) {
    if (top == NULL) return -1; // if stack is empty then return -1

    int data = (*top)->data;

    Node* tmp = *top;
    *top = (*top)->next;
    free(tmp);

    return data;
}


void freeAll(Node* top) {
    Node* tmp;
    while (top != NULL) {
        tmp = top->next;
        free(top);
        top = tmp;
    }
}


void printBuffer(char* buffer, int size) {
    for (int i = 0; i < size; i++) printf("%c\n", buffer[i]);
}


int isStackSequence(Node** top, int* arr, int size) {
    char* buffer = (char*)malloc(size * 2); // save the process, each element has push pop instructions, so buf size is double
    if (buffer == NULL) return -1;
    int buf_index = 0; // index for buffer
    int arr_index = 0; // index for arr
    int flag = 1; // if the arr is not stack sequence then flas == 0


    int cur;
    for (int i = 0; i < size; i++) {
        if ((*top) != NULL && (*top)->data == arr[arr_index]) {
            cur = pop(top);
            buffer[buf_index++] = '-';
            arr_index++;
            i--; // maintain comparing number
        }
        else {
            if (push(top, i + 1) == -1) return -1;
            buffer[buf_index++] = '+'; // append and increase index
        }
    }


    
    while (*top != NULL) { // pop all remaining elements.
        cur = pop(top);
        if (cur != arr[arr_index++]) { // if 
            flag = 0;
            break;
        }
        buffer[buf_index++] = '-';
    }


    // if last element is different then it is not stack sequence
    if (flag == 1) printBuffer(buffer, size*2);
    else printf("NO\n");

    return 0;
}



int main() {
    int arrSize = 0;
    scanf("%d", &arrSize);
    int* arr = (int*)malloc(sizeof(int) * arrSize);
    if (arr == NULL) return -1;


    Node* top = NULL;
    int data;
    for (int i = 0; i < arrSize; i++) {
        scanf("%d", &data);
        arr[i] = data;
    }


    if (isStackSequence(&top, arr, arrSize) == -1) {
        printf("malloc error\n");
        freeAll(top);
        return 1;
    }


    freeAll(top);

    return 0;
}