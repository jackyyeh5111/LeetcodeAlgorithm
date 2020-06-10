class Solution {
public:
    constexpr static int dirs[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    double knightProbability(int N, int K, int r, int c)
    {
        double probs[K+1][N][N]={};
        probs[0][r][c]=1.0;
        for(int k=1; k<=K;++k){
            for(int i=0; i<N; ++i){
                for(int j=0; j<N; ++j){
                    for (int d=0; d<8; ++d){
                        if (!isValid(i+dirs[d][0],j+dirs[d][1],N)) {
                            continue;
                        }
                        probs[k][i][j] += (probs[k-1][i+dirs[d][0]][j+dirs[d][1]]/8.0);
                    }
                }
            }
        }

        double result = 0.0;
        for (int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                result += probs[K][i][j];
            }
        }
        return result;
    }

    bool isValid(int r, int c, int N){
        return (r>=0 && r<N && c>=0 && c<N);
    }
};
