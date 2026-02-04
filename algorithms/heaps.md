Heap is a special case of balanced binary tree data structure where 
the root-node key is compared with its children and arranged accordingly.
Heap can be created differently with the same elements, but it must follow
properties listed below:

## Min Heap

Min Heap - where the value of the root node is less than or equal to either
of its children.

## Max Heap

Max Heap - where the value of the root node is more than or equal to either
of its children.

## Array

Heap can be implemented with an array. An element at index K, will have its
children on `2*K` and `2*K+1` indexes. A parent will be on `K / 2`.

## Asymptotics

We can insert and delete an element in a heap in O(log(n)) time.
Finding Maximum and Minimum can be done in O(1).
Deleting a root take O(log(n)) time to be restored.
Heap is not suited for finding an element.
Heap can be used to sort elements in O(nlog(n)) time, with heapsort.

---

Each level of the heap is ordered to the left, as seen in the picture.
[Heap](assets/heap.png)
