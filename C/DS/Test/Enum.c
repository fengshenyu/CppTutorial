#include <stdio.h>
typedef enum {
    Link,Thread
}PointerTag;
int main() {
    PointerTag pointerTag1;
    PointerTag pointerTag2;
    pointerTag1 = Link;
    pointerTag2 = Thread;
    if (pointerTag1 == Link) {
        printf("Hello world\n");
    }
    if (pointerTag2 == Thread) {
        printf("Hello world1\n");
    }
    if (pointerTag2 == Link) {
        printf("Hello world1\n");
    }
    return 0;
}