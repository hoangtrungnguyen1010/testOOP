#pragma once
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include<iostream>
#include"Book.h"
#include<QVector>
#include"QDebug"
#include<QString>

int partitionID(QVector<Book>& a, int first, int last)
{
    QString pivot = a[(first + last) / 2].getID();
    int i = first;
    int j = last;
    Book tmp;
    while (i <= j)
    {
        while (QString::compare(a[i].getID(), pivot)<0)
            i++;
        while (QString::compare(a[j].getID(), pivot)>0)
            j--;
        if (i <= j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    return i;
}

void quickSortID( QVector<Book>& a, int first, int last)
{

    int index = partitionID(a, first, last);
    if (first < index - 1)
        quickSortID(a, first, index - 1);
    if (index < last)
        quickSortID(a, index, last);
}

int partitionName(QVector<Book>& a, int first, int last)
{
    QString pivot = a[(first + last) / 2].getName();
    int i = first;
    int j = last;
    Book tmp;
    while (i <= j)
    {
        while (QString::compare(a[i].getName(), pivot)<0)
            i++;
        while (QString::compare(a[j].getName(), pivot)>0)
            j--;
        if (i <= j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    return i;
}

void quickSortName( QVector<Book>& a, int first, int last)
{

    int index = partitionName(a, first, last);
    if (first < index - 1)
        quickSortName(a, first, index - 1);
    if (index < last)
        quickSortName(a, index, last);
}
#endif // QUICKSORT_H
