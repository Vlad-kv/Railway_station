#ifndef LAYOUT_H
#define LAYOUT_H 0

#include <string>
#include <memory>
#include <vector>
#include <GL/freeglut.h>

#include "train_data.h"
#include "binary_tree.h"

struct layout {
    std::string name;

    layout* left = nullptr;
    layout* right = nullptr;

    int height = 0;
    int width = 0;
    int text_shift = 0;
    int name_center = 0;

    const int frame_size = 2;
    const int font_h = glutBitmapHeight(GLUT_BITMAP_TIMES_ROMAN_24);
    const int dist_between_levels = 20;

    layout(const std::string& name)
        : name(name) {
    }

    static layout* build_layout(const binary_tree<std::string, std::vector<std::shared_ptr<train_data>>>* bt) {
        return build_layout(bt->root);
    }

    static layout* build_layout(const typename binary_tree<std::string, std::vector<std::shared_ptr<train_data>>>::node* c);

    void draw_tree(int main_width, int main_height, int width_shift, int height_shift);
};

#include "binary_tree.h"
#include "drawing_tree.h"

#endif // LAYOUT_H
