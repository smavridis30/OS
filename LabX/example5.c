#include <stdio.h>

// Function to add three integers passed by reference
int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int x, y, z, result;

    // Input three integers
    printf("Enter three integers:\n");
    scanf("%d %d %d", &x, &y, &z);

    // Call the add function with addresses of the variables
    result = add(&x, &y, &z);

    // Print the result
    printf("The sum of %d, %d, and %d is: %d\n", x, y, z, result);

    return 0;
}
