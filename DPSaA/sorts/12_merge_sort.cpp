#include <list>

std::list<int> merge(std::list<int>& left, std::list<int>& right, int &swapCount, int &comparisonCount) {
    std::list<int> result;
    while (!left.empty() && !right.empty()) {
        comparisonCount++;
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();
        } else {
            result.push_back(right.front());
            right.pop_front();
            swapCount++;
        }
    }

    while (!left.empty()) {
        result.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty()) {
        result.push_back(right.front());
        right.pop_front();
    }

    return result;
}

std::list<int> mergeSort(std::list<int>& lst, int &swapCount, int &comparisonCount) {
    if (lst.size() <= 1) {
        return lst;
    }

    std::list<int> left, right;
    std::list<int>::iterator middle = lst.begin();
    std::advance(middle, lst.size() / 2);
    left.splice(left.begin(), lst, lst.begin(), middle);
    right.splice(right.begin(), lst);

    left = mergeSort(left,swapCount,comparisonCount);
    right = mergeSort(right,swapCount,comparisonCount);
    return merge(left, right,swapCount,comparisonCount);
}