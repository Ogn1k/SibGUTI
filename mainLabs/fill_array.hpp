#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <list>

template <typename T> void swap(T &var1, T &var2)
{
    auto temp = var1;
    var1 = var2;
    var2 = temp;
}

int* FillRand(int arr[], int size)
{
    for(int i =0; i<size; i++)
    {
        arr[i] = rand() % 100 +1;
    }
    return arr;
}

std::list<int>& FillRandL(std::list<int> &arr, int size)
{
    arr.clear();
    for(int i =0; i<size; i++)
    {
        arr.push_back(rand() % 100 +1);
    }
    return arr;
}

int* FillDec(int arr[], int size)
{
    for(int i = 0; i<size; i++)
    {
        arr[i] = size - i; 
    }
    return arr;
}

std::list<int>& FillDecL(std::list<int> &arr, int size)
{
    arr.clear();
    for(int i = 0; i<size; i++)
    {
        arr.push_back(size - i);
    }
    return arr;
}

int* FillInc(int arr[], int size)
{
    for(int i = 0; i<size; i++)
    {
        arr[i] = i;
    }
    return arr;
}

std::list<int>& FillIncL(std::list<int> &arr, int size)
{
    arr.clear();
    for(int i = 0; i<size; i++)
    {
        arr.push_back(i);
    }
    return arr;
}

void printTableHeader(std::string type) {
    std::cout << std::left << std::setw(12) << "| array size"
              << std::setw(20) << "| Theoretical M + C"
              << std::setw(20) << "| M + C " << type
              << std::endl;

    std::cout << std::setw(14) << "|"
              << std::setw(12) << "| decreasing"
              << std::setw(8) << "| random"
              << std::setw(12) << "| increasing"
              << std::setw(12) << "| decreasing"
              << std::setw(8) << "| random"
              << std::setw(12) << "| increasing"
              << std::endl;

    std::cout << "|-------------+--------------+--------+------------+------------+--------+------------|" << std::endl;
}


void printRow(int arraySize, int theoreticalDec, int theoreticalRnd, int theoreticalInc,
              int bubbleDec, int bubbleRnd, int bubbleInc) {
    std::cout << std::left << std::setw(14) << "| " + std::to_string(arraySize)
              << std::setw(12) << "| " + std::to_string(theoreticalDec)
              << std::setw(8) << "| " + std::to_string(theoreticalRnd)
              << std::setw(12) << "| " + std::to_string(theoreticalInc)
              << std::setw(12) << "| " + std::to_string(bubbleDec)
              << std::setw(8) << "| " + std::to_string(bubbleRnd)
              << std::setw(12) << "| " + std::to_string(bubbleInc)
              << std::endl;
}