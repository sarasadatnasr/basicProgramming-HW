    delete left;
    delete right;
}

int main()
{   int size = 0;
    cin>>size;
    int A[size];
    for(int i=0 ; i<size ;i++){
        cin>>A[i];
    }
printMedian(A, size);
return 0;
}