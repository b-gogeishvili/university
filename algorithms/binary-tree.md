A binary tree is a tree where each node has no more than 2 children.

### Binary Search Tree

BST has 3 properties:

1. Each node's subsegment is a binary tree as well.
2. Root node should be greater than the left child.
3. Root node should be less than the right child.

In a BST, leftmost child should be the least value. And the rightmost child
should be the greatest value.

---

To find a value in BST, we compare it to the root value first. If it is less
than the root value, we go to the left side of the tree. If it is greater than
the root value, we go to the right side of the tree, and so on.

BST is a data structure, which can do following operations in O(h) time,
where h is a height of a tree:
search; 
insertion;
deletion;
find minimum;
find maximum;
find next element;
find last element;

### BST Insert

Start from root. Always insert as leaf.

### BST Delete

3 possible cases: leaf, 1 child, 2 children.

1. We simply delete a leaf without breaking BST structure.
2. If a node has a child, we delete the node and write child in its place.
3. In case of 2 children, we replace node with smallest node in the
   right subtree (Inorder Successor).

## Traversing a BST

### PREORDER

Parent, left child, right child.

### POSTORDER

Left child, right child, parent.

### INORDER

Left child, parent, right child.

