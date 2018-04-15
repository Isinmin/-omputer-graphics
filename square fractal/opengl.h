#ifndef OPENGL_H
#define OPENGL_H
#include <QOpenGLWidget>


class opengl: public QOpenGLWidget
{
    Q_OBJECT
public:
    opengl();
    void setStep(int step);
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
private:
    struct point{
        float x;
        float y;
        point(float x=0.,float y=0.){
            this->x=x;
            this->y=y;
        }
    };

    struct vect{
        float x;
        float y;
        vect(int x=0,int y=0){
            this->x=x;
            this->y=y;
        }
        vect turnRight(){
            return vect(y,-x);
        }
        vect turnLeft(){
            return vect(-y,x);
        }
    };

    int step=4;
    float koef = 0.35f;
    float startLen = .8;
    point startPoint = point(-0.4,-0.4);
    void recursiveDraw(point p,vect v,float lenght,int steps,int current);
};

#endif // OPENGL_H
