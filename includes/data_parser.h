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
	TOKEN_HEAD,					//	head of the token list
	TOKEN_UNDEFINED,			//	undefined
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
	char			*data;
	int				length;
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

t_res		tokens_del_and_quit(t_token *self, char *msg);

/*
** TOKEN SETUP
*/

t_result	token_set(t_token *self, t_token_type type, char *data);

t_result	token_set_pos(t_token *self, int line, int column);

t_token		*new_token_set(t_token_type type, char *data, int line, int column);


/*
** TOKENIZE
*/
t_result	tokenize(char *data, t_token *root);

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

/*
** ANALYSE TOKENS
*/

t_token		*token_is_value_next(t_token *token);

t_token		*token_is_string(t_token *token);

t_token		*token_is_integer(t_token *token);

t_token		*token_is_float(t_token *token);

t_token		*token_is_value(t_token *token);

t_token		*token_is_curly_braces(t_token *token);

t_token		*token_is_brackets(t_token *token);

t_token		*token_is_container(t_token *token);

t_token		*token_is_key_next(t_token *token);

t_token		*token_is_key(t_token *token);

/*
** PARSE TOKENS
*/

t_result	parse_string(t_token *token, t_data *data);

t_result	parse_integer(t_token *token, t_data *data);

t_result	parse_float(t_token *token, t_data *data);

t_result	parse_value(t_token *token, t_data *data);

t_result	parse_container(t_token *token, t_data *data,
				t_result (*recursive_data_parsing)(t_token*, t_data*));

t_data	*parse_key(t_token *token, t_data *parent, int index);

t_result	recursive_data_parsing(t_token *token, t_data *parent);

t_data		*parse(t_token *root_token);


#endif