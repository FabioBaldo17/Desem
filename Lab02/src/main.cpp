#include "main.h"

using namespace std;
void getFigureAspect( Point & tl, Point & br, color::colorList & cl);

int main()
{	string answer="add";
	string figureType;
	vector<Figure*> figures;
	Point tl;
	Point br;
	color::colorList cl;
	vector<Figure*>::iterator itr;

	cout << "Hi this is your graphicla editor." << endl;

	while (answer!="fu")
	{
		cout << "Would you like to add a figure to your drawing? [add/no]" << endl;
		cin >> answer;

		while (answer!="add" and answer!="no" )
		{
			cout << "You entered a non valid option, retry!" << endl;
			cin >> answer;
		}
		
		if (answer=="no") return 0;

		cout << "Ok! let's add it..." << endl;
		printf("What figure would you like?\n\tc->circle\n\tl->line\n\tr->rectangle\n");
		cin >> figureType;
		cout << "OK, now tel me more..." << endl;


		switch (figureType.c_str()[0])
		{
			case 'l':
				getFigureAspect(tl, br, cl);
				figures.push_back(new Line(tl, br, cl));
				break;
			case 'c':
				getFigureAspect(tl, br, cl);
				figures.push_back(new Circle(tl, br, cl));
				break;
			case 'r':
				getFigureAspect(tl, br, cl);
				figures.push_back(new Rectangle(tl, br, cl));
				
				break;
			
			default:
				cout << "You inserted a non valid figure." << endl;
				break;
		}

		cout << "Would you like I show your drawing? [yes/no]" << endl;
		cin >> answer;

		
		while (answer!="yes" and answer!="no")
		{
			cout << "You entered a non valid option, retry!" << endl;
			cin >> answer;		
		}

		if (answer=="no") return 0;
		
		for (size_t i = 0; i < figures.size(); i++)
		{
			figures.at(i)->printInfo();
		}
	

	}	

	return 0;
}



void getFigureAspect( Point & tl, Point & br, color::colorList & cl)
{
	string answer;

	cout << "Tell me the top left x coordinate\nx = " ;
	cin >> answer;
	tl.setX(stoi(answer));
	cout << endl;
	cout << "Tell me the top left y coordinate\ny = " ;
	cin >> answer;
	tl.setY(stoi(answer));
	cout << endl;

	cout << "Tell me the bottom right x coordinate\nx = " ;
	cin >> answer;
	br.setX(stoi(answer));
	cout << endl;
	cout << "Tell me the bottom right y coordinate\ny = " ;
	cin >> answer;
	br.setY(stoi(answer));
	cout << endl;

	cout << "Ok, perfect! Now tell me what color\n\tb->blue\n\ty->yellow\n\tp->purple" << endl;
	cin >> answer;
	cl=color::getColor(answer.at(0));
	cout << endl;
}