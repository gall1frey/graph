#include<iostream> //for input of NoReadings
#include<graphics> //for graphics

using namespace std;

/*This function inputs readings into 2 arrays,
  First for values on x axis,
  second for values on y axis*/
void GetData(float x[], float y[], int r)
{
	cout<<"\nEnter Values as they are asked\n\n";
	for(int i=0; i<r; i++)
	{
		cout<<"Enter reading #0"<<i+1<<", x axis:";
		cin>>x[i];
		cout<<"\tEnter reading #0"<<i+1<<", y axis:";
		cin>>y[i];
		cout<<"\n";
	}
}

/*This function changes the readings into
  coordinates so that they can be plotted
	on the graph.*/
void GetCoordinates(float x[], float y[], int r)
{
	int maxy=getmaxy();
	for(int i=0;i<r;i++)
	{
		x[i]=(x[i]*20)+20;
		y[i]=(maxy-20)-(20*y[i]);
	}
}

//This function puts numbers near graph
void Numbers()
{
	int my=getmaxy();
	setcolor(2);
	//The y axis and origin
	outtextxy(15,my-20,"0"); outtextxy(15,my-40,"1");
	outtextxy(15,my-60,"2"); outtextxy(15,my-80,"3");
	outtextxy(15,my-100,"4"); outtextxy(15,my-120,"5");
	outtextxy(15,my-140,"6"); outtextxy(15,my-160,"7");
	outtextxy(15,my-180,"8"); outtextxy(15,my-200,"9");
	outtextxy(15,my-220,"10"); outtextxy(15,my-240,"11");
	outtextxy(15,my-260,"12"); outtextxy(15,my-280,"13");
	outtextxy(15,my-300,"14"); outtextxy(15,my-320,"15");
	outtextxy(15,my-340,"16"); outtextxy(15,my-360,"17");
	outtextxy(15,my-380,"18"); outtextxy(15,my-400,"19");
	outtextxy(15,my-420,"20"); outtextxy(15,my-440,"21");
	outtextxy(15,my-460,"22"); outtextxy(15,my-480,"23");
	//The x axis
  outtextxy(40,my-15,"1");
	outtextxy(60,my-15,"2"); outtextxy(80,my-15,"3");
	outtextxy(100,my-15,"4"); outtextxy(120,my-15,"5");
	outtextxy(140,my-15,"6"); outtextxy(160,my-15,"7");
	outtextxy(180,my-15,"8"); outtextxy(200,my-15,"9");
	outtextxy(220,my-15,"10"); outtextxy(240,my-15,"11");
	outtextxy(260,my-15,"12"); outtextxy(280,my-15,"13");
	outtextxy(300,my-15,"14"); outtextxy(320,my-15,"15");
	outtextxy(340,my-15,"16"); outtextxy(360,my-15,"17");
	outtextxy(380,my-15,"18"); outtextxy(400,my-15,"19");
	outtextxy(420,my-15,"20"); outtextxy(440,my-15,"21");
	outtextxy(460,my-15,"22"); outtextxy(480,my-15,"23");
}

/*This function draws the x axis,
  the y axis and the grey grid that
	is used for the sake of clarity*/
void DrawGraph()
{
	int i,j;
	int x=getmaxx();
	int y=getmaxy();
	line(20,y,20,0);
	line(0,y-20,x,y-20);
	setcolor(8);           //changes color to grey
  for (i=40; i<x; i+=20)
	line(i,y,i,0);
	for (i=20; i<y; i+=20)
	line(x,i,0,i);
	Numbers();
}

/*This function plots points on the graph
  in the form of tiny pink circles*/
void PlotPoints(float x[], float y[], int r)
{
	setcolor(5); //Changes color to pink
	for (int c=0;c<r;c++)
	{
		circle(x[c],y[c],2);
	}
}

/*This function joins the points
	on the graph using white lines*/
void JoinTheDots(float x[], float y[], int r)
{
	setcolor(7);
	for (int j=0; j<r-1; j++)
	{
		line(x[j],y[j],x[j+1],y[j+1]);
	}
}

//Main function
int main()
{
	float xArr[30], yArr[30];  //Arrays to store readings
	int NoReadings=0;          //Total No. of readings
	cout<<"How many readings?"; //Asks for total no. of readings
	cin>>NoReadings;
	GetData(xArr, yArr, NoReadings);  //Calls func. to get readings

	clrscr(); //Clears screen to draw graph

	/* idk what these two lines do, but they apparently
			open a "graphics window", and qithout this,
			graph is not possible.
			DO NOT MOVE OR EDIT THIS CODE NO MATTER WHAT*/
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

	DrawGraph();                            //Draws graph
	GetCoordinates(xArr, yArr, NoReadings); //Converts readings to coordinates
	PlotPoints(xArr, yArr, NoReadings);     //Plots Points on graph
	JoinTheDots(xArr, yArr, NoReadings);    //Makes lines joining the points

	return 0;
}
