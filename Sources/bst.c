#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "bst.h"
#include "../../../Queue/Headers/queue.h"

BST bst_create() {
  return (BST) {NULL, 0};
}

uint32_t bst_count(BST *tree) {
  assert(tree != NULL);
  return tree->mass;
}

static TreeNode *_get_new_node_(int32_t data) {
  TreeNode *node = (TreeNode *) (malloc(sizeof(TreeNode)));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

BST * bst_add(BST *tree, int32_t data) {
  assert(tree != NULL);
  TreeNode *parent = tree->root, *current = tree->root;
  while(current != NULL && current->data != data) {
    parent = current;
    if (data < current->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }

  if(current == NULL) {
    TreeNode *newNode = _get_new_node_(data);
    if (parent == NULL) {
      tree->root = newNode;
    } else if (data < parent->data) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }
    tree->mass++;
  }
  return tree;
}

uint8_t bst_lookup(BST *tree, int32_t data) {
  TreeNode *node = tree->root;
  while (node != NULL && node->data != data) {
    if (data < node->data) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return (node != NULL);
}

static TreeNode *_find_max_(TreeNode *node) {
  if (node->right == NULL) {
    return node;
  }
  return _find_max_(node->right);
}

static TreeNode *_delete_(BST *tree, TreeNode *node, int32_t data) {
  TreeNode *temp;
  if (node == NULL) {
    return node;
  }
  if (data < node->data) {
    node->left = _delete_(tree, node->left, data);
  } else if (data > node->data) {
    node->right = _delete_(tree, node->right, data);
  } else if (node->right && node->left) { // delete node having 2 children
    temp = _find_max_(node->left);
    node->data = temp->data;
    node->left = _delete_(tree, node->left, node->data);
  } else {
    temp = node;
    if (node->right == NULL) {
      node = node->left;
    } else {
      node = node->right;
    }
    free(temp);
    tree->mass--;
  }
  return node;
}

BST* bst_delete(BST *tree, int32_t data) {
  // replace with the inorder predecessor
  assert(tree != NULL);
  tree->root =  _delete_(tree, tree->root, data);
  return tree;
}

static void _inorder_(TreeNode *node) {
  if (node) {
    _inorder_(node->left);
    printf("%d\t", node->data);
    _inorder_(node->right);
  }
}

void bst_inorder(BST *tree) {
  printf("Inorder arrangement: ");
  _inorder_(tree->root);
  printf("\n");
}

static void _preorder_(TreeNode *node) {
  if (node) {
    printf("%d\t", node->data);
    _preorder_(node->left);
    _preorder_(node->right);
  }
}

void bst_preorder(BST *tree) {
  printf("Preorder arrangement: ");
  _preorder_(tree->root);
  printf("\n");
}

static void _postorder_(TreeNode *node) {
  if (node) {
    _postorder_(node->left);
    _postorder_(node->right);
    printf("%d\t", node->data);
  }
}

void bst_postorder(BST *tree) {
  printf("Postorder arrangement: ");
  _postorder_(tree->root);
  printf("\n");
}

void bst_level_order(BST *tree) {
  Queue q1 = queue_new(bst_count(tree)), *q = &q1;
  QueueResult result;
  TreeNode *node = tree->root;
  printf("Levelorder arrangement: ");
  queue_add(q, node, &result);
  while (!queue_empty(q)) {
    queue_delete(q, &result);
    node = (TreeNode *)result.data;
    if (node->left) {
      queue_add(q, node->left, &result);
    }
    if (node->right) {
      queue_add(q, node->right, &result);
    }
    printf("%d\t", node->data);
  }
  printf("\n");
}


static uint32_t _height_(const TreeNode *node) {
  if (node) {
    uint32_t left_height = _height_(node->left);
    uint32_t right_height = _height_(node->right);
    return 1 + ((left_height > right_height) ? left_height : right_height);
  }
  return 0;
}

uint32_t bst_height(BST *tree) {
  return _height_(tree->root);
}


uint32_t bst_terminal_nodes(BST *tree) {
  uint32_t terminal_node_count = 0;
  Queue q1 = queue_new(bst_count(tree)), *q = &q1;
  QueueResult result;
  TreeNode *node = tree->root;
  queue_add(q, node, &result);
  while (!queue_empty(q)) {
    queue_delete(q, &result);
    node = (TreeNode *)result.data;
    if (node->left) {
      queue_add(q, node->left, &result);
    }
    if (node->right) {
      queue_add(q, node->right, &result);
    }
    if ((node->left == NULL) && (node->right == NULL)) {
      terminal_node_count++;
    }
  }
  return terminal_node_count;
}


int32_t bst_max(const BST *tree) {
  TreeNode *node = tree->root;
  for (; node->right != NULL; node = node->right);
  return node->data;
}

int32_t bst_min(const BST *tree) {
  TreeNode *node = tree->root;
  for (; node->left != NULL; node = node->left);
  return node->data;
}

void bst_ascending(BST *tree) {
  printf("Ascending arrangement: ");
  _inorder_(tree->root);
  printf("\n");
}


static void _reverse_inorder_(TreeNode *node) {
  if (node) {
    _reverse_inorder_(node->right);
    printf("%d\t", node->data);
    _reverse_inorder_(node->left);
  }
}

void bst_descending(BST *tree) {
  printf("Descending arrangement: ");
  _reverse_inorder_(tree->root);
  printf("\n");
}