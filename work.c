#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Calculate(int a, int b, char c);
int Compare(char c);

int main() {
    int dataStack[100] = {0};//存放数字的栈
    int dataTop = -1;
    
    char operatorStack[100] = {'#'};//存放运算符的栈
    int operatorTop = 0;
    
    char str[100];
    scanf("%s", str);
    int length = (int)strlen(str);
    
    int i = 0, flag = 0, x = 0;
    
    while(i < length) {
        if (str[i] >= '0' && str[i] <= '9') {   //计算输入的是几位数
            x = x * 10 + (str[i++] - '0');
            flag = 1;
        } else {
            if (flag == 1) {
                dataStack[++dataTop] = x;
                x = 0;
                flag = 0;
            }
            if (Compare(operatorStack[operatorTop]) < Compare(str[i])) {
                operatorStack[++operatorTop] = str[i++];
            } else {
                int b = dataStack[dataTop--];
                int a = dataStack[dataTop--];
                dataStack[++dataTop] = Calculate(a, b, operatorStack[operatorTop--]);
                if (str[i] == '#' && operatorTop == 0) {
                    break;
                }
            }
        }
    }
    printf("%d\n", dataStack[dataTop]);
}

int Calculate(int a, int b, char c) {
    if (c == '-') {
        return a - b;
    } else if (c == '+') {
        return a + b;
    } else if (c == '*') {
        return a * b;
    } else if (c == '/') {
        return a / b;
    } else {
        return 0;
    }
}

int Compare(char c) {
    if (c == '#') {
        return 0;
    } else if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        printf("输入有误，请重新输入！\n");
        return -1;
    }
}
