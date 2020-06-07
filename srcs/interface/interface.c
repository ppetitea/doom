#include "interface/interface.h"
#include "interface/inputs/mouse.h"
#include "interface/inputs/keyboard.h"
#include "interface/events/observable.h"
#include "log/log.h"
#include <stdlib.h>

t_result del_scene(t_scene *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	// del_component_tree(&self->tree);
	self->destroy = NULL;
	list_del_entry(&self->node);
	return (OK);
}

t_result del_new_scene(t_scene *self)
{
	if (!del_scene(self))
		return (console(FATAL, __func__, __LINE__, "del_scene fail").err);
	free(self);
	return (OK);
}

t_result init_scene(t_scene *self)
{
	if (!init_list_head(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	// if (!init_component(&self->tree))
	// 	return (console(FATAL, __func__, __LINE__, "init_list fail").err);

	return (OK);
};

t_scene *init_new_scene()
{
	t_scene *self;

	if (!(self = malloc(sizeof(t_scene))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_scene(self);
	return (self);
}

// t_result set_scene(t_scene *self, )
// {
// 	if (!init_list(&self->node))
// 		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
// 	self-
// 	return (OK);
// };

// t_scene *set_new_scene()
// {
// 	t_scene *self;

// 	if (!(self = init_new_scene()))
// 		return (console(FATAL, __func__, __LINE__, "init_new_scene fail").null);
// 	if (!(set_scene(self, )))
// 		return (console(FATAL, __func__, __LINE__, "set_scene fail").null);
// 	return (self);
// }

t_interface *static_interface(t_interface *init)
{
	static t_interface *interface = NULL;

	if (!interface)
		interface = init;
	return (interface);
}

t_interface *get_interface()
{
	return (static_interface(NULL));
}

t_keys *get_keys()
{
	t_interface	*interface;

	if ((interface = static_interface(NULL)))
		return (&interface->keys);
	return (console(WARNING, __func__, __LINE__, "interface is null").null);
}

t_mouse *get_mouse()
{
	t_interface	*interface;

	if ((interface = static_interface(NULL)))
		return (&interface->mouse);
	return (console(WARNING, __func__, __LINE__, "interface is null").null);
}

t_scene *get_current_scene()
{
	t_interface	*interface;

	if ((interface = static_interface(NULL)))
		return (&interface->curr);
	return (console(WARNING, __func__, __LINE__, "interface is null").null);
}

t_result init_interface(t_interface *self)
{
	if (!init_list_head(&self->scenes))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->curr = NULL;
	if (!init_mouse(&self->mouse))
		return (console(FATAL, __func__, __LINE__, "init_mouse fail").err);
	if (!init_keys(&self->keys))
		return (console(FATAL, __func__, __LINE__, "init_keys fail").err);
	if (!init_observable(&self->events))
		return (console(FATAL, __func__, __LINE__, "init_observable fail").err);
	if (!init_list_head(&self->observables))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->streams))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->stream_observers))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self->curr = NULL;
		return (OK);
};

t_interface *init_new_interface()
{
	t_interface *self;

	if (!(self = malloc(sizeof(t_interface))))
		return (console(FATAL, __func__, __LINE__, "init_list fail").null);
	init_interface(self);
	return (self);
}

t_result del_interface(t_interface *self)
{
	if (!self)
		return (console(FATAL, __func__, __LINE__, "null pointer").err);
	// del_scene_list(self->scenes);
	self->curr = NULL;
	self->mouse.destroy(&self->mouse);
	self->keys.destroy(&self->keys);
	del_observable_list(&self->observables);
	del_stream_list(&self->streams);
	del_stream_observer_list(&self->stream_observers);
	return (OK);
}

t_result del_new_interface(t_interface *self)
{
	if (!del_interface(self))
		return (console(FATAL, __func__, __LINE__, "del_interface fail").err);
	free(self);
	return (OK);
}

// t_result set_interface(t_interface *self, )
// {
// 	if (!init_list(&self->node))
// 		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
// 	self -
// 		return (OK);
// };

// t_interface *set_new_interface()
// {
// 	t_interface *self;

// 	if (!(self = init_new_interface()))
// 		return (console(FATAL, __func__, __LINE__, "init_new_interface fail").null);
// 	if (!(set_interface(self, )))
// 		return (console(FATAL, __func__, __LINE__, "set_interface fail").null);
// 	return (self);
// }

