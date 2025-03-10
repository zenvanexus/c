#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_claim.h"



static v1_resource_claim_t *v1_resource_claim_create_internal(
    char *name,
    char *request
    ) {
    v1_resource_claim_t *v1_resource_claim_local_var = malloc(sizeof(v1_resource_claim_t));
    if (!v1_resource_claim_local_var) {
        return NULL;
    }
    v1_resource_claim_local_var->name = name;
    v1_resource_claim_local_var->request = request;

    v1_resource_claim_local_var->_library_owned = 1;
    return v1_resource_claim_local_var;
}

__attribute__((deprecated)) v1_resource_claim_t *v1_resource_claim_create(
    char *name,
    char *request
    ) {
    return v1_resource_claim_create_internal (
        name,
        request
        );
}

void v1_resource_claim_free(v1_resource_claim_t *v1_resource_claim) {
    if(NULL == v1_resource_claim){
        return ;
    }
    if(v1_resource_claim->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_resource_claim_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_claim->name) {
        free(v1_resource_claim->name);
        v1_resource_claim->name = NULL;
    }
    if (v1_resource_claim->request) {
        free(v1_resource_claim->request);
        v1_resource_claim->request = NULL;
    }
    free(v1_resource_claim);
}

cJSON *v1_resource_claim_convertToJSON(v1_resource_claim_t *v1_resource_claim) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_claim->name
    if (!v1_resource_claim->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_resource_claim->name) == NULL) {
    goto fail; //String
    }


    // v1_resource_claim->request
    if(v1_resource_claim->request) {
    if(cJSON_AddStringToObject(item, "request", v1_resource_claim->request) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_resource_claim_t *v1_resource_claim_parseFromJSON(cJSON *v1_resource_claimJSON){

    v1_resource_claim_t *v1_resource_claim_local_var = NULL;

    // v1_resource_claim->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_resource_claimJSON, "name");
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

    // v1_resource_claim->request
    cJSON *request = cJSON_GetObjectItemCaseSensitive(v1_resource_claimJSON, "request");
    if (cJSON_IsNull(request)) {
        request = NULL;
    }
    if (request) { 
    if(!cJSON_IsString(request) && !cJSON_IsNull(request))
    {
    goto end; //String
    }
    }


    v1_resource_claim_local_var = v1_resource_claim_create_internal (
        strdup(name->valuestring),
        request && !cJSON_IsNull(request) ? strdup(request->valuestring) : NULL
        );

    return v1_resource_claim_local_var;
end:
    return NULL;

}
