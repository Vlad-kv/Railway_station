#ifndef LAYOUT_H
#define LAYOUT_H 0

#include "binary_tree.h"
#include <string>



struct layout {
    std::string name;

    layout* left;
    layout* right;

    size_t height;
    size_t width;

    node(const string& name);

    template <typename T, typename V>
    static layout* build_layout(const binary_tree& bt);
};


#endif // LAYOUT_H
