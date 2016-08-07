import graph;
usepackage ("lmodern");
size (400, 400); //, IgnoreAspect);
defaultpen (font ("ptmr8t", 7pt) + 0.1);

pen apen= font ("ptmr8t", 10pt) + 1;
pen bpen= font ("ptmr8t", 9pt) + 1.2;
pen cpen= font ("ptmr8t", 7pt) + 0.5;
pen dpen= font ("ptmr8t", 12pt) + 2;
pen epen= font ("ptmr8t", 9pt) + 1.5;
pen fpen= Helvetica (series="b", shape="n");
pen graypen1= font ("ptmr8t", 14pt) + gray(0.7);
pen graypen2= font ("ptmr8t", 14pt) + gray(0.5);
pen redpen= font ("ptmr8t", 14pt) + rgb(1,0,0) + 1.5;
pen bluepen= font ("ptmr8t", 14pt) + rgb(0,0,1) + 1.5;
pen greenpen= font ("ptmr8t", 14pt) + rgb(0,1,0) + 1;
string[] cn={ "1", "2", "3", "4", "5"};

string fname = stdin;
//file finPath = input ("pathCoordSeveral.txt");
//file finPath = input (fname);
//file finPath = input ("pathCoord.txt");
//file finPath = input ("cutCoord.txt");
//file finSquares = input("valvesCoord.txt");

file finDevices = input("devices.txt");
file finPath = input("paths.txt");
//real[] row = finSquares; //means row unlimited, column 1
//real[] pathCoord = finPath; 

real[] devices = finDevices;
real[] paths = finPath;

/*for (int i = 0; i < squares.length ; i+=5)
{	
	if( squares[i] == -1)
		filldraw(box((squares[i+1],squares[i+2]),(squares[i+3],squares[i+4])),redpen);
	else if(squares[i] == -2)
		filldraw(box((squares[i+1],squares[i+2]),(squares[i+3],squares[i+4])),greenpen);
	else 
		filldraw(box((squares[i+1],squares[i+2]),(squares[i+3],squares[i+4])),graypen2);
	
}*/

for(int i = 0; i < devices.length ; i+=4)
{	
	
	filldraw(box((devices[i],devices[i+1]),(devices[i+2],devices[i+3])),greenpen);
	
	
}

path p;
int flag = 0;
for (int i = 0; i < paths.length ; i+=4)
{	
	
	
	p = (paths[i],paths[i+1]) -- (paths[i+2],paths[i+3]);

	draw(p,bluepen);

}

/*for (int i = 0; i < pathCoord.length ; i+=4)
{	
	p = (pathCoord[i],pathCoord[i+1]) -- (pathCoord[i+2],pathCoord[i+3]);
	draw(p,bluepen);
	
}*/



//xaxis(BottomTop,LeftTicks);
//yaxis(LeftRight,RightTicks);

//picture pic;
//label(pic, graphic("../tb_top.ps"),(100,100),NE);
//clip(pic,(255,446)--(255,566)--(562,566)--(562,446)--cycle);
//add(currentpicture, pic.fit(),(50,50),N);