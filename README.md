# LeetcodeAlgorithm
Practice of leetcode

## Dynamic Programming
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 5| Longest Palindromic Substring|[5.cpp](5.cpp)|Medium|LCS with corner case. Another DP derives p(i,j)=p(i+1,j-1)&s\[i\]==s\[j\]|
| 10| Regular Expression Matching|[10.cpp](10.cpp)|Medium|variation of LCS. check empty string also!|
| 22| Generate Parentheses|[22.cpp](22.cpp)|Medium|Catalan Number, could use DP or recursive(backtracking)|
| 44| Wildcard Matching|[44.cpp](44.cpp)|Hard|DP or Greedy. **Compare to 10.**|
| 62| Unique Paths|[62.cpp](62.cpp)|Medium|1-d dynamic, similar to combination|
| 63| Unique Paths II|[63.cpp](63.cpp)|Medium|prob. 62 with obstacles|
| 64| Minimum Path Sum|[64.cpp](64.cpp)|Medium|similar to prob. 62|
| 64| Minimum Path Sum|[64.cpp](64.cpp)|Medium|similar to prob. 62 with min sum|
| 70| Climbing Stairs|[70.cpp](70.cpp)|Easy|Fibonacci|
| 72| Edit Distance|[72.cpp](72.cpp)|Hard|String Editing|
| 87| Scramble String|[87.cpp](87.cpp)|Hard|each scramble should consider from left or right|
| 91| Decode Ways|[91.cpp](91.cpp)|Medium|recursive will cause TLE, using dp instead.|
| 97| Interleaving String|[97.cpp](97.cpp)|Hard|**once we get recursive, we can have a mem recursive which is DP. the induction is as the recursive condition.**|
| 115| Distinct Subsequences|[115.cpp](115.cpp)|Hard|**Noticie the string indexing in DP**|
| 121| Best Time to Buy and Sell Stock|[121.cpp](121.cpp)|Easy|One transaction. use data structure to record local min. Kind of dp.|
| 122| Best Time to Buy and Sell Stock II|[122.cpp](122.cpp)|Easy|Many transactions.|
| 123| Best Time to Buy and Sell Stock III|[123.cpp](123.cpp)|Hard|Only two transactions|
| 131| Palindrome Partitioning|[131.cpp](131.cpp)|Medium|back tracking with step: size of a plindrome.|
| 132| Palindrome Partitioning II|[132.cpp](132.cpp)|Hard|back tracking: TLE. 2D-DP: TLE. Use **Manancher-like solution**.|
| 134| Gas Station|[134.cpp](134.cpp)|Medium|2 ptr|
| 139| Word Break|[139.cpp](139.cpp)|Medium||
| 140| Word Break II|[140.cpp](140.cpp)|Hard|reduce to problem. 139 / Add forward check(early stop) to avoid TLE.|
| **152**| Maximum Product Subarray|[152.cpp](152.cpp)|Medium|imax/imin denotes max/min contiguous products at position i.|
| 169| Majority Element|[169.cpp](169.cpp)|Easy|**Boyer-Moore Voting Algorithm, T:O(n, S:O(1))**|
| 174| Dungeon Game|[174.cpp](174.cpp)|Hard|tell the scenario when should we bottom up / top down tracing|
| 188| Best Time to Buy and Sell Stock IV|[188.cpp](188.cpp)|Hard|reduce to 2 transaction problem with DP T:O(nk) / find all valley/peak with priotiry profit Q T:O(n+nlogn)|
| 198| House Robber|[198.cpp](198.cpp)|Easy|dp\[i\]=max(dp\[i-1\],dp\[i-2\]+nums\[i\])|
| 213| House Robber II|[213.cpp](213.cpp)|Medium|decompose into 2 HouseRobber.|
| 221| Maximal Square|[221.cpp](221.cpp)|Medium|dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1|
| **229**| Majority Element II|[229.cpp](229.cpp)|Medium|**Boyer-Moore Voting Algorithm, T:O(n, S:O(1))** ⌊ n/3 ⌋ means we have 2 candidates at most.|
| 238| Product of Array Except Self|[238.cpp](238.cpp)|Medium|left/right product|
| 263| Ugly Number|[263.cpp](263.cpp)|Easy||
| 264| Ugly Number II|[264.cpp](264.cpp)|Medium|Min(p2*2,p3*3,p5*5), 1-d DP|
| 279| Perfect Squares|[279.cpp](279.cpp)|Medium|**dp/math/graph/cache recursive**|
| **300**| Longest Increasing Subsequence|[300.cpp](300.cpp)|Medium|LCS/LIS. Find LIS so far in each current position with binary search. T:O(nlogn)|
| 309| Best Time to Buy and Sell Stock with Cooldown|[309.cpp](309.cpp)|Medium|State Machine Thinking|
| 312| Burst Balloons|[312.cpp](312.cpp)|Hard|bottom-up DP|
| 368| Largest Divisible Subset|[368.cpp](368.cpp)|Medium|a%b==0 && b%c==0 -> a%c==0|
| 416| Partition Equal Subset Sum|[416.cpp](416.cpp)|Medium|0/1 Knapsack / bit manipulation|
| 494| Target Sum|[494.cpp](494.cpp)|Medium|0/1 Knapsack|
| 518| Coin Change 2|[518.cpp](518.cpp)|Medium|0/1 Knapsack Problem. Backtracking will TLE|
| 673| Number of Longest Increasing Subsequence|[673.cpp](673.cpp)|Medium||
| 799| Champagne Tower|[799.cpp](799.cpp)|Medium|bottom-up DP|
| 983| Minimum Cost For Tickets|[983.cpp](983.cpp)|Medium|top down DP|
| 1035| Uncrossed Lines|[1035.cpp](1035.cpp)|Medium|Longest Common Sequence|
| 1041| Robot Bounded In Circle|[1041.cpp](1041.cpp)|Medium|check direction and position.|
| 1277| Count Square Submatrices with All Ones|[1277.cpp](1277.cpp)|Medium||
| 1463| Cherry Pickup II|[1463.cpp](1463.cpp)|Hard|bottom up thinking|
| 1504| Count Submatrices With All Ones|[1504.cpp](1504.cpp)|Medium|check horizontal first, then vertical. T:O(n^3)|
| 1510| Stone Game IV|[1510.cpp](1510.cpp)|Hard|T:O(n^(3/2))|
| 1745| Palindrome Partitioning IV|[1745.cpp](1745.cpp)|Hard|Make a table to check if palindrom from i to j, then iterate over all posisble pairs to check if feasible. T:O(n^2)/S:O(n^2)|

## Searching
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 4| Median of Two Sorted Arrays|[4.cpp](4.cpp)|Hard|binary search on first vector to split num1/num2|
| 33| Search in Rotated Sorted Array|[33.cpp](33.cpp)|Medium|find pivot and utilize the other part which is sorted|
| 34| Find First and Last Position of Element in Sorted Array|[34.cpp](34.cpp)|Medium|twice binary search|
| 35| Search Insert Position|[35.cpp](35.cpp)|Easy||
| 74| Search a 2D Matrix|[74.cpp](74.cpp)|Medium|Treat 2-d matrix as 1-d|
| 81| Search in Rotated Sorted Array II|[81.cpp](81.cpp)|Medium|duplicated entry of rotated sorted array, l++,r-- if cannot tell where the pivot is.|
| 149| Max Points on a Line|[149.cpp](149.cpp)|Hard|hash key of gradient: long double/gcd(a,b)|
| 153| Find Minimum in Rotated Sorted Array|[153.cpp](153.cpp)|Medium|binary search, T:O(logN)|
| 154| Find Minimum in Rotated Sorted Array II|[154.cpp](154.cpp)|Hard|duplicate nums will make worst case as O(n)|
| 162| Find Peak Element|[162.cpp](162.cpp)|Medium|binary search to find LOCAL MAX|
| 217| Contains Duplicate|[217.cpp](217.cpp)|Medium|hashmap|
| 219| Contains Duplicate II|[219.cpp](219.cpp)|Easy|set/map|
| 220| Contains Duplicate III|[220.cpp](220.cpp)|Medium|moving set/map window with lower bound checking, just check latest k nums|
| 228| Summary Ranges|[228.cpp](228.cpp)|Medium|O(n) vs binary search O(logn)|
| 240| Search a 2D Matrix II|[240.cpp](240.cpp)|Medium|O(m+n) from bottom left|
| 274| H-Index|[274.cpp](274.cpp)|Medium|sort(O(nlogn) or O(n) from bucket sort) + iterate|
| 275| H-Index II|[275.cpp](275.cpp)|Medium|Binary search, define mid, \<mid, \> mid criteria|
| 278| First Bad Version|[278.cpp](278.cpp)|Easy|template usage|
| 392| Is Subsequence|[392.cpp](392.cpp)|Easy|LCSequence/binary search|
| 436| Find Right Interval|[436.cpp](436.cpp)|Medium|binary search|
| 441| Arranging Coins|[441.cpp](441.cpp)|Easy|Linear/binary search, notice index|
| 528| Random Pick with Weight|[528.cpp](528.cpp)|Easy|binary search **REGION**|
| 704| Binary Search|[704.cpp](704.cpp)|Easy||
| 1044| Longest Duplicate Substring|[1044.cpp](1044.cpp)|**Hard**|binary search to find longest length, **Rabin-Karp** to compare string|
| 1103| Distribute Candies to People|[1103.cpp](1103.cpp)|Easy|binary search to find n(n+1)/2<=m, then do math calculation|
| 1237| Find Positive Integer Solution for a Given Equation|[1237.cpp](1237.cpp)|Medium|monotonic increasing -> binary search|
| 1283| Find the Smallest Divisor Given a Threshold|[1283.cpp](1283.cpp)|Medium|binary search on all possible dividor|
| 1539| Kth Missing Positive Number|[1539.cpp](1539.cpp)|Easy|binary search|


## Recursive / Backtracking
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 17| Letter Combinations of a Phone Number|[17.cpp](17.cpp)|Medium| iterative/recursive|
| **31**| Next Permutation|[31.cpp](31.cpp)|Medium|backtracking may TLE, Narayana Pandita's permutationn ALG|
| 37| Sudoku Solver|[37.cpp](37.cpp)|Hard|ROW MAJOR Top Down Backtracking, mind end up criteria.|
| 38| Count and Say|[38.cpp](38.cpp)|Easy|moving comparison or DP.|
| 39| Combination Sum|[39.cpp](39.cpp)|Medium|each entry could be used SEVERAL TIME|
| 40| Combination Sum II|[40.cpp](40.cpp)|Medium|each entry could be used ONCE, could reduce to problem 39.|
| 46| Permutations|[46.cpp](46.cpp)|Medium|allow duplicate|
| 47| Permutations II|[47.cpp](47.cpp)|Medium|no duplicate allowed, hashtable or **call by value**|
| 51| N-Queens|[51.cpp](51.cpp)|Hard|recursive vs stack|
| 52| N-Queens II|[52.cpp](52.cpp)|Hard|Don't need 2-d table to place Q. Use **diagonal flag** with 1-d bool array.|
| 60| Permutation Sequence|[60.cpp](60.cpp)|Medium|Find formula. Notice 0-based k.|
| 77| Combinations|[77.cpp](77.cpp)|Medium|typical back tracking problem, **check**|
| 78| Subsets|[78.cpp](78.cpp)|Medium|recursive,iteration, bit manipulation|
| 90| Subsets II|[90.cpp](90.cpp)|Medium|reduce to problem 87.|
| 200| Number of Islands|[200.cpp](200.cpp)|Medium||
| 216| Combination Sum III|[216.cpp](216.cpp)|Medium|unique number in each comb|
| 273| Integer to English Words|[273.cpp](273.cpp)|Hard|recursive on divisor and remainder, notice edge case!!|
| 282| Expression Add Operators|[282.cpp](282.cpp)|Hard|For * OP, we should keep previout value. ```cv-pv+pv*r```|
| 526| Beautiful Arrangement|[526.cpp](526.cpp)|Medium||
| 556| Next Greater Element III|[556.cpp](556.cpp)|Medium|Reduce to problem 31.|
| 949| Largest Time for Given Digits|[949.cpp](949.cpp)|Easy|permutation then check validation|
| 967| Numbers With Same Consecutive Differences|[967.cpp](967.cpp)|Medium|greedy recursive|
| 980| Unique Paths III|[980.cpp](980.cpp)|Hard||
| 994| Rotting Oranges|[994.cpp](994.cpp)|Medium|greedy approach|
| 1286| Iterator for Combination|[1286.cpp](1286.cpp)|Medium|recursive + call by value / 2 ptr dynamically|
| 1718| Construct the Lexicographically Largest Valid Sequence|[1718.cpp](1718.cpp)|Medium|buggy implementation|
| 1723| Find Minimum Time to Finish All Jobs|[1723.cpp](1723.cpp)|Hard|recursive + prunning / multi 0/1 knapsack DP.|


## Tree
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 95| Unique Binary Search Trees II|[95.cpp](95.cpp)|Medium|Catalan number, be care of same ptr for each tree, thus clone one.|
| 96| Unique Binary Search Trees|[96.cpp](96.cpp)|Medium|Catalan, refer to 95. and 22.|
| 98| Validate Binary Search Tree|[98.cpp](98.cpp)|Medium|**Notice predecessor and successor**|
| 99| Recover Binary Search Tree|[99.cpp](99.cpp)|Hard|**O(1) space by morris inorder traversal(similar to thread BST).**|
| 100| Same Tree|[100.cpp](100.cpp)|Easy||
| 101| Symmetric Tree|[101.cpp](101.cpp)|Easy||
| 102| Binary Tree Level Order Traversal|[102.cpp](102.cpp)|Medium|NLR:preorder/levelOrder|
| 103| Binary Tree Zigzag Level Order Traversal|[103.cpp](103.cpp)|Medium|reduce to problem 102.|
| 104| Maximum Depth of Binary Tree|[104.cpp](104.cpp)|Easy||
| 105| Construct Binary Tree from Preorder and Inorder Traversal|[105.cpp](105.cpp)|Medium|recursive/iteration(stack)|
| 106| Construct Binary Tree from Inorder and Postorder Traversal |[106.cpp](106.cpp)|Medium|recursive/iteration(stack)|
| 107| Binary Tree Level Order Traversal II|[107.cpp](107.cpp)|Easy|Zigzag|
| 108| Convert Sorted Array to Binary Search Tree|[108.cpp](108.cpp)|Easy||
| 109| Convert Sorted List to Binary Search Tree|[109.cpp](109.cpp)|Medium|**Use inorder traversal with ONE PASS**|
| 110| Balanced Binary Tree|[110.cpp](110.cpp)|Easy||
| 111| Minimum Depth of Binary Tree|[111.cpp](111.cpp)|Easy|leaf is a node without any child|
| 112| Path Sum|[112.cpp](112.cpp)|Easy|top down reduce sum|
| 113| Path Sum II|[113.cpp](113.cpp)|Medium|reduce to problem 112.|
| 114| Flatten Binary Tree to Linked List|[114.cpp](114.cpp)|Medium|remember to **clean the left part**.|
| 116| Populating Next Right Pointers in Each Node|[116.cpp](116.cpp)|Medium|use next ptr for constant space.|
| 117| Populating Next Right Pointers in Each Node II|[117.cpp](117.cpp)|Medium|reduce to problem 116.|
| 124| Binary Tree Maximum Path Sum|[124.cpp](124.cpp)|Hard|Must contain at least one node|
| 129| Sum Root to Leaf Numbers|[129.cpp](129.cpp)|Medium||
| 144| Binary Tree Preorder Traversal|[144.cpp](144.cpp)|Medium||
| 145| Binary Tree Postorder Traversal|[145.cpp](145.cpp)|Hard|stack|
| 199| Binary Tree Right Side View|[199.cpp](199.cpp)|Medium|Preorder/levelOrder|
| **222**| Count Complete Tree Nodes|[222.cpp](222.cpp)|Medium|O((logn)^2) recursive on left/right depth instead of O(n)|
| 226| Invert Binary Tree|[226.cpp](226.cpp)|Easy|iterative & recursive|
| 230| Kth Smallest Element in a BST|[230.cpp](230.cpp)|Medium|iterative. Follow up: what if modified frequently? LRU cache.(link list+hashmap)|
| 235| Lowest Common Ancestor of a Binary Search Tree|[235.cpp](235.cpp)|Easy|the LCA u of binary search tree will show p\<u\<q|
| 236| Lowest Common Ancestor of a Binary Tree|[236.cpp](236.cpp)|Medium|LRN/NLR traversal to check left/right/cur found bool.|
| 257| Binary Tree Paths|[257.cpp](257.cpp)|Easy|preorder traversal+back tracking|
| 297| Serialize and Deserialize Binary Tree|[297.cpp](297.cpp)|Hard|use preorder with an EOS to encode/decode|
| 337| House Robber III|[337.cpp](337.cpp)|Medium||
| 404| Sum of Left Leaves|[404.cpp](404.cpp)|Easy||
| 437| Path Sum III|[437.cpp](437.cpp)|Medium|recursive with/without hashmap sum|
| 450| Delete Node in a BST|[450.cpp](450.cpp)|Medium|replace with predecessor or successor|
| 501| Find Mode in Binary Search Tree|[501.cpp](501.cpp)|Easy|running ptr|
| 508| Most Frequent Subtree Sum|[508.cpp](508.cpp)|Medium||
| 538| Convert BST to Greater Tree|[538.cpp](538.cpp)|Medium|reverse inorder|
| 563| Binary Tree Tilt|[563.cpp](563.cpp)|Easy||
| 623| Add One Row to Tree|[623.cpp](623.cpp)|Medium|level order|
| 652| Find Duplicate Subtrees|[652.cpp](652.cpp)|Medium|postorder with node encoding|
| 662| Maximum Width of Binary Tree|[662.cpp](662.cpp)|Medium|level order traversal with offset subtraction|
| 700| Search in a Binary Search Tree|[700.cpp](700.cpp)|Easy||
| 701| Insert into a Binary Search Tree|[701.cpp](701.cpp)|Medium||
| 863| All Nodes Distance K in Binary Tree|[863.cpp](863.cpp)|Medium|dfs+postDFS|
| 865| Smallest Subtree with all the Deepest Nodes|[865.cpp](865.cpp)|Medium||
| 894| All Possible Full Binary Trees|[894.cpp](894.cpp)|Medium|Catalan Number|
| 951| Flip Equivalent Binary Trees|[951.cpp](951.cpp)|Medium||
| 971| Flip Binary Tree To Match Preorder Traversal|[971.cpp](971.cpp)|Medium||
| 979| Distribute Coins in Binary Tree|[979.cpp](979.cpp)|Medium|postOrder|
| 987| Vertical Order Traversal of a Binary Tree|[987.cpp](987.cpp)|Medium|nested map|
| 998| Maximum Binary Tree II|[998.cpp](998.cpp)|Medium||
| 1022| Sum of Root To Leaf Binary Numbers|[1022.cpp](1022.cpp)|Easy||
| 1026| Maximum Difference Between Node and Ancestor|[1026.cpp](1026.cpp)|Medium||
| 1145| Binary Tree Coloring Game|[1145.cpp](1145.cpp)|Medium||
| 1305| All Elements in Two Binary Search Trees|[1305.cpp](1305.cpp)|Medium|iterative inorder traversal, stack without flag|
| 1339| Maximum Product of Splitted Binary Tree|[1339.cpp](1339.cpp)|Medium|preorder|
| 1372| Longest ZigZag Path in a Binary Tree|[1372.cpp](1372.cpp)|Medium|postorder|
| 1379| Find a Corresponding Node of a Binary Tree in a Clone of That Tree|[1379.cpp](1379.cpp)|Medium|preorder|
| 1448| Count Good Nodes in Binary Tree|[1448.cpp](1448.cpp)|Medium|preorder|
| 1457| Pseudo-Palindromic Paths in a Binary Tree|[1457.cpp](1457.cpp)|Medium|preorder + bit manipulation|
| 1609| Even Odd Tree|[1609.cpp](1609.cpp)|Medium||
| 1649| Create Sorted Array through Instructions|[1649.cpp](1649.cpp)|Hard|Binary Indexed Tree, i.e. Segment Tree|


## Divide & Conquer
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 23| Merge k Sorted Lists|[23.cpp](23.cpp)|Hard|**Iterative split arrays equally in 2^n**|
| 241| Different Ways to Add Parentheses|[241.cpp](241.cpp)|Medium|recursive + memorized DP (CACHE)|
| 395| Longest Substring with At Least K Repeating Characters|[395.cpp](395.cpp)|Medium|divide & conquer|

## LinkedList
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 2| Add Two Numbers|[2.cpp](2.cpp)|Medium|notice carry|
| 19| Remove Nth Node From End of List|[19.cpp](19.cpp)|Medium|slow/fast ptr|
| 21| Merge Two Sorted Lists|[21.cpp](21.cpp)|Easy||
| 24| Swap nodes in Pairs|[24.cpp](24.cpp)|Medium|Header pointer|
| 25| Reverse Nodes in k-Group|[25.cpp](25.cpp)|Hard|recursive for neat code|
| 61| Rotate List|[61.cpp](61.cpp)|Medium||
| 82| Remove Duplicates from Sorted List II|[82.cpp](82.cpp)|Medium||
| 83| Remove Duplicates from Sorted List|[83.cpp](83.cpp)|Easy||
| 86| Partition List|[86.cpp](86.cpp)|Medium||
| 92| Reverse Linked List II|[92.cpp](92.cpp)|Medium|one pass reverse region|
| 94| Binary Tree Inorder Traversal|[94.cpp](94.cpp)|Medium|recursive/iterative(stack)|
| 138| Copy List with Random Pointer|[138.cpp](138.cpp)|Medium|Optima: T:O(n),S:O(1) with 3 pass|
| 141| Linked List Cycle|[141.cpp](141.cpp)|Easy|2ptr One pass T:O(n),S:O(1)|
| 142| Linked List Cycle II|[142.cpp](142.cpp)|Medium|2 ptr, L1=(C-L2)|
| 143| Reorder List|[143.cpp](143.cpp)|Medium|3 pass(separate in the middle)/2 pass(hashmap)/1 pass(recursive). |
| 147| Insertion Sort List|[147.cpp](147.cpp)|Medium|User a header ptr to store sorted list|
| 148| Sort List|[148.cpp](148.cpp)|Medium|T:O(nlogn),S:O(1)->merge sort|
| 160| Intersection of Two Linked Lists|[160.cpp](160.cpp)|Easy|T:O(1) with 2 ptr.|
| 203| Remove Linked List Elements|[203.cpp](203.cpp)|Easy|header ptr|
| 234| Palindrome Linked List|[234.cpp](234.cpp)|Easy|T:O(n)/S:O(1)|
| 237| Delete Node in a Linked List|[237.cpp](237.cpp)|Easy|ptr value assign|
| 430| Flatten a Multilevel Doubly Linked List|[430.cpp](430.cpp)|Medium|cyclic double link list for reaching head/tail easily.|
| 817| Linked List Components|[817.cpp](817.cpp)|Medium|**Union Find**|
| 1290| Convert Binary Number in a Linked List to Integer|[1290.cpp](1290.cpp)|Easy||


## Stack and Queue
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 20| Valid Parentheses|[20.cpp](20.cpp)|Easy|check empty stack in iteration|
| **32**| Longest Valid Parentheses|[32.cpp](32.cpp)|Hard|use stack to store index rather than '()'. Or use bi-directional checking|
| 71| Simplify Path|[71.cpp](71.cpp)|Medium|stack/word tokenizer instead of char tokenizer.|
| 84| Largest Rectangle in Histogram|[84.cpp](84.cpp)|Hard|stack with index of ascending order|
| 150| Evaluate Reverse Polish Notation|[150.cpp](150.cpp)|Medium|recursive/iterative|
| 155| Min Stack|[155.cpp](155.cpp)|Easy|Record local min so far as well. push/pop/top/getMin T:O(1)|
| 224| Basic Calculator|[224.cpp](224.cpp)|Hard|2 stack, infix->postfix->value|
| 225| Implement Stack using Queues|[225.cpp](225.cpp)|Easy|1 Q, drawback: O(n)|
| 227| Basic Calculator II|[227.cpp](227.cpp)|Medium|ISP v.s. ICP|
| 232| Implement Queue using Stacks|[232.cpp](232.cpp)|Easy|2 stacks|
| 239| Sliding Window Maximum|[239.cpp](239.cpp)|Hard|**Greedy** double ended queue T:O(n) / hashmap T:O(nlogn)|
| 295| Find Median from Data Stream|[295.cpp](295.cpp)|Hard|2 priority Q|
| 456| 132 Pattern|[456.cpp](456.cpp)|Medium|binary search T:O(nlogn) / tricky stack T:O(n)|
| 1438| Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit|[1438.cpp](1438.cpp)|Medium|Reduce to problem 239. Use deque to record local min/max|
| 1673| Find the Most Competitive Subsequence|[1673.cpp](1673.cpp)|Medium|mono increasing stack, |


## String
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 12| Integer to Roman|[12.cpp](12.cpp)|Medium|Elegant dictionary|
| 13| Roman to Integer|[13.cpp](13.cpp)|Easy|No additional dictionary entry needed.|
| **28**| Implement strStr()|[28.cpp](28.cpp)|Easy|KMP, failure function / while loop criteria|
| 30| Substring with Concatenation of All Words|[30.cpp](30.cpp)|Hard|Bottom up early stop instead of frequency comparison.|
| 43| Multiply Strings|[43.cpp](43.cpp)|Medium|basic multiplication|
| 58| Length of Last Word|[58.cpp](58.cpp)|Easy|Notice space in back|
| 125| Valid Palindrome|[125.cpp](125.cpp)|Easy|isalnum|
| 151| Reverse Words in a String|[151.cpp](151.cpp)|Medium|S:O(1), reverse while string then reverse each word|
| 165| Compare Version Numbers|[165.cpp](165.cpp)|Medium|istringstream/recursive|
| 205| Isomorphic Strings|[205.cpp](205.cpp)|Easy||
| 208| Implement TRIE (Prefix Tree)|[208.cpp](208.cpp)|Medium||
| 211| Add and Search Word - Data structure design|[211.cpp](211.cpp)|Medium|TRIE|
| 212| Word Search II|[212.cpp](212.cpp)|Hard|**TRIE (string tree)**, we can do early stop with TRIE.|
| 214| Shortest Palindrome|[214.cpp](214.cpp)|Hard|KMP!!|
| 242| Valid Anagram|[242.cpp](242.cpp)|Easy|unicode length: 4|
| 299| Bulls and Cows|[299.cpp](299.cpp)|Easy|Use one bucket. Use sign to simulate up/down|
| 316| Remove Duplicate Letters|[316.cpp](316.cpp)|Medium|greedy|
| 389| Find the Difference|[389.cpp](389.cpp)|Easy|xor|
| 394| Decode String|[394.cpp](394.cpp)|Medium||
| 409| Longest Palindrome|[409.cpp](409.cpp)|Easy|hashmap|
| 412| Fizz Buzz|[412.cpp](412.cpp)|Easy||
| 459| Repeated Substring Pattern|[459.cpp](459.cpp)|Easy|KMP|
| 468| Validate IP Address|[468.cpp](468.cpp)|Medium||
| 763| Partition Labels|[763.cpp](763.cpp)|Medium|treat is as array. moving anchor to check overlap region.|
| 824| Goat Latin|[824.cpp](824.cpp)|Easy||
| 859| Buddy Strings|[859.cpp](859.cpp)|Easy|running ptr|
| 880| Decoded String at Index|[880.cpp](880.cpp)|Medium|Forward/Backward.|
| 1032| Stream of Characters|[1032.cpp](1032.cpp)|Hard|inverse TRIE|
| 1446| Consecutive Characters|[1446.cpp](1446.cpp)|Easy||
| 1657| Determine if Two Strings Are Close|[1657.cpp](1657.cpp)|Medium||
| 1662| Check If Two String Arrays are Equivalent|[1662.cpp](1662.cpp)|Easy|2 ptr|
| 1704| Determine if String Halves Are Alike|[1704.cpp](1704.cpp)|Easy||

## Array
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 1| Two Sum|[1.cpp](1.cpp)|Easy||
| 3| Longest Substring Without Repeating Characters|[3.cpp](3.cpp)|Medium|one pass hashmap|
| 6| ZigZag Conversion|[6.cpp](6.cpp)|Medium||
| 11| Container With Most Water|[11.cpp](11.cpp)|Medium|two pointer|
| 14| Longest Common Prefix|[14.cpp](14.cpp)|Easy||
| 15| 3Sum|[15.cpp](15.cpp)|Medium| **Greedy / sandwitch(boudary) search**|
| 16| 3Sum Closest|[16.cpp](16.cpp)|Medium| 3Sum|
| **18**| 4Sum|[18.cpp](18.cpp)|Medium| **General way for k SUM, recursive on k until down to 2Sum**|
| 26| Remove Duplicates from Sorted Array|[26.cpp](26.cpp)|Easy||
| 27| Remove Element|[27.cpp](27.cpp)|Easy|what if less dupilcate nums?|
| 36| Valid Sudoku|[36.cpp](36.cpp)|Medium|indexing|
| 41| First Missing Positive|[41.cpp](41.cpp)|Hard|2 pass: Correct Slot Filling. 3 pass: sign bit checking if exist.|
| 42| Trapping Rain Water|[42.cpp](42.cpp)|Hard|Greedy. Graham's Scan or **2 pointers sandwitch search**|
| 45| Jump Game II|[45.cpp](45.cpp)|Hard|**2 pointers (start/end)**|
| 48| Rotate Image|[48.cpp](48.cpp)|Medium|clockwise / anticlockwise|
| 49| Group Anagrams|[49.cpp](49.cpp)|Medium||
| 53| Maximum Subarray|[53.cpp](53.cpp)|Easy|moving sum DP or divide & conquer|
| 54| Spiral Matrix|[54.cpp](54.cpp)|Medium|Elegant loop with 4 direction pointers.|
| 55| Jump Game|[55.cpp](55.cpp)|Medium|compare to problem 45|
| 59| Spiral Matrix II|[59.cpp](59.cpp)|Medium|Same as problem 54.|
| 68| Text Justification|[68.cpp](68.cpp)|Hard||
| 73| Set Matrix Zeroes|[73.cpp](73.cpp)|Medium|store the state of each row/col in first entry of row/col|
| 76| Minimum Window Substring|[76.cpp](76.cpp)|Hard|moving window<->2 pointers|
| 79| Word Search|[79.cpp](79.cpp)|Medium|dfs|
| 80| Remove Duplicates from Sorted Array II|[80.cpp](80.cpp)|Medium|check the last kth element|
| 85| Maximal Rectangle|[85.cpp](85.cpp)|Hard|**reduce to problem 84.**|
| 88| Merge Sorted Array|[88.cpp](88.cpp)|Easy|indexing|
| 93| Restore IP Addresses|[93.cpp](93.cpp)|Medium|0 leading ip is illegal|
| 118| Pascal's Triangle|[118.cpp](118.cpp)|Easy|top down DP|
| 119| Pascal's Triangle II|[119.cpp](119.cpp)|Easy|top down 1-D DP|
| 120| Triangle|[120.cpp](120.cpp)|Medium|**top down DP v.s. bottom up DP**|
| 130| Surrounded Regions|[130.cpp](130.cpp)|Medium||
| 135| Candy|[135.cpp](135.cpp)|Hard|S:O(1) top/down peak analysis. S:O(n) 2 endian traverse.|
| 163| Missing Ranges|[163.cpp](163.cpp)|Easy||
| 167| Two Sum II - Input array is sorted|[167.cpp](167.cpp)|Easy|2ptr|
| 189| Rotate Array|[189.cpp](189.cpp)|Easy|Reverse and reverse|
| 209| Minimum Size Subarray Sum|[209.cpp](209.cpp)|Medium|accumulate+2ptr: T:O(n), note that sanity check is needed in the begin|
| 218| The Skyline Problem|[218.cpp](218.cpp)|Hard|priority queue (multiset) to track local max height|
| 268| Missing Number|[268.cpp](268.cpp)|Easy|sort/set/bit manipulate/use sign|
| 283| Move Zeroes|[283.cpp](283.cpp)|Easy|2 ptr method|
| 287| Find the Duplicate Number|[287.cpp](287.cpp)|Medium|O(1) space. Floyd's Tortoise and Hare ALG.|
| 289| Game of Life|[289.cpp](289.cpp)|Medium|in-place|
| 290| Word Pattern|[290.cpp](290.cpp)|Easy|2 hashmap/1 hashmap|
| 303| Range Sum Query - Immutable|[303.cpp](303.cpp)|Easy||
| 334| Increasing Triplet Subsequence|[334.cpp](334.cpp)|Medium|2 endian stack check. / DP!!|
| 406| Queue Reconstruction by Height|[406.cpp](406.cpp)|Medium|**insert after sorting**|
| 442| Find All Duplicates in an Array|[442.cpp](442.cpp)|Medium|1 ≤ a\[i\] ≤ n|
| 454| 4Sum II|[454.cpp](454.cpp)|Medium|break down T:O(n^2)|
| 452| Minimum Number of Arrows to Burst Balloons|[452.cpp](452.cpp)|Medium|sort + greedy to find min-enclosed range|
| 463| Island Perimeter|[463.cpp](463.cpp)|Easy|4*count edge-2*repeat edge|
| 495| Teemo Attacking|[495.cpp](495.cpp)|Medium|runing ptr|
| 498| Diagonal Traverse|[498.cpp](498.cpp)|Medium||
| 525| Contiguous Array|[525.cpp](525.cpp)|Medium|Use map to record index of accumulated sum|
| 532| K-diff Pairs in an Array|[532.cpp](532.cpp)|Medium|Notice the default value of hashmap|
| 605| Can Place Flowers|[605.cpp](605.cpp)|Easy|Greedy|
| 713| Subarray Product Less Than K|[713.cpp](713.cpp)|Medium|2 ptr/sliding window|
| 735| Asteroid Collision|[735.cpp](735.cpp)|Medium|greedy with stack|
| 832| Flipping an Image|[832.cpp](832.cpp)|Easy||
| 835| Image Overlap|[835.cpp](835.cpp)|Medium|indexing|
| 845| Longest Mountain in Array|[845.cpp](845.cpp)|Medium|2 ptr solution|
| 849| Maximize Distance to Closest Person|[849.cpp](849.cpp)|Medium||
| 881| Boats to Save People|[881.cpp](881.cpp)|Medium|sort + 2 ptr solution|
| 905| Sort Array By Parity|[905.cpp](905.cpp)|Easy|2 ptr method/sorting|
| 908| Smallest Range I|[908.cpp](908.cpp)|Easy|T:O(n)|
| 910| Smallest Range II|[910.cpp](910.cpp)|Medium|greedy running ptr|
| 941| Valid Mountain Array|[941.cpp](941.cpp)|Easy|2 ptr|
| 948| Bag of Tokens|[948.cpp](948.cpp)|Meedium|2 ptr|
| 977| Squares of a Sorted Array|[977.cpp](977.cpp)|Easy|2 ptr|
| 1007| Minimum Domino Rotations For Equal Row|[1007.cpp](1007.cpp)|Medium||
| 1010| Pairs of Songs With Total Durations Divisible by 60|[1010.cpp](1010.cpp)|Medium||
| 1029| Two City Scheduling|[1029.cpp](1029.cpp)|Easy||
| 1094| Car Pooling|[1094.cpp](1094.cpp)|Medium|comparison/bucket sort|
| 1217| Minimum Cost to Move Chips to The Same Position|[1217.cpp](1217.cpp)|Easy||
| 1229| Meeting Scheduler|[1229.cpp](1229.cpp)|Medium||
| 1288| Remove Covered Intervals|[1288.cpp](1288.cpp)|Medium|sort|
| 1329| Sort the Matrix Diagonally|[1329.cpp](1329.cpp)|Medium|heap sort|
| 1423| Maximum Points You Can Obtain from Cards|[1423.cpp](1423.cpp)|Medium|sliding window.|
| 1437| Check If All 1's Are at Least Length K Places Away|[1437.cpp](1437.cpp)|Easy||
| 1477| Find Two Non-overlapping Sub-arrays Each With Target Sum|[1477.cpp](1477.cpp)|Medium|sliding window.|
| 1480| Running Sum of 1d Array|[1480.cpp](1480.cpp)|Easy||
| 1512| Number of Good Pairs|[1512.cpp](1512.cpp)|Easy|C^k_2, k=2,3,,,etc.|
| 1640| Check Array Formation Through Concatenation|[1640.cpp](1640.cpp)|Easy|hash table|
| 1646| Get Maximum in Generated Array|[1646.cpp](1646.cpp)|Easy||
| 1658| Minimum Operations to Reduce X to Zero|[1658.cpp](1658.cpp)|Medium|hash table / 2 ptr|
| 1675| Minimize Deviation in Array|[1675.cpp](1675.cpp)|Hard|priority queue, similar to **problem\ 910**|
| 1679| Max Number of K-Sum Pairs|[1679.cpp](1679.cpp)|Medium|hash map|
| 1710| Maximum Units on a Truck|[1710.cpp](1710.cpp)|Easy||
| 1712| Ways to Split Array Into Three Subarrays|[1712.cpp](1712.cpp)|Medium|binary search T:O(nlogn)/linear probing T:O(n)|
| 1717| Maximum Score From Removing Substrings|[1717.cpp](1717.cpp)|Medium|cumulative counter, same as bulls/cows concept.|
| 1726| Tuple with Same Product|[1726.cpp](1726.cpp)|Medium|running hashmap|
| 1727| Largest Submatrix With Rearrangements|[1727.cpp](1727.cpp)|Medium|Reduce to problem 84. and 85.|
| 1742| Maximum Number of Balls in a Box|[1742.cpp](1742.cpp)|Easy||

## Numeric
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 7| Reverse Integer|[7.cpp](7.cpp)|Easy|runtime checking INT_MAX/INT_MIN|
| 8| String to Integer (atoi)|[8.cpp](8.cpp)|Medium||
| 9| Palindrome Number|[9.cpp](9.cpp)|Easy|reverse half num! handle odd/even length|
| 29| Divide Two Integers|[29.cpp](29.cpp)|Medium|bit operating, exponential checking to avoid TLE!|
| 50| Pow(x, n)|[50.cpp](50.cpp)|Medium|bit operating|
| 65| Valid Number|[65.cpp](65.cpp)|Hard||
| 66| Plus One|[66.cpp](66.cpp)|Easy|**insert begin or end?** early stop if no carry.|
| 67| Add Binary|[67.cpp](67.cpp)|Easy|bit add, **XOR**|
| 69| Sqrt(x)|[69.cpp](69.cpp)|Easy|Newton Xn+1=1/2(Xn+a/Xn), take care of overflow.|
| 89| Gray Code|[89.cpp](89.cpp)|Medium|i^i>>1|
| 136| Single Number|[136.cpp](136.cpp)|Easy|bit operation for S:O(1),0->1->0|
| 137| Single Number II|[137.cpp](137.cpp)|Medium|save in int32. 0->1->2->0|
| 166| Fraction to Recurring Decimal|[166.cpp](166.cpp)|Medium|Edge cases!|
| 168| Excel Sheet Column Title|[168.cpp](168.cpp)|Easy|indexing, enumerate and observe pattern|
| 171| Excel Sheet Column Number|[171.cpp](171.cpp)|Easy||
| 172| Factorial Trailing Zeroes|[172.cpp](172.cpp)|Easy|Count how many 5 we have in the factorial|
| 190| Reverse Bits|[190.cpp](190.cpp)|Easy|block of bits reversing|
| 191| Number of 1 Bits|[191.cpp](191.cpp)|Easy|n&(n-1)|
| 201| Bitwise AND of Numbers Range|[201.cpp](201.cpp)|Medium||
| 202| Happy Number|[202.cpp](202.cpp)|Easy||
| 204| Count Primes|[204.cpp](204.cpp)|Easy|Eratosthenes|
| 223| Rectangle Area|[223.cpp](223.cpp)|Medium|iou calculate|
| 231| Power of Two|[231.cpp](231.cpp)|Easy|! n&(n-1) or binary search|
| 233| Number of Digit One|[233.cpp](233.cpp)|Hard|consider each decimal digit, spit into left/right part in decimal then calculate|
| 258| Add Digits|[258.cpp](258.cpp)|Easy|digital root, %9|
| 260| Single Number III|[260.cpp](260.cpp)|Medium|find last bit 1 n&~(n-1). Use last bit of xor nums to separate 2 target.|
| 292| Nim Game|[292.cpp](292.cpp)|Easy||
| 342| Power of Four|[342.cpp](342.cpp)|Easy|no loop/recursive|
| 421| Maximum XOR of Two Numbers in an Array|[421.cpp](421.cpp)|Medium|Greedy bit mannipulation / TRIE|
| 458| Poor Pigs|[458.cpp](458.cpp)|Hard|Encription thought.|
| 461| Hamming Distance|[461.cpp](461.cpp)|Easy|Brian Kernighan's algorithm n&(n-1)|
| 470| Implement Rand10() Using Rand7()|[470.cpp](470.cpp)|Medium|multiply scalar for boundary will return limit option, which is wrong!|
| 593| Valid Square|[593.cpp](593.cpp)|Medium||
| 621| Task Scheduler|[621.cpp](621.cpp)|Medium|Take examples!|
| 754| Reach a Number|[754.cpp](754.cpp)|Medium|Take examples!|
| 858| Mirror Reflection|[858.cpp](858.cpp)|Medium|geometry|
| 902| Numbers At Most N Given Digit Set|[902.cpp](902.cpp)|Hard|iterative|
| 957| Prison Cells After N Days|[957.cpp](957.cpp)|Medium|**state machine**|
| 1009| Complement of Base 10 Integer|[1009.cpp](1009.cpp)|Easy|Brian Kernighan's algorithm n&(n-1)|
| 1015| Smallest Integer Divisible by K|[1015.cpp](1015.cpp)|Medium|Pigeonhole Principle|
| 1344| Angle Between Hands of a Clock|[1344.cpp](1344.cpp)|Medium||
| 1492| The kth Factor of n|[1492.cpp](1492.cpp)|Medium|linear probing|
| 1641| Count Sorted Vowel Strings|[1641.cpp](1641.cpp)|Medium|combination|
| 1711| Count Good Meals|[1711.cpp](1711.cpp)|Medium|running window|
| 1716| Calculate Money in Leetcode Bank|[1716.cpp](1716.cpp)|Easy||
| 1744| Can You Eat Your Favorite Candy on Your Favorite Day?|[1744.cpp](1744.cpp)|Medium||

## Graph
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 126| Word Ladder II|[126.cpp](126.cpp)|Hard|Notice TLE while building graph. BFS find all shortest PATHS|
| 127| Word Ladder|[127.cpp](127.cpp)|Medium|Notice TLE while building graph. BFS find shortest LENGTH|
| 133| Clone Graph|[133.cpp](133.cpp)|Medium|BFS/DFS with seen map.|
| 207| Course Schedule|[207.cpp](207.cpp)|Medium|Detect cyclic in directed graph.|
| 210| Course Schedule II|[210.cpp](210.cpp)|Medium|topological sort. inverse of postDFS if acyclic|
| 261| Graph Valid Tree|[261.cpp](261.cpp)|Medium|cyclic detection on undirected graph, i.e. spanning tree verification.|
| 269| Alien Dictionary|[269.cpp](269.cpp)|Hard|topologic sort on directed graph.|
| 310| Minimum Height Trees|[310.cpp](310.cpp)|Medium|topologic order + MST|
| 322| Reconstruct Itinerary|[322.cpp](322.cpp)|Medium|Euler path. use priority queue for lexical order.|
| 399| Evaluate Division|[399.cpp](399.cpp)|Medium|DFS|
| 787| Cheapest Flights Within K Stops|[787.cpp](787.cpp)|Medium|Bellman ford|
| 797| All Paths From Source to Target|[797.cpp](797.cpp)|Medium|dfs+backtracking|
| 886| Possible Bipartition|[886.cpp](886.cpp)|Medium|bipartite + dfs/bfs|
| 938| Range Sum of BST|[938.cpp](938.cpp)|Easy|Utilize BST property for O(h)|
| 1306| Jump Game III|[1306.cpp](1306.cpp)|Medium|DFS|
| 1345| Jump Game IV|[1345.cpp](1345.cpp)|Hard|BFS, pruning continuous num to avoid TLE|
| 1466| Reorder Routes to Make All Paths Lead to the City Zero|[1466.cpp](1466.cpp)|Medium|undirected+directed graph/dfs|
| 1631| Path With Minimum Effort|[1631.cpp](1631.cpp)|Medium|Dijastra / binary search|
| 1743| Restore the Array From Adjacent Pairs|[1743.cpp](1743.cpp)|Medium|DFS on the begin node, which has in-degree 1|


## Sorting
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 56| Merge Intervals|[56.cpp](56.cpp)|Medium|greedy|
| 57| **Insert Interval**|[57.cpp](57.cpp)|Hard|while in for loop to avoid TLE|
| 75| Sort Colors|[75.cpp](75.cpp)|Medium|**2 pointers** for O(n) in place.|
| 164| Maximum Gap|[164.cpp](164.cpp)|Hard|**Radix Sort with buckets**|
| 179| Largest Number|[179.cpp](179.cpp)|Medium|customize comparison|
| 215| Kth Largest Element in an Array|[215.cpp](215.cpp)|Medium|partition/priority q|
| 252| Meeting Rooms|[252.cpp](252.cpp)|Easy|sort/REGIONS|
| 253| Meeting Rooms II|[253.cpp](253.cpp)|Medium|separate start/end time and sort|
| 347| Top K Frequent Elements|[347.cpp](347.cpp)|Medium|priority Q|
| 969| Pancake Sorting|[969.cpp](969.cpp)|Medium|bubble sort. 2(n-1) flips|

## Design
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 146| LRU Cache|[146.cpp](146.cpp)|Medium|hashmap+single linked list|
| 173| Binary Search Tree Iterator|[173.cpp](173.cpp)|Medium|practice of morris traversal|
| 284| Peeking Iterator|[284.cpp](284.cpp)|Medium|Utilize copy constructor|
| 380| Insert Delete GetRandom O(1)|[380.cpp](380.cpp)|Medium|hashmap+vector|
| 933| Number of Recent Calls|[933.cpp](933.cpp)|Easy|linked list|

## Union
 - find/union O(1)
 - During find (parent), we need to update its parent also for speed up. With frequently update its parent, we can have amortized complexity O(1)
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 128| Longest Consecutive Sequence|[128.cpp](128.cpp)|Hard|require. T: O(n)|
| 323| Number of Connected Components in an Undirected Graph|[323.cpp](323.cpp)|Medium|dfs or union/find.|
| 952| Largest Component Size by Common Factor|[952.cpp](952.cpp)|Hard|graph solution will TLE while building graph. Use union instead.|
| 1722| Minimize Hamming Distance After Swap OperationsMinimize Hamming Distance After Swap Operations|[1722.cpp](1722.cpp)|Medium|DFS on graph to find cconnected component / union to find group (same as connected component concept).|

## HashMap
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 187| Repeated DNA Sequences|[187.cpp](187.cpp)|Medium|Saving substr time with bit operation due to limited char|
| 804| Unique Morse Code Words|[804.cpp](804.cpp)|Easy||

## Random Algorithm
| #    | Title             | Solution | Difficult |         Note           |
| ---- |-------------------|----------|-----------|------------------------|
| 382| Linked List Random Node|[382.cpp](382.cpp)|Medium|Online random alg which doesn't need to know the length. RESOVOUR SAMPLING|
| 497| Random Point in Non-overlapping Rectangles|[497.cpp](497.cpp)|Medium|random should take area of each rect into consideration, using totalSum & binary search|


## Combo
 - Array(current min/max/median): 239, 295, 1438
 - stack index: 84, 85
 - Tree Ancestor: 235, 236
 - LL Cyclic: 141, 142, 287
 - str match DP: 10, 44, 97, 115
     - mid way DP / Divide&Conquer: 241
 - Perm: 31, 47
 - **Palindrome Partition: 131, 132, 1745**
 - LIS (increasing & equal): 300, 334
 - Min Range: 908, 910, 1675
 - Possible expression num w./w.o. parentheses: 241, 282
 - Mono Stack: 456, 1673, 316, 1081, \[76\]
 - Regions: 252, 253, 56, 57
