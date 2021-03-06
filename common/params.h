#ifndef __PARAMS_H__

#define __PARAMS_H__

typedef struct __params_t {
  int is_help_presented;
  int is_version_presented;
  int lang_id;
  const char* compiler_params;
} params_t;

#endif /* __PARAMS_H__ */
