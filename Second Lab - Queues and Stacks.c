//225. Implement Stack using Queue
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
    queue->capacity = 100; // Initial capacity
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
