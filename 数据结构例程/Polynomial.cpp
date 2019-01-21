//#include"LinkList.cpp"   //����뽫LinkList.cppֱ�Ӱ�������ʹ�ã���Ҫ�޸�ԭ�ļ���ElemType�������ز��������������õ�main����ע�͵������ļ���LinkList.cpp�еĴ��븴�Ƶ����棬����ElemType��������޸�


//--------------------------------------------------------------------------------------------------------------------
//-------------------------------����ΪLinkList.cpp�еĴ��룬ֻ�ǽ�ElemType�Ķ�������޸ģ���-----------------------------
//--------------------------------------------------------------------------------------------------------------------

//�⺯��ͷ�ļ�����
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

//�Ľ��ĵ�����洢�ṹ����
//typedef int ElemType;    //����Ԫ������Ϊint
typedef struct LNode{    //�������
	ElemType data;
	struct LNode *next;
}*Link,*Position;

typedef struct{          //��������
	Link head,tail;//ͷָ���βָ��
	int len;     //��
}LinkList;


//������������ĺ���ԭ��˵��
/*����˴�ʡ����Ҫע�⺯���ĳ���˳�򣬺���ʹ��ǰ�����Ѿ���������������˴���ȥ*/


//�������������ʵ��
//��������
Status MakeNode(Link &p,ElemType e){
	//������pָ���ֵΪe�Ľ�㣬������OK��������ʧ���򷵻�ERROR��
	p=(Link)malloc(sizeof(LNode));
	if(!p)return ERROR;
	p->data=e;p->next=NULL;
	
	return OK;
}
void FreeNode(Link p){
	//�ͷ�p��ָ���
	free(p);p=NULL;
}


//�ṹ��ʼ�������ٲ���
Status  InitList_L(LinkList &L){
    //��ʼ��LΪһ����ͷ���Ŀ�����,ͷβָ��ָ��ͷ��㣬����0
	ElemType e;
	e.coef=-1;e.expn=-1;
	if(!MakeNode(L.head,e))return ERROR;  //����ͷ���
	L.tail=L.head;L.len=0;
	return OK;
}//InitList_L

Status DestroyList_L(LinkList &L){
	//��������L
	Link p;
	while(p=L.head->next){  //�����ͷ����������е�һ��Ԫ�������һ��Ԫ����ռ�ÿռ�;
		L.head->next=p->next;
		FreeNode(p);
	}
	free(L.head);
	L.head=NULL;L.tail=NULL;L.len=0;
	return OK;
}//DestroyList_L
/*������Ԫ�ؽ�㼰ͷ����ͷţ����Ϊn�����ͷ�n+1����㣬ʱ�临�Ӷ�ΪO(n)*/


//�ӹ��Ͳ���
Status ClearList_L(LinkList &L){
	//����L�ÿ�
	Link p;
	while(p=L.head->next){  //�����ͷ����������е�һ��Ԫ�������һ��Ԫ����ռ�ÿռ�;
		L.head->next=p->next;
		FreeNode(p);
	}	
	L.tail=L.head;
	L.len=0;
	return OK;
}


Status InsFirst_L(LinkList &L,Link s){
	//��s��ָ�����뵽L�ĵ�һ��Ԫ�ؽ��ǰ��ͷ����
	s->next=L.head->next;
	L.head->next=s;
	if(L.len==0)L.tail=s;  //����ǰΪ�ձ���βָ����Ӧ�ı�
	++L.len;
	return OK;
}	
Status Append_L(LinkList &L,Link s){
	//��L��ĩβ׷��һ����sָ���һ�����,βָ��������ı�
	L.tail->next=s;
	while(L.tail->next){L.tail=L.tail->next;L.len++;}
	return OK;
}
Status InsAfter_L(LinkList &L,Link &p,Link s){
	//��֪pָ��L��ĳ����㣬��s��ָ�����뵽p��ָ���󣬲��޸�pʹָ֮���²���Ľ�㣬ͬʱ����1
	s->next=p->next;
	p->next=s;
	p=s;
	++L.len;
	if(p->next==NULL)L.tail=p;//�����뵽��β��βָ��Ӧ�ı�
	return OK;
}
Status InsBefore_L(LinkList &L,Link &p,Link s){
	//��֪pָ��L��ĳ����㣬��s��ָ�����뵽p��ָ���ǰ�����޸�pʹָ֮���²���Ľ�㣬ͬʱ����1
//��˲���Ϊ����ʱ�临�Ӷȣ��ҿ���InsertAfter����������������ʲ����ã��˴���
	printf("InsBefore_L()  is to be implemented...\n");
	return ERROR;
}

Status DeleteFirst_L(LinkList &L,Link &q){
	//��L�ĵ�һ��Ԫ�ؽ��ɾ������q���أ���LΪ�ձ���q���գ�����ERROR
	if(!L.len){q=NULL;return ERROR;}
	if(L.len==1)L.tail=L.head;  //��ɾ����Ϊ�ձ���βָ��ı�
	q=L.head->next;
	L.head->next=q->next;
	q->next=NULL;
	--L.len;
	return OK;

}
Status Remove_L(LinkList &L,Link &q){
	//ɾ��L��β��㲢��q���أ�ͬʱ�ı�βָ��
	//�˲���Ϊ����ʱ�临�Ӷ����ܱ�DeleteAfter�Ȳ���ȡ���������ã�����
	printf("Remove_L()  is to be implemented...\n");
	return ERROR;
}
Status DeleteAfter_L(LinkList &L,Link p,Link &q){
	//��֪pָ��L��ĳ����㣬ɾ��p��ָ����Ľ�㲢��q���أ�ͬʱ����1
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
	//��֪pָ��L��ĳ����㣬ɾ��p��ָ���ǰ�Ľ����q���أ�ͬʱ����1
//��˲���Ϊ����ʱ�临�Ӷȣ��ҿ���DeleteAfter����������������ʲ����ã��˴���
	printf("DeleteBefore_L()  is to be implemented...\n");
	return ERROR;
}
Status SetCurElem_L(Link &p,ElemType e){
    //��e����p��ָ������������ֵ
	if(!p)return ERROR;
	p->data=e;
	return OK;
}


//�����Ͳ���
Status ListEmpty_L(LinkList L){
	//�б��
	if(L.len)return TRUE;
	else return FALSE;
}
int ListLength_L(LinkList L){
	//���
	return(L.len);
}
ElemType GetCurElem_L(Link p){
	if(!p)exit(OVERFLOW);
	return p->data;
}

Position GetHead_L(LinkList L){
	//����ͷ����λ�ü�ͷָ��
	return L.head;
}
Position GetLast_L(LinkList L){
	//����βָ��
	return L.tail;
}
Status LocatePos_L(LinkList L,int i,Link &p){
	//��p����L�е�i��Ԫ�ؽ���λ��,i���Ϸ�ʱ����iERROR
	if(i<1||i>L.len){p=NULL;return ERROR;}
	Link q=L.head;  int j=0;
	while(p&&j<i){p=p->next;++j;}
	if(!p)return ERROR;  //ʵ��i��ȡֵ��Χ�ж��Ѿ������˴�������ķ���
	else return OK;
}
Position PriorPos_L(LinkList L,Link p){
	//����p��ָ����ǰ�Ľ���λ��
	//���Ը��Ӷȣ������ã���
	printf("PriorPos is to be implemented ...\n");
	return NULL;
}
Position NextPos_L(LinkList L,Link p){
	//����L��p��ָ����Ľ���ָ��;�޺���򷵻�NULL
	return p->next;
}

/*����Ӧ���п�����Ҫ��д
Status SmallEqual(ElemType e1,ElemType e2){
	if(e1<=e2) return TRUE;
	else return FALSE;
}

Status equal(ElemType e1,ElemType e2){
	if(e1==e2) return TRUE;
	else return FALSE;
}*/
Position  LocateElem_L(LinkList L,ElemType e,Status (*cmp)(ElemType,ElemType)){
	//����L�е�һ����Ԫ��e�����ϵcmp()��Ԫ�ص�λ�ã����������򷵻�NULL��ʵ��Ӧ��ʱ���ʵ��޸�ʹ���������ϵ��Ԫ�ص�ǰ��	
	Link p=L.head;
	while(p&&!cmp(e,p->data))p=p->next;
	return p;
}

Position  LocateElemPrior_L(LinkList L,ElemType e,Status (*cmp)(ElemType,ElemType)){
	//����L�е�һ����Ԫ��e�����ϵcmp()��Ԫ�ص�ǰ����λ�ã����������򷵻�NULL��	
	Link p=L.head;
	while(p->next&&!(*cmp)(e,p->next->data))p=p->next;
	if(p->next)return p;
	else return NULL;
}


void PrintList_L(LinkList L){
 //�����������˳���L�еĸ���Ԫ�ؼ���
	Link p=L.head->next;
	printf("��%d�����\n",L.len);
	while(p){printf("--%d--",*p);p=p->next;}
	printf("\n\n");
}

//�����ó���
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
	q=LocateElemPrior_L(L,4,SmallEqual);  //��λ����һ������e<=q->data�Ľ��q��ǰ��

	printf("%d",q->data);
	q=GetLast_L(L);
	printf("%d",q->data);


	ClearList_L(L);
	PrintList_L(L);
	DestroyList_L(L);
}*/




//-----------------------------------------------------------------------------
//-------------------����Ϊ����ʽ�����Ͷ��弰����ʵ��--------------------------
//------------------------------------------------------------------------------
//����ʽ��ʽ�洢�ṹ����
typedef LinkList  Polynomial;  //����ʽ���͵Ķ���,������ʽ�洢�ṹ

//����ʽ��ʾ�еıȽϺ���
Status SmallEqual(ElemType e1,ElemType e2){
	if(e1.coef<=e2.coef) return TRUE;
	else return FALSE;
}

Status equal(ElemType e1,ElemType e2){
	if(e1.coef==e2.coef) return TRUE;
	else return FALSE;
}


//������ԭ��������


//����������ʵ��
int compare(ElemType e1,ElemType e2)
{ if(e1.expn<e2.expn)return -1;    else if(e1.expn==e2.expn)return 0;    else return 1;}

Status LocateElem(LinkList L,ElemType e,Link &q, Status(*cmp)(ElemType,ElemType)){
	//��L�д�����eָ�����(cmp����0)��Ԫ�أ���Locate����TRUE,qָ���һ����ȵ�Ԫ�أ�����Locate����FALSE����ʱ��qָ���һ��ָ������e(cmp����0)��Ԫ�ص�ǰ�����������ڴ���eָ��(cmp��С��0)��Ԫ�أ���qָ��β���

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
	e.coef=0; e.expn=-1; SetCurElem_L(h,e);//ͷ��㸳ֵ
    for(int i=1;i<=n;++i){   
		printf("��%d���ϵ����ָ��Ϊ:\n",i); 
		scanf("%f,%d",&e.coef,&e.expn);
		 if(!LocateElem(P,e,q,compare))   //��������eָ����ȵ���  
		 {
			 if(MakeNode(s,e))
				 InsAfter_L(P,q,s);
			
		 }
		 else
		 {	 
			 printf("�ظ���ѱ����ԡ�\n");--i;
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
	//˼·:����ָ��qa��qb�ֱ����Pa��Pb,�Ƚϵ�ǰ����,���������:��һ,Pa�����ָ��С,��qa����һ��;  ���,����ָ�����,��ϵ����Ӻ�Ϊ��,��ʱ�ӺͶ���ʽPa�н�����ɾ��(��prea),ͬʱ�ͷ�Pb�еĵ�ǰ��(��preb);��ָ�����ϵ���Ͳ�Ϊ0�����޸�Pa�е�ǰ���ϵ��ֵ,ͬʱ�ͷ�Pb�ĵ�ǰ���;  ����,Pb��ָ��С,��ɾ��Pb�е�ǰ����뵽Pa�е�ǰ���ǰ�ߡ�

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
	printf("�������ʽP������:\n");
    scanf("%d",&n);
	CreatePolyn(P,n);
	printf("P:\n");
	PrintPolyn(P);
	printf("\n");
	printf("�������ʽQ������:\n");
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


