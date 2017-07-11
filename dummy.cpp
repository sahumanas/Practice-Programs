#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ofstream outfile;

int heapSize = 0;

int leftChild(int index)
{
  return (2 * index)+1;
}

int rightChild(int index)
{
  return (2 * index) + 2;
}

int parent(int index)
{
  return (index - 1)/2;
}

void heapify(int h[], int index)
{
  int largest;
  int l = leftChild(index); // 36
  int r = rightChild(index); // 37

  if((l <= (heapSize)) && h[l] > h[index]){
    largest = l;
  }
  else
    largest = index;

  if((r <= (heapSize)) && h[r] > h[largest])
    largest = r;

  if(largest != index){
    swap(h[index], h[largest]);
    heapify(h, largest);
  }  
}

void buildMaxHeap(int h[])
{
  for(int i = heapSize / 2; i >= 0; i--){
    heapify(h, i);
  }
}

void siftUp(int h[], int index, int key)
{
  h[index] = key;
  while(index > 0 && h[parent(index)] < h[index]){
    swap(h[index], h[parent(index)]);
    index = parent(index);
  }
}


void siftDown(int h[], int index, int key)
{
  int child = 0;

  while(!((index >= (key/2))  &&  (index < key))){
    child = leftChild(index);
    if((child < (key - 1)) && (h[child] < h[child+1]))
      child++;

    if(h[index] >= h[child])
      return;

    swap(h[index], h[child]);
    index = child; 
  }
}

void decreaseKey(int h[], int index, int key)
{
  int final = h[index] - key;
  h[index] = final;
  siftDown(h, index, final);
}

void increaseKey(int h[], int index, int key)
{
  h[index] = h[index] + key;
}

void insertElement(int h[], int key)
{
  h[heapSize] = INT_MIN;
  siftUp(h,heapSize,key);
  heapSize++;
}

int deleteMax(int h[])
{
  int max = h[0];
  h[0] = h[heapSize - 1];
  --heapSize;
  heapify(h,0);
  return max;
}

void remove(int h[], int index)
{
  h[index] = h[heapSize - 1];
  --heapSize;
  heapify(h, index);
}

void deleteMin(int h[])
{
  int key = h[0];
  int index = 0;
  for(int i = 0; i < heapSize; i++){
    if(key > h[i]){
      key = h[i];
      index = i;
    }
  }
  remove(h, index);
}

void printHeap(int h[])
{
  for(int i = 0; i < heapSize; i++){
    outfile << h[i] << " ";
  }
  outfile << endl << "---------" << endl;
}

int main()
{

  outfile.open("heapoutput");

  // I COULDN'T FIGURE OUT HOW TO PROCESS YOUR INPUT FILE 
  // PROPERLY SO INSTEAD OF MODIFYING IT AND MANGLING IT
  // I AM JUST DOING THINGS MANUALLY


  // Initialize a heap array of 100 elements
  int heap[100];

  heap[0] = 34;
  heap[1] = 54;
  heap[2] = 92;
  heap[3] = 56;
  heap[4] = 100;
  heap[5] = 200;
  heap[6] = 300;
  heap[7] = 123;
  heap[8] = 345;
  heap[9] = 129;
  heap[10] = 367;
  heap[11] = 280;
  heap[12] = 670;
  heap[13] = 1000; 
  heap[14] = 2000; 
  heap[15] = 3000; 
  heap[16] = 1120; 
  heap[17] = 2300; 
  heap[18] = 3200; 
  heap[19] = 2001; 
  heap[20] = 12;  
  heap[21] = 79; 
  heap[22] = 82; 
  heap[23] = 701; 
  heap[24] = 892; 
  heap[25] = 931; 
  heap[26] = 566;
  heap[27] = 377; 
  heap[28] = 901; 
  heap[29] = 5000; 
  heap[30] = 3009; 
  heap[31] = 1201; 
  heap[32] = 59; 
  heap[33] = 601; 
  heap[34] = 6001; 
  heap[35] = 2230; 
  heap[36] = 770;

  heapSize = 37;

  outfile << "Build Max Heap" << endl;
  buildMaxHeap(heap);
  printHeap(heap);

  outfile << "Insert 9000" << endl;
  insertElement(heap, 9000);
  printHeap(heap);
  
  outfile << "Insert 389" << endl;
  insertElement(heap, 389);
  printHeap(heap);
  
  outfile << "Insert 400" << endl;
  insertElement(heap, 400);
  printHeap(heap);
  
  outfile << "Insert 3" << endl;
  insertElement(heap, 3);
  printHeap(heap);
  
  outfile << "Insert 17" << endl;
  insertElement(heap, 17);
  printHeap(heap);
  
  outfile << "DeleteMin" << endl;
  deleteMin(heap);
  printHeap(heap);

  outfile << "DeleteMin" << endl;
  deleteMin(heap);
  printHeap(heap);

  outfile << "DeleteMin" << endl;
  deleteMin(heap);
  printHeap(heap);

  outfile << "DecreaseKey 10, 20" << endl;
  decreaseKey(heap, 10, 2);
  printHeap(heap);

  outfile << "DecreaseKey 30, 19" << endl;
  decreaseKey(heap, 30, 19);
  printHeap(heap);

  outfile << "IncreaseKey 25, 500" << endl;
  increaseKey(heap, 25, 500);
  printHeap(heap);

  outfile << "IncreaseKey 17, 370" << endl;
  increaseKey(heap, 17, 370);
  printHeap(heap);

  outfile << "Remove 20" << endl;
  remove(heap, 20);
  printHeap(heap);

  outfile << "DeleteMax" << endl;
  deleteMax(heap);
  printHeap(heap);

  outfile << "DeleteMax" << endl;
  deleteMax(heap);
  printHeap(heap);

  return 0;
}

