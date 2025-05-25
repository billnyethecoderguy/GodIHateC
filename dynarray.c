//im gonna mess this up so bad but here goes nothing lmao
#include <stdio.h>
#include <stdlib.h>

struct dynArrStruct {
    int* memlocation;
    int elemcount;
};

struct dynArrStruct initDynArr(int* firstElem) {
    struct dynArrStruct dynArr;
    dynArr.memlocation = malloc(1 * sizeof(int));
    dynArr.elemcount = 1;
    *dynArr.memlocation = *firstElem;
    return dynArr;
}

void addElem(struct dynArrStruct* dynArray, int newElem) {
    dynArray->memlocation = realloc(dynArray->memlocation, (dynArray->elemcount + 1) * sizeof(int));
    dynArray->memlocation[dynArray->elemcount] = newElem;
    dynArray->elemcount++;
}

void remElem(struct dynArrStruct* dynArray, int elemPos) {
    if (elemPos < 0 || elemPos >= dynArray->elemcount) return; // thanks for the help chatgpt :D

    for (int i = elemPos; i < dynArray->elemcount - 1; i++) {
        dynArray->memlocation[i] = dynArray->memlocation[i + 1];
    }

    dynArray->elemcount--;
    dynArray->memlocation = realloc(dynArray->memlocation, dynArray->elemcount * sizeof(int));
}

int main() {
    int x = 5;
    int y = 8;
    struct dynArrStruct dynArr = initDynArr(&x);
    printf("%d\n", dynArr.memlocation[0]);
    addElem(&dynArr, y);
    printf("%d", dynArr.memlocation[0]);
    printf("%d\n", dynArr.memlocation[1]);
    remElem(&dynArr, 0);
    printf("%d\n", dynArr.memlocation[0]);
    free(dynArr.memlocation);
    return 0;
}
