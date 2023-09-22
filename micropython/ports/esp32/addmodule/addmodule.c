// Include MicroPython API.
#include "py/runtime.h"

// This is the function which will be called from Python as addmodule.add(a, b).
STATIC mp_obj_t addmodule_add(mp_obj_t a_obj, mp_obj_t b_obj) {
    int a = mp_obj_get_int(a_obj);
    int b = mp_obj_get_int(b_obj);
    return mp_obj_new_int(a + b);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(addmodule_add_obj, addmodule_add);

// Define all attributes of the module.
STATIC const mp_rom_map_elem_t addmodule_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_addmodule) },
    { MP_ROM_QSTR(MP_QSTR_add), MP_ROM_PTR(&addmodule_add_obj) },
};
STATIC MP_DEFINE_CONST_DICT(addmodule_globals, addmodule_globals_table);

// Define module object.
const mp_obj_module_t addmodule_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&addmodule_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_addmodule, addmodule_user_cmodule);
