///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    堆
///
///    \author   deguangchow
///    \version  1.0
///    \2019/04/25

#pragma once
#ifndef HEAP_DEMO_H
#define HEAP_DEMO_H

class HeapDemo {
public:
    static int left(int i) {
        return (i + 1) * 2 - 1;
    }

    static int right(int i) {
        return (i + 1) * 2;
    }

    static int parent(int i) {
        if (0 == i) {
            return -1;
        } else {
            return (i - 1) / 2;
        }
    }

    //大根堆
    static void maxHeapify(int a[], int i, int heapLength) {
        int indexLeft   = left(i);
        int indexRight  = right(i);
        int indexMax    = -1;

        if (indexLeft < heapLength && a[i] < a[indexLeft]) {
            indexMax    = indexLeft;
        } else {
            indexMax    = i;
        }

        if (indexRight < heapLength && a[indexMax] < a[indexRight]) {
            indexMax    = indexRight;
        }

        if (i != indexMax) {
            int temp    = a[i];
            a[i]        = a[indexMax];
            a[indexMax] = temp;
            maxHeapify(a, indexMax, heapLength);
        }
    }

    //小根堆
    static void minHeapify(int a[], int i, int heapLength) {
        int indexLeft   = left(i);
        int indexRight  = right(i);
        int indexMin    = -1;
        if (indexLeft < heapLength && a[i] > a[indexLeft]) {
            indexMin    = indexLeft;
        } else {
            indexMin    = i;
        }

        if (indexRight < heapLength && a[indexMin] > a[indexRight]) {
            indexMin    = indexRight;
        }

        if (i != indexMin) {
            int temp    = a[i];
            a[i]        = a[indexMin];
            a[indexMin] = temp;
            minHeapify(a, indexMin, heapLength);
        }
    }

    //建大根堆
    static void buildMaxHeap(int a[], int heapLength) {
        int lengthParent = parent(heapLength - 1);

        for (int i = lengthParent; i >= 0; --i) {
            maxHeapify(a, i, heapLength);
        }
    }

    //建小根堆
    static void buildMinHeap(int a[], int heapLength) {
        int lengthParent = parent(heapLength - 1);

        for (int i = lengthParent; i >= 0; --i) {
            minHeapify(a, i, heapLength);
        }
    }
};

#endif  //HEAP_DEMO_H
