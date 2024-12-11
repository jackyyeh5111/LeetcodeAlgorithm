'''
Problem Statement:
You are given a graph G with n layers, where each layer is a node. Each node can have directed edges to node connected

Additionally, you are provided with another smaller subgraph S, with the same structural properties as G. Your task is to determine if S is a subgraph isomorphic to G.

In simpler terms:

You need to check if all nodes in S are present in G while maintaining the structure of the connections.

Input:
Graph 
G:
Represented as an adjacency list or a dictionary where keys are nodes and values are lists of nodes to which the key node has directed edges.
G = {
    1: [2],
    2: [3],
    3: [4],
    4: [5],
    5: []
}

Subgraph S:

Represented in the same format as G.

S = {
    3: [4],
    4: [5]
}

Output : True

'''

def is_subgraph_present(G, S):
    """
    Checks if subgraph S is subgraph of G.

    Args:
        G (dict): graph represented as an adjacency list.
        S (dict): Subgraph represented as an adjacency list.

    Returns:
        bool: True if S is a subgraph of G, False otherwise.
    """
    for node, nb_nodes in S.items():
        if node not in G.keys():
            return False

        for nb_node in nb_nodes:
            # node: 1
            # nb_node: 8 
            if nb_node not in G[node]:
                return False
    return True

# Preprocess
G = {
    1: {
        2: True
        6: True
        7: True
    }
    ..
}

# Tester Code
G = {
    1: [2,6,7],
    2: [3],
    3: [4,9],
    4: [5],
    5: [],
    6: [8],
    7: [],
    8: [],
    9: [10],
    10: []
}
"""
visualization 

     8       10
     ^        ^
    /        /
7  6        9
^  ^        ^
|/         /
1 -> 2 -> 3 -> 4 -> 5


"""


S = {
    3: [4],
    4: [5],
}

print(is_subgraph_present(G, S))  # Output: True

S2 = {
    2: [4],
    4: [5]
}

print(is_subgraph_present(G, S2))  # Output: False

S3 = {
    2: [3],
    3: [9],
    9: [10]
}

print(is_subgraph_present(G, S3))  # Output: True
 