//225. Implement Stack using Queue
typedef struct {
    int *queue;
    int front, rear, size, capacity;

} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->capacity = 100;
    stack->queue = (int*)malloc(stack->capacity * sizeof(int));
    stack->front = 0;
    stack->rear = -1;
    stack->size = 0;
    return stack; 
}

void myStackPush(MyStack* obj, int x) {
    if (obj->size == obj->capacity) return;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->queue[obj->rear] = x;
    obj->size++;
    for (int i = 0; i < obj->size - 1; i++) {
        obj->rear = (obj->rear + 1) % obj->capacity;
        obj->queue[obj->rear] = obj->queue[obj->front];
        obj->front = (obj->front + 1) % obj->capacity;
    }
}

int myStackPop(MyStack* obj) {
    if (obj->size == 0) return -1;
    int val = obj->queue[obj->front];
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return val;
}

int myStackTop(MyStack* obj) {
    if (obj->size == 0) return -1;
    return obj->queue[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->queue);
    free(obj);
}

//232. Implement Queue using Stack
