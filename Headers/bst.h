#ifndef _BST_INCLUDED_H_
#define _BST_INCLUDED_H_

#include <stdint.h>

typedef struct _tree_node_ TreeNode;

struct _tree_node_ {
  TreeNode      *left;
  TreeNode      *right;
  int32_t         data;
};

typedef struct _bst_ BST;

struct _bst_ {
  TreeNode      *root;
  uint32_t      mass;
};

BST                   bst_create(void);
uint32_t              bst_count(BST *);
BST*                  bst_add(BST *, int32_t);
uint8_t               bst_lookup(BST *, int32_t);
BST*                  bst_delete(BST *, int32_t);

void                  bst_inorder(BST *);
void                  bst_preorder(BST *);
void                  bst_postorder(BST *);
void                  bst_level_order(BST *);

uint32_t              bst_height(BST *);
uint32_t              bst_terminal_nodes(BST *);

int32_t               bst_max(const BST *);
int32_t               bst_min(const BST *);

void                  bst_ascending(BST *);
void                  bst_descending(BST *);

#endif /* _BST_INCLUDED_H_ */