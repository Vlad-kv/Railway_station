#ifndef DRAWING_TREE_H
#define DRAWING_TREE_H 0

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <GL/freeglut.h>

#include <vector>
#include <iostream>

#include "binary_tree.h"

template<typename T, typename V>
void draw_tree(const binary_tree<T, V>* tree);

void draw_line(const std::vector<std::pair<int, int>>& line, int main_width, int main_height);

int get_text_width(const std::string& s);

int print_text(int x, int y, const std::string& s, int main_width, int main_height);

void display();

#include "layout.h"

extern layout* global_layout;

template<typename T, typename V>
void draw_tree(const binary_tree<T, V>* tree) {
    global_layout = layout::build_layout(tree);

    glutInitDisplayMode(GLUT_DOUBLE);
    if (global_layout == nullptr) {
        glutInitWindowSize(100, 100);
    } else {
        glutInitWindowSize(global_layout->width + 20, global_layout->height + 20);
    }
    
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Window");
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, 0, 0);

    glutDisplayFunc(display);
    glutMainLoop();
}

#endif // DRAWING_TREE_H
