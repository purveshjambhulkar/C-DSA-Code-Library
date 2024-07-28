// for  a "i" th node in the heap the ----- this is for 1 based indexing 
// left child is at "2 * i" th position in the array
// right child is at "2 * i + 1 " th position in the array
// similary the parent node is at "i / 2" th position

// for 0th based indexing
// left = 2 * i + 1
// right = 2 * i + 2


// insertion in heap - max heap

// add the element to be inserted at the end of the array 
// then compare it with its parent 
// if the element is > then the parent then swap them 
// repeat until parent > element

//properties of the leaf node

// if the array is of size "n" then the leaf node of the heap are
// at the positions "n/2 + 1" to "n"