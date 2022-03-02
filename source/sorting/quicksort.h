#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SWAP(type_, pos1, pos2) \
    register type_ t = pos1;\
    pos1 = pos2; \
    pos2 = t; \

int partition(int array[], int low, int high);

void quicksort(int array[], int low, int high);

