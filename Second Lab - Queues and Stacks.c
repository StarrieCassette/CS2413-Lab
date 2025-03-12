//225. Implement Stack using Queue
typedef struct {
    int *q1, *q2;
    int front1, rear1, size1;
    int front2, rear2, size2;
    int capacity;

} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->capacity = 100;
    stack->q1 = (int*)malloc(stack->capacity * sizeof(int));
    stack->q2 = (int*)malloc(stack->capacity * sizeof(int));
    stack->front1 = stack->rear1 = stack->size1 = 0;
    stack->front2 = stack->rear2 = stack->size2 = 0;
    return stack; 
}

void myStackPush(MyStack* obj, int x) {
    if (obj->size1 == obj->capacity) return;
    obj->q2[obj->rear2++] = x;
    obj->size2++;
    while (obj->size1 > 0) {
        obj->q2[obj->rear2++] = obj->q1[obj->front1++];
        obj->size1--;
        obj->size2++;
    }
    int *temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    obj->front1 = 0;
    obj->rear1 = obj->size2;
    obj->front2 = obj->rear2 = obj->size2 = 0;
    obj->size1 = obj->rear1;
}

int myStackPop(MyStack* obj) {
    if (obj->size1 == 0) return -1;
    int val = obj->q1[obj->front1++];
    obj->size1--;
    return val;
}

int myStackTop(MyStack* obj) {
    if (obj->size1 == 0) return -1;
    return obj->q1[obj->front1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size1 == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}


//232. Implement Queue using Stack
typedef struct {
    int *input;
    int *output;
    int inputTop;
    int outputTop;
    int capacity;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->capacity = 100; 
    queue->input = (int*)malloc(queue->capacity * sizeof(int));
    queue->output = (int*)malloc(queue->capacity * sizeof(int));
    queue->inputTop = -1;
    queue->outputTop = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x);
int myQueuePeek(MyQueue* obj);
int myQueuePop(MyQueue* obj);
bool myQueueEmpty(MyQueue* obj);
void myQueueFree(MyQueue* obj);

void myQueuePush(MyQueue* obj, int x) {
    if (obj->inputTop + 1 >= obj->capacity) {
        return;
    }
    obj->input[++obj->inputTop] = x;
}

int myQueuePop(MyQueue* obj) {
    myQueuePeek(obj);
    return obj->output[obj->outputTop--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->outputTop == -1) {
        while (obj->inputTop != -1) {
            obj->output[++obj->outputTop] = obj->input[obj->inputTop--];
        }
    }
    return obj->output[obj->outputTop];  
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->inputTop == -1 && obj->outputTop == -1;

}

void myQueueFree(MyQueue* obj) {
    free(obj->input);
    free(obj->output);
    free(obj);
}
