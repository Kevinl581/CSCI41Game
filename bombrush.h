#include<ncurses.h>
class bomb;
class hostage;
class player;
const unsigned char bmb = 'B';
const unsigned char htge = 'H';
const unsigned char pyr = 'P';
int xdim, ydim; //world dimensions
const int MAX_SCORES = 10;

class Heap
{
    private:
    int size = 0;
    int items[MAX_SCORES];

    public:

    int getLeftChildIndex(int parentIndex) {return 2 * parentIndex + 1;}
    int getRightChildIndex(int parentIndex) {return 2 * parentIndex +2;}
    int getParentIndex(int childIndex) {return (childIndex - 1) / 2;}

    bool hasLeftChild(int index) {return getLeftChildIndex(index) < size;}
    bool hasRightChild(int index) {return getRightChildIndex(index) < size;}
    bool hasParent(int index) {return getParentIndex(index) >= 0;}

    int leftChild(int index) {return items[getLeftChildIndex(index)];}
    int rightChild(int index) {return items[getRightChildIndex(index)];}
    int parent(int index) {return items[getParentIndex(index)];}

    void swap(int indexOne, int indexTwo)
    {
        int temp = items[indexOne];
        items[indexOne] = items[indexTwo];
        items[indexTwo] = temp;
    }

    void highScoreList()
    {
    if (size == 0) return;
    else
        {
        cout<<"Your high scores!!!\n";
        while(size > 0)
            {
            int item = items[0];
            items[0] = items[size - 1];
            cout<<size<<". "<<item<<endl;
            size--;
            heapifyDown();
            }
        }
    }

    void add(int item)
    {
    if(size == MAX_SCORES) return;
    else{
        items[size] = item;
        size++;
        heapifyUp();
        }

    }

    void heapifyUp()
    {
    int index = size - 1;
    while (hasParent(index) && parent(index) > items[index])
        {
        swap(getParentIndex(index), index);
        index = getParentIndex(index);
        }
    }

    void heapifyDown()
    {
    int index = 0;
    while(hasLeftChild(index))
        {
        int smallerChildIndex = getLeftChildIndex(index);
        if(hasRightChild(index) && rightChild(index) < leftChild(index))
            {
             smallerChildIndex = getRightChildIndex(index);
            }
        }

    }
};
                                                                                                                  

