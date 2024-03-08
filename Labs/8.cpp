#include <stdio.h>
#include <stdbool.h>

typedef enum {
    INT,
    FLOAT,
    ERROR
} DataType;

DataType checkBinaryOperation(DataType left, char op, DataType right) {
    switch (op) {
        case '+':
        case '-':
        case '*':
        case '/':
            if (left == INT && right == INT) {
                return INT;
            } else if ((left == INT && right == FLOAT) || (left == FLOAT && right == INT) ||
                       (left == FLOAT && right == FLOAT)) {
                return FLOAT;
            } else {
                return ERROR;
            }
        default:
            return ERROR;
    }
}

int main() {
    char op;
    DataType leftType, rightType, resultType;

    printf("Enter a binary arithmetic expression (e.g., 2.5 + 3):\n");
    scanf("%lf %c lf", &leftType, &op, &rightType);

    resultType = checkBinaryOperation(leftType, op, rightType);

    if (resultType == ERROR) {
        printf("Error: Incompatible types in the expression.\n");
    } else {
        printf("Result type of the expression: %s\n", resultType == INT ? "int" : "float");
    }

    return 0;
}
