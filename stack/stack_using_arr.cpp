#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int elm)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = elm;
        }
        else
            cout << "overflow" << endl;
    }

    void pop()
    {
        if (top >= 0)
            top--;
        else
            cout << "underflow" << endl;
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }
};

int main()
{
    // Stack *st = new Stack(5);
    Stack st(5);

    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    cout << st.peek() << endl;

    return 0;
}