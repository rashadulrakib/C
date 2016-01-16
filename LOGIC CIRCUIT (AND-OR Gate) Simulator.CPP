#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
//#include<editor.cpp>
//#include<mouse.cpp>
//#include<lineget.cpp>
//#include<Front_pa.cpp>


int x,y;
int button,mouse_x,mouse_y;
int and,or,not,nand,nor,lin,condition=0,xor;
int mo_pr_px=0,mo_pr_py=0,origin_x,origin_y;
int input_0,input_1,output,st_count=-1,vari;
int loop,str_ind=-1,i,j,value,s_ind=-1,sub_ind,box;
int get_out;
int get_tes=0,check_gt=0,end_x=0,end_y=0;
int id_count=0,val_push=0,only_1=1;
char ch,*buff,str[20],sub_str[20],s_str[20],*m;
int save,order=0,graph;
int binary[20];
int g_count=-1,pp,loop_1;
int gate_no[10];

void interface();
int loaddrive();
void mouse_program();
void draw_get(int mousex,int mousey,int a);
void draw_line(int color1,int linx1,int liny1,int color2,int linx2,int liny2);
void drawvari();
void drawcont();
void draw_in1();
void draw_in2();
void draw_out();
void draw_box(); //cotain variable or constant
void draw_linkbox(); //containing input which are linked
void remove_box(); // remove the box when output is left clicked
void total_getdraw(); //draw total gates and components and lines which are drawn
void draw_emptybox(); //draw empty box
void h_draw();


void load();
music(int);


void showmouse();
void hidemouse();
void mouseposition();
void restrictmouseptr(int x_1,int y_1,int x_2,int y_2);

struct st
{
int a,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,in_1,in_2,out,out_t,in1_t,in2_t;
char ch1,ch2,get_in1,get_in2,b1,b2;
}array[50];



struct get_vari
 {
   int get_no;
   char c;
   int position;
 }variabol[20];
int counter1=-1;
struct get_cont
 {
   int get_no;
   int in_valu;
   int position;
 };
struct get_cont constant[20];
int constant1=-1;
struct stor1
 {
   int get_no;
   int in1_valu;
 };
struct stor1 stor_in1[50];
int counter2=-1;
struct stor2
 {
   int get_no;
   int in2_valu;
 };
struct stor2 stor_in2[50];
int counter3=-1;
struct stor3
 {
   int get_no;
   int out_valu;
 };
struct stor3 stor_out[50];
int counter4=-1;

struct stor_get //this structure use to draw background when line is drawn
{
 int a;
 int x,y;
};
struct stor_get gate[50];
int n_o_gate=-1;

struct stor_lin //use to draw the line
 {
   int color1;
   int linx1,liny1;
   int color2;
   int linx2,liny2;
 };
struct stor_lin lyne[100];
int n_o_line=-1;

//*********************************************************

void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"D:\\TC\\BGI");
 load();
 interface();
 while(1)
  {
   mouse_program();
  }
}
		    /*|----------------------------|
		      |        LOGIC OPERATION     |
		      |----------------------------|*/
void mouse_program()
{
     if(loaddrive()==0)
       printf("Error");
       showmouse();
       mouseposition();
      while(1)
	 {
	    showmouse();
	    mouseposition();
	    if(button & 1 == 1)
	      {
		if(mouse_x >= x-25 && mouse_x <= x-10 &&mouse_y >= 9 && mouse_y <= 22)
		   {
		     //if "exit" is click program is terminating
		     closegraph();
		     exit(1);
		     return;
		   }
	      }
//******************************  for new  **********************************
	     if((button & 1)==1)
	       {
		 if(mouse_x>=20 && mouse_x<=70&&mouse_y>=40 && mouse_y<=52)
		    {
		     //if "new" is click all thinks are remove
		     st_count=-1;
		     output=0;
		     str_ind=-1;
		     s_ind=-1;
		     sub_ind=-1;
		     get_out=0;
		     get_tes=0;
		     end_x=0;
		     end_y=0;
		     id_count=0;
		     val_push=0;
		     n_o_gate=-1;
		     n_o_line=-1;
		     order=0;
		     graph=1;
		     constant1=-1;
		     counter1=-1;
		     counter2=-1;
		     counter3=-1;
		     counter4=-1;
		     setcolor(15);
		     setfillstyle(1,7);
		     bar3d(520,40,580,52,0,0);
		     outtextxy(531,42,"graph");
		     setcolor(0);
		     line(520,52,580,52);
		     line(580,40,580,52);
		     setcolor(15);
		     setfillstyle(1,9);
		     bar3d(6,61,50,y-5,0,0);
		     setcolor(0);
		     line(7,61,7,y-5);
		     line(50,61,50,y-5);
		     line(50,y-5,6,y-5);
		     setcolor(15);

		     setfillstyle(1,8);
		     bar3d(51,60,x-75,y-45,0,0);
		     setcolor(15);
		     setfillstyle(1,CYAN);
		     bar3d(51,y-45,x-75,y-5,0,0);
		     outtextxy(250,y-40,"Message Bar");
		     hidemouse();
		     line(20,52,70,52);
		     line(70,40,70,52);
		     delay(25);
		     line(20,52,70,52);
		       line(70,40,70,52);
		     setcolor(0);
		     line(20,52,70,52);
		     line(70,40,70,52);
		     delay(200);
		       line(20,52,70,52);
		       line(70,40,70,52);
		       setcolor(15);
		       line(20,40,70,40);
		       line(20,40,20,52);
		       h_draw();
		     showmouse();
		     setcolor(15);
		    }
	       }
//**************************   Button 1  ************************************


	     if((button & 1)==1)
	       {
		 if(mouse_x>=x-71 && mouse_x<=x-7 && mouse_y>=64 && mouse_y<=125)
		   {
		     //if left click on "AND" gate
		     h_draw();
		     and=1;
		     not=0;
		     or=0;
		     nand=0;
		     nor=0;
		     lin=0;
		     input_0=0;
		     input_1=0;
		     output=0;
		     vari=0;
		     box=0;
		     xor=0;
		     graph=0;
		     hidemouse();
		     setcolor(15);
		     line(x-71,125,x-7,125);
		     line(x-7,64,x-7,125);
		     setcolor(0);//the "AND" bar is pushed
		      line(x-71,64,x-7,64);
		     line(x-71,125,x-71,64);
		     setcolor(15);
		     line(x-71,125,x-7,125);
		     line(x-7,64,x-7,125);
		     showmouse();
		     total_getdraw();
		     setcolor(15);
		      setfillstyle(1,3);
		      bar3d(51,y-45,x-75,y-5,0,0);
		      outtextxy(160,y-30,"Click Right Button to draw AND gate");
		   }
		 else if(mouse_x>=x-71 && mouse_x<=x-7 && mouse_y>=127 && mouse_y<=190)
		   {
			 //if left click on "OR" gate
			 h_draw();
			 or=1;
			 not=0;
			 and=0;
			 nand=0;
			 nor=0;
			 lin=0;
			 input_0=0;
			 input_1=0;
			 output=0;
			 vari=0;
			 box=0;
			 xor=0;
			 graph=0;
			 hidemouse();
			 setcolor(15);
			 line(x-71,190,x-7,190);
			 line(x-7,127,x-7,190);
			 setcolor(0);//the OR gate bar is pushed
			 line(x-71,127,x-7,127);
			 line(x-71,127,x-71,190);
			 setcolor(15);
			 line(x-71,190,x-7,190);
			 line(x-7,127,x-7,190);

			 showmouse();
			 total_getdraw();
			 setcolor(15);
			  setfillstyle(1,3);
			  bar3d(51,y-45,x-75,y-5,0,0);
			  outtextxy(160,y-30,"Click Right Button to draw OR gate");
		   }
		 else if(mouse_x>=x-71 && mouse_x<=x-7 && mouse_y>=192 && mouse_y<=254)
		   {
			 //if left click on "NOT" gate
			 h_draw();
			 not=1;
			 and=0;
			 or=0;
			 nand=0;
			 nor=0;
			 lin=0;
			 input_0=0;
			 input_1=0;
			 output=0;
			 vari=0;
			 box=0;
			 xor=0;
			 graph=0;
			 hidemouse();
			 setcolor(15);
			 line(x-71,254,x-7,254);
			 line(x-7,192,x-7,254);
			 setcolor(0);//The NOT gate bar
			 line(x-71,192,x-7,192);
			 line(x-71,254,x-7,254);
			 setcolor(15);
			 line(x-71,254,x-7,254);
			 line(x-7,192,x-7,254);
			 showmouse();
			 total_getdraw();
			 setcolor(15);
			  setfillstyle(1,3);
			  bar3d(51,y-45,x-75,y-5,0,0);
			  outtextxy(160,y-30,"Click Right Button to draw NOT gate");
		   }
		 else if(mouse_x>=x-71 && mouse_x<=x-7&&mouse_y>=256 && mouse_y<=318)
		   {
			  //if left click on "NAND" gate
			 h_draw();
			 nand=1;
			 not=0;
			 and=0;
			 or=0;
			 nor=0;
			 lin=0;
			 input_0=0;
			 input_1=0;
			 output=0;
			 vari=0;
			 box=0;
			 xor=0;
			 graph=0;
			 hidemouse();
			 setcolor(15);
			 line(x-71,318,x-7,318);
			 line(x-7,256,x-7,318);
			 setcolor(0);//The NAND gate is pushed
			 line(x-71,256,x-7,256);
			 line(x-71,318,x-71,318);
			 setcolor(15);
			 line(x-71,318,x-7,318);
			 line(x-7,256,x-7,318);
			 showmouse();
			 total_getdraw();
			 setcolor(15);
			  setfillstyle(1,3);
			  bar3d(51,y-45,x-75,y-5,0,0);
			  outtextxy(160,y-30,"Click Right Button to draw NAND gate");
		   }
		 else if(mouse_x>=x-71 && mouse_x<=x-7&&mouse_y>=320 && mouse_y<=382)
		   {
			 //if left click on "NOR" gate
			 h_draw();
			 nor=1;
			 not=0;
			 and=0;
			 or=0;
			 nand=0;
			 lin=0;
			 input_0=0;
			 input_1=0;
			 output=0;
			 vari=0;
			 box=0;
			 xor=0;
			 graph=0;
			 hidemouse();
			 setcolor(15);
			 line(x-71,382,x-7,382);
			 line(x-7,320,x-7,382);
			 setcolor(0);//The NOR gate is pushed
			 line(x-71,320,x-7,320);
			 line(x-71,382,x-71,382);
			 setcolor(15);

			 line(x-71,382,x-7,382);
			 line(x-7,320,x-7,382);
			 showmouse();
			 total_getdraw();
			 setcolor(15);
			  setfillstyle(1,3);
			  bar3d(51,y-45,x-75,y-5,0,0);
			  outtextxy(160,y-30,"Click Right Button to draw NOR gate");
		   }
		 else if(mouse_x>=x-71 && mouse_x<=x-7&&mouse_y>=384 && mouse_y<=445)
		   {
			 //if left click on "XOR" gate
			 h_draw();
			 xor=1;
			 nor=0;
			 not=0;
			 and=0;
			 or=0;
			 nand=0;
			 lin=0;
			 input_0=0;
			 input_1=0;
			 output=0;
			 vari=0;
			 box=0;
			 graph=0;
			 hidemouse();
			 setcolor(15);
			 line(x-71,445,x-7,445);
			 line(x-7,384,x-7,445);
			 setcolor(0);//if left click on "XOR" gate
			 line(x-71,384,x-7,384);
			 line(x-71,445,x-71,445);
			 setcolor(15);

			 line(x-71,445,x-7,445);
			 line(x-7,384,x-7,445);
			 showmouse();
			 total_getdraw();
			 setcolor(15);
			  setfillstyle(1,3);
			  bar3d(51,y-45,x-75,y-5,0,0);
			  outtextxy(160,y-30,"Click Right Button to draw XOR gate");
		   }
		  else if(mouse_x>=520 && mouse_x<=580 && mouse_y>=40 && mouse_y<=52)
		   {
			 graph=1;
			 xor=0;  //for graph gate
			 nor=0;
			 not=0;
			 and=0;
			 or=0;
			 nand=0;
			 lin=0;
			 input_0=0;
			 input_1=0;
			 output=0;
			 vari=0;
			 box=0;
		      hidemouse();
		      setcolor(15);
		      line(580,40,580,52);
		      line(520,52,580,52);//For Hiding Graph bar
		      delay(25);
		      setcolor(0);
		      line(580,40,580,52);
		      line(520,52,580,52);//For Hiding Graph bar
		      setcolor(15);
		      showmouse();
		      int m=-1,x1=100,y1=400,x2,y2;
		      int i,j,k,l;
		      int binary_1[20],binary_3[30];
		      int loop_1,loop_2,loop_3;
		      hidemouse();
		      setfillstyle(1,4);
		      bar3d(51,60,x-75,y-45,0,0);
		      setcolor(15);
		      line(100,100,100,400);//Horizontal line
		      line(100,400,500,400);//Vertical line
		      showmouse();
		      i=pow(2,s_ind+1);//Combination of variable input
		      j=400/i;// Horizontal line/combination
		      k=s_ind+st_count+2;
		      l=300/(k+1);//Vertical line/(variable+Gate)
		      setcolor(10);
		      outtextxy(100,405,"0");
		      setcolor(15);
		      m=0;
		      for(loop=0;loop<k;loop++)//For Vartical
			{
			  y1=y1-l;//y1 means the origin of graph
			  setcolor(10);
			  line(x1-5,y1,x1,y1);
			  if(loop<=s_ind)
			    {
			      sprintf(buff,"%c",s_str[loop]); //show the variable in the vartical line
			      outtextxy(x1-12,y1,buff);
			    }
			  else
			    {
			      ++m;//Initial value of m is 0
			      sprintf(buff,"%d",m); //Showing the gate number
			      outtextxy(x1-12,y1,buff);
			    }
			}
		     m=0;
		     for(loop=1;loop<i;loop++)//For Horizontal
			{
			  x1=x1+j;
			  setcolor(10);
			  line(x1,395,x1,405);
			  ++m;
			  sprintf(buff,"%d",m);
			  outtextxy(x1,407,buff);
			}

		     x1=100-j;y1=400-l;
		     for(loop_3=1;loop_3<=i;loop_3++) //for 2^n combination of input
			{
			   x1=x1+j;
			   x2=x1;y2=y1;
			   for(loop=0;loop<=st_count;loop++)//Default value for input
			      {
				if(array[loop].get_in1==-1)
				   array[loop].in_1=-1;
				if(array[loop].get_in2==-1)
				   array[loop].in_2=-1;
				array[loop].out=-1;
			     }

			   if(loop_3==1)//all position initilized 0  at first time
			     {
			       for(loop_1=0;loop_1<=s_ind;loop_1++)
				   binary[loop_1]=0;
			     }
			   else
			     {
				for(loop_1=s_ind;loop_1>=0;loop_1--)
				   {
				     if(binary[loop_1]==0)//for binary increasing
				       {
					 binary[loop_1]=1;
					 break;
				       }
				     else
				       binary[loop_1]=0;
				   }
			     }//End of else statement
			   for(loop_1=0;loop_1<=s_ind;loop_1++)
			     {
			       for(loop_2=0;loop_2<=st_count;loop_2++)//st_count is the total gate number
				  {
				    if(array[loop_2].a==3)//for NOT gate
				      {
					if(array[loop_2].ch1==s_str[loop_1])
					   array[loop_2].in_1=binary[loop_1];
				      }
				    else  //for other gate
				      {
					 if(array[loop_2].ch1==s_str[loop_1])
					    array[loop_2].in_1=binary[loop_1];
					 if(array[loop_2].ch2==s_str[loop_1])
					    array[loop_2].in_2=binary[loop_1];
				      }
				  }//End of inner for() loop
			     } //End of outer for() loop


			  g_count=-1;
			  for(loop=0;loop<=st_count;loop++)
			    {
			     if(array[loop].in1_t>=1 && array[loop].in_1!= -1)
			       {
				  pp=1;
				  if(g_count==-1)
				     gate_no[++g_count]=array[loop].in1_t;
				  else
				    {
				       for(loop_1=0;loop_1<=g_count;loop_1++)
					  {
					     if(gate_no[loop_1]==array[loop].in1_t)
					       {
						  pp=0;
						  break;
					       }
					  }//end of for() loop
				       if(pp==1)
					 gate_no[++g_count]=array[loop].in1_t;
				    }//end of else statement
				  if(pp==1)
				    {
				       for(loop_1=0;loop_1<=st_count;loop_1++)
					  {
					     if(array[loop_1].in1_t==array[loop].in1_t)
						array[loop_1].in_1=array[loop].in_1;
					     if(array[loop_1].in2_t==array[loop].in1_t )
						array[loop_1].in_2=array[loop].in_1;
					  }//end of for() loop
				    }//end of if() statement
			       }//end of if() statement
			    if(array[loop].in2_t>=1 && array[loop].in_2!= -1)
			       {
				  pp=1;
				  if(g_count==-1)
				     gate_no[++g_count]=array[loop].in2_t;
				  else
				    {
				       for(loop_1=0;loop_1<=g_count;loop_1++)
					  {
					     if(gate_no[loop_1]==array[loop].in2_t)
					       {
						  pp=0;
						  break;
					       }
					  }//end of for() loop
				      if(pp==1)
					 gate_no[++g_count]=array[loop].in2_t;
				     }//end of else statement
				  if(pp==1)
				    {
				       for(loop_1=0;loop_1<=st_count;loop_1++)
					  {
					     if(array[loop_1].in1_t==array[loop].in2_t)
						array[loop_1].in_1=array[loop].in_2;
					     if(array[loop_1].in2_t==array[loop].in2_t )
						array[loop_1].in_2=array[loop].in_2;
					  }//end of for() loop
				    }//end of if() statement
			       }//end of if() statement
			  }//end of for() loop
			 for(loop=0;loop<=st_count;loop++)
			  {
			     if(array[loop].a==1)
			       {
				  if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
				    {
				       if(array[loop].in_1==1 && array[loop].in_2==1)
					   array[loop].out=1;
				       else
					   array[loop].out=0;
				    }
			       }//end of if() statement
			     else if(array[loop].a==2)
			       {
				  if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
				    {
				       if(array[loop].in_1==0 && array[loop].in_2==0)
					   array[loop].out=0;
				       else
					   array[loop].out=1;
				   }
			       }//end of else if() statement
			     else if(array[loop].a==3)
			       {
				  if(array[loop].in_1 !=-1)
				    {
				       if(array[loop].in_1==0)
					   array[loop].out=1;
				       else
					   array[loop].out=0;
				    }
			       }//end of else if() statement
			     else if(array[loop].a==4)
			       {
				  if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
				    {
				       if(array[loop].in_1==1 && array[loop].in_2==1)
					   array[loop].out=0;
				       else
					   array[loop].out=1;
				    }
			       }//end of else if() statement
			     else if(array[loop].a==5)
			       {
				  if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
				    {
				       if(array[loop].in_1==0 && array[loop].in_2==0)
					   array[loop].out=1;
				       else
					   array[loop].out=0;
				    }
			       }//end of else if() statement
			    else if(array[loop].a==6)
			       {
				  if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
				    {
				       if((array[loop].in_1==0 && array[loop].in_2==0) || (array[loop].in_1==1 && array[loop].in_2==1))
					   array[loop].out=0;
				       else if((array[loop].in_1==0 && array[loop].in_2==1) || (array[loop].in_1==1 && array[loop].in_2==0))
					   array[loop].out=1;
				    }
			       }//end of else if() statement
			  }//end of for() loop
			int z=0;
			int p;
			while(1)
			  {
			    z++;
			    if(z==20)
			      break;
			    p=0;
			    for(loop=0;loop<=st_count;loop++)
			      {
				if(array[loop].in_1==-1 || array[loop].in_2==-1 || array[loop].out==-1)
				   {
					p=1;
					break;
				   }
			      }//End of for() loop
			    if(p==0)
			       break;
			    else if(p==1)
			      {
				for(loop=0;loop<=st_count;loop++)
				  {
				    if(array[loop].out_t >=1 && array[loop].out != -1)
				      {
					for(loop_1=0;loop_1<=st_count;loop_1++)
					  {
					    if(array[loop_1].in1_t==array[loop].out_t )
					      array[loop_1].in_1=array[loop].out;
					    if(array[loop_1].in2_t==array[loop].out_t )
					      array[loop_1].in_2=array[loop].out;
					  } //end of 2nd for() loop
				      } //end of if() statement
				  }//end of 1st for() loop
				for(loop=0;loop<=st_count;loop++)
				  {
				    if(array[loop].a==1)
				      {
					if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
					  {
					    if(array[loop].in_1==1 && array[loop].in_2==1)
					       array[loop].out=1;
					    else
					       array[loop].out=0;
					  }
				      } //end of if() statement
				    else if(array[loop].a==2)
				      {
					if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
					  {
					    if(array[loop].in_1==0 && array[loop].in_2==0)
					       array[loop].out=0;
					    else
					       array[loop].out=1;
					  }
				      }
				    else if(array[loop].a==3)
				      {
					if(array[loop].in_1 !=-1)
					  {
					    if(array[loop].in_1==0)
					       array[loop].out=1;
					    else
					       array[loop].out=0;
					  }
				      }//end of else if() statement
				    else if(array[loop].a==4)
				      {
					if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
					  {
					    if(array[loop].in_1==1 && array[loop].in_2==1)
					       array[loop].out=0;
					    else
					       array[loop].out=1;
					  }
				      }
				    else if(array[loop].a==5)
				      {
					if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
					  {
					    if(array[loop].in_1==0 && array[loop].in_2==0)
					       array[loop].out=1;
					    else
					       array[loop].out=0;
					  }
				      }
				   else if(array[loop].a==6)
				      {
					if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
					  {
					    if((array[loop].in_1==0 && array[loop].in_2==0) || (array[loop].in_1==1 && array[loop].in_2==1))
					       array[loop].out=0;
					    else if((array[loop].in_1==0 && array[loop].in_2==1) || (array[loop].in_1==1 && array[loop].in_2==0))
					       array[loop].out=1;
					  }
				      }//end of else if() statement
				  }//end of for() loop
			      }//End of else if() statement
			  }//End of while() loop
			 //*************** end of out put

			 for(loop=0;loop<=s_ind;loop++)//For variable
			    {
			      if(binary[loop]==0)
			       {
				 line(x2,y2,x2+j,y2); //horizontal line
				 if(loop_3>1)
				   {
				     if(binary_1[loop]==1)
					line(x2,y2-(l/2),x2,y2);
				   }
			       }
			      else if(binary[loop]==1)
			       {
				 line(x2,y2-(l/2),x2+j,y2-(l/2));
				 if(loop_3>1)
				   {
				     if(binary_1[loop]==0)
					line(x2,y2-(l/2),x2,y2);
				   }
			       }
			      y2=y2-l;
			    }
			 for(loop=0;loop<=s_ind;loop++)
			    binary_1[loop]=binary[loop];//saving previous value
			 for(loop=0;loop<=st_count;loop++)//For gate's output
			    {
			      if(array[loop].out==0)
				{
				   line(x2,y2,x2+j,y2);
				   if(loop_3>1)
				     {
				       if(binary_3[loop]==1)
					  line(x2,y2-(l/2),x2,y2);
				     }
				}
			      else if(array[loop].out==1)
				{
				   line(x2,y2-(l/2),x2+j,y2-(l/2));
				   if(loop_3>1)
				     {
				       if(binary_3[loop]==0)
					  line(x2,y2-(l/2),x2,y2);
				     }
				}
			      y2=y2-l;
			    }//End of for() loop
			 for(loop=0;loop<=st_count;loop++)
			    binary_3[loop]=array[loop].out;
			}//End of for() loop
		      //}//End of if() statement
		   } //End of graph

			 else if(mouse_x>=x-71 && mouse_x<=x-7&&mouse_y>=447 && mouse_y<=472)
		   {
			 //if left click on "line"
			 lin=1;
			 nor=0;
			 not=0;
			 and=0;
			 or=0;
			 nand=0;
			 input_0=0;
			 input_1=0;
			 output=0;
			 vari=0;
			 box=0;
			 xor=0;
			 hidemouse();
			 setcolor(15);
			 line(x-71,472,x-7,472);
			 line(x-7,447,x-7,472);
			 delay(25);
			 h_draw();
			 setcolor(0);//the line bar is pushed
			 line(x-71,447,x-7,447);
			  line(x-71,447,x-71,472);
			 setcolor(15);
			  line(x-71,472,x-7,472);
			  line(x-7,447,x-7,472);
			 showmouse();
			 setcolor(15);
			 if(st_count>-1)
			  {
			   setfillstyle(1,3);
			   bar3d(51,y-45,x-75,y-5,0,0);
			   outtextxy(160,y-30,"Click Right Button to draw Line");
			  }
		   }
		 else if(mouse_x>=94 && mouse_x<=160&&mouse_y>=40 && mouse_y<=52)
		   {
			  //if left click on "input-0"
			  h_draw();
			  input_0=1;
			  lin=0;
			  nor=0;
			  not=0;
			  and=0;
			  or=0;
			  nand=0;
			  input_1=0;
			  output=0;
			  vari=0;
			  box=0;
			  xor=0;
			  hidemouse();//when click on "input_0" bar is pused
			  setcolor(0);
			    line(94,40,160,40);
			    line(94,40,94,52);
			    setcolor(15);
			    line(94,52,160,52);
			    line(160,40,160,52);
			   setcolor(0);
			     line(173,52,245,52);//input_1
			     line(245,40,245,52);//input_1
			     line(260,52,332,52);//output
			     line(332,40,332,52);//output
			     line(410,40,410,52);//box
			     line(348,52,410,52);//box
			     line(425,52,505,52);//variable
			     line(505,40,505,52);//variable
			     line(x-71,472,x-7,472);//line
			     line(x-7,447,x-7,472);  //line

			   setcolor(15);
			     line(173,40,245,40);//input_1
			     line(173,52,173,40);//input_1
			     line(260,40,332,40);//output
			     line(260,40,260,52);//output
			     line(348,40,410,40);//box
			     line(348,40,348,52);//box
			     line(425,40,505,40);//variable
			     line(425,40,425,52);//variable
			     line(x-71,447,x-7,447); //line
			     line(x-71,447,x-71,472);//line

			  showmouse();
			  setcolor(15);
		   }
		 else if(mouse_x>=173 && mouse_x<=245&&mouse_y>=40 && mouse_y<=52)
		   {
			 //if left click on "input-1"
			 h_draw();
			 input_1=1;
			 lin=0;
			 nor=0;
			 not=0;
			 and=0;
			 or=0;
			 nand=0;
			 input_0=0;
			 output=0;
			 vari=0;
			 box=0;
			 xor=0;
			 hidemouse();
			 setcolor(0);
			   line(173,40,245,40);
			   line(173,52,173,40);
			   setcolor(15);
			   line(173,52,245,52);
			   line(245,40,245,52);
			   setcolor(0);
			    line(94,52,160,52);//input_0
			    line(160,40,160,52);//input_0
			    line(260,52,332,52);//output
			    line(332,40,332,52);//output
			    line(410,40,410,52);//box
			    line(348,52,410,52);//box
			    line(425,52,505,52);//variable
			    line(505,40,505,52);//variable
			    line(x-71,472,x-7,472); //line
			    line(x-7,447,x-7,472);  //line

			   setcolor(15);
			    line(94,40,160,40);//input_0
			    line(94,40,94,52);//input_0
			    line(260,40,332,40);//output
			    line(260,40,260,52);//output
			    line(348,40,410,40);//box
			    line(348,40,348,52);//box
			    line(425,40,505,40);//variable
			    line(425,40,425,52);//variable
			    line(x-71,447,x-7,447); //line
			    line(x-71,447,x-71,472);//line

			 showmouse();
			 setcolor(15);
		   }
		 else if(mouse_x>=260 && mouse_x<=332 && mouse_y>=40 && mouse_y<=52)
		   {
			 //if left click on "output"
			 h_draw();
			 output=1;
			 lin=0;
			 nor=0;
			 not=0;
			 and=0;
			 or=0;
			 nand=0;
			 input_0=0,
			 input_1=0;
			 vari=0;
			 box=0;
			 xor=0;
			 hidemouse();
			 setcolor(0);
			   line(260,40,332,40);
			   line(260,40,260,52);
			   setcolor(15);
			   line(260,52,332,52);
			   line(332,40,332,52);
			   setcolor(0);
			    line(94,52,160,52);//input_0
			    line(160,40,160,52);//input_0
			    line(173,52,245,52);//input_1
			    line(245,40,245,52);//input_1
			    line(410,40,410,52);//box
			    line(348,52,410,52);//box
			    line(425,52,505,52);//variable
			    line(505,40,505,52);//variable
			    line(x-71,472,x-7,472); //line
			    line(x-7,447,x-7,472);  //line

			   setcolor(15);
			    line(94,40,160,40);//input_0
			    line(94,40,94,52);//input_0
			    line(173,40,245,40);//input_1
			    line(173,52,173,40);//input_1
			    line(348,40,410,40);//box
			    line(348,40,348,52);//box
			    line(425,40,505,40);//variable
			    line(425,40,425,52);//variable
			    line(x-71,447,x-7,447); //line
			    line(x-71,447,x-71,472);//line

			 showmouse();
			 for(i=0;i<=st_count;i++)
			  {
			   if(array[i].get_in1==-1)
			     array[i].in_1=-1;
			   if(array[i].get_in2==-1)
			     array[i].in_2=-1;
			   array[i].out=-1;
			  }
			 setcolor(15);
			 //remove the box in which input is not given but linked
			 remove_box();
			 //draw lines which parts are removed by box
			 setcolor(15);
			 for(loop=0;loop<=n_o_line;loop++)//Repetation of drawing lines
			    draw_line(lyne[loop].color1,lyne[loop].linx1,lyne[loop].liny1,lyne[loop].color2,lyne[loop].linx2,lyne[loop].liny2);
			 setcolor(15);
			 setfillstyle(1,CYAN);
			 bar3d(51,y-45,x-75,y-5,0,0);
			 outtextxy(250,y-40,"Message Bar");
			 s_ind=-1;
			 sub_ind=-1;
			 for(j=0;j<=str_ind;j++)
			  {
			     sub_str[++sub_ind]=str[j];
			     for(i=j+1;i<=str_ind;i++)
			       {
				  if(str[i]==' ')
				   continue;
				  if(str[j]==str[i])
				   str[i]=' ';
			       }
			  }
			 for(j=0;j<=sub_ind;j++)
			  {
			    if(sub_str[j]==' ')
			      continue;
			    s_str[++s_ind]=sub_str[j];
			  }
			    setcolor(15);
			 if(s_ind>=0)
			  {
			    setfillstyle(1,CYAN);
			    bar3d(51,y-45,x-75,y-5,0,0);
			    outtextxy(250,y-40,"Message Bar");
			    setfillstyle(1,BLACK);
			    bar3d(345,y-30,365,y-15,0,0);
			    outtextxy(200,y-26,"Entre Value For:");
			  }
			 setfillstyle(1,9);
			 bar3d(6,61,50,y-5,0,0);
			 loop=85;
			 for(i=0;i<=s_ind;i++)
			  {
			     sprintf(buff,"%c",s_str[i]);
			     outtextxy(350,y-26,buff);
			     ch=getch();
			     if(ch!='0' && ch!='1')
			      {
			       --i;
			       continue;
			      }
			     if(ch=='0') value=0;
			     if(ch=='1') value=1;
			     sprintf(m,"%c=%c",s_str[i],ch);
			     setcolor(15);
			     loop=loop+15;
			     setfillstyle(1,4);
			     bar3d(14,loop,43,loop+15,0,0);
			     outtextxy(18,loop+3,m);
			     for(j=0;j<=st_count;j++)
			      {
				if(array[j].a!=3)
				if(s_str[i]==array[j].ch1)
				    array[j].in_1=value;
				if(array[j].a!=3)
				if(s_str[i]==array[j].ch2)
				    array[j].in_2=value;
				if(array[j].a==3)
				if(s_str[i]==array[j].ch1)
				    array[j].in_1=value;
			      }
			     if(i!=s_ind)
			      {
				setfillstyle(1,BLACK);
				bar3d(345,y-30,365,y-15,0,0);
			      }
			     if(i==s_ind)
			      {
				setcolor(15);
				setfillstyle(1,CYAN);
				bar3d(51,y-45,x-75,y-5,0,0);
				outtextxy(250,y-40,"Message Bar");
			      }
			  }
			get_out=0;
			//int g_count=-1,pp,loop_1;
			//int gate_no[10];
			g_count=-1;
			for(loop=0;loop<=st_count;loop++)
			  {
			     if(array[loop].in1_t>=1 && array[loop].in_1!= -1)
			       {
				  pp=1;
				  if(g_count==-1)
				     gate_no[++g_count]=array[loop].in1_t;
				  else
				    {
				       for(loop_1=0;loop_1<=g_count;loop_1++)
					  {
					     if(gate_no[loop_1]==array[loop].in1_t)
					       {
						  pp=0;
						  break;
					       }
					  }//end of for() loop
				       if(pp==1)
					 gate_no[++g_count]=array[loop].in1_t;
				    }//end of else statement
				  if(pp==1)
				    {
				       for(loop_1=0;loop_1<=st_count;loop_1++)
					  {
					     if(array[loop_1].in1_t==array[loop].in1_t)
						array[loop_1].in_1=array[loop].in_1;
					     if(array[loop_1].in2_t==array[loop].in1_t )
						array[loop_1].in_2=array[loop].in_1;
					  }//end of for() loop
				    }//end of if() statement
			       }//end of if() statement
			    if(array[loop].in2_t>=1 && array[loop].in_2!= -1)
			       {
				  pp=1;
				  if(g_count==-1)
				     gate_no[++g_count]=array[loop].in2_t;
				  else
				    {
				       for(loop_1=0;loop_1<=g_count;loop_1++)
					  {
					     if(gate_no[loop_1]==array[loop].in2_t)
					       {
						  pp=0;
						  break;
					       }
					  }//end of for() loop
				      if(pp==1)
					 gate_no[++g_count]=array[loop].in2_t;
				     }//end of else statement
				  if(pp==1)
				    {
				       for(loop_1=0;loop_1<=st_count;loop_1++)
					  {
					     if(array[loop_1].in1_t==array[loop].in2_t)
						array[loop_1].in_1=array[loop].in_2;
					     if(array[loop_1].in2_t==array[loop].in2_t )
						array[loop_1].in_2=array[loop].in_2;
					  }//end of for() loop
				    }//end of if() statement
			       }//end of if() statement
			  }//end of for() loop
			 for(loop=0;loop<=st_count;loop++)
			  {
			     if(array[loop].a==1)
			       {
				  if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
				    {
				       if(array[loop].in_1==1 && array[loop].in_2==1)
					   array[loop].out=1;
				       else
					   array[loop].out=0;
				    }
			       }//end of if() statement
			     else if(array[loop].a==2)
			       {
				  if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
				    {
				       if(array[loop].in_1==0 && array[loop].in_2==0)
					   array[loop].out=0;
				       else
					   array[loop].out=1;
				   }
			       }//end of else if() statement
			     else if(array[loop].a==3)
			       {
				  if(array[loop].in_1 !=-1)
				    {
				       if(array[loop].in_1==0)
					   array[loop].out=1;
				       else
					   array[loop].out=0;
				    }
			       }//end of else if() statement
			     else if(array[loop].a==4)
			       {
				  if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
				    {
				       if(array[loop].in_1==1 && array[loop].in_2==1)
					   array[loop].out=0;
				       else
					   array[loop].out=1;
				    }
			       }//end of else if() statement
			     else if(array[loop].a==5)
			       {
				  if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
				    {
				       if(array[loop].in_1==0 && array[loop].in_2==0)
					   array[loop].out=1;
				       else
					   array[loop].out=0;
				    }
			       }//end of else if() statement
			    else if(array[loop].a==6)
			       {
				  if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
				    {
				       if((array[loop].in_1==0 && array[loop].in_2==0) || (array[loop].in_1==1 && array[loop].in_2==1))
					   array[loop].out=0;
				       else if((array[loop].in_1==0 && array[loop].in_2==1) || (array[loop].in_1==1 && array[loop].in_2==0))
					   array[loop].out=1;
				    }
			       }//end of else if() statement
			  }//end of for() loop
			int z=0;
			int p;
			order=0;
			while(1)
			  {
			    order=1;
			    z++;
			    if(z==20)
			      break;
			    p=0;
			    for(loop=0;loop<=st_count;loop++)
			      {
				if(array[loop].in_1==-1 || array[loop].in_2==-1 || array[loop].out==-1)
				   {
					p=1;
					break;
				   }
			      }//End of for() loop
			    if(p==0)
			       break;
			    else if(p==1)
			      {
				for(loop=0;loop<=st_count;loop++)
				  {
				    if(array[loop].out_t >=1 && array[loop].out != -1)
				      {
					for(loop_1=0;loop_1<=st_count;loop_1++)
					  {
					    if(array[loop_1].in1_t==array[loop].out_t )
					      array[loop_1].in_1=array[loop].out;
					    if(array[loop_1].in2_t==array[loop].out_t )
					      array[loop_1].in_2=array[loop].out;
					  } //end of 2nd for() loop
				      } //end of if() statement
				  }//end of 1st for() loop
				for(loop=0;loop<=st_count;loop++)
				  {
				    if(array[loop].a==1)
				      {
					if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
					  {
					    if(array[loop].in_1==1 && array[loop].in_2==1)
					       array[loop].out=1;
					    else
					       array[loop].out=0;
					  }
				      } //end of if() statement
				    else if(array[loop].a==2)
				      {
					if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
					  {
					    if(array[loop].in_1==0 && array[loop].in_2==0)
					       array[loop].out=0;
					    else
					       array[loop].out=1;
					  }
				      }
				    else if(array[loop].a==3)
				      {
					if(array[loop].in_1 !=-1)
					  {
					    if(array[loop].in_1==0)
					       array[loop].out=1;
					    else
					       array[loop].out=0;
					  }
				      }//end of else if() statement
				    else if(array[loop].a==4)
				      {
					if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
					  {
					    if(array[loop].in_1==1 && array[loop].in_2==1)
					       array[loop].out=0;
					    else
					       array[loop].out=1;
					  }
				      }
				    else if(array[loop].a==5)
				      {
					if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
					  {
					    if(array[loop].in_1==0 && array[loop].in_2==0)
					       array[loop].out=1;
					    else
					       array[loop].out=0;
					  }
				      }
				   else if(array[loop].a==6)
				      {
					if(array[loop].in_1 != -1 && array[loop].in_2 != -1)
					  {
					    if((array[loop].in_1==0 && array[loop].in_2==0) || (array[loop].in_1==1 && array[loop].in_2==1))
					       array[loop].out=0;
					    else if((array[loop].in_1==0 && array[loop].in_2==1) || (array[loop].in_1==1 && array[loop].in_2==0))
					       array[loop].out=1;
					  }
				      }//end of else if() statement
				  }//end of for() loop
			      }//End of else if() statement
			  }//End of while() loop
			 setfillstyle(1,BLUE);
			 for(i=0;i<=st_count;i++)
			  {
			    if(array[i].a==3)
			     {
			      if(array[i].get_in1==-1)
			       {
				sprintf(m,"%d",array[i].in_1);
				bar3d(array[i].x4-15,array[i].y4-7.5,array[i].x4,array[i].y4+7.5,0,0);
				outtextxy(array[i].x4-11,array[i].y4-2,m);
			       }
			     }
			    else
			    {
			      if(array[i].get_in1==-1)
			       {
				sprintf(m,"%d",array[i].in_1);
				bar3d(array[i].x4-15,array[i].y4-10,array[i].x4,array[i].y4+5,0,0);
				outtextxy(array[i].x4-10,array[i].y4-5,m);
			       }
			      if(array[i].get_in2==-1)
			       {
				sprintf(m,"%d",array[i].in_2);
				bar3d(array[i].x5-15,array[i].y5-5,array[i].x5,array[i].y5+10,0,0);
				outtextxy(array[i].x5-10,array[i].y5,m);
			       }
			    }
			  }
			 setfillstyle(1,4);
			 for(loop=0;loop<=st_count;loop++)
			 {
			   bar3d(array[loop].x1+8,array[loop].y1-12,array[loop].x1+18,array[loop].y1-2,0,0);
			   if(array[loop].out==0)
			     outtextxy((array[loop].x1)+10,array[loop].y1-10,"0");
			   else if(array[loop].out==1)
			     outtextxy((array[loop].x1)+10,array[loop].y1-10,"1");
			 }
		     get_out=0;
		     end_x=0;
		     end_y=0;
		     only_1=0;
		   }
		 else if(mouse_x>=348 && mouse_x<=410&&mouse_y>=40 && mouse_y<=52)
		   {
			 //if left click on "box"
			 h_draw();
			 box=1;
			 output=0;
			 lin=0;
			 nor=0;
			 not=0;
			 and=0;
			 or=0;
			 nand=0;
			 xor=0;
			 input_0=0;
			 input_1=0;
			 vari=0;
			 hidemouse();
			 setcolor(0);
			   line(348,40,410,40);
			   line(348,40,348,52);
			   setcolor(15);
			   line(410,40,410,52);
			   line(348,52,410,52);

			   setcolor(0);
			    line(94,52,160,52);//input_0
			    line(160,40,160,52);//input_0
			    line(173,52,245,52);//input_1
			    line(245,40,245,52);//input_1
			    line(260,52,332,52);//output
			    line(332,40,332,52);//output
			    line(425,52,505,52);//variable
			    line(505,40,505,52);//variable
			    line(x-71,472,x-7,472); //line
			    line(x-7,447,x-7,472);  //line

			   setcolor(15);
			    line(94,40,160,40);//input_0
			    line(94,40,94,52);//input_0
			    line(173,40,245,40);//input_1
			    line(173,52,173,40);//input_1
			    line(260,40,332,40);//output
			    line(260,40,260,52);//output
			    line(425,40,505,40);//variable
			    line(425,40,425,52);//variable
			    line(x-71,447,x-7,447); //line
			    line(x-71,447,x-71,472);//line

			 showmouse();
			 setcolor(15);
		   }
		 else if(mouse_x>=425 && mouse_x<=505&&mouse_y>=40 && mouse_y<=52)
		   {
			  //if left click on "variable"
			  h_draw();
			  vari=1;
			  output=0;
			  lin=0;
			  nor=0;
			  not=0;
			  and=0;
			  or=0;
			  nand=0;
			  input_0=0,
			  input_1=0;
			  box=0;
			  xor=0;
			  hidemouse();
			  setcolor(0);
			    line(425,40,505,40);
			    line(425,40,425,52);
			    setcolor(15);
			    line(425,52,505,52);
			    line(505,40,505,52);
			    setcolor(0);
			      line(94,52,160,52);//input_0
			      line(160,40,160,52);//input_0
			      line(173,52,245,52);//input_1
			      line(245,40,245,52);//input_1
			      line(260,52,332,52);//output
			      line(332,40,332,52);//output
			      line(410,40,410,52);//box
			      line(348,52,410,52);//box
			      line(x-71,472,x-7,472);//line
			      line(x-7,447,x-7,472);//line

			    setcolor(15);
			      line(94,40,160,40);//input_0
			      line(94,40,94,52);//input_0
			      line(173,40,245,40);//input_1
			      line(173,52,173,40);//input_1
			      line(260,40,332,40);//output
			      line(260,40,260,52);//output
			      line(348,40,410,40);//box
			      line(348,40,348,52);//box
			      line(x-71,447,x-7,447);//line
			      line(x-71,447,x-71,472);//line

			  showmouse();
			  setcolor(15);
		   }
	       }
//********************Start of button 2***************
	     if((button & 2)==2)
	       {
		 hidemouse();
		 if(mouse_x>=54 && mouse_x<=x-78 && mouse_y>=60 && mouse_y<=y-50)
		   {
		    if(and==1 && mouse_x>=115 && mouse_x<=515 && mouse_y>=90 && mouse_y<=405)
		      {
		       setcolor(15);
		       st_count++;
		       get_tes=get_tes+2;
		       line(mouse_x-10,mouse_y-23,mouse_x-10,mouse_y+23);
		       line(mouse_x-10,mouse_y-23,mouse_x,mouse_y-23);
		       line(mouse_x-10,mouse_y+23,mouse_x,mouse_y+23);
		       arc(mouse_x,mouse_y,0,90,23);
		       arc(mouse_x,mouse_y,270,360,23);
		       line(mouse_x+25,mouse_y,mouse_x+35,mouse_y);
		       line(mouse_x-40,mouse_y-10, mouse_x-10,mouse_y-10);
		       line(mouse_x-40,mouse_y+10, mouse_x-10,mouse_y+10);
		       and=0;
		       array[st_count].a=1; //To identyfy AND gate
		       array[st_count].x1=mouse_x+25;
		       array[st_count].y1=mouse_y;
		       array[st_count].x2=mouse_x-10;
		       array[st_count].y2=mouse_y-10;
		       array[st_count].x3=mouse_x-10;
		       array[st_count].y3=mouse_y+10;
		       array[st_count].x4=mouse_x-40;//.-----
		       array[st_count].y4=mouse_y-10;//.-----
		       array[st_count].x5=mouse_x-40; //.____
		       array[st_count].y5=mouse_y+10; //.____
		       array[st_count].in_1= -1;
		       array[st_count].in_2= -1;
		       array[st_count].out= -1;
		       array[st_count].in1_t=-1;
		       array[st_count].in2_t=-1;
		       array[st_count].out_t=-1;
		       array[st_count].get_in1=-1;
		       array[st_count].get_in2=-1;
		       array[st_count].b1=-1;
		       array[st_count].b2=-1;
		       setfillstyle(1,3);
		       bar3d(51,y-45,x-75,y-5,0,0);
		       outtextxy(250,y-40,"Message Bar");
		       n_o_gate++;
		       gate[n_o_gate].a=1;
		       gate[n_o_gate].x=mouse_x;
		       gate[n_o_gate].y=mouse_y;
		      }
		   else if(or==1&& mouse_x>=108 && mouse_x<=510 && mouse_y>=90 && mouse_y<=405)
		      {
			setcolor(15);
			st_count++;
			get_tes=get_tes+2;
			arc(mouse_x-42,mouse_y-67,294,318,100);
			arc(mouse_x-42,mouse_y+67,42,66,100);
			arc(mouse_x-77,mouse_y,0,18,80);
			arc(mouse_x-77,mouse_y,342,360,80);
			line(mouse_x+33,mouse_y,mouse_x+43,mouse_y);
			line(mouse_x-30,mouse_y-10, mouse_x,mouse_y-10);
			line(mouse_x-30,mouse_y+10, mouse_x,mouse_y+10);
			or=0;
			array[st_count].a=2; //To identyfy OR gate
			array[st_count].x1=mouse_x+33;
			array[st_count].y1=mouse_y;
			array[st_count].x2=mouse_x;
			array[st_count].y2=mouse_y-10;
			array[st_count].x3=mouse_x;
			array[st_count].y3=mouse_y+10;
			array[st_count].x4=mouse_x-30;
			array[st_count].y4=mouse_y-10;
			array[st_count].x5=mouse_x-30;
			array[st_count].y5=mouse_y+10;
			array[st_count].in_1= -1;
			array[st_count].in_2= -1;
			array[st_count].out= -1;
			array[st_count].in1_t=-1;
			array[st_count].in2_t=-1;
			array[st_count].out_t=-1;
			array[st_count].get_in1=-1;
			array[st_count].get_in2=-1;
			array[st_count].b1=-1;
			array[st_count].b2=-1;
			setfillstyle(1,3);
			 bar3d(51,y-45,x-75,y-5,0,0);
			 outtextxy(250,y-40,"Message Bar");
			n_o_gate++;
			gate[n_o_gate].a=2;
			gate[n_o_gate].x=mouse_x;
			gate[n_o_gate].y=mouse_y;
		      }
		   else if(not==1 && mouse_x>=115 && mouse_x<=510 && mouse_y>=85 && mouse_y<=410)
		      {
			setcolor(15);
			st_count++;
			get_tes=get_tes+1;
			line(mouse_x-10,mouse_y-16,mouse_x-10,mouse_y+16);
			circle(mouse_x+28,mouse_y,4);
			line(mouse_x+32,mouse_y,mouse_x+40,mouse_y);
			line(mouse_x-10,mouse_y-16,mouse_x+24,mouse_y);
			line(mouse_x-10,mouse_y+16,mouse_x+24,mouse_y);
			line(mouse_x-40,mouse_y,mouse_x-10,mouse_y);
			not=0;
			array[st_count].a=3; //To identyfy NOT gate
			array[st_count].x1=mouse_x+32;
			array[st_count].y1=mouse_y;
			array[st_count].x2=mouse_x-10;
			array[st_count].y2=mouse_y;
			array[st_count].x4=mouse_x-40;
			array[st_count].y4=mouse_y;
			array[st_count].in_1= -1;
			array[st_count].in_2=-1;
			array[st_count].out= -1;
			array[st_count].in1_t=-1;
			array[st_count].in2_t=-1;
			array[st_count].out_t=-1;
			array[st_count].get_in1=-1;
			array[st_count].get_in2=-1;
			array[st_count].b1=-1;
			array[st_count].b2=-1;
			setfillstyle(1,3);
			bar3d(51,y-45,x-75,y-5,0,0);
			outtextxy(250,y-40,"Message Bar");
			n_o_gate++;
		       gate[n_o_gate].a=3;
		       gate[n_o_gate].x=mouse_x;
		       gate[n_o_gate].y=mouse_y;
		      }
		   else if(nand==1 && mouse_x>=115 && mouse_x<=515 && mouse_y>=90 && mouse_y<=405)
		      {
			setcolor(15);
			st_count++;
			get_tes=get_tes+2;
			line(mouse_x-10,mouse_y-23,mouse_x-10,mouse_y+23);
			line(mouse_x-10,mouse_y-23,mouse_x,mouse_y-23);
			line(mouse_x-10,mouse_y+23,mouse_x,mouse_y+23);
			arc(mouse_x,mouse_y,0,90,23);
			arc(mouse_x,mouse_y,270,360,23);
			circle(mouse_x+27,mouse_y,4);
			line(mouse_x+31,mouse_y,mouse_x+39,mouse_y);
			line(mouse_x-40,mouse_y-10, mouse_x-10,mouse_y-10);
			line(mouse_x-40,mouse_y+10, mouse_x-10,mouse_y+10);
			nand=0;
			array[st_count].a=4; //To identyfy NAND gate
			array[st_count].x1=mouse_x+31;
			array[st_count].y1=mouse_y;
			array[st_count].x2=mouse_x-10;
			array[st_count].y2=mouse_y-10;
			array[st_count].x3=mouse_x-10;
			array[st_count].y3=mouse_y+10;
			array[st_count].x4=mouse_x-40;
			array[st_count].y4=mouse_y-10;
			array[st_count].x5=mouse_x-40;
			array[st_count].y5=mouse_y+10;
			array[st_count].in_1= -1;
			array[st_count].in_2= -1;
			array[st_count].out= -1;
			array[st_count].in1_t=-1;
			array[st_count].in2_t=-1;
			array[st_count].out_t=-1;
			array[st_count].get_in1=-1;
			array[st_count].get_in2=-1;
			array[st_count].b1=-1;
			array[st_count].b2=-1;
			setfillstyle(1,3);
			bar3d(51,y-45,x-75,y-5,0,0);
			outtextxy(250,y-40,"Message Bar");
			n_o_gate++;
			gate[n_o_gate].a=4;
			gate[n_o_gate].x=mouse_x;
			gate[n_o_gate].y=mouse_y;
		      }
		   else if(nor==1 && mouse_x>=108 && mouse_x<=505 && mouse_y>=90 && mouse_y<=405)
		      {
			setcolor(15);
			st_count++;
			get_tes=get_tes+2;
			arc(mouse_x-42,mouse_y-67,294,318,100);
			arc(mouse_x-42,mouse_y+67,42,66,100);
			arc(mouse_x-77,mouse_y,0,18,80);
			arc(mouse_x-77,mouse_y,342,360,80);
			circle(mouse_x+36,mouse_y,4);
			line(mouse_x+40,mouse_y,mouse_x+50,mouse_y);
			line(mouse_x-30,mouse_y-10, mouse_x,mouse_y-10);
			line(mouse_x-30,mouse_y+10, mouse_x,mouse_y+10);
			nor=0;
			array[st_count].a=5; //To identyfy NOR gate
			array[st_count].x1=mouse_x+40;
			array[st_count].y1=mouse_y;
			array[st_count].x2=mouse_x;
			array[st_count].y2=mouse_y-10;
			array[st_count].x3=mouse_x;
			array[st_count].y3=mouse_y+10;
			array[st_count].x4=mouse_x-30;
			array[st_count].y4=mouse_y-10;
			array[st_count].x5=mouse_x-30;
			array[st_count].y5=mouse_y+10;
			array[st_count].in_1= -1;
			array[st_count].in_2= -1;
			array[st_count].out= -1;
			array[st_count].in1_t=-1;
			array[st_count].in2_t=-1;
			array[st_count].out_t=-1;
			array[st_count].get_in1=-1;
			array[st_count].get_in2=-1;
			array[st_count].b1=-1;
			array[st_count].b2=-1;
			setfillstyle(1,3);
			bar3d(51,y-45,x-75,y-5,0,0);
			outtextxy(250,y-40,"Message Bar");
			n_o_gate++;
			gate[n_o_gate].a=5;
			gate[n_o_gate].x=mouse_x;
			gate[n_o_gate].y=mouse_y;
		      }
		   else if(xor==1 && mouse_x>=108 && mouse_x<=505 && mouse_y>=90 && mouse_y<=405)
		      {
			setcolor(15);
			st_count++;
			get_tes=get_tes+2;
			arc(mouse_x-42,mouse_y-67,294,318,100);
			arc(mouse_x-42,mouse_y+67,42,66,100);
			arc(mouse_x-77,mouse_y,0,18,80);
			arc(mouse_x-77,mouse_y,342,360,80);
			line(mouse_x+32,mouse_y,mouse_x+42,mouse_y);
			arc(mouse_x-83,mouse_y,0,18,80);
			arc(mouse_x-83,mouse_y,342,360,80);
			line(mouse_x-35,mouse_y-10,mouse_x-5,mouse_y-10);
			line(mouse_x-35,mouse_y+10,mouse_x-5,mouse_y+10);
			xor=0;
			array[st_count].a=6; //To identyfy XOR gate
			array[st_count].x1=mouse_x+30;
			array[st_count].y1=mouse_y;
			array[st_count].x2=mouse_x;
			array[st_count].y2=mouse_y-10;
			array[st_count].x3=mouse_x;
			array[st_count].y3=mouse_y+10;
			array[st_count].x4=mouse_x-35;
			array[st_count].y4=mouse_y-10;
			array[st_count].x5=mouse_x-35;
			array[st_count].y5=mouse_y+10;
			array[st_count].in_1= -1;
			array[st_count].in_2= -1;
			array[st_count].out= -1;
			array[st_count].in1_t=-1;
			array[st_count].in2_t=-1;
			array[st_count].out_t=-1;
			array[st_count].get_in1=-1;
			array[st_count].get_in2=-1;
			array[st_count].b1=-1;
			array[st_count].b2=-1;
			setfillstyle(1,3);
			bar3d(51,y-45,x-75,y-5,0,0);
			outtextxy(250,y-40,"Message Bar");
			n_o_gate++;
			gate[n_o_gate].a=6;
			gate[n_o_gate].x=mouse_x;
			gate[n_o_gate].y=mouse_y;
		      }
		   else if(lin==1)
		      {
		       setfillstyle(1,CYAN);
		       bar3d(51,y-45,x-75,y-5,0,0);
		       outtextxy(250,y-40,"Message Bar");
		       origin_x=mouse_x;
		       origin_y=mouse_y;
		       if(st_count>-1)
			{
			    restrictmouseptr(52,65,x-78,y-50);
			    check_gt=0;
			    hidemouse();
			    if(end_x!=0 && end_y!=0)
			    {
			     if(origin_x>=end_x-3 && origin_x<=end_x+3 && origin_y>=end_y-3 && origin_y<=end_y+3)
			       {
				  check_gt=1;
				  origin_x=end_x;
				  origin_y=end_y;
				  setcolor(9);
				  setfillstyle(SOLID_FILL,9);
				  circle(end_x,end_y,2);
				  floodfill(end_x,end_y,9);
				  n_o_line++;
				  lyne[n_o_line].color1=9;
				  lyne[n_o_line].linx1=end_x;
				  lyne[n_o_line].liny1=end_y;
			       }

			    }
			    else if(check_gt==0 )
			    for(j=0;j<=st_count;j++)
			     {
			       if(origin_x>=array[j].x4-5 && origin_x<=array[j].x4+30 && origin_y>=array[j].y4-5 && origin_y<=array[j].y4+5)
				  {
				   if(array[j].in1_t<0)
				    {
				      id_count++;
				      array[j].in1_t=id_count;
				      save=array[j].in1_t;
				    }
				   else
				     save=array[j].in1_t;
				   setcolor(10);
				   setfillstyle(SOLID_FILL,10);
				   circle(origin_x,origin_y,2);
				   floodfill(origin_x,origin_y,10);
				   check_gt=1;
				   n_o_line++;
				   lyne[n_o_line].color1=10;
				   lyne[n_o_line].linx1=origin_x;
				   lyne[n_o_line].liny1=origin_y;
				   break;
				  }
				else if(origin_x>=array[j].x5-5 && origin_x<=array[j].x5+30 && origin_y>=array[j].y5-5 && origin_y<=array[j].y5+5)
				  {
				   if(array[j].in2_t<0)
				    {
				      id_count++;
				      array[j].in2_t=id_count;
				      save=array[j].in2_t;
				    }
				   else
				    save=array[j].in2_t;
				   setcolor(10);
				   setfillstyle(SOLID_FILL,10);
				   circle(origin_x,origin_y,2);
				   floodfill(origin_x,origin_y,10);
				   check_gt=1;
				   n_o_line++;
				   lyne[n_o_line].color1=10;
				   lyne[n_o_line].linx1=origin_x;
				   lyne[n_o_line].liny1=origin_y;
				   break;
				  }
				else if(origin_x>=array[j].x1-5 && origin_x<=array[j].x1+15 && origin_y>=array[j].y1-5 && origin_y<=array[j].y1+5)
				  {
				   if(array[j].out_t<0)
				    {
				      id_count++;
				      array[j].out_t=id_count;
				      save=array[j].out_t;
				    }
				   else
				     save=array[j].out_t;
				   setcolor(10);
				   setfillstyle(SOLID_FILL,10);
				   circle(origin_x,origin_y,2);
				   floodfill(origin_x,origin_y,10);
				   check_gt=1;
				   n_o_line++;
				   lyne[n_o_line].color1=10;
				   lyne[n_o_line].linx1=origin_x;
				   lyne[n_o_line].liny1=origin_y;
				   break;
				  }
			     }
			    showmouse();
			    if(check_gt==1)
			    while(1)
			     {
				   showmouse();
				   mouseposition();
				   if(condition==1)
				   {
				     mo_pr_px=mouse_x;
				     mo_pr_py=mouse_y;
				     condition=0;
				   }

				   if(lin!=1)
				     {
					hidemouse();
				       line( origin_x,origin_y,mouse_x,mouse_y);
				       showmouse();
				     }
				   if(mo_pr_px !=mouse_x ||mo_pr_py !=mouse_y)
				    {
				      condition=1;
				      setcolor(0);
				      if(lin!=1)
				       {
					hidemouse();
					line( origin_x,origin_y,mo_pr_px,mo_pr_py);
					for(loop=0;loop<=n_o_gate;loop++)//Repetation of drawing gates
					   draw_get(gate[loop].x,gate[loop].y,gate[loop].a);
					//if(n_o_line>=1)
					for(loop=0;loop<n_o_line;loop++)//Repetation of drawing lines
					   draw_line(lyne[loop].color1,lyne[loop].linx1,lyne[loop].liny1,lyne[loop].color2,lyne[loop].linx2,lyne[loop].liny2);
					draw_emptybox();
					// here work is much . It should  less in draw_box()
					draw_box(); //draw  the  box containing veriable or input
					if(only_1==0)  //after one derived , draw  the  box containing linked input
					 draw_linkbox();
					setcolor(15);
					showmouse();
				       }
				    }
				   lin=0;
				   if((button & 1)==1)
				    {
				       if(end_x==0 && end_y==0)
					{
					 setcolor(10);
					 setfillstyle(SOLID_FILL,10);
					 circle(origin_x,origin_y,2);
					 floodfill(origin_x,origin_y,10);
					}
				       setcolor(15);
				       hidemouse();
				       line(origin_x,origin_y,mouse_x,mouse_y);
				       //showmouse();
				       for(j=0;j<=st_count;j++)
					{
					  if(mouse_x>=array[j].x4-5 && mouse_x<=array[j].x4+30 && mouse_y>=array[j].y4-5 && mouse_y<=array[j].y4+5)
					   {
					      if(end_x!=0 && end_y!=0)
					       {
						 setcolor(9);
						 setfillstyle(SOLID_FILL,9);
						 circle(end_x,end_y,2);
						 floodfill(end_x,end_y,9);
					       }
					      end_x=0;
					      end_y=0;
					      setcolor(5);
					      setfillstyle(SOLID_FILL,5);
					      circle(mouse_x,mouse_y,2);
					      floodfill(mouse_x,mouse_y,5);

					      lyne[n_o_line].color2=5;
					      lyne[n_o_line].linx2=mouse_x;
					      lyne[n_o_line].liny2=mouse_y;

					      if(array[j].in1_t<0)
						 array[j].in1_t=save;
					      else if(array[j].in1_t>=1)
					      {
						 val_push=array[j].in1_t;
						 for(i=0;i<=st_count;i++)
						  {
						    if(array[i].in1_t==val_push)
						     array[i].in1_t=save;
						    if(array[i].in2_t==val_push)
						     array[i].in2_t=save;
						  }
						 /* here correction will be done and
						 wrong line will be removed*/
					      }
					      showmouse();
					      break;
					   }
					  else if(mouse_x>=array[j].x5-5 && mouse_x<=array[j].x5+30 && mouse_y>=array[j].y5-5 && mouse_y<=array[j].y5+5)
					   {
					      if(end_x!=0 && end_y!=0)
					       {
						 setcolor(9);
						 setfillstyle(SOLID_FILL,9);
						 circle(end_x,end_y,2);
						 floodfill(end_x,end_y,9);
					       }
					      end_x=0;
					      end_y=0;
					      setcolor(5);
					      setfillstyle(SOLID_FILL,5);
					      circle(mouse_x,mouse_y,2);
					      floodfill(mouse_x,mouse_y,5);

					      lyne[n_o_line].color2=5;
					      lyne[n_o_line].linx2=mouse_x;
					      lyne[n_o_line].liny2=mouse_y;

					      if(array[j].in2_t<0)
						array[j].in2_t=save;
					      else if(array[j].in2_t>=1)
					      {
						val_push=array[j].in2_t;
						for(i=0;i<=st_count;i++)
						 {
						   if(array[i].in1_t==val_push)
						    array[i].in1_t=save;
						   if(array[i].in2_t==val_push)
						    array[i].in2_t=save;
						 }
						 // here correction will be done and
						 //wrong line will be removed
					      }
					      showmouse();
					      break;
					   }
					  else if(mouse_x>=array[j].x1-5 && mouse_x<=array[j].x1+15 && mouse_y>=array[j].y1-5 && mouse_y<=array[j].y1+5)
					   {
					      setcolor(15);
					      setfillstyle(1,CYAN);
					      bar3d(51,y-45,x-75,y-5,0,0);
					      outtextxy(250,y-40,"Message Bar");
					      /* here correction will be done and
						 wrong line will be removed*/
					      printf("\a");
					      outtextxy(200,y-26,"Circuit Is Dismissed");
					      showmouse();
					      break;
					   }

					}
				       if(j>st_count)
					{
					 if(end_x!=0 && end_y!=0)
					  {
					   setcolor(9);
					   setfillstyle(SOLID_FILL,9);
					   circle(end_x,end_y,2);
					   floodfill(end_x,end_y,9);
					  }
					 end_x=mouse_x;
					 end_y=mouse_y;
					 setcolor(9);
					 setfillstyle(SOLID_FILL,9);
					 circle(mouse_x,mouse_y,2);
					 floodfill(mouse_x,mouse_y,9);

					 lyne[n_o_line].color2=9;
					 lyne[n_o_line].linx2=mouse_x;
					 lyne[n_o_line].liny2=mouse_y;
					 showmouse();
					}
				     restrictmouseptr(0,0,x,y);
				     break;
				    }
			     }
			   restrictmouseptr(0,0,x,y);
			}
			lin=1;
			setcolor(15);
		      }
		   else if(input_0==1)
		      {
			    for(loop=0;loop<=st_count;loop++ )
			      {
				if(array[loop].a!=3)
				if(mouse_x>=array[loop].x4-15 && mouse_x<=array[loop].x4+40 && mouse_y>=array[loop].y4-8 && mouse_y<=array[loop].y4+8)
				{
				  array[loop].in_1=0;
				  array[loop].get_in1=1;
				  setfillstyle(1,3);
				  bar3d(array[loop].x4-15,array[loop].y4-10,array[loop].x4,array[loop].y4+5,0,0);
				  outtextxy(array[loop].x4-11,array[loop].y4-5,"0");
				  break;
				}
				if(array[loop].a!=3)
				if(mouse_x>=array[loop].x5-15 && mouse_x<=array[loop].x5+40 && mouse_y>=array[loop].y5-8 && mouse_y<=array[loop].y5+8)
				{
				  array[loop].in_2=0;
				  array[loop].get_in2=1;
				  setfillstyle(1,3);
				  bar3d(array[loop].x5-15,array[loop].y5-5,array[loop].x5,array[loop].y5+10,0,0);
				  outtextxy(array[loop].x5-11,array[loop].y5,"0");
				  break;
				}
				if(array[loop].a==3)
				if(mouse_x>=array[loop].x4-15 && mouse_x<=array[loop].x4+40 && mouse_y>=array[loop].y4-8 && mouse_y<=array[loop].y4+8)
				{
				  array[loop].in_1=0;
				  array[loop].get_in1=1;
				  setfillstyle(1,3);
				  bar3d(array[loop].x4-15,array[loop].y4-8,array[loop].x4,array[loop].y4+8,0,0);
				  outtextxy(array[loop].x4-11,array[loop].y4-2,"0");
				  break;
				}
			      }
			    input_0=1;
		      }
		   else if(input_1==1)
		      {
			     setfillstyle(1,0);
			     for(loop=0;loop<=st_count;loop++ )
			      {
				if(array[loop].a!=3)
				if(mouse_x>=array[loop].x4-15 && mouse_x<=array[loop].x4+40 && mouse_y>=array[loop].y4-8 && mouse_y<=array[loop].y4+8)
				{
				  setfillstyle(1,3);
				  array[loop].in_1=1;
				  array[loop].get_in1=1;
				  bar3d(array[loop].x4-15,array[loop].y4-10,array[loop].x4,array[loop].y4+5,0,0);
				  outtextxy(array[loop].x4-11,array[loop].y4-5,"1");
				  break;
				}
				if(array[loop].a!=3)
				if(mouse_x>=array[loop].x5-15 && mouse_x<=array[loop].x5+40 && mouse_y>=array[loop].y5-8 && mouse_y<=array[loop].y5+8)
				{
				  array[loop].in_2=1;
				  array[loop].get_in2=1;
				  setfillstyle(1,3);
				  bar3d(array[loop].x5-15,array[loop].y5-5,array[loop].x5,array[loop].y5+10,0,0);
				  outtextxy(array[loop].x5-11,array[loop].y5,"1");
				  break;
				}
				if(array[loop].a==3)
				if(mouse_x>=array[loop].x4-15 && mouse_x<=array[loop].x4+40 && mouse_y>=array[loop].y4-8 && mouse_y<=array[loop].y4+8)
				{
				  array[loop].in_1=1;
				  array[loop].get_in1=1;
				  setfillstyle(1,3);
				  bar3d(array[loop].x4-15,array[loop].y4-8,array[loop].x4,array[loop].y4+8,0,0);
				  outtextxy(array[loop].x4-11,array[loop].y4-2,"1");
				  break;
				}
			      }
			     input_1=1;
		      }
		   else if(output==1)
		      {

		      }
		   else if(vari==1)
		      {
			for(loop=0;loop<=st_count;loop++)
			  {
				if(array[loop].a!=3)
				if(mouse_x>=array[loop].x4-15 && mouse_x<=array[loop].x4+40 && mouse_y>=array[loop].y4-8 && mouse_y<=array[loop].y4+8)
				{
				  // hidemouse();
				   setfillstyle(1,CYAN);
				   bar3d(51,y-45,x-75,y-5,0,0);
				   //outtextxy(250,y-40,"Message Bar");
				   outtextxy(200,y-30,"Entre Variable For Input 1:");
				   setfillstyle(1,BLACK);
				   bar3d(420,y-40,450,y-10,0,0);
				  showmouse();
				  ch=getch();
				  if(ch>='a'&&ch<='z')
				  {
				   delay(10);
				   array[loop].ch1=ch;
				   str[++str_ind]=ch;
				   sprintf(buff,"%c",ch);
				   hidemouse();
				   setfillstyle(1,LIGHTBLUE);
				   bar3d(array[loop].x4-15,array[loop].y4-10,array[loop].x4,array[loop].y4+5,0,0);
				   outtextxy(array[loop].x4-10,array[loop].y4-5,buff);
				   outtextxy(430,y-30,buff);
				   array[loop].get_in1=2;
				  }
				   showmouse();
				   break;
				}
				if(array[loop].a!=3)
				if(mouse_x>=array[loop].x5-15 && mouse_x<=array[loop].x5+40 && mouse_y>=array[loop].y5-8 && mouse_y<=array[loop].y5+8)
				{
				   setfillstyle(1,CYAN);
				   bar3d(51,y-45,x-75,y-5,0,0);
				   //outtextxy(250,y-40,"message bar");
				   outtextxy(200,y-30,"Entre Variable For Input 2:");
				   setfillstyle(1,BLACK);
				   bar3d(420,y-40,450,y-10,0,0);
				  showmouse();
				  ch=getch();
				  if(ch>='a'&&ch<='z')
				  {
				   delay(10);
				   array[loop].ch2=ch;
				   str[++str_ind]=ch;
				   sprintf(buff,"%c",ch);
				   hidemouse();
				   setfillstyle(1,LIGHTBLUE);
				   bar3d(array[loop].x5-15,array[loop].y5-5,array[loop].x5,array[loop].y5+10,0,0);
				   outtextxy(array[loop].x5-10,array[loop].y5,buff);
				   outtextxy(430,y-30,buff);
				   array[loop].get_in2=2;
				  }
				  showmouse();
				  break;
				}
				if(array[loop].a==3)
				if(mouse_x>=array[loop].x4-15 && mouse_x<=array[loop].x4+40 && mouse_y>=array[loop].y4-8 && mouse_y<=array[loop].y4+8)
				{
				   setfillstyle(1,CYAN);
				   bar3d(51,y-45,x-75,y-5,0,0);
				   //outtextxy(250,y-40,"message bar");
				   outtextxy(200,y-30,"Entre Variable For Input:");
				   setfillstyle(1,BLACK);
				   bar3d(420,y-40,450,y-10,0,0);
				  showmouse();
				  ch=getch();
				  if(ch>='a'&&ch<='z')
				  {
				   delay(10);
				   array[loop].ch1=ch;
				   str[++str_ind]=ch;
				   sprintf(buff,"%c",ch);
				   hidemouse();
				   setfillstyle(1,LIGHTBLUE);
				   bar3d(array[loop].x4-15,array[loop].y4-8,array[loop].x4,array[loop].y4+8,0,0);
				   outtextxy(array[loop].x4-10,array[loop].y4-4,buff);
				   outtextxy(430,y-30,buff);
				   array[loop].get_in1=2;
				  }
				  showmouse();
				  break;
				}
			  }
			setfillstyle(1,CYAN);
			bar3d(51,y-45,x-75,y-5,0,0);
			outtextxy(250,y-40,"Message Bar");
			vari=1;
		      }
		   else if(box==1)
		      {
			for(j=0;j<=st_count;j++)
			 {
			   if(mouse_x>=array[j].x4-15 && mouse_x<=array[j].x4+40 && mouse_y>=array[j].y4-8 && mouse_y<=array[j].y4+8)
			    {
			      array[j].b1=1;
			      if(array[j].a!=3)
			       {
				 setfillstyle(1,3);
				 bar3d(array[j].x4-15,array[j].y4-10,array[j].x4,array[j].y4+5,0,0);
			       }
			      if(array[j].a==3)
			       {
				 setfillstyle(1,3);
				 bar3d(array[j].x4-15,array[j].y4-8,array[j].x4,array[j].y4+8,0,0);
			       }
			    }
			   if(mouse_x>=array[j].x5-15 && mouse_x<=array[j].x5+40 && mouse_y>=array[j].y5-8 && mouse_y<=array[j].y5+8)
			    {
			       array[j].b2=1;
			       setfillstyle(1,3);
			       bar3d(array[j].x5-15,array[j].y5-5,array[j].x5,array[j].y5+10,0,0);
			    }
			 }
			box=1;
		      }
		   else if(graph==1)
		      {
			total_getdraw();
			graph=0;
		      }
		   }
		 showmouse();
	       }
	 }
}
//*********************************************************
/*void draw_get(int mousex,int mousey,int a)
   {
     if(a==1)
       {
	  setcolor(15);
	  line(mousex-10,mousey-23,mousex-10,mousey+23);
	  line(mousex-10,mousey-23,mousex,mousey-23);
	  line(mousex-10,mousey+23,mousex,mousey+23);
	  arc(mousex,mousey,0,90,23);
	  arc(mousex,mousey,270,360,23);
	  line(mousex+25,mousey,mousex+35,mousey);
	  line(mousex-40,mousey-10, mousex-10,mousey-10);
	  line(mousex-40,mousey+10, mousex-10,mousey+10);
       }
     else if(a==2)
       {
	  setcolor(15);
	  arc(mousex-42,mousey-67,294,318,100);
	  arc(mousex-42,mousey+67,42,66,100);
	  arc(mousex-77,mousey,0,18,80);
	  arc(mousex-77,mousey,342,360,80);
	  line(mousex+33,mousey,mousex+43,mousey);
	  line(mousex-30,mousey-10, mousex,mousey-10);
	  line(mousex-30,mousey+10, mousex,mousey+10);
       }
     else if(a==3)
       {
	  setcolor(15);
	  line(mousex-10,mousey-16,mousex-10,mousey+16);
	  circle(mousex+28,mousey,4);
	  line(mousex+32,mousey,mousex+40,mousey);
	  line(mousex-10,mousey-16,mousex+24,mousey);
	  line(mousex-10,mousey+16,mousex+24,mousey);
	  line(mousex-40,mousey,mousex-10,mousey);
       }
     else if(a==4)
       {
	  setcolor(15);
	  line(mousex-10,mousey-23,mousex-10,mousey+23);
	  line(mousex-10,mousey-23,mousex,mousey-23);
	  line(mousex-10,mousey+23,mousex,mousey+23);
	  arc(mousex,mousey,0,90,23);
	  arc(mousex,mousey,270,360,23);
	  circle(mousex+27,mousey,4);
	  line(mousex+31,mousey,mousex+39,mousey);
	  line(mousex-40,mousey-10, mousex-10,mousey-10);
	  line(mousex-40,mousey+10, mousex-10,mousey+10);
       }
     else if(a==5)
       {
	  setcolor(15);
	  arc(mousex-42,mousey-67,294,318,100);
	  arc(mousex-42,mousey+67,42,66,100);
	  arc(mousex-77,mousey,0,18,80);
	  arc(mousex-77,mousey,342,360,80);
	  circle(mousex+36,mousey,4);
	  line(mousex+40,mousey,mousex+50,mousey);
	  line(mousex-30,mousey-10, mousex,mousey-10);
	  line(mousex-30,mousey+10, mousex,mousey+10);
       }
     else if(a==6)
       {
	  setcolor(15);
	  arc(mousex-42,mousey-67,294,318,100);
	  arc(mousex-42,mousey+67,42,66,100);
	  arc(mousex-77,mousey,0,18,80);
	  arc(mousex-77,mousey,342,360,80);
	  line(mousex+32,mousey,mousex+42,mousey);
	  arc(mousex-83,mousey,0,18,80);
	  arc(mousex-83,mousey,342,360,80);
	  line(mousex-35,mousey-10,mousex-5,mousey-10);
	  line(mousex-35,mousey+10,mousex-5,mousey+10);
       }
   }
//***************************************************************
void draw_line(int color1,int linx1,int liny1,int color2,int linx2,int liny2)
 {
    line(linx1,liny1,linx2,liny2);
    setcolor(color1);
    setfillstyle(SOLID_FILL,color1);
    circle(linx1,liny1,2);
    floodfill(linx1,liny1,color1);
    setcolor(color2);
    setfillstyle(SOLID_FILL,color2);
    circle(linx2,liny2,2);
    floodfill(linx2,liny2,color2);
    setcolor(15);
 }  */
//*****************************************************************
void drawvari()
 {
   for(loop=0;loop<=counter1;loop++)
      {
	if(variabol[loop].position==1 && array[variabol[loop].get_no].a!=3)
	  {
	   sprintf(buff,"%c",variabol[loop].c);
	   hidemouse();
	   setfillstyle(1,LIGHTBLUE);
	   bar3d(array[variabol[loop].get_no].x4-15,array[variabol[loop].get_no].y4-10,array[variabol[loop].get_no].x4,array[variabol[loop].get_no].y4+5,0,0);
	   outtextxy(array[variabol[loop].get_no].x4-10,array[variabol[loop].get_no].y4-7,buff);
	   showmouse();
	  }
	else if(variabol[loop].position==1 && array[variabol[loop].get_no].a==3)
	  {
	   sprintf(buff,"%c",variabol[loop].c);
	   hidemouse();
	   setfillstyle(1,LIGHTBLUE);
	   bar3d(array[variabol[loop].get_no].x4-15,array[variabol[loop].get_no].y4-10,array[variabol[loop].get_no].x4,array[variabol[loop].get_no].y4+8,0,0);
	   outtextxy(array[variabol[loop].get_no].x4-11,array[variabol[loop].get_no].y4-4,buff);
	   showmouse();
	  }
	if(variabol[loop].position==2)
	  {
	   sprintf(buff,"%c",variabol[loop].c);
	   hidemouse();
	   setfillstyle(1,LIGHTBLUE);
	   bar3d(array[variabol[loop].get_no].x5-15,array[variabol[loop].get_no].y5-5,array[variabol[loop].get_no].x5,array[variabol[loop].get_no].y5+10,0,0);
	   outtextxy(array[variabol[loop].get_no].x5-10,array[variabol[loop].get_no].y5-2,buff);
	   showmouse();
	  }
      }
 }
//*********************************************************************
void drawcont()
 {
   for(loop=0;loop<=constant1;loop++)
      {
	if((constant[loop].position==1)&&(array[constant[loop].get_no].a)!=3)
	  {
	   sprintf(buff,"%d",constant[loop].in_valu);
	   hidemouse();
	   setfillstyle(1,3);
	   bar3d(array[constant[loop].get_no].x4-15,array[constant[loop].get_no].y4-10,array[constant[loop].get_no].x4,array[constant[loop].get_no].y4+5,0,0);
	   outtextxy(array[constant[loop].get_no].x4-10,array[constant[loop].get_no].y4-5,buff);
	   showmouse();
	  }
	else if((constant[loop].position==1)&&(array[constant[loop].get_no].a)==3)
	  {
	   sprintf(buff,"%d",constant[loop].in_valu);
	   hidemouse();
	   setfillstyle(1,3);
	   bar3d(array[constant[loop].get_no].x4-15,array[constant[loop].get_no].y4-8,array[constant[loop].get_no].x4,array[constant[loop].get_no].y4+8,0,0);
	   outtextxy(array[constant[loop].get_no].x4-11,array[constant[loop].get_no].y4-2,buff);
	   showmouse();
	  }
	if(constant[loop].position==2)
	  {
	   sprintf(buff,"%d",constant[loop].in_valu);
	   hidemouse();
	   setfillstyle(1,3);
	   bar3d(array[constant[loop].get_no].x5-15,array[constant[loop].get_no].y5-5,array[constant[loop].get_no].x5,array[constant[loop].get_no].y5+10,0,0);
	   outtextxy(array[constant[loop].get_no].x5-10,array[constant[loop].get_no].y5,buff);
	   showmouse();
	  }

      }
 }
//*************************************************************
void draw_in1()
  {
    for(loop=0;loop<=counter2;loop++)
       {
	 if(array[stor_in1[loop].get_no].a != 3)
	   {
	     sprintf(buff,"%d",stor_in1[loop].in1_valu);
	     hidemouse();
	     setfillstyle(1,BLUE);
	     bar3d(array[stor_in1[loop].get_no].x4-15,array[stor_in1[loop].get_no].y4-10,array[stor_in1[loop].get_no].x4,array[stor_in1[loop].get_no].y4+5,0,0);
	     outtextxy(array[stor_in1[loop].get_no].x4-10,array[stor_in1[loop].get_no].y4-5,buff);
	     showmouse();
	   }
	 else if(array[stor_in1[loop].get_no].a == 3)
	   {
	     sprintf(buff,"%d",stor_in1[loop].in1_valu);
	     hidemouse();
	     setfillstyle(1,BLUE);
	     bar3d(array[stor_in1[loop].get_no].x4-15,array[stor_in1[loop].get_no].y4-8,array[stor_in1[loop].get_no].x4,array[stor_in1[loop].get_no].y4+8,0,0);
	     outtextxy(array[stor_in1[loop].get_no].x4-11,array[stor_in1[loop].get_no].y4-2,buff);
	     showmouse();
	   }
       }
  }
//***********************************************************
void draw_in2()
  {
    for(loop=0;loop<=counter3;loop++)
       {
	   sprintf(buff,"%d",stor_in2[loop].in2_valu);
	   hidemouse();
	   setfillstyle(1,BLUE);
	   bar3d(array[stor_in2[loop].get_no].x5-15,array[stor_in2[loop].get_no].y5-5,array[stor_in2[loop].get_no].x5,array[stor_in2[loop].get_no].y5+10,0,0);
	   outtextxy(array[stor_in2[loop].get_no].x5-10,array[stor_in2[loop].get_no].y5,buff);
	   showmouse();
       }
  }
//***************************************************************
void draw_out()
  {
    for(loop=0;loop<=counter4;loop++)
       {
	   sprintf(buff,"%d",stor_out[loop].out_valu);
	   hidemouse();
	   setfillstyle(1,4);
	   bar3d(array[stor_out[loop].get_no].x1+8,array[stor_out[loop].get_no].y1-12,array[stor_out[loop].get_no].x1+18,array[stor_out[loop].get_no].y1-2,0,0);
	   outtextxy(array[stor_out[loop].get_no].x1+10,array[stor_out[loop].get_no].y1-10,buff);
	   showmouse();
       }
  }
void draw_box()
 {
   //in which direct input or veriable is given
   for(loop=0;loop<=st_count;loop++)
    {
     if(array[loop].a!=3)
      {
	if(array[loop].get_in1==1)
	 {
	   sprintf(m,"%d",array[loop].in_1);
	   setcolor(15);
	   setfillstyle(1,3);
	   bar3d(array[loop].x4-15,array[loop].y4-10,array[loop].x4,array[loop].y4+5,0,0);
	   outtextxy(array[loop].x4-11,array[loop].y4-5,m);
	 }
	else if(array[loop].get_in1==2)
	 {
	   sprintf(m,"%c",array[loop].ch1);
	   setcolor(15);
	   setfillstyle(1,9);
	   bar3d(array[loop].x4-15,array[loop].y4-10,array[loop].x4,array[loop].y4+5,0,0);
	   outtextxy(array[loop].x4-10,array[loop].y4-5,m);
	 }
	if(array[loop].get_in2==1)
	 {
	   sprintf(m,"%d",array[loop].in_2);
	   setcolor(15);
	   setfillstyle(1,3);
	   bar3d(array[loop].x5-15,array[loop].y5-5,array[loop].x5,array[loop].y5+10,0,0);
	   outtextxy(array[loop].x5-11,array[loop].y5,m);
	 }
	else if(array[loop].get_in2==2)
	 {
	   sprintf(m,"%c",array[loop].ch2);
	   setcolor(15);
	   setfillstyle(1,9);
	   bar3d(array[loop].x5-15,array[loop].y5-5,array[loop].x5,array[loop].y5+10,0,0);
	   outtextxy(array[loop].x5-10,array[loop].y5,m);
	 }
      }
     else if(array[loop].a==3)
      {
	if(array[loop].get_in1==1)
	 {
	   sprintf(m,"%d",array[loop].in_1);
	   setcolor(15);
	   setfillstyle(1,3);
	   bar3d(array[loop].x4-15,array[loop].y4-8,array[loop].x4,array[loop].y4+8,0,0);
	   outtextxy(array[loop].x4-11,array[loop].y4-2,m);
	 }
	else if(array[loop].get_in1==2)
	 {
	   sprintf(m,"%c",array[loop].ch1);
	   setcolor(15);
	   setfillstyle(1,9);
	   bar3d(array[loop].x4-15,array[loop].y4-8,array[loop].x4,array[loop].y4+8,0,0);
	   outtextxy(array[loop].x4-10,array[loop].y4-4,m);
	 }
      }
    }
 }
void draw_linkbox()
 {
   setcolor(15);
   for(i=0;i<=st_count;i++)
    {
      if(array[i].get_in1==-1 && array[i].in_1!=-1)
       {
	 sprintf(m,"%d",array[i].in_1);
	 setfillstyle(1,BLUE);
	 if(array[i].a==3)
	  {
	    bar3d(array[i].x4-15,array[i].y4-8,array[i].x4,array[i].y4+8,0,0);
	    outtextxy(array[i].x4-10,array[i].y4-3,m);
	  }
	 else if(array[i].a!=3 )
	  {
	    bar3d(array[i].x4-15,array[i].y4-10,array[i].x4,array[i].y4+5,0,0);
	    outtextxy(array[i].x4-10,array[i].y4-5,m);
	  }
       }
      if(array[i].get_in2==-1 && array[i].in_2!=-1)
       {
	 setfillstyle(1,BLUE);
	 sprintf(m,"%d",array[i].in_2);
	 if(array[i].a!=3 && array[i].in_2!=-1)
	  {
	    bar3d(array[i].x5-15,array[i].y5-5,array[i].x5,array[i].y5+10,0,0);
	    outtextxy(array[i].x5-10,array[i].y5,m);
	  }
       }
      if(array[i].out!=-1)
       {
	 setfillstyle(1,4);
	 sprintf(m,"%d",array[i].out);
	 bar3d(array[i].x1+8,array[i].y1-12,array[i].x1+18,array[i].y1-2,0,0);
	 outtextxy((array[i].x1)+10,array[i].y1-10,m);
       }
    }
 }
void remove_box()
 {
    //remove the box in which input is not given but linked
    setfillstyle(1,8);
    setcolor(8);
    for(i=0;i<=st_count;i++)
     {
       if(array[i].get_in1==-1)
	{
	 if(array[i].a==3)
	  bar3d(array[i].x4-15,array[i].y4-8,array[i].x4,array[i].y4+8,0,0);
	 else if(array[i].a!=3)
	   bar3d(array[i].x4-15,array[i].y4-10,array[i].x4,array[i].y4+5,0,0);
	}
       if(array[i].get_in2==-1)
	{
	 if(array[i].a!=3)
	  bar3d(array[i].x5-15,array[i].y5-5,array[i].x5,array[i].y5+10,0,0);
	}
       bar3d(array[i].x1+8,array[i].y1-12,array[i].x1+18,array[i].y1-2,0,0);
     }
 }
void total_getdraw()
 {
   setcolor(15);
   setfillstyle(1,8);
   bar3d(51,60,x-75,y-45,0,0);
   for(loop=0;loop<=n_o_gate;loop++)//Repetation of drawing gates
    draw_get(gate[loop].x,gate[loop].y,gate[loop].a);
   for(loop=0;loop<=n_o_line;loop++)//Repetation of drawing lines
    draw_line(lyne[loop].color1,lyne[loop].linx1,lyne[loop].liny1,lyne[loop].color2,lyne[loop].linx2,lyne[loop].liny2);
   // here work is much . It should  less in draw_box()
   draw_emptybox();
   draw_box(); //draw  the  box containing veriable or input
   if(only_1==0)  //after one derived , draw  the  box containing linked input
     draw_linkbox();
 }
void draw_emptybox()
 {
   setcolor(15);
   setfillstyle(1,3);
   for(j=0;j<=st_count;j++)
    {
      if(array[j].b1==1)
       {
	 if(array[j].a==3)
	    bar3d(array[j].x4-15,array[j].y4-8,array[j].x4,array[j].y4+8,0,0);
	 if(array[j].a!=3)
	    bar3d(array[j].x4-15,array[j].y4-10,array[j].x4,array[j].y4+5,0,0);
       }
      if(array[j].b2==1)
       {
	 if(array[j].a!=3)
	   bar3d(array[j].x5-15,array[j].y5-5,array[j].x5,array[j].y5+10,0,0);
       }
    }
 }
void h_draw()
     {
     setcolor(0);
       line(94,52,160,52);//input_0
       line(160,40,160,52);//input_0
       line(173,52,245,52);//input_1
       line(245,40,245,52);//input_1
       line(260,52,332,52);//output
       line(332,40,332,52);//output
       line(410,40,410,52);//box
       line(348,52,410,52);//box
       line(425,52,505,52);//variable
       line(505,40,505,52);//variable
       line(x-71,472,x-7,472);
       line(x-7,447,x-7,472);
       line(x-71,125,x-7,125);//AND
       line(x-7,64,x-7,125);//AND
       line(x-71,190,x-7,190);//OR
       line(x-7,127,x-7,190);//OR
       line(x-71,254,x-7,254);//NOT gate
       line(x-7,192,x-7,254);//NOT
       line(x-71,318,x-7,318);//NAND
       line(x-7,256,x-7,318);//NAND
       line(x-71,382,x-7,382); //NOR
       line(x-7,320,x-7,382); //NOR
       line(x-71,445,x-7,445);//XOR
       line(x-7,384,x-7,445);//XOR


     setcolor(15);
       line(94,40,160,40);//input_0
       line(94,40,94,52);//input_0
       line(173,40,245,40);//input_1
       line(173,52,173,40);//input_1
       line(260,40,332,40);//output
       line(260,40,260,52);//output
       line(348,40,410,40);//box
       line(348,40,348,52);//box
       line(425,40,505,40);//variable
       line(425,40,425,52);//variable
       line(x-71,447,x-7,447);
       line(x-71,447,x-71,472);
       line(x-71,64,x-7,64);//AND
       line(x-71,125,x-71,64);//AND
       line(x-71,127,x-7,127);//OR
       line(x-71,127,x-71,190);//OR
       line(x-71,192,x-7,192);//NOT gate
       line(x-71,254,x-7,254);//NOT
       line(x-71,256,x-7,256);//NAND
       line(x-71,318,x-71,318);//NAND
       line(x-71,320,x-7,320);//NOR
       line(x-71,382,x-71,382);//NOR
       line(x-71,384,x-7,384);// XOR
       line(x-71,445,x-71,445);// XOR
     }


void interface()
{
 char*msg;
 x=getmaxx();
 y=getmaxy();
 setbkcolor(8);
 setcolor(15);
 //***************************  TITLE BAR  *******************************
 setfillstyle(1,BLUE);
 bar3d(6,6,x-5,25,0,0);
 setcolor(0);
 line(x-5,6,x-5,25);
 line(x-5,25,6,25);
 setcolor(15);
 outtextxy((x-5)/3-20,13,"Electronic Logic Circuit Designer");
 setfillstyle(1,8);
 bar3d(51,60,x-75,y-45,0,0);//main area
 setfillstyle(1,3);
 bar3d(x-74,62,x-5,474,0,0);

 setfillstyle(1,4);
 bar3d(x-25,9,x-10,22,0,0);
 setcolor(15);
 line(x-25,9,x-10,22);
 line(x-25,22,x-10,9);

 setcolor(0);
 line(x-25,22,x-10,22);
 line(x-10,9,x-10,22);

 setcolor(15);
 setfillstyle(1,CYAN);
 bar3d(6,27,x-5,60,0,0);//Upper middel bar
 setcolor(0);

 line(x-5,27,x-5,60);
 line(x-5,60,6,60);
 setcolor(15);
  line(6,60,x-5,60);
 //************************  FOR NEW INPUT OUTPUT  *************************
 setfillstyle(1,7);
 bar3d(20,40,70,52,0,0);
  outtextxy(34,42,"New");
  setcolor(0);
 line(20,52,70,52);
 line(70,40,70,52);
  setcolor(15);
 bar3d(94,40,160,52,0,0);
   outtextxy(100,42,"Input-0");
 setcolor(0);
 line(94,52,160,52);
 line(160,40,160,52);
 setcolor(15);
 bar3d(173,40,245,52,0,0);
   outtextxy(180,42,"Input-1");
 setcolor(0);
 line(173,52,245,52);
 line(245,40,245,52);
 setcolor(15);
 bar3d(260,40,332,52,0,0);
   outtextxy(272,42,"Output");
 setcolor(15);
 bar3d(348,40,410,52,0,0);
   outtextxy(360,42," Box ");
 setcolor(0);
 line(348,52,410,52);
 line(410,40,410,52);
 setcolor(0);
 line(260,52,332,52);
 line(332,40,332,52);
 setcolor(15);
 bar3d(425,40,505,52,0,0);
   outtextxy(435,42,"Variable");
 setcolor(0);
 line(425,52,505,52);
 line(505,40,505,52);
 setcolor(15);
 bar3d(520,40,580,52,0,0);
 outtextxy(531,42,"Graph");
 setcolor(0);
 line(520,52,580,52);
 line(580,40,580,52);
 setcolor(15);
//**********************************************************************
 setfillstyle(1,9);
 bar3d(6,61,50,y-5,0,0);//Left bar
 setcolor(0);
 line(7,61,7,y-5);
 line(50,61,50,y-5);
 line(50,y-5,6,y-5);
 setcolor(15);
//**********************************************************************
 setfillstyle(1,3);
 bar3d(51,y-45,x-75,y-5,0,0);
    outtextxy(250,y-40,"Message bar");
    setcolor(0);
    line(51,y-44,x-75,y-44);
    line(x-75,y-45,x-75,y-5);
    line(51,y-6,x-75,y-6);
    setcolor(15);

 //*****************  RIGHT BAR CONTAINING LOGIC GATES  *****************
 setcolor(15);
 setfillstyle(1,3);
 bar3d(x-71,64,x-7,125,0,0);//"AND gate"
 setcolor(0);
 line(x-71,125,x-7,125);
 line(x-7,64,x-7,125);

 setcolor(15);
 setfillstyle(1,9);
 bar3d(x-71,127,x-7,190,0,0);//"OR"gate
 setcolor(0);
 line(x-71,190,x-7,190);
 line(x-7,127,x-7,190);

 setcolor(15);
 setfillstyle(1,2);
 bar3d(x-71,192,x-7,254,0,0);//"NOT"gate
 setcolor(0);
 line(x-71,254,x-7,254);
 line(x-7,192,x-7,254);

 setcolor(15);
 setfillstyle(1,3);
 bar3d(x-71,256,x-7,318,0,0);//"NAND"gate
 setcolor(0);
 line(x-71,318,x-7,318);
 line(x-7,256,x-7,318);

 setcolor(15);
 setfillstyle(1,9);
 bar3d(x-71,320,x-7,382,0,0);//"NOR"gate
 setcolor(0);
 line(x-71,382,x-7,382);
 line(x-7,320,x-7,382);

 setcolor(15);
 setfillstyle(1,2);
 bar3d(x-71,384,x-7,445,0,0);//"XOR"gate
 setcolor(0);
 line(x-71,445,x-7,445);
 line(x-7,384,x-7,445);

 setcolor(15);
 setfillstyle(1,3);
 bar3d(x-71,447,x-7,472,0,0);//line
 line(x-61,459,x-21,459);
 setcolor(0);
 line(x-71,472,x-7,472);
 line(x-7,447,x-7,472);
 setcolor(15);
//***************************  OR GATE  **********************************
 arc(540,91,294,318,100);
 arc(540,225,42,66,100);
 arc(505,158,0,18,80);
 arc(505,158,342,360,80);
 line(540+74,91+67, 623,158);
 line(572 ,148, 583,148);
 line(572 ,168, 583,168);
//**************************   NOT GATE  *********************************
 line(577,207,577,239);
 line( 572,223,577,223);
 line(577,207,611,223);
 line(577,239,611,223);
 circle(615,223,4);
 line(619,223,627,223);
//*************************   AND GATE  **********************************
 line(582,72,582,118);
 line(582,72,592,72);
 line(582,118,592,118);
 arc(592,95,0,90,23);
 arc(592,95,270,360,23);
 line(615,95,625,95);
 line(572,85,582,85);
 line(572,105 ,582,105);
//*************************   NAND GATE  ********************************
 line(582,263,582,309);
 line(582,263,592,263);
 line(582,309,592,309);
 arc(592,286,0,90,23);
 arc(592,286,270,360,23);
 circle(619,286,4);
 line(623,286,627,286);
 line( 582-10,276, 623-33-8, 276);
 line( 582-10,296, 623-33-8, 296);
//************************   NOR GATE  *********************************
 arc(535,284,294,318,100);
 arc(535,418,42,66,100);
 arc(500,351,0,18,80);
 arc(500,351,342,360,80);
 circle(613,351,4);
 line(535+74+8,284+67,625,351);
 line(571 , 341,578 ,341);
 line(571 , 361,578 ,361);
//************************   XOR GATE  *********************************
 arc(548,348,294,318,100);
 arc(547,481,42,66,100);
 arc(511,415,0,18,80);
 arc(511,415,342,360,80);
 line(622,415,628,415);
 //2nd part && line
 arc(505,415,0,18,80);
 arc(505,415,342,360,80);
 line(575 , 405,584 ,405);
 line(575 , 425,584 ,425);
}


int loaddrive()
{
  union REGS i,o;
  i.x.ax=0;
  int86(0x33,&i,&o);
  return (o.x.ax);
}
void showmouse()
{
  union REGS i,o;
  i.x.ax=1;
  int86(0x33,&i,&o);
}
void hidemouse()
{
  union REGS i,o;
  i.x.ax=2;
  int86(0x33,&i,&o);
}
void mouseposition()
{
  union REGS i,o;
  i.x.ax=3;
  int86(0x33,&i,&o);
  button=o.x.bx;
  mouse_x=o.x.cx;
  mouse_y=o.x.dx;
}
void restrictmouseptr(int x_1,int y_1,int x_2,int y_2)
{
 union REGS i,o;
 i.x.ax=7;
 i.x.cx=x_1;
 i.x.dx=x_2;
 int86(0x33,&i,&o);
 i.x.ax=8;
 i.x.cx=y_1;
 i.x.dx=y_2;
 int86(0x33,&i,&o);

}
//******************  END OF PART OF MOUSE PROGRAMMING ********************

void load()
  {
     int a;
     clrscr();
     setcolor(14);
     setfillstyle(1,9);
     floodfill(10,10,getmaxcolor());
     settextstyle(1,0,5);
     outtextxy(100,20,"Logic Circuit Designer");

     delay(1000);
     settextstyle(7,0,1);
     setcolor(8);
     outtextxy(145,120,"Md Babul Sarker Sumon    020211");
     outtextxy(145,140,"Md Rashadul Hasan Rakib  020212");
     outtextxy(145,160,"Sk Alamgir Hossain Hira   020216");
     setcolor(14);
     settextstyle(5,0,3);
     outtextxy(145,240,"Advised by... ");
     settextstyle(7,0,1);
     outtextxy(145,270,"Mr Masud Karim");
     music(3);
     getch();
     setfillstyle(1,5);
     floodfill(10,10,getmaxcolor());
     settextstyle(1,0,3);
     outtextxy(150,220,"LOADING ......................");
	setcolor(14);
	rectangle(150,250,383,250);
	settextstyle(1,0,3);
     outtextxy(150,250,"Please,Wait..................");
     setcolor(4);
     for(a=150;a<=383;a++){
     line(a,250,a,250);
     delay(10);
     }
      delay(10);
     settextstyle(0,0,0);
     setcolor(0);
     setfillstyle(1,0);
     bar3d(0,0,639,479,0,0);
  }
/********************************************************************
***************************** music *********************************
********************************************************************/
music ( int type )
{
      float octave[7]={130.81,146.83,164.81,174.61,196,220,246.94};
      int m, j ;
      switch ( type )
	{
	     case 1 :
		  for ( j = 0 ; j < 5 ; j++ )
			{
			     sound ( octave[j] * 7 ) ;
			     delay ( 19 ) ;
			}
			nosound() ;
			break ;

	     case 2 :
		   for ( j = 0 ; j < 16 ; j++ )
			{
			     m = random ( 7 ) ;
			     sound ( octave[m] * 4 ) ;
			     delay ( 95 ) ;
			}
			delay(500);
			nosound() ;
			break ;
	     case 3 :
		    while ( !kbhit() )
			{
			      setcolor(j++);
			      gotoxy(20,25);
			      if(j%2==0)gotoxy(21,25);
			      settextstyle(4,0,5);
			      outtextxy(100,350,"Press any key to continue... ");
			      m = random ( 7 ) ;
			      sound ( octave[m] * 4 ) ;
			      delay ( 100 ) ;
			}
			nosound() ;
			break ;
	     case 4 :
		     for ( j = 6 ; j >= 0 ; j-- )
			{
			     sound ( octave[j] * 4 ) ;
			     delay ( 16 ) ;
			}
			nosound() ;
			break ;

	     case 5 :
		    for ( j = 8 ; j >= 0 ; j-- )
			{
			     sound ( octave[j] ) ;
			     delay ( 60 ) ;
			}
			nosound() ;
			break ;
	      case 6:
		    for ( j = 0 ; j < 5 ; j++ )
			{
			     sound ( octave[j] * 9 ) ;
			     delay ( 19 ) ;
			}
			nosound() ;
			break ;
	      case 7 :
		  for ( j = 0 ; j < 5 ; j++ )
			{
			     sound ( octave[j] * 8 ) ;
			     delay ( 19 ) ;
			}
			nosound() ;
			break ;

	 }
	 return 0;

}

//*********************************************************
void draw_get(int mousex,int mousey,int a)
   {
     if(a==1)
       {
	  setcolor(15);
	  line(mousex-10,mousey-23,mousex-10,mousey+23);
	  line(mousex-10,mousey-23,mousex,mousey-23);
	  line(mousex-10,mousey+23,mousex,mousey+23);
	  arc(mousex,mousey,0,90,23);
	  arc(mousex,mousey,270,360,23);
	  line(mousex+25,mousey,mousex+35,mousey);
	  line(mousex-40,mousey-10, mousex-10,mousey-10);
	  line(mousex-40,mousey+10, mousex-10,mousey+10);
       }
     else if(a==2)
       {
	  setcolor(15);
	  arc(mousex-42,mousey-67,294,318,100);
	  arc(mousex-42,mousey+67,42,66,100);
	  arc(mousex-77,mousey,0,18,80);
	  arc(mousex-77,mousey,342,360,80);
	  line(mousex+33,mousey,mousex+43,mousey);
	  line(mousex-30,mousey-10, mousex,mousey-10);
	  line(mousex-30,mousey+10, mousex,mousey+10);
       }
     else if(a==3)
       {
	  setcolor(15);
	  line(mousex-10,mousey-16,mousex-10,mousey+16);
	  circle(mousex+28,mousey,4);
	  line(mousex+32,mousey,mousex+40,mousey);
	  line(mousex-10,mousey-16,mousex+24,mousey);
	  line(mousex-10,mousey+16,mousex+24,mousey);
	  line(mousex-40,mousey,mousex-10,mousey);
       }
     else if(a==4)
       {
	  setcolor(15);
	  line(mousex-10,mousey-23,mousex-10,mousey+23);
	  line(mousex-10,mousey-23,mousex,mousey-23);
	  line(mousex-10,mousey+23,mousex,mousey+23);
	  arc(mousex,mousey,0,90,23);
	  arc(mousex,mousey,270,360,23);
	  circle(mousex+27,mousey,4);
	  line(mousex+31,mousey,mousex+39,mousey);
	  line(mousex-40,mousey-10, mousex-10,mousey-10);
	  line(mousex-40,mousey+10, mousex-10,mousey+10);
       }
     else if(a==5)
       {
	  setcolor(15);
	  arc(mousex-42,mousey-67,294,318,100);
	  arc(mousex-42,mousey+67,42,66,100);
	  arc(mousex-77,mousey,0,18,80);
	  arc(mousex-77,mousey,342,360,80);
	  circle(mousex+36,mousey,4);
	  line(mousex+40,mousey,mousex+50,mousey);
	  line(mousex-30,mousey-10, mousex,mousey-10);
	  line(mousex-30,mousey+10, mousex,mousey+10);
       }
     else if(a==6)
       {
	  setcolor(15);
	  arc(mousex-42,mousey-67,294,318,100);
	  arc(mousex-42,mousey+67,42,66,100);
	  arc(mousex-77,mousey,0,18,80);
	  arc(mousex-77,mousey,342,360,80);
	  line(mousex+32,mousey,mousex+42,mousey);
	  arc(mousex-83,mousey,0,18,80);
	  arc(mousex-83,mousey,342,360,80);
	  line(mousex-35,mousey-10,mousex-5,mousey-10);
	  line(mousex-35,mousey+10,mousex-5,mousey+10);
       }
   }
//***************************************************************
void draw_line(int color1,int linx1,int liny1,int color2,int linx2,int liny2)
 {
    line(linx1,liny1,linx2,liny2);
    setcolor(color1);
    setfillstyle(SOLID_FILL,color1);
    circle(linx1,liny1,2);
    floodfill(linx1,liny1,color1);
    setcolor(color2);
    setfillstyle(SOLID_FILL,color2);
    circle(linx2,liny2,2);
    floodfill(linx2,liny2,color2);
    setcolor(15);
 }
