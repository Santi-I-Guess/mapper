#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include "graph_handling.h"

struct db_settings {
        sqlite3 *db;
        bool is_temp_db;
        enum raylib_color curr_node_default_color; // black
        enum raylib_color curr_edge_default_color; // blue
};

// each change is an instruction on how to sync the file with the program data
enum db_change_enum {
        INSERT_NODE,
        INSERT_EDGE,
        REMOVE_NODE,
        REMOVE_EDGE,
        EDIT_NODE,
        EDIT_EDGE
};

struct db_change {
        // alpha_node/edge is either
        // data to insert
        // indentifier for data to remove
        // identifier for data to change
        enum db_change_enum the_change;
        struct node alpha_node;
        struct edge alpha_edge;
};

#endif
