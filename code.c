
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

char **manipulate_args(int argc, const char *const *argv, int (*const manip)(int)) {
    char **new_string = malloc((argc + 1) * sizeof(char *));
    if (!new_string) {
        return NULL;
    }

    for (int i = 0; i < argc; i++) {
        int length = strlen(argv[i]);
        new_string[i] = malloc((length + 1) * sizeof(char));

        if (!new_string[i]) {
            for (int j = 0; j < i; j++) {
                free(new_string[j]);
            }
            free(new_string);
            return NULL;
        }
        for (int j = 0; j < length; j++) {
            new_string[i][j] = manip(argv[i][j]);
        }
        new_string[i][length] = '\0';
    }

    new_string[argc] = NULL;
    return new_string;
}

void free_copied_args(char **args, ...) {
    va_list new_list;

    va_start(new_list, args);

    while (args != NULL) {
        for (int i = 0; args[i] != NULL; i++) {
            free(args[i]);
        }
        free(args);
        args = va_arg(new_list, char **);
    }

    va_end(new_list);
}
    
