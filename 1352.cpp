/*
    [1,2,3,4,5]

    [120,120,60,20,5]

    <-----
    k=1
    return arr[n-k]
    -----
    --->
    [1,2,6,24,120]
    k=1 arr[n-1] /  arr[n-k-1]
    k=2 arr[n-1] / arr[n-3]

    case:
        integer overflow
        k># of array
        [0,1,2,3]
        [<0,0>,<1,1>,<2,1>,<6,1>], n=4
        k=4  return 0 arr[n-k]
        k=3 check n-k=1
    prev product [0,1,2,6]

    [1,2,3,4,5]
             120
        if arr[n-k]==0 return 0;
        else if n-k-1<0 || arr[n-k-1]==0 return arr.back();
        else arr.back()/arr[n-k-1]
    [1,2,3]
    [1,2,6]
    k=1 3 verified
    k=2 6 verified
    k=3 6 verfied

    [(1,-1),(0,1),(2,1)] // second one means the last 0 we've met before.
    [1,0,2]
    k=1 2 verifiied
    k=2 0 verifid n-k
    k=3 2 fail
    -----
    vector<pair<int,int>> table // first: contiguous product, second: the last 0's index
    -----
    int ckpt // last 0's index
    [1,2,0,3]
         ^
    k>=2
*/
class ProductOfNumbers {
public:

    vector<int> table;
    int cur=1, n=0;
    int ckpt=-1;
    ProductOfNumbers() {

    }

    // T:O(1)
    void add(int num) {
        cur*=num;
        table.push_back(cur);
        if (cur==0) cur=1;
        if (num==0) ckpt=n;
        n++;
    }

    // T:O(k) -> T:O(1) by previous product
    int getProduct(int k) {
        if (n-k<=ckpt) return 0;
        else if (n-k-1<0 || table[n-k-1]==0) return table.back();
        else return table.back()/table[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
