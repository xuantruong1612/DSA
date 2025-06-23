#include <stdio.h>

typedef struct {
    char ten[10];
    double gpa;
} SV;

struct node {
    SV data;
    struct node *next;
};
