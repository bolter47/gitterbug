/********************************************************************************/
/*                                                                              */
/*  INF-1010 Lab 6 :                                                            */
/*  Interface Graphique et Exception                                      	  	*/
/*                                                                              */
/********************************************************************************/

#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
