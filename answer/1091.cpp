/***** Second Visit *****/
/*
    shortest path -> BFS
    T:O(V+E)/S:O(V+E)
    V: n, E: 8n
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int m=grid.size(), n=grid[0].size(), ans=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while (!q.empty()) {
            int k=q.size();
            for (int i=0; i<k; ++i) {
                auto t=q.front(); q.pop();
                int x=t.first, y=t.second;
                if (x<0||x>=m||y<0||y>=n||grid[x][y]==1) continue;
                else if (x==m-1&&y==n-1) return ans;
                grid[x][y]=1;
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x,y+1});
                q.push({x,y-1});
                q.push({x+1,y+1});
                q.push({x+1,y-1});
                q.push({x-1,y+1});
                q.push({x-1,y-1});
            }
            ans++;
        }
        return -1;
    }
};

/***** First Visit *****/
/*
    Find the shortest path from left-top to right-bottom.
    SHORTEST PATH -> BFS!
    T:O(n)/S:O(n)
    -----
    A* could have better performance in practice.
    T:O(nlogn)/S:O(n)
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        if (grid[0][0]==1) return -1;
        int m=grid.size(), n=grid[0].size();
        int ans=INT_MAX, length=1;
        queue<vector<int>> q;
        q.push({0,0});
        while (!q.empty()) {
            int k=q.size();
            for (int i=0; i<k; ++i) {
                auto t=q.front(); q.pop();
                int x=t[0],y=t[1];
                if (x<0||x>=m||y<0||y>=n||grid[x][y]==1) continue;
                else if (x==m-1&&y==n-1) {return length;}
                grid[x][y]=1;
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x,y+1});
                q.push({x,y-1});
                q.push({x+1,y+1});
                q.push({x+1,y-1});
                q.push({x-1,y+1});
                q.push({x-1,y-1});
            }
            length++;
        }
        return -1;
    }
};

/* [JAVA]
class Solution {

    // Candidate represents a possible option for travelling to the cell
    // at (row, col).
    class Candidate {

        public int row;
        public int col;
        public int distanceSoFar;
        public int totalEstimate;

        public Candidate(int row, int col, int distanceSoFar, int totalEstimate) {
            this.row = row;
            this.col = col;
            this.distanceSoFar = distanceSoFar;
            this.totalEstimate = totalEstimate;
        }
    }


    private static final int[][] directions =
        new int[][]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};


    public int shortestPathBinaryMatrix(int[][] grid) {

        // Firstly, we need to check that the start and target cells are open.
        if (grid[0][0] != 0 || grid[grid.length - 1][grid[0].length - 1] != 0) {
            return -1;
        }

        // Set up the A* search.
        Queue<Candidate> pq = new PriorityQueue<>((a,b) -> a.totalEstimate - b.totalEstimate);
        pq.add(new Candidate(0, 0, 1, estimate(0, 0, grid)));

        boolean[][] visited = new boolean[grid.length][grid[0].length];

        // Carry out the A* search.
        while (!pq.isEmpty()) {

            Candidate best = pq.remove();

            // Is this for the target cell?
            if (best.row == grid.length - 1 && best.col == grid[0].length - 1) {
                return best.distanceSoFar;
            }

            // Have we already found the best path to this cell?
            if (visited[best.row][best.col]) {
                continue;
            }

            visited[best.row][best.col] = true;

            for (int[] neighbour : getNeighbours(best.row, best.col, grid)) {
                int neighbourRow = neighbour[0];
                int neighbourCol = neighbour[1];

                // This check isn't necessary for correctness, but it greatly
                // improves performance.
                if (visited[neighbourRow][neighbourCol]) {
                    continue;
                }

                // Otherwise, we need to create a Candidate object for the option
                // of going to neighbor through the current cell.
                int newDistance = best.distanceSoFar + 1;
                int totalEstimate = newDistance + estimate(neighbourRow, neighbourCol, grid);
                Candidate candidate =
                    new Candidate(neighbourRow, neighbourCol, newDistance, totalEstimate);
                pq.add(candidate);
            }
        }
        // The target was unreachable.
        return -1;
    }

    private List<int[]> getNeighbours(int row, int col, int[][] grid) {
        List<int[]> neighbours = new ArrayList<>();
        for (int i = 0; i < directions.length; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if (newRow < 0 || newCol < 0 || newRow >= grid.length
                    || newCol >= grid[0].length
                    || grid[newRow][newCol] != 0) {
                continue;
            }
            neighbours.add(new int[]{newRow, newCol});
        }
        return neighbours;
    }

    // Get the best case estimate of how much further it is to the bottom-right cell.
    private int estimate(int row, int col, int[][] grid) {
        int remainingRows = grid.length - row - 1;
        int remainingCols = grid[0].length - col - 1;
        return Math.max(remainingRows, remainingCols);
    }
}class Solution {

    // Candidate represents a possible option for travelling to the cell
    // at (row, col).
    class Candidate {

        public int row;
        public int col;
        public int distanceSoFar;
        public int totalEstimate;

        public Candidate(int row, int col, int distanceSoFar, int totalEstimate) {
            this.row = row;
            this.col = col;
            this.distanceSoFar = distanceSoFar;
            this.totalEstimate = totalEstimate;
        }
    }


    private static final int[][] directions =
        new int[][]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};


    public int shortestPathBinaryMatrix(int[][] grid) {

        // Firstly, we need to check that the start and target cells are open.
        if (grid[0][0] != 0 || grid[grid.length - 1][grid[0].length - 1] != 0) {
            return -1;
        }

        // Set up the A* search.
        Queue<Candidate> pq = new PriorityQueue<>((a,b) -> a.totalEstimate - b.totalEstimate);
        pq.add(new Candidate(0, 0, 1, estimate(0, 0, grid)));

        boolean[][] visited = new boolean[grid.length][grid[0].length];

        // Carry out the A* search.
        while (!pq.isEmpty()) {

            Candidate best = pq.remove();

            // Is this for the target cell?
            if (best.row == grid.length - 1 && best.col == grid[0].length - 1) {
                return best.distanceSoFar;
            }

            // Have we already found the best path to this cell?
            if (visited[best.row][best.col]) {
                continue;
            }

            visited[best.row][best.col] = true;

            for (int[] neighbour : getNeighbours(best.row, best.col, grid)) {
                int neighbourRow = neighbour[0];
                int neighbourCol = neighbour[1];

                // This check isn't necessary for correctness, but it greatly
                // improves performance.
                if (visited[neighbourRow][neighbourCol]) {
                    continue;
                }

                // Otherwise, we need to create a Candidate object for the option
                // of going to neighbor through the current cell.
                int newDistance = best.distanceSoFar + 1;
                int totalEstimate = newDistance + estimate(neighbourRow, neighbourCol, grid);
                Candidate candidate =
                    new Candidate(neighbourRow, neighbourCol, newDistance, totalEstimate);
                pq.add(candidate);
            }
        }
        // The target was unreachable.
        return -1;
    }

    private List<int[]> getNeighbours(int row, int col, int[][] grid) {
        List<int[]> neighbours = new ArrayList<>();
        for (int i = 0; i < directions.length; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if (newRow < 0 || newCol < 0 || newRow >= grid.length
                    || newCol >= grid[0].length
                    || grid[newRow][newCol] != 0) {
                continue;
            }
            neighbours.add(new int[]{newRow, newCol});
        }
        return neighbours;
    }

    // Get the best case estimate of how much further it is to the bottom-right cell.
    private int estimate(int row, int col, int[][] grid) {
        int remainingRows = grid.length - row - 1;
        int remainingCols = grid[0].length - col - 1;
        return Math.max(remainingRows, remainingCols);
    }
}
*/
