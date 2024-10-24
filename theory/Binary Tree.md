Binary Tree is a simple data structure. We have a topmost node, which we will call **root** and two, thus the name "binary", subsequent nodes which we will call **leaves**, if they are at the end of our tree. Those nodes are named **left child**, and **right child** of the parent upper node.

All nodes **stores** just **data and the pointer to the following two leaves**.
If we want to express it in code, using python, for example, we could just represent them as:
```
class Node:
	def __init__(self, key):
		self.left = None
		self.right = None
		self.value = key
```

If we want to define, we would just need to point out to these 2 attributes, right and left, to build our tree.

This would summarize the data structure terminology and visualization.
Also, for complement:
- Leaf node -> Do not have any child.
- Parent node -> Has at least on child.
	- Internal node -> Has at least one child. (Not root)
- Depth -> Distance from the root node -> Number of edges to there.
	- The deepest are at the higher levels -> Leaves.
![[Binary tree terms.png]]

# Summary of Binary Tree Types

### Based on the Number of Children

- **Full Binary Tree:** Every node has either 0 or 2 children.
- **Degenerate Binary Tree:** Every node has only one child or no child.
    - **Skewed Binary Trees:** A degenerate tree where all nodes are on one side.

### Based on Completion of Levels

- **Complete Binary Tree:** All levels are filled except possibly the last level, and all nodes on the last level are as far left as possible.
- **Perfect Binary Tree:** A complete binary tree where all levels are filled.
- **Balanced Binary Tree:** The height of the left and right subtrees of any node differ by at most 1.

### Based on Node Values

- **Binary Search Tree:** For every node, the values in its left subtree are less than its value, and the values in its right subtree are greater.
- **AVL Tree:** A self-balancing binary search tree where the heights of the left and right subtrees of any node differ by at most 1. 
- **Red-Black Tree:** A self-balancing binary search tree that uses a coloring scheme (red and black) to maintain balance.
- **B Tree:** A self-balancing tree that can store more than one key in each node.
- **B+ Tree:** A variant of the B tree where all data is stored in leaf nodes, and internal nodes only store keys for searching.
- **Segment Tree:** A data structure used to efficiently perform range queries on an array.


# Operations
## Traversal 
**Traversal -> visiting all nodes**
#### **DFS** - Depth First Search
Visits all nodes by deepening to the highest level before backtracking and then visiting others
- **Preorder Traversal** (**CURRENT -> LEFT -> RIGHT**) -> Left subtree, then the right subtree
- **Inorder Traversal** (**CURRENT -> RIGHT -> LEFT**) -> Right subtree, then the left subtree
- **Postorder Traversal** (**LEFT -> RIGHT -> CURRENT**) -> It will explore the current node just after exploring the subtrees.

#### BFS - Breadth First Search
Visits all the nodes on the same level before deepening. (Also called **Level Order Traversal**)

## Addition and Removal of Elements

### Addition (Insertion)
If we want to add something, it will depend entirely on us which order, or where we will add it. On the approach below represented, i imagined an algorithm that searched from left to right with an BFS approach, find the lowest level, searching from left to right to fill an spot. That was the way i thought about that. But we can structure it in many ways. Basically, it will depend on what we are actually thinking about implementing. 
![[Binary tree additon.png]]

So, what we could do would be:
```
# ==== OUR TREE ====
"""
Our tree:
    ____A
____B___       
C       D
"""

A = Node("A")
B = Node("B")
C = Node("C")
D = Node("D")

A.left = B
B.left = C
B.right = D
# =================

# To add
E = Node("E")

def addition(root, node_to_add):
    to_visit = [root]
    next = []

    added = False
    while not added:
        for node in to_visit:
            if node.left == None:
                node.left = node_to_add
                added = True
                break
            else:
                next.append(node.left)

            if node.right == None:
                node.right = node_to_add
                added = True
                break
            else:
                next.append(node.right)
        
        to_visit = next

addition(A, E)
print(E == A.right)
```

This code is **not meant to be fast**, but it is just to show the fundamentals of what i am talking about.

### Deletion (Removal)
If we want to remove an element, it will do it by prioritizing substituting the node with one of the right or left subtrees, depending on the algorithm. Besides that, the focus of the process of deletion is to do that while we maintain our tree structure.
For the algorithm below, we will do something kinda different, but it's just to show.