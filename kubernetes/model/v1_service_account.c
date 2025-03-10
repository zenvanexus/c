#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_service_account.h"



static v1_service_account_t *v1_service_account_create_internal(
    char *api_version,
    int automount_service_account_token,
    list_t *image_pull_secrets,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *secrets
    ) {
    v1_service_account_t *v1_service_account_local_var = malloc(sizeof(v1_service_account_t));
    if (!v1_service_account_local_var) {
        return NULL;
    }
    v1_service_account_local_var->api_version = api_version;
    v1_service_account_local_var->automount_service_account_token = automount_service_account_token;
    v1_service_account_local_var->image_pull_secrets = image_pull_secrets;
    v1_service_account_local_var->kind = kind;
    v1_service_account_local_var->metadata = metadata;
    v1_service_account_local_var->secrets = secrets;

    v1_service_account_local_var->_library_owned = 1;
    return v1_service_account_local_var;
}

__attribute__((deprecated)) v1_service_account_t *v1_service_account_create(
    char *api_version,
    int automount_service_account_token,
    list_t *image_pull_secrets,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *secrets
    ) {
    return v1_service_account_create_internal (
        api_version,
        automount_service_account_token,
        image_pull_secrets,
        kind,
        metadata,
        secrets
        );
}

void v1_service_account_free(v1_service_account_t *v1_service_account) {
    if(NULL == v1_service_account){
        return ;
    }
    if(v1_service_account->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_service_account_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_service_account->api_version) {
        free(v1_service_account->api_version);
        v1_service_account->api_version = NULL;
    }
    if (v1_service_account->image_pull_secrets) {
        list_ForEach(listEntry, v1_service_account->image_pull_secrets) {
            v1_local_object_reference_free(listEntry->data);
        }
        list_freeList(v1_service_account->image_pull_secrets);
        v1_service_account->image_pull_secrets = NULL;
    }
    if (v1_service_account->kind) {
        free(v1_service_account->kind);
        v1_service_account->kind = NULL;
    }
    if (v1_service_account->metadata) {
        v1_object_meta_free(v1_service_account->metadata);
        v1_service_account->metadata = NULL;
    }
    if (v1_service_account->secrets) {
        list_ForEach(listEntry, v1_service_account->secrets) {
            v1_object_reference_free(listEntry->data);
        }
        list_freeList(v1_service_account->secrets);
        v1_service_account->secrets = NULL;
    }
    free(v1_service_account);
}

cJSON *v1_service_account_convertToJSON(v1_service_account_t *v1_service_account) {
    cJSON *item = cJSON_CreateObject();

    // v1_service_account->api_version
    if(v1_service_account->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_service_account->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_account->automount_service_account_token
    if(v1_service_account->automount_service_account_token) {
    if(cJSON_AddBoolToObject(item, "automountServiceAccountToken", v1_service_account->automount_service_account_token) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_service_account->image_pull_secrets
    if(v1_service_account->image_pull_secrets) {
    cJSON *image_pull_secrets = cJSON_AddArrayToObject(item, "imagePullSecrets");
    if(image_pull_secrets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *image_pull_secretsListEntry;
    if (v1_service_account->image_pull_secrets) {
    list_ForEach(image_pull_secretsListEntry, v1_service_account->image_pull_secrets) {
    cJSON *itemLocal = v1_local_object_reference_convertToJSON(image_pull_secretsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(image_pull_secrets, itemLocal);
    }
    }
    }


    // v1_service_account->kind
    if(v1_service_account->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_service_account->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_service_account->metadata
    if(v1_service_account->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_service_account->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_service_account->secrets
    if(v1_service_account->secrets) {
    cJSON *secrets = cJSON_AddArrayToObject(item, "secrets");
    if(secrets == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *secretsListEntry;
    if (v1_service_account->secrets) {
    list_ForEach(secretsListEntry, v1_service_account->secrets) {
    cJSON *itemLocal = v1_object_reference_convertToJSON(secretsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(secrets, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_service_account_t *v1_service_account_parseFromJSON(cJSON *v1_service_accountJSON){

    v1_service_account_t *v1_service_account_local_var = NULL;

    // define the local list for v1_service_account->image_pull_secrets
    list_t *image_pull_secretsList = NULL;

    // define the local variable for v1_service_account->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local list for v1_service_account->secrets
    list_t *secretsList = NULL;

    // v1_service_account->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_service_account->automount_service_account_token
    cJSON *automount_service_account_token = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "automountServiceAccountToken");
    if (cJSON_IsNull(automount_service_account_token)) {
        automount_service_account_token = NULL;
    }
    if (automount_service_account_token) { 
    if(!cJSON_IsBool(automount_service_account_token))
    {
    goto end; //Bool
    }
    }

    // v1_service_account->image_pull_secrets
    cJSON *image_pull_secrets = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "imagePullSecrets");
    if (cJSON_IsNull(image_pull_secrets)) {
        image_pull_secrets = NULL;
    }
    if (image_pull_secrets) { 
    cJSON *image_pull_secrets_local_nonprimitive = NULL;
    if(!cJSON_IsArray(image_pull_secrets)){
        goto end; //nonprimitive container
    }

    image_pull_secretsList = list_createList();

    cJSON_ArrayForEach(image_pull_secrets_local_nonprimitive,image_pull_secrets )
    {
        if(!cJSON_IsObject(image_pull_secrets_local_nonprimitive)){
            goto end;
        }
        v1_local_object_reference_t *image_pull_secretsItem = v1_local_object_reference_parseFromJSON(image_pull_secrets_local_nonprimitive);

        list_addElement(image_pull_secretsList, image_pull_secretsItem);
    }
    }

    // v1_service_account->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_service_account->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_service_account->secrets
    cJSON *secrets = cJSON_GetObjectItemCaseSensitive(v1_service_accountJSON, "secrets");
    if (cJSON_IsNull(secrets)) {
        secrets = NULL;
    }
    if (secrets) { 
    cJSON *secrets_local_nonprimitive = NULL;
    if(!cJSON_IsArray(secrets)){
        goto end; //nonprimitive container
    }

    secretsList = list_createList();

    cJSON_ArrayForEach(secrets_local_nonprimitive,secrets )
    {
        if(!cJSON_IsObject(secrets_local_nonprimitive)){
            goto end;
        }
        v1_object_reference_t *secretsItem = v1_object_reference_parseFromJSON(secrets_local_nonprimitive);

        list_addElement(secretsList, secretsItem);
    }
    }


    v1_service_account_local_var = v1_service_account_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        automount_service_account_token ? automount_service_account_token->valueint : 0,
        image_pull_secrets ? image_pull_secretsList : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        secrets ? secretsList : NULL
        );

    return v1_service_account_local_var;
end:
    if (image_pull_secretsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, image_pull_secretsList) {
            v1_local_object_reference_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(image_pull_secretsList);
        image_pull_secretsList = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (secretsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, secretsList) {
            v1_object_reference_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(secretsList);
        secretsList = NULL;
    }
    return NULL;

}
