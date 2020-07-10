
#ifndef TREE_H
# define TREE_H
# include <stdio.h>
# include <stdlib.h>
# define left_flag 0
# define right_flag 1

typedef struct	s_node
{
	void		*data;
	struct s_node	*left;
	struct s_node	*right;
	//struct s_node *back; 이 있으면 tree_delete에서 훨씬 코딩이 쉬워질 수 있다.
}		t_node;

typedef struct	s_binary_search_tree
{
	t_node	*root;
	int	(*cmp)(void *, void *);
	int	size;
}		t_tree;

int cmp_int(void *a, void *b);
t_tree *tree_init(int (*cmp)(void *, void *));
t_node *create_elem(void *data);
int	tree_size(t_tree *tree);
t_node *tree_find(t_tree *tree, void *data_ref);
int tree_insert(t_tree *tree, void *data);
void tree_insert_sub(t_tree *tree, void *data);

t_node *tree_rightside_min(t_node *sub_tree);
t_node *tree_leftdirection_beforeleaf(t_node *sub_tree, t_node *right_min);
t_node *tree_leftside_max(t_node *sub_tree);
t_node *tree_rightdirection_beforeleaf(t_node *sub_tree, t_node *left_max);
void tree_delete_root(t_tree *tree, void (*free_data)(void *));
t_node *tree_find_both(t_tree *tree, void *data_ref, t_node **node_before, char *flag);
void delete_node_has_right(t_tree *tree, t_node *del_node, t_node *del_before, t_node *leaf_node, t_node *leaf_before, char flag);
void delete_node_has_left(t_tree *tree, t_node *del_node, t_node *del_before, t_node *leaf_node, t_node *leaf_before, char flag);
void tree_delete_sub(t_tree *tree, void *data_ref, void (*free_data)(void *));
int tree_delete(t_tree *tree, void *data_ref, void (*free_data)(void *));

void tree_recursive(t_node *node, void (*free_data)(void *));
void free_tree(t_tree *tree, void (*free_data)(void *));
#endif
