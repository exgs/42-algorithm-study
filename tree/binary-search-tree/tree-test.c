#include "tree.h"

void print_admin_tree(t_tree *admin)
{
	if (admin == NULL)
	{
		printf("tree is NULL");
		return ;
	}
	else if (admin->root == NULL || admin->size == 0)
	{
		printf("root is NULL(size == 0)\n");
		return ;
	}
	printf("tree size = %d\n", tree_size(admin));
	printf("tree root data = %d\n", *(int *)admin->root->data);
	printf("-----------------------------------------\n");
	return ;
}

void print_recursive_tree(t_node *node)
{
	if (node == NULL)
	{
		printf("root is NULL\n");
		return ;
	}
	if (node->left != NULL)
	{
		print_recursive_tree(node->left);
		// printf("=================\n");
	}
	else if (node->right != NULL)
	{
		// printf("node address : %p\n", node);
		print_recursive_tree(node->right);
	}
	printf("(In recursive)node data : %d\n",*(int *)node->data);
	// printf("-=-=-=-=-=-=-=-=-=-=-\n");
	return ;
}

void print_all_tree(t_tree *admin)
{
	if (admin == NULL)
		return ;
	t_node *node;

	node = admin->root;
	print_recursive_tree(node);
}

int main()
{
	int num[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	t_tree *admin = tree_init(cmp_int);
	
	//tree_delete 에러처리
	
	print_admin_tree(admin);
	print_all_tree(admin);
	printf("---------------------\n");
	printf("num[] %d %p\n", num[0], &num[0]);
	
	printf("---------Insert debugging-----------\n");
	for (size_t i = 0; i < 10; i++)
	{
		printf("tree insert Success: %d\n", tree_insert(admin, &(num[i])));
		printf("tree_find : %d Anser : %d\n",num[i], *((int *)tree_find(admin, &num[i])->data));
		print_all_tree(admin);
		print_admin_tree(admin);
	}
	print_admin_tree(admin);
	int z = 5;
	printf("tree_find : %d Anser : %d\n",num[z], tree_find(admin, &num[z]) ? *((int *)tree_find(admin, &num[z])->data) : -1);
	printf("---------Delete debugging-----------\n");
	
	// printf("tree delete Success: %d\n", tree_delete(admin, &num[8], free));
	// printf("tree delete Success: %d\n", tree_delete(admin, &num[7], free));
	// printf("tree delete Success: %d\n", tree_delete(admin, &num[9], free));
	// printf("tree_find : %d Anser : %d\n",num[5], tree_find(admin, &num[5])->data ? *((int *)tree_find(admin, &num[5])->data) : -1);
	// for (int i = 9; i >= 0; i--)
	for (int i = 0; i < 10; i++)
	{
		printf("tree delete Success: %d\n", tree_delete(admin, &num[i], free));
		// printf("tree_find : %d Anser : %d\n",num[i], tree_find(admin, &num[i])->data ? *((int *)tree_find(admin, &num[i])->data) : -1);
		print_all_tree(admin);
		print_admin_tree(admin);
		printf("---------------------\n");
	}
	print_all_tree(admin);
	print_admin_tree(admin);
	printf("---------------------\n");
	
	printf("---------------------\n");
	free_tree(admin, free);
}