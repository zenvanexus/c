/*
 * v1_user_info.h
 *
 * UserInfo holds the information about the user needed to implement the user.Info interface.
 */

#ifndef _v1_user_info_H_
#define _v1_user_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_user_info_t v1_user_info_t;




typedef struct v1_user_info_t {
    list_t* extra; //map
    list_t *groups; //primitive container
    char *uid; // string
    char *username; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_user_info_t;

__attribute__((deprecated)) v1_user_info_t *v1_user_info_create(
    list_t* extra,
    list_t *groups,
    char *uid,
    char *username
);

void v1_user_info_free(v1_user_info_t *v1_user_info);

v1_user_info_t *v1_user_info_parseFromJSON(cJSON *v1_user_infoJSON);

cJSON *v1_user_info_convertToJSON(v1_user_info_t *v1_user_info);

#endif /* _v1_user_info_H_ */

