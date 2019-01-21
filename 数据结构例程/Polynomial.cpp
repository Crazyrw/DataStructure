//#include"LinkList.cpp"   //如果想将LinkList.cpp直接包含进来使用，需要修改原文件中ElemType定义等相关操作，并将测试用的main函数注释掉。本文件将LinkList.cpp中的代码复制到下面，并对ElemType定义进行修改


//--------------------------------------------------------------------------------------------------------------------
//-------------------------------以下为LinkList.cpp中的代码，只是将ElemType的定义加以修改，且-----------------------------
//--------------------------------------------------------------------------------------------------------------------

//库函数头文件包含
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
typedef int  Status;


typedef struct{
	float coef;
	int expn;
}term,ElemType;

//改进的单链表存储结构定义
//typedef int ElemType;    //假设元素类型为int
typedef struct LNode{    //结点类型
	ElemType data;
	struct LNode *next;
}*Link,*Position;

typedef struct{          //链表类型
	Link head,tail;//头指针和尾指针
	int len;     //表长
}LinkList;


//链表基本操作的函数原型说明
/*如果此处省略则要注意函数的出现顺序，函数使用前必须已经被定义或声明，此处略去*/


//链表基本操作的实现
//结点类操作
Status MakeNode(Link &p,ElemType e){
	//分配由p指向的值为e的结点，并返回OK，若分配失败则返回ERROR；
	p=(Link)malloc(sizeof(LNode));
	if(!p)return ERROR;
	p->data=e;p->next=NULL;
	
	return OK;
}
void FreeNode(Link p){
	//释放p所指结点
	free(p);p=NULL;
}


//结构初始化和销毁操作
Status  InitList_L(LinkList &L){
    //初始化L为一个带头结点的空链表,头尾指针指向头结点，表长赋0
	ElemType e;
	e.coef=-1;e.expn=-1;
	if(!MakeNode(L.head,e))return ERROR;  //开辟头结点
	L.tail=L.head;L.len=0;
	return OK;
}//InitList_L

Status DestroyList_L(LinkList &L){
	//销毁链表L
	Link p;
	while(p=L.head->next){  //依次释放有序链表中第一个元素至最后一个元素所占用空间;
		L.head->next=p->next;
		FreeNode(p);
	}
	free(L.head);
	L.head=NULL;L.tail=NULL;L.len=0;
	return OK;
}//DestroyList_L
/*将所有元素结点及头结点释放，设表长为n，则共释放n+1个结点，时间复杂度为O(n)*/


//加工型操作
Status ClearList_L(LinkList &L){
	//链表L置空
	Link p;
	while(p=L.head->next){  //依次释放有序链表中第一个元素至最后一个元素所占用空间;
		L.head->next=p->next;
		FreeNode(p);
	}	
	L.tail=L.head;
	L.len=0;
	return OK;
}


Status InsFirst_L(LinkList &L,Link s){
	//将s所指结点插入到L的第一个元素结点前，头结点后
	s->next=L.head->next;
	L.head->next=s;
	if(L.len==0)L.tail=s;  //插入前为空表则尾指针相应改变
	++L.len;
	return OK;
}	
Status Append_L(LinkList &L,Link s){
	//在L的末尾追加一串由s指向的一串结点,尾指针与表长均改变
	L.tail->next=s;
	while(L.tail->next){L.tail=L.tail->next;L.len++;}
	return OK;
}
Status InsAfter_L(LinkList &L,Link &p,Link s){
	//已知p指向L中某个结点，将s所指结点插入到p所指结点后，并修改p使之指向新插入的结点，同时表长加1
	s->next=p->next;
	p->next=s;
	p=s;
	++L.len;
	if(p->next==NULL)L.tail=p;//若插入到表尾则尾指针应改变
	return OK;
}
Status InsBefore_L(LinkList &L,Link &p,Link s){
	//已知p指向L中某个结点，将s所指结点插入到p所指结点前，并修改p使之指向新插入的结点，同时表长加1
//因此操作为线性时间复杂度，且可用InsertAfter及其它操作替代，故不常用，此处略
	printf("InsBefore_L()  is to be implemented...\n");
	return ERROR;
}

Status DeleteFirst_L(LinkList &L,Link &q){
	//将L的第一个元素结点删除并以q返回，若L为空表则q赋空，返回ERROR
	if(!L.len){q=NULL;return ERROR;}
	if(L.len==1)L.tail=L.head;  //若删除后为空表则尾指针改变
	q=L.head->next;
	L.head->next=q->next;
	q->next=NULL;
	--L.len;
	return OK;

}
Status Remove_L(LinkList &L,Link &q){
	//删除L的尾结点并以q返回，同时改变尾指针
	//此操作为线性时间复杂度且能被DeleteAfter等操作取代，不常用，故略
	printf("Remove_L()  is to be implemented...\n");
	return ERROR;
}
Status DeleteAfter_L(LinkList &L,Link p,Link &q){
	//已知p指向L中某个结点，删除p所指结点后的结点并以q返回，同时表长减1
	if(!p->next){q=NULL;return ERROR;}
	if(p==L.head){DeleteFirst_L(L,q);return OK;}
	if(p->next==L.tail)L.tail=p;
	q=p->next;
	p->next=q->next;
	q->next=NULL;
	--L.len;
	return OK;
}
Status DeleteBefore_L(LinkList &L,Link p,Link s){
	//已知p指向L中某个结点，删除p所指结点前的结点以q返回，同时表长减1
//因此操作为线性时间复杂度，且可用DeleteAfter及其它操作替代，故不常用，此处略
	printf("DeleteBefore_L()  is to be implemented...\n");
	return ERROR;
}
Status SetCurElem_L(Link &p,ElemType e){
    //用e更新p所指向结点的数据域的值
	if(!p)return ERROR;
	p->data=e;
	return OK;
}


//引用型操作
Status ListEmpty_L(LinkList L){
	//判表空
	if(L.len)return TRUE;
	else return FALSE;
}
int ListLength_L(LinkList L){
	//求表长
	return(L.len);
}
ElemType GetCurElem_L(Link p){
	if(!p)exit(OVERFLOW);
	return p->data;
}

Position GetHead_L(LinkList L){
	//返回头结点的位置即头指针
	return L.head;
}
Position GetLast_L(LinkList L){
	//返回尾指针
	return L.tail;
}
Status LocatePos_L(LinkList L,int i,Link &p){
	//用p返回L中第i个元素结点的位置,i不合法时返回iERROR
	if(i<1||i>L.len){p=NULL;return ERROR;}
	Link q=L.head;  int j=0;
	while(p&&j<i){p=p->next;++j;}
	if(!p)return ERROR;  //实际i的取值范围判定已经避免了此种情况的发生
	else return OK;
}
Position PriorPos_L(LinkList L,Link p){
	//返回p所指向结点前的结点的位置
	//线性复杂度，不常用，略
	printf("PriorPos is to be implemented ...\n");
	return NULL;
}
Position NextPos_L(LinkList L,Link p){
	//返回L中p所指结点后的结点的指针;无后继则返回NULL
	return p->next;
}

/*具体应用中可能需要改写
Status SmallEqual(ElemType e1,ElemType e2){
	if(e1<=e2) return TRUE;
	else return FALSE;
}

Status equal(ElemType e1,ElemType e2){
	if(e1==e2) return TRUE;
	else return FALSE;
}*/
Position  LocateElem_L(LinkList L,ElemType e,Status (*cmp)(ElemType,ElemType)){
	//返回L中第一个与元素e满足关系cmp()的元素的位置，若不存在则返回NULL。实际应用时可适当修改使返回满足关系的元素的前驱	
	Link p=L.head;
	while(p&&!cmp(e,p->data))p=p->next;
	return p;
}

Position  LocateElemPrior_L(LinkList L,ElemType e,Status (*cmp)(ElemType,ElemType)){
	//返回L中第一个与元素e满足关系cmp()的元素的前驱的位置，若不存在则返回NULL。	
	Link p=L.head;
	while(p->next&&!(*cmp)(e,p->next->data))p=p->next;
	if(p->next)return p;
	else return NULL;
}


void PrintList_L(LinkList L){
 //依次输出有序顺序表L中的各个元素及表长
	Link p=L.head->next;
	printf("共%d个结点\n",L.len);
	while(p){printf("--%d--",*p);p=p->next;}
	printf("\n\n");
}

//测试用程序
/*

void main(){
	LinkList L;
	InitList_L(L);
    PrintList_L(L);
	if(!ListEmpty_L(L))printf("NULL");

	ElemType e1=5,e2=3,e3=6;
	Link p,q,s;
	if(MakeNode(p,e1)) InsFirst_L(L,p);
	PrintList_L(L);
	if(!ListEmpty_L(L))printf("NULL");
	if(MakeNode(q,e2))Append_L(L,q);
	PrintList_L(L);
	if(MakeNode(p,e3))InsAfter_L(L,q,p);
	PrintList_L(L);
	if(MakeNode(p,e3))InsAfter_L(L,q,p);
	PrintList_L(L);
	e1=GetCurElem_L(L.tail);
	printf("%d\n",e1);
	s=LocateElem_L(L,e1,equal);
	if(s)printf("%d",s->data);
	DeleteFirst_L(L,q);
	PrintList_L(L);
	DeleteAfter_L(L,L.head->next,q);
	printf("%d\n",q->data);
	PrintList_L(L);
        q=LocateElem_L(L,4,SmallEqual);
	printf("%d",q->data);
	q=LocateElemPrior_L(L,4,SmallEqual);  //定位到第一个满足e<=q->data的结点q的前驱

	printf("%d",q->data);
	q=GetLast_L(L);
	printf("%d",q->data);


	ClearList_L(L);
	PrintList_L(L);
	DestroyList_L(L);
}*/




//-----------------------------------------------------------------------------
//-------------------以下为多项式的类型定义及操作实现--------------------------
//------------------------------------------------------------------------------
//多项式链式存储结构定义
typedef LinkList  Polynomial;  //多项式类型的定义,采用链式存储结构

//多项式表示中的比较函数
Status SmallEqual(ElemType e1,ElemType e2){
	if(e1.coef<=e2.coef) return TRUE;
	else return FALSE;
}

Status equal(ElemType e1,ElemType e2){
	if(e1.coef==e2.coef) return TRUE;
	else return FALSE;
}


//各函数原型声明略


//各函数具体实现
int compare(ElemType e1,ElemType e2)
{ if(e1.expn<e2.expn)return -1;    else if(e1.expn==e2.expn)return 0;    else return 1;}

Status LocateElem(LinkList L,ElemType e,Link &q, Status(*cmp)(ElemType,ElemType)){
	//若L中存在与e指数相等(cmp返回0)的元素，则Locate返回TRUE,q指向第一个相等的元素；否则，Locate返回FALSE，此时，q指向第一个指数大于e(cmp大于0)的元素的前驱，若不存在大于e指数(cmp均小于0)的元素，则q指向尾结点

   q=L.head;
   while(q->next!=NULL&&cmp(q->next->data, e)<0)
	   q=q->next;
   if(q->next!=NULL&&cmp(e,q->next->data)==0){
	   q=q->next; 
	   return TRUE;
   }
   else
	   return FALSE; 
}

Status CreatePolyn(Polynomial &P,int n){
    
	InitList_L(P);  
	
	Link h=GetHead_L(P) ,s,q;
    term e; 
	e.coef=0; e.expn=-1; SetCurElem_L(h,e);//头结点赋值
    for(int i=1;i<=n;++i){   
		printf("第%d项的系数和指数为:\n",i); 
		scanf("%f,%d",&e.coef,&e.expn);
		 if(!LocateElem(P,e,q,compare))   //不存在与e指数相等的项  
		 {
			 if(MakeNode(s,e))
				 InsAfter_L(P,q,s);
			
		 }
		 else
		 {	 
			 printf("重复项！已被忽略。\n");--i;
		}
		 
		 
	}
	return OK;

}//CreatePolyn
ElemType Add(ElemType e1,ElemType e2){
	ElemType sum;
	sum.coef=e1.coef+e2.coef;
	sum.expn=e1.expn;
	return sum;
}
void PrintPolyn(Polynomial P){
	Link p=P.head->next;
	for(int i=1;i<=P.len;++i){
		printf("(%.2f+x^%-3d)+",p->data.coef,p->data.expn);p=p->next;
	}
	printf("\b");
}
void AddPolyn(Polynomial &Pa,Polynomial &Pb){
	//思路:设两指针qa与qb分别遍历Pa与Pb,比较当前两项,分三种情况:其一,Pa中项的指数小,则qa后移一项;  其二,两者指数相等,若系数相加和为零,此时从和多项式Pa中将该项删除(设prea),同时释放Pb中的当前项(设preb);若指数相等系数和不为0，则修改Pa中当前项的系数值,同时释放Pb的当前结点;  其三,Pb中指数小,则删除Pb中当前项，插入到Pa中当前项的前边。

	Link prea=GetHead_L(Pa),preb=GetHead_L(Pb);
	Link qa=NextPos_L(Pa,prea),qb=NextPos_L(Pb,preb);
	ElemType a,b;
	float sum;


	while(qa&&qb){
		a=GetCurElem_L(qa);b=GetCurElem_L(qb);
		//printf("%f+x^%d,   vs   ,%f+x^%d\n",a.coef,a.expn,b.coef,b.expn);
		switch(compare(a,b)){
 case -1:prea=qa;qa=NextPos_L(Pa,qa);
	 break;
 case 0: sum=a.coef+b.coef;
	 if(sum){SetCurElem_L(qa,Add(qa->data,qb->data));prea=qa;qa=NextPos_L(Pa,qa);}
	 else  {DeleteAfter_L(Pa,prea,qa);qa=NextPos_L(Pa,prea);}
	 DeleteAfter_L(Pb,preb,qb);qb=NextPos_L(Pb,preb);
	 break;
 case 1: DeleteAfter_L(Pb,preb,qb); InsAfter_L(Pa,prea,qb);qb=NextPos_L(Pb,preb);
		}//switch      
	}
	if(!ListEmpty_L(Pb)) Append_L(Pa,qb);
	FreeNode(Pb.head);
	
}



void main(){
    Polynomial P,Q;
	int n,m;
	printf("输入多项式P的项数:\n");
    scanf("%d",&n);
	CreatePolyn(P,n);
	printf("P:\n");
	PrintPolyn(P);
	printf("\n");
	printf("输入多项式Q的项数:\n");
	scanf("%d",&m);
	CreatePolyn(Q,m);
	printf("Q:\n");
	PrintPolyn(Q);
	printf("\n");

	AddPolyn(P,Q);
	printf("P\n");
	PrintPolyn(P);
    DestroyList_L(P);
}


