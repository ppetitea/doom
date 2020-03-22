# DOCUMENTATION

## Parser bitmap

L'utilisation de `fread()` est necessaire car `read()` ne lit pas les fichiers binaires 

Les instructions de type `# pragma` sont pratiques mais facultatives

### todo

- Supprimer les `#pragma`

## Parser objets

Utilisation d'`enum` et d'`union` pour stocker la data

    typedef enum    e_obj_data_type
    {
        CHAR,
        INT,
        FLOAT,
        STRING,
        LIST
    }               t_obj_data_type;

    typedef union   u_obj_data
    {
        char        c;
        int         i;
        float       f;
        char        *s;
        t_list_head *list;
    }               t_obj_data;

    typedef struct  t_obj
    {
        t_node          node;
        t_obj_data_type type;
        t_obj_data      data;
    }               s_obj;

### todo

* Tweak the parser with this struct

## Event handler

* s'inscrire a un event `add_event_listener()`

