#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std ;
struct MaxHeap
{
    vector<int> data;
    MaxHeap()
    {
        data.push_back(0);
    }

    MaxHeap(vector<int> input)
    {
        data.push_back(0);
        data.insert(data.end(), input.begin(), input.end());
        for(int i = data.size() / 2; i > 0; --i)
        {
            max_heapify(i);
        }
    }
    void insert(int value)
    {
        data.push_back(value);
        int current = data.size()-1;
        while(current != 1)
        {
            if(data[current] > data[current >> 1])
            {
                std::swap(data[current], data[current >> 1]);
                current >>= 1;
            }
            else break;
        }
    }
    void pop()
    {
        if(data.size() == 1) return;
        std::swap(data[1], data[data.size()-1]);
        data.pop_back();
        int current = 1;
        while(current < data.size())
        {
            int largest = current;
            if((current << 1) < data.size() && data[current << 1] > data[largest])
            {
                largest = current << 1;
            }
            if((current << 1) + 1 < data.size() && data[(current << 1) + 1] > data[largest])
            {
                largest = (current << 1) + 1;
            }
            if(largest != current)
            {
                std::swap(data[current], data[largest]);
                current = largest;
            }
            else break;
        }
    }
    int top()
    {
        return data[1];
    }
    bool empty()
    {
        return data.size() <= 1;
    }
private:
    void max_heapify(int index)
    {
        int largest = index;
        if((index << 1) < data.size() && data[largest] < data[index << 1])
        {
            largest = index << 1;
        }
        if((index << 1) + 1 < data.size() && data[largest] < data[(index << 1) + 1])
        {
            largest = (index << 1) + 1;
        }
        if(index != largest)
        {
            std::swap(data[index], data[largest]);
            max_heapify(largest);
        }
    }
};
int main()
{
    MaxHeap h;
    for(int i = 0; i <= 10; ++i)
    {
        h.insert(rand() % 10000000);
    }
    while(!h.empty())
    {
        int top = h.top(); h.pop();
        std::cout<<top<<'\n';

    }
    return 0;
}
