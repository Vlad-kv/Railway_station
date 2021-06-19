#include "layout.h"

using namespace std;

void layout::draw_tree(int main_width, int main_height, int width_shift, int height_shift) {
    int x = width_shift + text_shift;
    int y = main_height - height_shift - font_h;

    print_text(x, y, name, main_width, main_height);

    draw_line({{x - frame_size, y - frame_size - 6},
               {x - frame_size, y + font_h + frame_size - 6},
               {x + frame_size + get_text_width(name), y + font_h + frame_size - 6},
               {x + frame_size + get_text_width(name), y - frame_size - 6},
               {x - frame_size, y - frame_size - 6}
              },
              main_width,
              main_height
    );
    
    if (left != nullptr) {
        left->draw_tree(main_width,
                        main_height,
                        width_shift,
                        height_shift + dist_between_levels + font_h + frame_size * 2 + 2);

        draw_line({{width_shift + name_center, y - frame_size - 6},
                   {width_shift + left->name_center, y - frame_size - 6 - dist_between_levels - 2}},
                  main_width,
                  main_height);
    }
    if (right != nullptr) {
        right->draw_tree(main_width,
                         main_height, 
                         width_shift + name_center, 
                         height_shift + dist_between_levels + font_h + frame_size * 2 + 2);

        draw_line({{width_shift + name_center, y - frame_size - 6},
                   {width_shift + name_center + right->name_center, y - frame_size - 6 - dist_between_levels - 2}},
                  main_width,
                  main_height);
    }
}

layout* layout::build_layout(const typename binary_tree<std::string, std::vector<std::shared_ptr<train_data>>>::node* c) {
    if (c == nullptr) {
        return nullptr;
    }
    layout* l = new layout(c->data.first);

    l->height = l->font_h + l->frame_size * 2 + 2;

    int half = get_text_width(std::string(l->name)) / 2 + l->frame_size + 2;

    int left_w  = half;
    int right_w = half;
    int children_h = 0;

    l->left  = build_layout(c->left);
    l->right = build_layout(c->right);

    if (l->left != nullptr) {
        left_w = max(left_w, l->left->width);
        children_h = max(children_h, l->left->height);
    }
    if (l->right != nullptr) {
        right_w = max(right_w, l->right->width);
        children_h = max(children_h, l->right->height);
    }
    l->width = left_w + right_w;

    if (children_h > 0) {
        l->height += children_h + l->dist_between_levels;
    }

    l->name_center = left_w;

    l->text_shift = left_w - half + l->frame_size + 1;
    return l;
}
