#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    void swap(int *a, int *b);
    int search(int search);
    void Get(int index);
    void Set(int index, int element);
    void Max();
    void Min();
    int Sum();
    void Avg();
    void Reverse();
    void InsertSort(int x);
    int IsSorted();
    void Rearrange();
    Array *Merge(Array B);
    Array *Union(Array B);
    Array *Intersection(Array B);
    Array *Difference(Array B);
};

void Array::Display()
{
    cout << "Elements are : ";
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
};

void Array::Insert(int index, int x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i >= index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
};

int Array::Delete(int index)
{
    if (index >= 0 && index < length)
    {
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        return A[index];
    }
    return 0;
};

void Array::swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int Array::search(int search)
{
    for (int i = 0; i < length; i++)
    {
        if (search == A[i])
        {
            swap(&A[0], &A[i]);
            i--;
            return i;
        }
    }
    return -1;
}

void Array::Get(int index)
{
    if (index >= 0 && index < length)
    {
        cout << "Get elements is : " << A[index] << endl;
    }
}
void Array::Set(int index, int element)
{
    if (index >= 0 && index < length)
    {
        A[index] = element;
    }
}

void Array::Max()
{
    int max = A[0];

    for (int i = 0; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    cout << "Max element is " << max << endl;
}

void Array::Min()
{
    int min = A[0];

    for (int i = 0; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    cout << "Min element is " << min << endl;
}

int Array::Sum()
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }
    return sum;
}

void Array::Avg()
{
    int sum = 0;
    float avg = 0;

    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }
    avg = sum / length;
    cout << "Avg of all elements is " << avg << endl;
}

void Array::Reverse()
{
    int B[length - 1];
    int i, j;

    for (i = length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }

    for (i = 0; i < length; i++)
    {
        A[i] = B[i];
    }
}

void Array::InsertSort(int x)
{
    int i = length - 1;

    if (length == size)
        return;

    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

int Array::IsSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}

void Array::Rearrange()
{
    int i;
    int j;

    i = 0;
    j = length - 1;

    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        if (i < j)
            swap(&A[i], &A[j]);
    }
}

Array *Array::Merge(Array B)
{
    int i, j, k;
    i = j = k = 0;

    Array *C = new Array(length + B.length);

    while (i < length && j < B.length)
    {
        if (A[i] < B.A[j])
            C->A[k++] = A[i++];
        else
            C->A[k++] = B.A[j++];
    }

    for (; i < length; i++)
        C->A[k++] = A[i];
    for (; j < B.length; j++)
        C->A[k++] = B.A[j];

    C->length = length + B.length;

    return C;
}

Array *Array::Union(Array B)
{
    int i, j, k;
    i = j = k = 0;

    Array *C = new Array(length + B.length);

    while (i < length && j < B.length)
    {
        if (A[i] < B.A[j])
            C->A[k++] = A[i++];
        else if (A[i] > B.A[j])
            C->A[k++] = B.A[j++];
        else
        {
            C->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < length; i++)
        C->A[k++] = A[i];
    for (; j < B.length; j++)
        C->A[k++] = B.A[j];

    C->length = k;
    C->size = 10;

    return C;
}

Array *Array::Intersection(Array B)
{
    int i, j, k;
    i = j = k = 0;

    Array *C = new Array(length + B.length);

    while (i < length && j < B.length)
    {
        if (A[i] < B.A[j])
            i++;
        else if (A[i] > B.A[j])
            j++;
        else
        {
            C->A[k++] = A[i++];
            j++;
        }
    }

    C->length = k;
    C->size = 10;

    return C;
}

Array *Array::Difference(Array B)
{
    int i, j, k;
    i = j = k = 0;

    Array *C = new Array(length + B.length);

    while (i < length && j < B.length)
    {
        if (A[i] < B.A[j])
            C->A[k++] = A[i++];
        else if (A[i] > B.A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < length; i++)
        C->A[k++] = A[i];

    C->length = k;
    C->size = 10;

    return C;
}

int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;

    cout << "Enter the size of array : ";
    cin >> sz;

    arr1 = new Array(sz);
    do
    {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6.Exit\n";

        cout << "enter you choice ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter an element and index ";
            cin >> x >> index;
            arr1->Insert(index, x);
            break;
        case 2:
            cout << "Enter index ";
            cin >> index;
            x = arr1->Delete(index);
            cout << "Deleted Element is" << x;
            break;
        case 3:
            cout << "Enter element to search  ";
            cin >> x;
            index = arr1->search(x);
            cout << "Element index " << index;
            break;
        case 4:
            cout << "Sum is " << arr1->Sum();
            break;
        case 5:
            arr1->Display();
        }
    } while (ch < 6);

    return 0;
}