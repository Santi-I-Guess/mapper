#ifndef GRAPH_HANDLING_H
#define GRAPH_HANDLING_H

#include <stdint.h>

#define TRAIL_ARRAY_LEN 256
#define NODE_NAME_LEN 64

// note to self: fucking with preprocessor redefintions is HARD to debug
enum raylib_color {
        RC_LIGHTGRAY,
        RC_GRAY,
        RC_DARKGRAY,
        RC_YELLOW,
        RC_GOLD,
        RC_ORANGE,
        RC_PINK,
        RC_RED,
        RC_MAROON,
        RC_GREEN,
        RC_LIME,
        RC_DARKGREEN,
        RC_SKYBLUE,
        RC_BLUE,
        RC_DARKBLUE,
        RC_PURPLE,
        RC_VIOLET,
        RC_DARKPURPLE,
        RC_BEIGE,
        RC_BROWN,
        RC_DARKBROWN,
        RC_WHITE,
        RC_BLACK,
        RC_BLANK,
        RC_MAGENTA,
        RC_RAYWHITE
};

struct node {
        uint8_t color; // default
        uint8_t floor; // bigger floors are deeper
        int16_t x, y, z;
        char name[NODE_NAME_LEN];  // default to empty
};

// avoid premature optimization
struct edge {
        uint8_t color;
        struct { uint8_t floor; int16_t x, y, z; } parent;
        struct { uint8_t floor; int16_t x, y, z; } child;
};

#endif
