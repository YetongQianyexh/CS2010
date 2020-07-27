#ifndef __BI_TREE_H__
#define __BI_TREE_H__

#include<stdio.h>
#include<stdlib.h>
#include"SqQueue.h"


//类型的定义和函数的声明
typedef int TElemType; //二叉树中用户数据类型为int
//二叉树的结点类型
typedef struct BiTNode
{
	TElemType data;//用户数据类型
	struct BiTNode *lchild; //指向它的左子结点
	struct BiTNode *rchild;//指向它的右子结点
}BiTNode;

/*
create_tree_by_str:根据用户输入的字符串,建立一颗二叉树
返回值:
返回建立的二叉树的根节点的指针
*/
BiTNode *create_tree_by_str(const char *str);

//把元素e插入到t表示的二叉树中
BiTNode *insert_node_to_tree(BiTNode *t,TElemType e);


//先序遍历二叉树
void pre_order(BiTNode *t);

//中序遍历二叉树
void mid_order(BiTNode *t);

//后序遍历二叉树
void last_order(BiTNode *t);

//层次遍历t表示的二叉树
void level_order(BiTNode *t);

//求二叉树的高度
int hight_tree(BiTNode *t);

/*
delete_x:在t指向的二叉树中删除一个元素x
返回值:返回删除后的二叉树的根节点指针
*/
BiTNode *delete_x(BiTNode *t,TElemType x);

int Binary_Sort_Tree(BiTNode *n);
int max_lchild(BiTNode *n);
int min_rchild(BiTNode *n);

int BinaryTreeHigh(BiTNode* root);
int IsBalancedTree_1(BiTNode* root);
int IsBalancedTree_2(BiTNode* root, int *depth);
int Complete_Binary_Tree(BiTNode *t);

int Balance_Binary_Tree(BiTNode *n);

int Full_Binary_Tree(BiTNode *n);
#endif




