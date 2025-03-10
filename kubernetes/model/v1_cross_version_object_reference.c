#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_cross_version_object_reference.h"



static v1_cross_version_object_reference_t *v1_cross_version_object_reference_create_internal(
    char *api_version,
    char *kind,
    char *name
    ) {
    v1_cross_version_object_reference_t *v1_cross_version_object_reference_local_var = malloc(sizeof(v1_cross_version_object_reference_t));
    if (!v1_cross_version_object_reference_local_var) {
        return NULL;
    }
    v1_cross_version_object_reference_local_var->api_version = api_version;
    v1_cross_version_object_reference_local_var->kind = kind;
    v1_cross_version_object_reference_local_var->name = name;

    v1_cross_version_object_reference_local_var->_library_owned = 1;
    return v1_cross_version_object_reference_local_var;
}

__attribute__((deprecated)) v1_cross_version_object_reference_t *v1_cross_version_object_reference_create(
    char *api_version,
    char *kind,
    char *name
    ) {
    return v1_cross_version_object_reference_create_internal (
        api_version,
        kind,
        name
        );
}

void v1_cross_version_object_reference_free(v1_cross_version_object_reference_t *v1_cross_version_object_reference) {
    if(NULL == v1_cross_version_object_reference){
        return ;
    }
    if(v1_cross_version_object_reference->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_cross_version_object_reference_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_cross_version_object_reference->api_version) {
        free(v1_cross_version_object_reference->api_version);
        v1_cross_version_object_reference->api_version = NULL;
    }
    if (v1_cross_version_object_reference->kind) {
        free(v1_cross_version_object_reference->kind);
        v1_cross_version_object_reference->kind = NULL;
    }
    if (v1_cross_version_object_reference->name) {
        free(v1_cross_version_object_reference->name);
        v1_cross_version_object_reference->name = NULL;
    }
    free(v1_cross_version_object_reference);
}

cJSON *v1_cross_version_object_reference_convertToJSON(v1_cross_version_object_reference_t *v1_cross_version_object_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1_cross_version_object_reference->api_version
    if(v1_cross_version_object_reference->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_cross_version_object_reference->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_cross_version_object_reference->kind
    if (!v1_cross_version_object_reference->kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kind", v1_cross_version_object_reference->kind) == NULL) {
    goto fail; //String
    }


    // v1_cross_version_object_reference->name
    if (!v1_cross_version_object_reference->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_cross_version_object_reference->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_cross_version_object_reference_t *v1_cross_version_object_reference_parseFromJSON(cJSON *v1_cross_version_object_referenceJSON){

    v1_cross_version_object_reference_t *v1_cross_version_object_reference_local_var = NULL;

    // v1_cross_version_object_reference->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_cross_version_object_referenceJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_cross_version_object_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_cross_version_object_referenceJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1_cross_version_object_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_cross_version_object_referenceJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_cross_version_object_reference_local_var = v1_cross_version_object_reference_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring)
        );

    return v1_cross_version_object_reference_local_var;
end:
    return NULL;

}
