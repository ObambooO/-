#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <time.h>
#include <string.h>
#include <iostream>

using namespace std;
#define n 3
int vip1=0;
int y,z;
float sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
float i1=0,i2=0,i3=0,i4=0,i5=0;
float ave1=0,ave2=0,ave3=0,ave4=0,ave5=0;
typedef struct List
{
  int A[n+1];           //�˿���������ҵ���N������
  int len;              //��ʾ�����е�Ԫ�ظ���
}List;

typedef struct Lnode
{            //����������
  int data;
  struct Lnode *next;
}Lnode;
typedef struct Linkqueue
{       //��ʽ�洢�ĵȺ���е����Ͷ���
  Lnode *front;
  Lnode *rear;
}Linkqueue;

List L;
Linkqueue Q;
void Initshuzu()        //��ʼ������
{
  int i;
  for(i=1;i<=n;i++)
  L.A[i]=0;             //Ԫ��ֵΪ0����ʾ���ΪI�Ĵ��ڵ�ǰ״̬Ϊ��
  L.len=0;
}
 void Initqueue()       //��ʼ�����е��㷨
{
  Q.front=Q.rear=(Lnode *)malloc(sizeof(Lnode));
  Q.front->next=NULL;
}
void Enqueue(Linkqueue *Q,int elem)  //�����㷨
{
   Lnode *s;
   s=(Lnode *)malloc(sizeof(Lnode));
   s->data=elem;
   s->next=NULL;
   Q->rear->next=s;
   Q->rear=s;
}
int Dlqueue(Linkqueue *Q)  //�����㷨
{
   Lnode *t;
   int x;
   if(Q->front==Q->rear)
   {
	   printf("����Ϊ�գ�\n");
	   exit(1);
   }
   else
   {
	   t=Q->front->next;
       Q->front->next=t->next;
       x=t->data;
       free(t);
	   return x;
   }
}
void printl()    //��������㷨
{ 
	int i;
    printf("  ���ڰ���ҵ��Ĺ˿ͱ��Ϊ��  һ�Ź�̨        ���Ź�̨        ���Ź�̨\n");
	printf("                              ");
    for( i=1;i<=L.len;i++)
	{
		printf("%d �ſͻ�        ",L.A[i]);
      
	}
	printf("\n"); 
}
void print2()    //��������㷨
{   
	Lnode *s;
	int i=0;
    printf("     ���ڵȺ����ҵ��Ĺ˿ͱ��Ϊ��");
    s=Q.front->next;
    while(s!=NULL)
	{
		printf("%d ",s->data);
        s=s->next;
	    i++;
	}
	printf("\n     ����ǰ��һ���� %d �����Ŷӣ������Ժ�",i);
	printf("\n");
}
void daoda(int x)   //����˿͵����¼��㷨
{   
	int i=L.len+1;
	if (L.len<n)   //
		{	L.A[i]=x;
			i++;
			L.len++;
	   }
   
    else
    Enqueue(&Q,x);

}
void likai(int x)        //����˿��뿪�¼��㷨
{  
	int i=0,j=1,y;
	do
	{
		if(x>L.len)
		{	
			 printf("     �����������������룺");
			 scanf("%d",&x);
			 j++;
		}
		else
		   for(i=0; i<=L.len; i++)
		   {
				if(i==x)
				{
					 printf("     �𾴵� %d �Ź˿����ã�\n",x);
					 L.A[i]=0;
					 L.len--;
					 if(Q.front!=Q.rear)
					 {
						y=Dlqueue(&Q);
						L.A[i]=y;
						L.len++;
					 }
				}

		   }
	}while(i==0 && j<3);
	if(j==3) 
	{ 
	  printf("    �ټ�����ӭ�´ι��٣�");        //������󣾣�3ʱ���˳�ϵͳ
	  exit(0);
	}
}
int  guitai( )             //�ж�����Ĺ�̨���Ƿ���ȷ
{
	int y=0;
    printf("     ��������������ҵ��Ĺ�̨�ţ�1-3����");
	scanf("%d",&y);
	if(y<1||y>5)
	{
		printf("     ������Ĺ�̨���������������룡\n");
        printf("     ��������������ҵ��Ĺ�̨�ţ�1-3����");
	    scanf("%d",&y);
	}
	else
		printf("     ��������ҵ��Ĺ�̨Ϊ %d.\n",y);
	return y;
    
}
int  pingfeng( )             //�ж�����ķ����Ƿ���ȷ
{
	int y=0;
    printf("     �������������֣�1-5����\n     1�֡������ǳ�������;      2�֡����������⣻     3�֡�����һ�����⣻\n     4�֡������Ƚ����⣻       5�֡������ǳ����⡣\n");
	printf("     �����룺");
	scanf("%d",&y);
	if(y<1||y>5)
	{
		printf("     �����������������������룡\n");
        printf("     ������������֣�1-5����\n");
	    scanf("%d",&y);
	}
	else
	    printf("     �������Ϊ%d.\n",y);
	return y;
    
}
void mygrade()                 //�����ֺ���
{  
	printf("     Ϊ�˸��Ʒ�����������������ǵķ���������ۡ�лл��\n");
	z=guitai( );
	y=pingfeng( );
    switch (z)                 //��̨���ִ���
   {
		case 1:                //1�Ź�̨���ִ���  
			{
			sum1+=y;
			i1++;
			ave1=sum1/i1;
	        printf("     %d�Ź�̨��ƽ�������Ϊ%0.2f����л������֣�лл��\n",z,ave1);
			break;
			}
		case 2:                 //2�Ź�̨���ִ���  
			{
			sum2+=y;
			i2++;
			ave2=sum2/i2;
	        printf("     %d�Ź�̨��ƽ�������Ϊ%0.2f����л������֣�лл��\n",z,ave2);
			break;
			}
        case 3:                 //3�Ź�̨���ִ���  
			{
			sum3+=y;
			i3++;
			ave3=sum3/i3;
	        printf("     %d�Ź�̨��ƽ�������Ϊ%0.2f����л������֣�лл��\n",z,ave3);
			break;
			}
		
		default : printf("     ��������������������룡\n");

	}
    getch();
}
void vip(int x)               //vip�û���֤
 {  
	 int i,a; 
	 char ch[3];
     int k=0;
     a=x;
	 switch(a)
	 {
	    case 1:
		 {
			 printf("     ��������Ŀ��ţ�");
		     scanf("%d",&i);
             printf("     ����������λ���룺");
			 while(ch[k-1]!=' ')
			 {   
				 ch[k]=getch();
	             k++;
                 printf("*");
			 }
			 if(i==100 && ch[0]=='1' && ch[1]=='1' && ch[2]=='1' && ch[3]=='1')
			 {
				 printf("\n     �𾴵�VIP�û����ã�����ֱ�ӵ�VIP������ҵ��\n");
			     vip1++;
			 }
			 else if(i==200 && ch[0]=='2' && ch[1]=='2' && ch[2]=='2' && ch[3]=='2')
			 {
				 printf("\n     �𾴵�VIP�û����ã�����ֱ�ӵ�VIP������ҵ��\n");
				 vip1++;
			 }
			 else if(i==300 && ch[0]=='3' && ch[1]=='3' && ch[2]=='3' && ch[3]=='3')
			 {
				 printf("\n     �𾴵�VIP�û����ã�����ֱ�ӵ�VIP������ҵ��\n");
				 vip1++;
			 }
			 else if(i==400 && ch[0]=='4' && ch[1]=='4' && ch[2]=='4' && ch[3]=='4')
			 {
				 printf("\n     �𾴵�VIP�û����ã�����ֱ�ӵ�VIP������ҵ��\n");
				 vip1++;
			 }
			 else if(i==500 && ch[0]=='5' && ch[1]=='5' && ch[2]=='5' && ch[3]=='5')
			 {
				 printf("\n     �𾴵�VIP�û����ã�����ֱ�ӵ�VIP������ҵ��\n");
			     vip1++;
			 }
			 else printf("\n     �����������\n");
			 break;
		 }
	    default : break;		
	 }	 
 }

void mytime()         ////// ʱ�亯��
{ 
    time_t timep;
    time (&timep);
    printf("                 ����ʱ�̣�%s",ctime(&timep));
}

void main()            //������
{
	time_t a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,end;   
	double  b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0,b9=0,b10=0,allsum=0,average=0,xi=0;
	double A[10]={0,0,0,0,0,0,0,0,0,0};
    int c,x,v=0,w=0;
	double sum=0;
	system("color 1f");                            //��Ļ��ɫ�趨
    system("mode con: cols=90 lines=35"); 
    Initshuzu();
    Initqueue();
    while(1)
	{  
      printf("\n********************��ӭ�����й����к�����ʦ����***********************\n");
	  printf("\n                                                                       \n");
      printf("                         1      �˿͵���\n");
      printf("                         2      �˿��뿪\n");
      printf("                         3      �鿴ҵ�����\n");
      printf("                         4      �鿴�Ŷ����\n");
	  printf("                         5      ϵͳ��ѯ\n");
      printf("                         6      �˳�\n\n");
	  mytime();
      printf("\n                   ��ʾ���밴�س���������һ������\n");
	  printf("\n                                                                       \n");
	  printf("************************************************************************\n");
	  printf("����������ѡ��");
      scanf("%d",&c);
	  switch(c)
	  {
	      case 1:
		  {
			  int k=0;
	          int a; 
			  system("cls");
		      printf("\n*************************�˿͵������*******************************\n\n");
		      printf("     ��ѡ�������û����ͣ�VIP�û� �밴 1��    ��ͨ�û� �밴 2.\n");
		      printf("     �����룺");
	          scanf("%d",&a);
	          if (a==1)
			  {  
				  vip(a);
				  getch();
			  } 
			  else
			  {	
				  v++;                   //��ͨ���˿ͼ���
				  printf("     �𾴵���ͨ�û�������ҵ���Ϊ %d.\n",v);
				  daoda(v);
				  if(v==1)
				  {
					  a1=time(NULL);     //ȡv=1�Ŀͻ�����ʱ��
					  mytime();          //��ʾv=1�Ŀͻ�����ʱ��
                      system("pause");
				  }
				  else if(v==2)
				  {
					  a2=time(NULL);
					  mytime();
					  system("pause");
				  }
				  else if(v==3)
				  {
					  a3=time(NULL);
					  mytime();
				      system("pause");
				  }
				  else if(v==4)
				  {
					  a4=time(NULL);
					  mytime();
				      system("pause");
				  }
		          else if(v==5)
				  {
				      a5=time(NULL);
					  mytime();
				      system("pause");
				  }
				  else if(v==6)
				  {
				      a6=time(NULL);
					  mytime();
				      system("pause");
				  }
		          else if(v==7)
				  {
				      a7=time(NULL);
					  mytime();
				      system("pause");
				  }
		          else if(v==8)
				  {
				      a8=time(NULL);
					  mytime();
				      system("pause");
				  }
		   
		          else if(v==9)
				  {
				      a9=time(NULL);
					  mytime();
				      system("pause");
				  }
		          else if(v==10)
				  {
				      a10=time(NULL);
					  mytime();
				      system("pause");
				  }
		          else 
				  {
					  printf("     ���Ժ��ú�,лл��");
					  system("pause");
				  }
			  }
			  system("cls");
			  break;
		  }
	  case 2:
		  {
			  system("cls");
              printf("\n*****************************�˿��뿪����***************************\n\n");
              printf("     �������뿪�˿͵ñ�ţ�");
              scanf("%d",&x);
              likai(x);
              mygrade();
	          w++;
	          if(x=1)
			  {
				  end=time(NULL);              //ȡϵͳ�ĵ�ǰʱ��
		          A[0]=difftime(end,a1);
		          printf("     ������ҵ������ʱ��Ϊ %0.2f ��.\n",A[0]);
			  }
			  else if(x=2)
			  {
				  end=time(NULL);
		          A[1]=difftime(end,a2);
		          printf("     ������ҵ������ʱ��Ϊ %0.2f ��.\n",A[1]);
			  }
			  else if(x=3)
			  {
		          end=time(NULL);
		          A[2]=difftime(end,a3);
		          printf("     ������ҵ������ʱ��Ϊ %0.2f ��.\n",A[2]);
			  }
	          else if(x=4)
			  {
		          end=time(NULL);
		          A[3]=difftime(end,a4);
		          printf("     ������ҵ������ʱ��Ϊ %0.2f ��.\n",A[3]);
			  }
	          else if(x=5)
			  {
		          end=time(NULL);
		          A[4]=difftime(end,a5);
		          printf("     ������ҵ������ʱ��Ϊ %0.2f ��.\n",A[4]);
			  }
	          else if(x=6)
			  {
		          end=time(NULL);
		          A[5]=difftime(end,a6);
		          printf("     ������ҵ������ʱ��Ϊ %0.2f ��.\n",A[5]);
			  }
	         else if(x=7)
			 {
		          end=time(NULL);
		          A[6]=difftime(end,a7);
		          printf("     ������ҵ������ʱ��Ϊ %0.2f ��.\n",A[6]);
			 }
	         else if(x=8)
			 {
		          end=time(NULL);
		          A[7]=difftime(end,a8);
		          printf("     ������ҵ������ʱ��Ϊ %0.2f ��.\n",A[7]);
			 }
	         else if(x=9)
			 {
		          end=time(NULL);
		          A[8]=difftime(end,a9);
		          printf("     ������ҵ������ʱ��Ϊ %0.2f ��.\n",A[8]);
			 }
	         else if(x=10)
			 {
		          end=time(NULL);
		          A[9]=difftime(end,a10);
		          printf("     ������ҵ������ʱ��Ϊ %0.2f ��.\n",A[9]);
			 }
			 allsum+=A[0];
			 getch();
			 system("cls");
			 break;
		  }
	  case 3:
		  {   
			  system("cls");
	          printf("\n****************************ҵ���ѯ����*****************************\n\n");
              printl();
	          getch();
	          system("cls");
              break;
	   
		  }
	  case 4:
		  {
			  system("cls");
	          printf("\n****************************�ŶӲ�ѯ����*****************************\n\n");
              print2();
	          getch();
	          system("cls");
              break;
		  }
	  case 5:
		  {   
			  char cool[3];
		      int i,k=0; ////
			  system("cls");
	          printf("\n************************* ϵͳ��ѯ����*****************************\n\n");
		      printf("  ��������Ŀ��ţ�");
		      scanf("%d",&i);
              printf("  ����������λ���룺");
		      while(cool[k-1]!=' ')
			  {   
				  cool[k]=getch();
	              k++;
                  printf("*");
			  }
			  if(i==000 && cool[0]=='1' && cool[1]=='1' && cool[2]=='1' && cool[3]=='1')
			  {	
				  average=allsum/w;
		          printf("\n  �������� %d λ��ͨ�û���%d λvip�û��ɹ�����ҵ��!",w,vip1);
		          printf("\n  ��ͨ�û�ҵ������ܹ���ʱ %0.2f��,ƽ����ʱ %0.2f��\n",allsum,average);
			  }
			  getch();
	          system("cls");
			  break;
		  }
		  return;
		  getch();
		  system("cls");
	  case 6:
		  return;
		  getch();
		  system("cls");
	  default: printf("     �����������������룺\n");
		  getch();
		  system("cls");
    }
  }
}
