#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QPainter>
#include <QTimer>

class Widget : public QWidget
{

public:
    int xMax=500;
    int yMax=500;
    int x = 0 ;
    int y = 0;
    bool ready = false;

    void move(){
        if(!(x==xMax or y==yMax)){
            x +=1;
            y+=1;
        }if(ready){
            ready = true;
        }


    }

protected:
    void paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        painter.setPen(QPen(Qt::black, 12, Qt::DashDotLine, Qt::RoundCap));
        painter.drawPoint(x,y);
        move();
        if(!ready){
            update();
        }
    }
};



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget window;
    window.resize(1920,1080);
    window.show();
    return app.exec();
}

