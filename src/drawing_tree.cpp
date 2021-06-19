#include "drawing_tree.h"

layout* global_layout;

void draw_line(const std::vector<std::pair<int, int>>& line, int main_width, int main_height) {
    glLineWidth(1);

    for (int i = 1; i < (int)line.size(); i++) {
        glBegin(GL_LINES);
        for (int j = 0; j < 2; j++) {
            glVertex2d((line[i - 1 + j].first  - main_width  / 2.0) / (main_width  / 2.0),
                       (line[i - 1 + j].second - main_height / 2.0) / (main_height / 2.0)
            );
        }
        glEnd();
    }
}

int get_text_width(const std::string& s) {
    int length = 0;
    for (char c : s) {
        length += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    return length;
}

int print_text(int x, int y, const std::string& s, int main_width, int main_height) {
    int length = 0;
    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, main_width, 0, main_height);

    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);
    
    for (char c : s) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        length += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    glPopMatrix();

    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );
    return length;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,0.0f,0.0f);

    if (global_layout != nullptr) {
        global_layout->draw_tree(global_layout->width + 10, global_layout->height + 10, 0, 0);
    }

    glutSwapBuffers();
}
