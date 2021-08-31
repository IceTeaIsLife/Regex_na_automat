#include <stdio.h>
#include "regex.h"

int main() {
    struct RegexEngine engine;
    engine_init(&engine);
    scanf("%s", engine.line);
    while (engine.is_found != true && engine.index < 255) {
        engine_tick(&engine);
        if (engine.is_error == true) {
            break;
        }
    }
    if (engine.is_found) {
        printf("%s\n", "REGEX FOUND");
    } else printf("%s\n", "ERROR");
    return 0;
}
/*
++++++++++++
aaa:a
a:a
aa:a
B:B
B::B


------------------
aaa:a
a:aa
B:::B

*/