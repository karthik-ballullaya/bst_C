#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include "bst.h"

void populate_tree(BST *tree) {
  tree = bst_add(tree, 50);
  tree = bst_add(tree, 20);
  tree = bst_add(tree, 90);
  tree = bst_add(tree, 25);
  tree = bst_add(tree, 70);
  tree = bst_add(tree, 60);
  tree = bst_add(tree, 85);
  tree = bst_add(tree, 35);
  tree = bst_add(tree, 10);
}

void test_bst_trivial() {
  BST b = bst_create(), *tree = &b;
  assert(bst_count(tree) == 0);
  populate_tree(tree);
  assert(bst_count(tree) == 9);
  assert(bst_lookup(tree, 90));
  assert(!bst_lookup(tree, 75));
  tree = bst_delete(tree, 90);
  assert(!bst_lookup(tree, 90));
  assert(bst_count(tree) == 8);
}

void test_bst_traversals() {
  BST b = bst_create(), *tree = &b;
  populate_tree(tree);
  bst_inorder(tree);  // left print right
  bst_preorder(tree); // print left right
  bst_postorder(tree); // left right print
  bst_level_order(tree); // level by level
}

void test_bst_counts() {
  BST b = bst_create(), *tree = &b;
  populate_tree(tree);
  assert(bst_height(tree) == 4);
  assert(bst_terminal_nodes(tree) == 4);
}

void test_bst_extermities() {
  BST b = bst_create(), *tree = &b;
  populate_tree(tree);
  assert(bst_max(tree) == 90);
  assert(bst_min(tree) == 10);
}

void test_bst_arrangement() {
  BST b = bst_create(), *tree = &b;
  populate_tree(tree);
  bst_ascending(tree);
  bst_descending(tree);
}

void main() {
  test_bst_trivial();
  test_bst_traversals();
  test_bst_counts();
  test_bst_extermities();
  test_bst_arrangement();
}