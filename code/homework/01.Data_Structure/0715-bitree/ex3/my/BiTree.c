// 3.写出二叉树的层次遍历代码。从左至右,从上至下,遍历每一个节点

#include"BiTree.h"

/*
create_tree_by_str:根据用户输入的字符串,建立一颗二叉树
返回值:
返回建立的二叉树的根节点的指针
*/
//const:不能通过str这个指针去修改str指向的值
BiTNode *create_tree_by_str(const char *str)
{
	BiTNode *root = NULL;//创建了一颗空树
	BiTNode *pi = NULL;//指向新创建的结点
	
	while(*str) //str指向不为NULL
	{
		//把字符串中的字符拿出来
		//创建一个结点保存字符的值(用户数据)
		pi = (BiTNode *)malloc(sizeof(BiTNode));
		pi->data = *str++; //===>*str;str++
		pi->lchild = pi->rchild = NULL;

		//把创建的结点插入二叉排序树
		if(root == NULL)
		{
			root = pi;
		}else
		{
			//找插入位置(遍历root表示的二叉树,找到一个合适的位置)
			//pi成为查找路径上面最后一个结点的左子或者右子
			//pr记录查找路径上面最后一个结点的指针
			BiTNode *p = root;//遍历使用的指针
			BiTNode *pr = root;//遍历使用的指针
			while(p)
			{
				if(p->data < pi->data) //当前结点的值小于待插入结点的值(往右走)
				{
					pr = p; //记录p的父节点
					p = p->rchild;
				}
				else if(p->data > pi->data)
				{
					pr = p;
					p = p->lchild;
				}else
				{
					free(pi);
					break;
				}
			}
			//p肯定为NULL,pr指向路径上面最后一个结点
			//pi放到p的位置
			if(pi->data > pr->data)
			{
				pr->rchild = pi;
			}else if(pi->data < pr->data)
			{
				pr->lchild = pi;
			}
		}
	}
	return root;
}

//把元素e插入到t表示的二叉树中
BiTNode *insert_node_to_tree(BiTNode *t,TElemType e)
{
	BiTNode *pi = NULL;
	//创建结点保存e的值
	pi = (BiTNode *)malloc(sizeof(BiTNode));
	pi->data = e;
	pi->lchild = pi->rchild = NULL;
	//把结点插入t表示的二叉树
	//把创建的结点插入二叉排序树
	if(t == NULL)
	{
		t = pi;
	}else
	{
		//找插入位置(遍历root表示的二叉树,找到一个合适的位置)
		//pi成为查找路径上面最后一个结点的左子或者右子
		//pr记录查找路径上面最后一个结点的指针
		BiTNode *p = t;//遍历使用的指针
		BiTNode *pr = t;//遍历使用的指针
		while(p)
		{
			if(p->data < pi->data) //当前结点的值小于待插入结点的值(往右走)
			{
				pr = p; //记录p的父节点
				p = p->rchild;
			}
			else if(p->data > pi->data)
			{
				pr = p;
				p = p->lchild;
			}else
			{
				free(pi);
				break;
			}
		}
		//p肯定为NULL,pr指向路径上面最后一个结点
		//pi放到p的位置
		if(pi->data > pr->data)
		{
			pr->rchild = pi;
		}else if(pi->data < pr->data)
		{
			pr->lchild = pi;
		}
	}
	return t;
}

//按层次遍历t指向的那棵二叉树
void level_order(BiTNode *t)
{
	if(t == NULL)
	{
		return;
	}
	//利用队列
	SqQueue *s = InitQueue(4096);
	int level[4096] = {0};
	//约定访问一个结点后,让它入队列
	//访问根节点并且入队
	printf("%c ",t->data);
	EnQueue(s,t);	
	int i=0,j=0;
	level[j] = 1;
	j++;
	while(!QueueIsEmpty(s))//队列不为NULL
	{
		//出队列,
		BiTNode *x = NULL; //存储出队元素  NULL(0x0)
		DeQueue(s,&x);
		//在调用函数后,x就指向出队元素(保存出队指针)		
		//访问出队元素的左子结点和右子结点,访问完需要入队
		if(x->lchild)
		{
			printf("%c ",x->lchild->data);
			EnQueue(s,x->lchild);	
			level[j++] = level[i]+1;
		}
		if(x->rchild)
		{
			printf("%c ",x->rchild->data);
			EnQueue(s,x->rchild);
			level[j++] = level[i]+1;
		}
		i++;
	}
	for(i=0;i<j;i++)
	{
		printf("%d ",level[i]);
	}
	printf("\n");
}
	
	





