/*
 * Today’s task: Dynamic List page  6
 * Create a function that prints out the linked list
 *   you should send the head pointer to the function
 *   void print(struct Student *student);
 * Create functions that
 *  - Add more nodes to the list
 *  - Search the node using a number – i.e. output the 4th person in the list
 *  - Search for a node that compares to a name in the list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 学生结构，最后用一个struct Student *next指针指向下一个学生
struct Student {
	char name[30];
	int id;
	struct Student *next;
};

// 链表结构，存储链表头、尾 和 学生总数
struct Linklist {
	// 存储链表中有多少个学生
	int len;
	// 学生指针，指向链表开头
	struct Student *phead;
	// 学生指针，指向链表结尾
	struct Student *ptail;
};

// 传入一个学生指针，然后打印出这个学生和之后的所有学生
void print(struct Student *student);
// 传入链表，姓名和id，将新学生添加到链表尾部
void add(struct Linklist *linklist, char name[], int id);
// 返回链表中第x位学生
struct Student *search_i(struct Linklist *linklist, int i);
// 在链表中查找姓名匹配的学生，返回该学生的指针
struct Student *search_name(struct Linklist *linklist, char name[]);

int main() {
	// 声明链表
	struct Linklist linklist;
	// 将链表初始化为空
	// （如果只声明不初始化，链表中会包含随机数据）
	linklist.phead = NULL;
	linklist.ptail = NULL;
	linklist.len = 0;
	printf("输出空链表\n");
	// 传入学生指针
	print(linklist.phead);
	printf("添加几个奇怪的学生\n");
	add(&linklist, "Miku", 39);
	add(&linklist, "Rin", 23);
	add(&linklist, "Len", 32);
	add(&linklist, "Ruka", 666);
	printf("输出链表\n");
	print(linklist.phead);
	printf("链表中第四个学生：");
	struct Student *p = search_i(&linklist, 4);
	printf("姓名：%s, ID：%d\n", p->name, p->id);
	printf("链表中姓名为'Miku'的学生：");
	p = search_name(&linklist, "Miku");
	printf("姓名：%s, ID：%d\n", p->name, p->id);
}
void print(struct Student *student) {
	// 判断指针是否为空
	while (student != NULL) {
		// 指针不指向空则输出学生信息
		printf("Name: %s, ID: %d\n", student->name, student->id);
		// 指针指向下一个学生
		student = student->next;
	}
}

void add(struct Linklist *linklist, char name[], int id) {
	// 声明一个指针，并用它指向新分配的内存
	struct Student *newStudent = (struct Student*)malloc(sizeof(struct Student));
	// 如果指针为空，则说明内存分配失败
	if  (newStudent == NULL) {
		printf("malloc error\n");
		return;
	}

	// 赋值
	newStudent->id = id;
	strcpy(newStudent->name, name);
	newStudent->next = NULL;
	
	// 特殊情况：链表为空
	if (linklist->len == 0) {
		linklist->phead = newStudent;
		linklist->ptail = newStudent;
		linklist->len = 1;
		// 结束
		return;
	}
	// 通常情况：链表不为空：将新学生添加到链表尾部
	// 链表中->最后一个学生->的下一个学生 = newStudent;
	linklist->ptail->next = newStudent;
	// 设置ptail指向newStudent;
	linklist->ptail = newStudent;
	// 数量+1
	linklist->len++;
}

struct Student *search_i(struct Linklist *linklist, int i) {
	// 第4个学生对应索引是3，所以i要减1
	i = i-1;
	// 范围检查
	if (i > linklist->len) {
		printf("out of range\n");
		return NULL;
	}
	struct Student *p = linklist->phead;
	// 将指针往前移动i次
	for (int x=0; x<i; x++) {
		p = p->next;
	}
	// 返回找到的学生（的指针）
	return p;
}

struct Student *search_name(struct Linklist *linklist, char name[]) {
	struct Student *p;
	for (p=linklist->phead; p; p=p->next) {
		if (strcmp(p->name, name) == 0) {
			return p;
		}
	}
	return NULL;
}
