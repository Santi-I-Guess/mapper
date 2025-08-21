#ifndef GRAPH_HANDLING_H
#define GRAPH_HANDLING_H

#define TRAIL_ARRAY_LEN 256
#define NODE_NAME_LEN 64

struct node {
        uint8_t color;
        uint16_t x, y, z;
        char name[NODE_NAME_LEN];  // default to empty
};

// avoid premature optimization
struct edge {
        uint8_t color;
        struct { uint16_t x, y, z; } parent;
        struct { uint16_t x, y, z; } child;
};

#endif
