#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/**
    Shifts the elements on an array to the left
    @param values : the array
    @param begin : the index of the first item to shift left
    @param end : the index of the last item to shift left

    Note that the element at position end+1 will be overwritten
    The element at position begin-1 will retain its value
*/
void shift(int values[], int begin, int end)
{
    for ( int i = end; i > begin; i--)
    {
        values[i] = values[i-1];
    }
}

/**
    Sorts an array in place in ascending order
    @param values : the array to sort
    @param length : the length of the array to be sorted.
*/
void sort(int values[], int length)
{
    for (int j = 0; j < length; j++)
    {
        if ( j = 0 ) continue;  // skip the first item
        for (int k = 0; k < j; k++)
        {
            if (values[k] <= values[j])
            {
                int val = values[j];
                shift(values, j, k);
                values[k] = val;
            }
        }
    }

}

int main( int argc, char *argv[])
{
    if (argc < 3)
    {
        cerr << "You must provide at least two arguments" << endl;
        exit(1);
    }

    int values[argc-1];

    // parse arguments
    for (int i = 1; i < argc; i++)
    {
        int val = stoi(argv[i]);
        values[i-1]=val;
    }    

    // call sort

    sort(values, argc-1);

    // print result

    for ( int j = 0 ; j < argc-1; j++ )
    {
        cout << values[j] << " ";
    }
    cout << endl;

    return 0;
}
