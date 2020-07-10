#include "tree_yunslee.h"

int cmp_int(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}
 
t_tree *tree_init(int (*cmp)(void *, void *))
{
	t_tree * admin;
	admin = malloc(sizeof (t_tree));
	admin->cmp = cmp;
	admin->root = NULL;
	admin->size = 0;
	return (admin);
}

t_node *create_elem(void *data)
{
	if (data == NULL)
		return (NULL);
	t_node *new;
	new = malloc(sizeof(t_node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int	tree_size(t_tree *tree)
{
	if (tree == NULL)
	 	return -1;
	return (tree->size);
}

t_node *tree_find(t_tree *tree, void *data_ref)
{
	if (tree == NULL || tree->size == 0)
		return (NULL);
	t_node *node = tree -> root;
	
	while (node)
	{
		if (tree->cmp(node->data, data_ref) == 0)
			return (node);
		else if (tree->cmp(node->data, data_ref) > 0)
			node= node->left;
		else if (tree->cmp(node->data, data_ref) < 0)
			node= node->right;
	}
	// printf("what?\n");
	return (NULL);
}

void tree_insert_sub(t_tree *tree, void *data)
{
	t_node *node;

	node = tree->root;
	while (node && tree->size != 0)
	{
		if (tree->cmp(node->data, data) > 0 && node->left != NULL)
			node= node->left;
		else if (tree->cmp(node->data, data) > 0 && node->left == NULL)
		{
			node->left = create_elem(data);
			return ;
		}
		else if (tree->cmp(node->data, data) < 0 && node->right != NULL)
			node= node->right;
		else if (tree->cmp(node->data, data) < 0 && node->right == NULL)
		{
			node->right = create_elem(data);
			return ;
		}
	}
}

int tree_insert(t_tree *tree, void *data)
{
	if (tree == NULL || data == NULL || tree_find(tree,data) != NULL)
		return (0);
	else if (tree->size == 0)
		tree->root = create_elem(data);//when first node is added
	tree_insert_sub(tree, data);
	tree->size++;
	return (1);
}
	
t_node *tree_rightside_min(t_node *sub_tree)
{
	t_node *node;

	node = sub_tree->right;
	if (node == NULL)
		return (NULL);
	while (node->left != NULL)
	{
		node = node->left;
	}
	return (node);
}

t_node *tree_leftdirection_beforeleaf(t_node *sub_tree, t_node *right_min)
{
	t_node *node;
	
	node = sub_tree->right;
	if (node == NULL)
		return (NULL);
	else if (node == right_min)
		return(sub_tree);
	while (node->left != right_min)
	{
		node = node->left;
	}
	return (node);
}

t_node *tree_leftside_max(t_node *sub_tree)
{
	t_node *node;
	
	node = sub_tree->left;
	if (node == NULL)
		return (NULL);
	while (node->right != NULL)
	{
		node = node->right;
	}
	return (node);
}

t_node *tree_rightdirection_beforeleaf(t_node *sub_tree, t_node *left_max)
{
	t_node *node;
	
	node = sub_tree->left;
	if (node == NULL)
		return (NULL);
	else if (node == left_max)
		return(sub_tree);
	while (node->right != left_max)
	{
		node = node->right;
	}
	return (node);
}

void tree_delete_root(t_tree *tree, void (*free_data)(void *))
{
	free_data(tree->root->data);
	tree->root->left = NULL;
	tree->root->right = NULL;
	free(tree->root);
	tree->root = NULL; //Mac에서는 error가 날 수도 있음.
}

t_node *tree_find_both(t_tree *tree, void *data_ref, t_node **node_before, char *flag)
{
	if (tree == NULL || tree->size == 0)
		return (NULL);
	t_node *node;
	
	node = tree -> root;
	*node_before = NULL;
	while (node)
	{
		if (tree->cmp(node->data, data_ref) == 0)
			return (node);
		else if (tree->cmp(node->data, data_ref) > 0)
		{
			*node_before = node;
			node= node->left;
			*flag = left_flag;
		}
		else if (tree->cmp(node->data, data_ref) < 0)
		{
			*node_before = node;
			node= node->right;
			*flag = right_flag;
		}
	}
	return (NULL);
}

void delete_node_has_right(t_tree *tree, t_node *del_node, t_node *del_before, t_node *leaf_node, t_node *leaf_before, char flag)
{
	if (del_node == tree->root)
	{
		tree->root = leaf_node;
		leaf_before->left = NULL;
		leaf_node->left = del_node->left;
		if (leaf_before != del_node)
		{
			leaf_before->left = leaf_node->right;
			leaf_node->right = del_node->right;
		}
		return ;
	}
	
	if (flag == left_flag)
		del_before->left = leaf_node;
	else
		del_before->right = leaf_node;
		
	leaf_node->left = del_node->left;
	if (leaf_before != del_node)
	{
		leaf_before->left = NULL;
		leaf_before->left = leaf_node->right;
		leaf_node->right = del_node->right;
	}
}

void delete_node_has_left(t_tree *tree, t_node *del_node, t_node *del_before, t_node *leaf_node, t_node *leaf_before, char flag)
{
	if (del_node == tree->root)
	{
		tree->root = leaf_node;
		leaf_before->right = NULL;
		leaf_node->right = del_node->right;
		if (leaf_before != del_node)
		{
			leaf_before->right = leaf_node->left;
			leaf_node->left = del_node->left;
		}
		return ;
	}
	
	if (flag == left_flag)
		del_before->left = leaf_node;
	else
		del_before->right = leaf_node;
		
	leaf_before->right = NULL;
	leaf_node->right = del_node->right;
	if (leaf_before != del_node)
	{
		leaf_before->right = leaf_node->left;
		leaf_node->left = del_node->left;
	}
}

void tree_delete_sub(t_tree *tree, void *data_ref, void (*free_data)(void *))
{
	t_node *del_node;
	t_node *del_before;
	t_node *leaf_node;
	t_node *leaf_before;
	char flag = -1; //초기상태 OR size == 1
	
	del_before = NULL;
	if (tree->size == 1) //tree->root = NULL이 되기때문에 따로 처리
	{
		tree_delete_root(tree, free_data);
		return ;
	}
	del_node = tree_find_both(tree, data_ref, &del_before, &flag);
	if (del_node->right != NULL)
	{
		leaf_node = tree_rightside_min(del_node);
		leaf_before = tree_leftdirection_beforeleaf(del_node, leaf_node);/*여기서 최소값을 가진 node를 찾아야하는데 이건 삭제하려는 node의 child 왼쪽 오른쪽 둘다 구하는 함수를 정립하고 선택해서 사용할 수 있도록 해야함*/
		delete_node_has_right(tree, del_node, del_before, leaf_node, leaf_before, flag);
	}
	else if (del_node->left != NULL && del_node->right == NULL)
	{
		leaf_node = tree_leftside_max(del_node);
		leaf_before = tree_rightdirection_beforeleaf(del_node, leaf_node);
		delete_node_has_left(tree, del_node, del_before, leaf_node, leaf_before, flag);
	}
	else if (del_node->right == NULL && del_node->left == NULL)
	{
		// printf("-----debug line ----\n");
		if (tree_size(tree) == 1)
			tree->root = NULL;
		else
		{
			if (flag == left_flag)
				del_before->left = NULL;
			else
				del_before->right = NULL;
		}
	}
	del_node->left = NULL;
	del_node->right = NULL;
	free_data(del_node->data);
	free(del_node);
	return ;
}
	
int tree_delete(t_tree *tree, void *data_ref, void (*free_data)(void *))
{
	if (tree == NULL || data_ref == NULL || tree->size == 0 || tree_find(tree,data_ref) == NULL)
	{
		// printf("Can't delete data!\n");
		return (0);
	}
	//단락 평가(short-circuit evalution) 때문에 tree_find에 중복되는 논리연산 (tree->size==0)을 추가해주었다.
	tree_delete_sub(tree, data_ref, free_data);
	tree->size--;
	return (1);
}

//tree 전체 탐색....
void tree_recursive(t_node *node, void (*free_data)(void *))
{
	static int i = 0;
	
	if (node == NULL)
		return ;
	if (node->left != NULL)
	{
		tree_recursive(node->left, free_data);
	}
	else if (node->right != NULL)
	{
		tree_recursive(node->right, free_data);
	}
	free_data(node->data);
	free(node);
	return ;
}

void free_tree(t_tree *tree, void (*free_data)(void *))
{
	t_node *node;
	
	if (tree == NULL || free_data == NULL)
		return ;
	node = tree->root;
	tree_recursive(node, free_data);
	//
	tree->cmp = NULL;
	tree->size = 0;
	tree->root = NULL;
	free(tree);
	return ;
}