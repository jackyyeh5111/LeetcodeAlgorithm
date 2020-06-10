// Swap method
void perm(int start, int end, int** a)
{
    if (start==end){
        for(int i=0;i<end;++i) std::cout << a[i] << std::endl;
    }
    for (int i = 0; i < end; ++i){
        swap(start, i);
        perm(start+1, end, a);
        swap(i, start);
    }
}

// backtracking method
void perm(int start, int end, int** a)
{
    if (start==end){
        for(int i=0;i<end;++i) std::cout << a[i] << std::endl;
    }
    for (int i=0; i < end; ++i){
        if (!used[i]){
            used[i]=true;
            a[start]=i;
            perm(start+1, end, a);
            used[i]=false;
        }
    }
}
