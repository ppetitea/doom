#ifndef KEYBOARD_H
# define KEYBOARD_H

# include "interface/events/event.h"
# include "interface/events/observable.h"
# include "SDL_keycode.h"

/*
** Pour chaque input key fourni par la sdl
** Une nouvelle key est malloc et ajouter a la liste correspondante
*/
typedef struct	s_key
{
	t_list_head	node;
	SDL_Keycode	code;
	t_result	(*destroy)(struct s_key*);
}				t_key;

t_result del_key(t_key *self);

t_result del_new_key(t_key *self);

t_result del_key_list(t_list_head *key_list);

t_result del_key_list_by_code(t_list_head *list, SDL_Keycode code);

t_result add_new_key(t_list_head *list, SDL_Keycode code);

t_result init_key(t_key *self);

t_key *init_new_key();

t_result	set_key(t_key *self, SDL_Keycode code);

t_key *set_new_key(SDL_Keycode code);

/*
** key state
** followed by component to up to date its own state
** plus besoin de stocker les hold key il suffit que l'observer check:
	for (down of keys.curr.down)
	{
		if (keys_list_contain(keys.curr.down, down) &&
			keys_list_contain(keys.last.down, down))
			trigger_action()
	}, key.curr)
*/

/*
** si pas d'event fourni par sdl 
** 		events.queu = empty  
** 		source.unsubscribe()
** les events sont inscrit a events.queu <=> ils sont fournis par la sdl
**
** Lorsque tous les events lies au clavier ont ete geres
**	On destroy chaque noeud de last
**	On swap keys.curr dans keys.last
**	L'en tete de liste keys.curr est maintenant vide pret a recevoir de new events
**
**	keys.last et keys.curr designent respectivement les dernierres et actuelles touches enfonces
**
*/
typedef struct	s_keys
{
	t_list_head		last;
	t_list_head		curr;
	t_observable	events;
	t_result		(*destroy)(struct s_keys*);
}				t_keys;

t_result del_keys(t_keys *self);

t_result del_new_keys(t_keys *self);

t_result init_keys(t_keys *self);

t_keys *init_new_keys();

#endif