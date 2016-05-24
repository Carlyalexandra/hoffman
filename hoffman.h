//
// Created by CARLY  on 5/22/16.
//

#ifndef HOFFMAN_HOFFMAN_H
#define HOFFMAN_HOFFMAN_H



extern int WIDTH,HEIGHT,COLOR;

// A Huffman tree node
struct MinHeapNode
{
    char data; // One of the input characters
    unsigned freq; // Frequency of the character
    struct MinHeapNode *left, *right; // Left and right child of this node
};

// A Min Heap: Collection of min heap (or Hufmman tree) nodes
struct MinHeap
{
    unsigned size; // Current size of min heap
    unsigned capacity; // capacity of min heap
    struct MinHeapNode **array; // Attay of minheap node pointers
};


struct MinHeapNode* newNode(char data, unsigned freq);
struct MinHeap* createMinHeap(unsigned capacity);
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);
void minHeapify(struct MinHeap* minHeap, int idx);
int isSizeOne(struct MinHeap* minHeap);
struct MinHeapNode* extractMin(struct MinHeap* minHeap);
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode);
void buildMinHeap(struct MinHeap* minHeap);
void printArr(int arr[], int n);
int isLeaf(struct MinHeapNode* root);
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size);
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size);
void printCodes(struct MinHeapNode* root, int arr[], int top);
void HuffmanCodes(char data[], int freq[], int size);


///biggrams includes
int mainPopulate();
void print_bigrams(char bigrams[WIDTH*HEIGHT-1][2]);
void populate_bigrams(char bigrams[WIDTH*HEIGHT-1][2]);

int freq_of_bigram(char a, char b, char bigrams[WIDTH*HEIGHT-1][2]);
int populate_bigrams_freq_table(int bigram_frequency_table[92][92], char bigrams[WIDTH*HEIGHT-1][2]);
void find_max (int bigram_frequency_table[92][92]);


//picture info includes
int getLineInfo();

#endif //HOFFMAN_HOFFMAN_H
