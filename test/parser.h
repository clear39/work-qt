#ifndef PARSER_H
#define PARSER_H


#define T_EOF 0
#define T_TEXT 1
#define T_NEWLINE 2

struct parse_state
{
    char *ptr;
    char *text;
    int line;
    int nexttoken;
};

int next_token(struct parse_state *state);

class Parser
{
public:
    Parser();
};

#endif // PARSER_H
