#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <sqlite3.h>

#include "includes/database.h"
#include "includes/visualization.h"

int main(int argc, char **argv) {
        struct db_settings alpha;

        int res = 0;
        switch (argc) {
        case 1:
                alpha.is_temp_db = true;
                res = sqlite3_open(":memory:", &(alpha.db));
                printf("\e[34mopening in_memory db\e[0m\n");
                break;
        case 2:
                alpha.is_temp_db = false;
                res = sqlite3_open(argv[1], &(alpha.db));
                printf("\e[34mopening in_file db\e[0m\n");
                break;
        default:
                printf("\e[31musage: mapper [input_file.db]\e[0m\n");
                return 0;
        }

        if (res != SQLITE_OK) {
                printf("\e[31msqlitt3_open failed on %s\e[0m\n", argv[1]);
                return 1;
        }

        main_loop(&alpha);

        res = sqlite3_close(alpha.db);
        return 0;
}
