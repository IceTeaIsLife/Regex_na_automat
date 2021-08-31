#ifndef REGEX_AUTOMATA_REGEX_H
#define REGEX_AUTOMATA_REGEX_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__cplusplus)
extern  "C" {
#endif


#define symbol_colon engine->line[engine->index] == ':'
#define symbol_a engine->line[engine->index] == 'a'
#define symbol_B engine->line[engine->index] == 'B'


enum RegexState{
    State_0, State_1,
    State_2, State_3, State_4,
    State_Complete, State_Error
};


struct RegexEngine {
    enum RegexState state;
    int a_counter;
    int colon_counter;
    bool is_error;
    int index;
    char line[255];
    bool is_found;

};

bool engine_init(struct RegexEngine *engine);
void engine_tick(struct RegexEngine *engine);
bool engine_reset(struct RegexEngine *engine);

#if defined(__cplusplus)
}
#endif


#endif //REGEX_AUTOMATA_REGEX_H
