#include "regex.h"


bool engine_init(struct RegexEngine *engine) {
    engine->index = 0;
    engine->state = State_0;
    engine->a_counter = 0;
    engine->colon_counter = 0;
    return true;
}

bool engine_reset(struct RegexEngine *engine) {
    engine_init(engine);
    return true;
}


void engine_tick(struct RegexEngine *engine) {
    switch (engine->state) {
        case State_Complete: {
            engine_reset(engine);
            engine->is_found = true;
            break;
        }
        case State_Error: {
            engine->is_error = true;
            break;
        }
        case State_0: {
            if (symbol_a) {
                engine->state = State_1;
                engine->a_counter++;
            } else if (symbol_B) {
                engine->state = State_2;
            } else {
                engine->state = State_Error;
            }
            break;
        }
        case State_1: {
            if ((symbol_a)&&(engine->a_counter < 3)) {
                engine->state = State_1;
                engine->a_counter++;
            } else if (symbol_colon) {
                engine->state = State_4;
            } else {
                engine->state = State_Error;
            }
            break;

        }
        case State_2: {
            if (symbol_colon) {
                engine->state = State_3;
                engine->colon_counter++;
            } else {
                engine->state = State_Error;
            }
            break;
        }
        case State_3:{
            if ((symbol_colon)&&(engine->colon_counter < 2)) {
                engine->state = State_3;
                engine->colon_counter++;
            }
            else if (symbol_B){
                engine->state = State_Complete;
            }
            else {
                engine->state = State_Error;
            }
            break;
        }
        case State_4:{
            if (symbol_a){
                engine->state = State_Complete;
            }
            else {
                engine->state = State_Error;
            }
        }
    }
    engine->index++;
}

