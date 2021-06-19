#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>

#include <GL/freeglut.h>
// #include "freeglut/freeglut/include/GL/freeglut_ext.h"
// #include "freeglut/freeglut/include/GL/freeglut_std.h"
// #include "freeglut/freeglut/include/GL/freeglut_ucall.h"
// #include "freeglut/freeglut/include/GL/glut.h"
// #include "freeglut/freeglut/src/fg_internal.h"

/*
int main(int argc, char **argv) {
  
  if(!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  glfwDefaultWindowHints();

  GLFWwindow* window = glfwCreateWindow(300, 300, "Red Triangle",
                                        nullptr, nullptr);
  if(window == nullptr) {
    std::cerr << "Failed to open GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  glfwShowWindow(window);

  // Важно! Не эквивалентно glEnable(GL_DEPTH_TEST | GL_DOUBLEBUFFER)
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_DOUBLEBUFFER);
  glDepthFunc(GL_LESS);

  glClearColor(0, 0, 0, 1);

  glm::mat4 m = glm::perspective(45.0f, 4.0f / 3.0f, 1.0f, 100.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf(glm::value_ptr(m));

  while(glfwWindowShouldClose(window) == GL_FALSE) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4f(1, 0, 0, 1);
    glBegin(GL_TRIANGLES);
    glVertex3f(   0,  0.5, -5);
    glVertex3f( 0.5, -0.5, -5);
    glVertex3f(-0.5, -0.5, -5);
    glEnd();

    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'a');

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;


}
*/

void display()
     {
       glClear(GL_COLOR_BUFFER_BIT);//очищаем буфер
       glColor3f(1.0f,0.0f,0.0f);//задаем цвет рисования
       glLineWidth(3);//задаем толщину линии
       glBegin(GL_LINES);//говорим что будем рисовать линию
       glVertex2d(-1, 0);//координата начала отрезка в формате (x,y)
       glVertex2d( 1, 0);//координата конца отрезка
       glEnd();//говорим что закончили рисовать линию

       glutStrokeCharacter(GLUT_STROKE_ROMAN, 'a');

       glutSwapBuffers();//прорисовываем буфер на экран
     }

void display_2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);//задаем цвет рисования

    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D( 0, 1280, 0, 1024 );

    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i( 20, 1000 );  // move in 10 pixels from the left and bottom edges
    
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'a');
    
    glPopMatrix();

    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );

    glutSwapBuffers();//прорисовываем буфер на экран
}  

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Window");
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, 0, 0);
    glutDisplayFunc(display_2);
    glutMainLoop();
    return 0;
}
