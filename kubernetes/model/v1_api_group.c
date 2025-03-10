#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_api_group.h"



static v1_api_group_t *v1_api_group_create_internal(
    char *api_version,
    char *kind,
    char *name,
    v1_group_version_for_discovery_t *preferred_version,
    list_t *server_address_by_client_cidrs,
    list_t *versions
    ) {
    v1_api_group_t *v1_api_group_local_var = malloc(sizeof(v1_api_group_t));
    if (!v1_api_group_local_var) {
        return NULL;
    }
    v1_api_group_local_var->api_version = api_version;
    v1_api_group_local_var->kind = kind;
    v1_api_group_local_var->name = name;
    v1_api_group_local_var->preferred_version = preferred_version;
    v1_api_group_local_var->server_address_by_client_cidrs = server_address_by_client_cidrs;
    v1_api_group_local_var->versions = versions;

    v1_api_group_local_var->_library_owned = 1;
    return v1_api_group_local_var;
}

__attribute__((deprecated)) v1_api_group_t *v1_api_group_create(
    char *api_version,
    char *kind,
    char *name,
    v1_group_version_for_discovery_t *preferred_version,
    list_t *server_address_by_client_cidrs,
    list_t *versions
    ) {
    return v1_api_group_create_internal (
        api_version,
        kind,
        name,
        preferred_version,
        server_address_by_client_cidrs,
        versions
        );
}

void v1_api_group_free(v1_api_group_t *v1_api_group) {
    if(NULL == v1_api_group){
        return ;
    }
    if(v1_api_group->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_api_group_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_api_group->api_version) {
        free(v1_api_group->api_version);
        v1_api_group->api_version = NULL;
    }
    if (v1_api_group->kind) {
        free(v1_api_group->kind);
        v1_api_group->kind = NULL;
    }
    if (v1_api_group->name) {
        free(v1_api_group->name);
        v1_api_group->name = NULL;
    }
    if (v1_api_group->preferred_version) {
        v1_group_version_for_discovery_free(v1_api_group->preferred_version);
        v1_api_group->preferred_version = NULL;
    }
    if (v1_api_group->server_address_by_client_cidrs) {
        list_ForEach(listEntry, v1_api_group->server_address_by_client_cidrs) {
            v1_server_address_by_client_cidr_free(listEntry->data);
        }
        list_freeList(v1_api_group->server_address_by_client_cidrs);
        v1_api_group->server_address_by_client_cidrs = NULL;
    }
    if (v1_api_group->versions) {
        list_ForEach(listEntry, v1_api_group->versions) {
            v1_group_version_for_discovery_free(listEntry->data);
        }
        list_freeList(v1_api_group->versions);
        v1_api_group->versions = NULL;
    }
    free(v1_api_group);
}

cJSON *v1_api_group_convertToJSON(v1_api_group_t *v1_api_group) {
    cJSON *item = cJSON_CreateObject();

    // v1_api_group->api_version
    if(v1_api_group->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_api_group->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_group->kind
    if(v1_api_group->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_api_group->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_api_group->name
    if (!v1_api_group->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_api_group->name) == NULL) {
    goto fail; //String
    }


    // v1_api_group->preferred_version
    if(v1_api_group->preferred_version) {
    cJSON *preferred_version_local_JSON = v1_group_version_for_discovery_convertToJSON(v1_api_group->preferred_version);
    if(preferred_version_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "preferredVersion", preferred_version_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_api_group->server_address_by_client_cidrs
    if(v1_api_group->server_address_by_client_cidrs) {
    cJSON *server_address_by_client_cidrs = cJSON_AddArrayToObject(item, "serverAddressByClientCIDRs");
    if(server_address_by_client_cidrs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *server_address_by_client_cidrsListEntry;
    if (v1_api_group->server_address_by_client_cidrs) {
    list_ForEach(server_address_by_client_cidrsListEntry, v1_api_group->server_address_by_client_cidrs) {
    cJSON *itemLocal = v1_server_address_by_client_cidr_convertToJSON(server_address_by_client_cidrsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(server_address_by_client_cidrs, itemLocal);
    }
    }
    }


    // v1_api_group->versions
    if (!v1_api_group->versions) {
        goto fail;
    }
    cJSON *versions = cJSON_AddArrayToObject(item, "versions");
    if(versions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *versionsListEntry;
    if (v1_api_group->versions) {
    list_ForEach(versionsListEntry, v1_api_group->versions) {
    cJSON *itemLocal = v1_group_version_for_discovery_convertToJSON(versionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(versions, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_api_group_t *v1_api_group_parseFromJSON(cJSON *v1_api_groupJSON){

    v1_api_group_t *v1_api_group_local_var = NULL;

    // define the local variable for v1_api_group->preferred_version
    v1_group_version_for_discovery_t *preferred_version_local_nonprim = NULL;

    // define the local list for v1_api_group->server_address_by_client_cidrs
    list_t *server_address_by_client_cidrsList = NULL;

    // define the local list for v1_api_group->versions
    list_t *versionsList = NULL;

    // v1_api_group->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_api_group->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_api_group->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "name");
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

    // v1_api_group->preferred_version
    cJSON *preferred_version = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "preferredVersion");
    if (cJSON_IsNull(preferred_version)) {
        preferred_version = NULL;
    }
    if (preferred_version) { 
    preferred_version_local_nonprim = v1_group_version_for_discovery_parseFromJSON(preferred_version); //nonprimitive
    }

    // v1_api_group->server_address_by_client_cidrs
    cJSON *server_address_by_client_cidrs = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "serverAddressByClientCIDRs");
    if (cJSON_IsNull(server_address_by_client_cidrs)) {
        server_address_by_client_cidrs = NULL;
    }
    if (server_address_by_client_cidrs) { 
    cJSON *server_address_by_client_cidrs_local_nonprimitive = NULL;
    if(!cJSON_IsArray(server_address_by_client_cidrs)){
        goto end; //nonprimitive container
    }

    server_address_by_client_cidrsList = list_createList();

    cJSON_ArrayForEach(server_address_by_client_cidrs_local_nonprimitive,server_address_by_client_cidrs )
    {
        if(!cJSON_IsObject(server_address_by_client_cidrs_local_nonprimitive)){
            goto end;
        }
        v1_server_address_by_client_cidr_t *server_address_by_client_cidrsItem = v1_server_address_by_client_cidr_parseFromJSON(server_address_by_client_cidrs_local_nonprimitive);

        list_addElement(server_address_by_client_cidrsList, server_address_by_client_cidrsItem);
    }
    }

    // v1_api_group->versions
    cJSON *versions = cJSON_GetObjectItemCaseSensitive(v1_api_groupJSON, "versions");
    if (cJSON_IsNull(versions)) {
        versions = NULL;
    }
    if (!versions) {
        goto end;
    }

    
    cJSON *versions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(versions)){
        goto end; //nonprimitive container
    }

    versionsList = list_createList();

    cJSON_ArrayForEach(versions_local_nonprimitive,versions )
    {
        if(!cJSON_IsObject(versions_local_nonprimitive)){
            goto end;
        }
        v1_group_version_for_discovery_t *versionsItem = v1_group_version_for_discovery_parseFromJSON(versions_local_nonprimitive);

        list_addElement(versionsList, versionsItem);
    }


    v1_api_group_local_var = v1_api_group_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        strdup(name->valuestring),
        preferred_version ? preferred_version_local_nonprim : NULL,
        server_address_by_client_cidrs ? server_address_by_client_cidrsList : NULL,
        versionsList
        );

    return v1_api_group_local_var;
end:
    if (preferred_version_local_nonprim) {
        v1_group_version_for_discovery_free(preferred_version_local_nonprim);
        preferred_version_local_nonprim = NULL;
    }
    if (server_address_by_client_cidrsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, server_address_by_client_cidrsList) {
            v1_server_address_by_client_cidr_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(server_address_by_client_cidrsList);
        server_address_by_client_cidrsList = NULL;
    }
    if (versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, versionsList) {
            v1_group_version_for_discovery_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(versionsList);
        versionsList = NULL;
    }
    return NULL;

}
