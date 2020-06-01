#include "interface/interface.h"
#include "log/log.h"
#include <stdlib.h>

t_result init_interface(t_interface *self)
{
	if (!init_list_head(&self->scenes))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->observables))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->streams))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	if (!init_list_head(&self->stream_observers))
		return (console(FATAL, __func__, __LINE__, "init_list_head fail").err);
	self-
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
	//free self
	del_node(&self->node);
	return (OK);
}

t_result del_new_interface(t_interface *self)
{
	if (!del_interface(self))
		return (console(FATAL, __func__, __LINE__, "del_interface fail").err);
	free self
	return (OK);
}

t_result set_interface(t_interface *self, )
{
	if (!init_list(&self->node))
		return (console(FATAL, __func__, __LINE__, "init_list fail").err);
	self-
	return (OK);
};

t_interface *set_new_interface()
{
	t_interface *self;

	if (!(self = init_new_interface()))
		return (console(FATAL, __func__, __LINE__, "init_new_interface fail").null);
	if (!(set_interface(self, )))
		return (console(FATAL, __func__, __LINE__, "set_interface fail").null);
	return (self);
}

