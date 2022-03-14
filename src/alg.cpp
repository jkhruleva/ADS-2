// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
double pown(double value, uint16_t n) {
    uint64_t i;
    double x = 1;
    for (i = 1; i <= n; i++)
        x *= value;
    return x;
}
uint64_t fact(uint16_t n) {
    if (n == 0)
        return 1;
    return fact(n-1)*n;
}
double calcItem(double x, uint16_t n) {
    return pown(x, n)/fact(n);
}
double expn(double x, uint16_t count) {
    uint16_t i;
    double w;
    for (i = 0; i <= count; i++) {
        w += calcItem(x, i);
    }
    return w;
}

double sinn(double x, uint16_t count) {
    uint16_t i;
    double w = 0;
    for (i = 1; i <= count; i++) {
        w += pown(-1, i-1)*calcItem(x, 2*i-1);
  }
    return w;
}

double cosn(double x, uint16_t count) {
    uint16_t i;
    double w = 0;
    for (i = 1; i <= count; i++) {
        w += pown(-1, i-1)*calcItem(x, 2*i-2);
    }
    return w;
}
