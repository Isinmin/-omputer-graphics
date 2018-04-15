#include "opengl.h"

opengl::opengl()
{

}

void opengl::setStep(int step){
    this->step=step;
    update();
}

void opengl::initializeGL(){

}

void opengl::resizeGL(int w, int h){

}

void opengl::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    glVertex3f(startPoint.x,startPoint.y,0);
    recursiveDraw(startPoint,vect(0,1),startLen,4,step);
    glEnd();
  //  glFlush();
}


void opengl::recursiveDraw(point p,vect v,float lenght,int steps,int current){
    if (current<=0) return;
    float nextLen = lenght*koef;
    float subLen = (lenght - nextLen)/2.f;
    point nextP;
    for(int i=0;i<steps;i++){
        nextP = point(p.x + v.x*subLen,p.y + v.y*subLen);
        glVertex3f(nextP.x,nextP.y,0);
        recursiveDraw(nextP,v.turnLeft(),nextLen,3,current-1);
        p = point(p.x + v.x*lenght,p.y + v.y*lenght);
        glVertex3f(p.x,p.y,0);
        v = v.turnRight();
    }
}
