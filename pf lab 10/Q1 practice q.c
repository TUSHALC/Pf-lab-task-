#include <stdio.h>
struct Box {
    int weight; 
    int numNestedBoxes;
    struct Box* nestedBoxes;
};
int calculateTotalWeight(struct Box* box) {
    int totalWeight = 0;

    if (box != NULL) {
        totalWeight += box->weight;

        for (int i = 0; i < box->numNestedBoxes; i++) {
            totalWeight += calculateTotalWeight(&(box->nestedBoxes[i]));
        }
    }

    return totalWeight;
}

int main() {
    struct Box box1 = {5, 0, NULL};
    struct Box nestedBoxes2[] = {
        {3, 0, NULL},  
        {2, 0, NULL}  
    };
    struct Box box2 = {10, 2, nestedBoxes2};

    struct Box nestedBoxes3[] = {
        {1, 0, NULL}, 
        {4, 0, NULL},  
        {6, 0, NULL}  
    };
    struct Box box3 = {0, 3, nestedBoxes3};

    printf("Total weight of box1: %d\n", calculateTotalWeight(&box1));  
    printf("Total weight of box2: %d\n", calculateTotalWeight(&box2));  
    printf("Total weight of box3: %d\n", calculateTotalWeight(&box3)); 

    return 0;
}