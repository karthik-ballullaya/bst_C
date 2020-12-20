# BST implementation in C

[Queue library Link](https://github.com/karthik-ballullaya/queue_C)

### Functionalities
* Trivial Functionalities
    * Add a node to the bst tree
    * Count the number of nodes in the bst tree
    * Delete a node from the bst tree
    * Search a node in the bst tree
* BST traversal algorithms
    * inorder traversal
    * preorder traversal
    * postorder traversal
    * levelorder traversal
* BST metrics
    * find the height of the bst tree
    * find the number of nodes in the bst tree
* BST extermities
    * find the maximum node in the bst tree
    * find the minimum node in the bst tree
* BST sorting
    * ascending order
    * descending order

Compilation command: gcc -D QUEUE_CONTENT_TYPE="void*" -I [Address to Queue header] -I [Address to BST header] -g [Address to BST source] [Address to Queue source] -o [Address followed by the output file name]
Ex: gcc -D QUEUE_CONTENT_TYPE="void*" -I ..\..\Queue\Headers -I .\Headers -g .\Sources\*.c ..\..\Queue\Sources\queue.c -o .\Sources\main.exe