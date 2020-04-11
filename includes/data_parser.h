#ifndef DATA_PARSER_H
# define DATA_PARSER_H

# include "data.h"
# include "node.h"
# include "log.h"

/*
** LOAD DATA FROM FILE
*/
char		*load_from_file(char *path);

/*
** CLEAN DATA
*/
t_result	clean_data(char *data);

/*
** TOKENS
*/

typedef enum	e_token_type
{
	TOKEN_UNDEFINED,
	TOKEN_STRING,				//	[""]		→
	TOKEN_NUMBER,				//	[0-9]		→
	TOKEN_LESS,					//	-			→
	TOKEN_DOT,					//	.			→
	TOKEN_COMMA,				//	,			→
	TOKEN_COLON,				//	:			→
	TOKEN_BRACKET_OPEN,			//	[			↓
	TOKEN_BRACKET_CLOSE,		//	]			↑
	TOKEN_CURLY_BRACES_OPEN,	//	{			↓
	TOKEN_CURLY_BRACES_CLOSE,	//	}			↑
}				t_token_type;

typedef struct	s_token
{
	t_node			node;
	t_token_type	type;
	t_data_type		data_type;
	t_val			data;
	int				line;
	int				column;
}				t_token;

/*
** FOREACH TOKEN
*/

t_result	token_foreach_prev(t_token *self, t_result (*fn)(t_token*));

t_result	token_foreach_next(t_token *self, t_result (*fn)(t_token*));

/*
** PRINT TOKEN
*/

void		print_token_type(t_token_type type);

t_result	print_token(t_token *self);

t_result	print_tokens(t_token *self);

/*
** INIT TOKEN
*/

t_result init_token(t_token *self);

t_token *init_new_token();

/*
** DELETE TOKEN
*/

t_result	token_del(t_token *self);

t_result	tokens_childs_del(t_token *self);

t_result	tokens_del(t_token *self);

t_res		tokens_del_and_quit(t_token *self);

/*
** TOKEN SETUP
*/

t_result token_set(t_token *self, t_token_type type, t_val data);

t_result token_set_pos(t_token *self, int line, int column);

t_token	*new_token_set(t_token_type type, t_val data, int line, int column);

/* 
	TEST TOKEN
*/

t_result	test_token_creation();



/*
** 	JSON SYNTAX
** 	
** 	"key" → :
** 			 → "string"
** 			 → 42
** 			 → 21.21
** 			 → [ → ]
** 			 → { → }
** 					→ ,
** 						→ "key" → :
** 					→ }
** 						→ ,
** 						→ ]
** 						→ }
**
** 	"key" → : → [
** 			 	→ "string" → , → "string"
** 			 	→ 42 → , → 42
** 			 	→ 21.21 → , → 21.21
** 			 	→ [ → ] → , → [ → ]
** 			 	→ { → } → , → { → }
** 			 						→ ]
** 										→ ,
** 										→ ]
** 										→ }
*/

typedef enum	e_syntax_type
{
	SYNTAX_STRING,				//	"key" → : → "value"
	SYNTAX_INTEGER,				//	"key" → : → 42
	SYNTAX_FLOAT,				//	"key" → : → - → 21.42
	SYNTAX_OBJECT,				//	"key" → : → {↓ → ↑}
	SYNTAX_ARRAY				//	"key" → : → [↓ → ↑]
}				t_syntax_type;

typedef struct	s_syntax
{
	t_node		node;
}				t_syntax;

#endif