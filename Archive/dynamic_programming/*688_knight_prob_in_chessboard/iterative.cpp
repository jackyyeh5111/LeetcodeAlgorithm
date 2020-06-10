#include <stack>
class Solution {
public:
    // Time Limited Expired, since it needs to take O(8^K)
    // stack::top() would return an object reference by copy constructor.
    struct Record {
        int r;
        int c;
        int dir;
        int k;
        Record(){};
        Record(int r, int c, int dir, int k) : r(r), c(c), dir(dir), k(k) {};
    };

    double knightProbability(int N, int K, int r, int c)
    {
        stack<Record*> record_stack;
        record_stack.push(new Record(0,0,0,0));
        int total=0; int valid=0;
        while (!record_stack.empty()) {
            Record* record = record_stack.top();
            if(record->k==K) {
                record_stack.pop();
                if(record->c<N && record->c>=0 && record->r<N && record->r>=0){
                    valid++; total++;
                }
                else total++;
            }
            else{
                if (record->dir == 8) record_stack.pop();
                else if (!(record->c<N && record->c>=0 && record->r<N && record->r>=0)){
                    total += pow(8,(K-record->k));
                    record_stack.pop();
                }
                else {
                    record->dir++;
                    Record* new_record;
                    switch(record->dir){
                        case 1:
                            new_record = new Record(record->r-2, record->c+1, 0,record->k+1);
                            break;
                        case 2:
                            new_record = new Record(record->r-1, record->c+2, 0,record->k+1);
                            break;
                        case 3:
                            new_record = new Record(record->r+1, record->c+2, 0,record->k+1);
                            break;
                        case 4:
                            new_record = new Record(record->r+2, record->c+1, 0,record->k+1);
                            break;
                        case 5:
                            new_record = new Record(record->r+2, record->c-1, 0,record->k+1);
                            break;
                        case 6:
                            new_record = new Record(record->r+1, record->c-2, 0,record->k+1);
                            break;
                        case 7:
                            new_record = new Record(record->r-1, record->c-2, 0,record->k+1);
                            break;
                        case 8:
                            new_record = new Record(record->r-2, record->c-1, 0,record->k+1);
                            break;
                    }
                    record_stack.push(new_record);
                }
            }
        }
        cout<<valid<<" "<<total<<endl;
        return (double)valid/(double)total;
    }
