#include <iostream>
#include <vector>
#include <stdexcept>
#include "myQueue.cpp"
#include "myStack.cpp"

void FillInc_stack(Stack<int> &stack, int size)
{
    for(int i=0;i<size;i++)
        stack.push(i);
} 

void FillDec_stack(Stack<int> &stack, int size)
{
    for(int i=size; i>0;i--)
        stack.push(i);
}

void FillRand_stack(Stack<int> &stack, int size)
{
    for(int i =0; i<size; i++)
        stack.push(rand() % 100 +1);
}

void FillInc_queue(Queue<int> &queue, int size)
{
    for(int i=0;i<size;i++)
        queue.enqueue(i);
} 

void FillDec_queue(Queue<int> &queue, int size)
{
    for(int i=size; i>0;i--)
        queue.enqueue(i);
}

void FillRand_queue(Queue<int> &queue, int size)
{
    for(int i =0; i<size; i++)
        queue.enqueue(rand() % 100 +1);
}

template <typename T>
void Print_list(List<T> &list)
{
    for(T obj : list)
        std::cout << obj << " ";
}

template <typename T>
double ElemSumm_list(List<T> list)
{
    double summ = 0;
    for(T obj : list)
        summ += obj;
    return summ;
}

template <typename T>
int SeriesSumm_list(List<T> list)
{
    int maxSumm = 0, summ = 0;
    for(int i=0; i<list.size()-1; i++)
    {
        if(list[i] == list[i+1])
            summ++;
        if(summ>maxSumm)
            maxSumm = summ;
    }
    return summ+1;
}

int main() 
{
    setlocale(LC_ALL, "");
    List<int> list;
    for(int i = 0; i<10; i++) list.push_back(1);

    list.print();
    //std::cout << SeriesSumm_list(list);

    return 0;
}