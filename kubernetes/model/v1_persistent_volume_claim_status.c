#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_claim_status.h"



static v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_create_internal(
    list_t *access_modes,
    list_t* allocated_resource_statuses,
    list_t* allocated_resources,
    list_t* capacity,
    list_t *conditions,
    char *current_volume_attributes_class_name,
    v1_modify_volume_status_t *modify_volume_status,
    char *phase
    ) {
    v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_local_var = malloc(sizeof(v1_persistent_volume_claim_status_t));
    if (!v1_persistent_volume_claim_status_local_var) {
        return NULL;
    }
    v1_persistent_volume_claim_status_local_var->access_modes = access_modes;
    v1_persistent_volume_claim_status_local_var->allocated_resource_statuses = allocated_resource_statuses;
    v1_persistent_volume_claim_status_local_var->allocated_resources = allocated_resources;
    v1_persistent_volume_claim_status_local_var->capacity = capacity;
    v1_persistent_volume_claim_status_local_var->conditions = conditions;
    v1_persistent_volume_claim_status_local_var->current_volume_attributes_class_name = current_volume_attributes_class_name;
    v1_persistent_volume_claim_status_local_var->modify_volume_status = modify_volume_status;
    v1_persistent_volume_claim_status_local_var->phase = phase;

    v1_persistent_volume_claim_status_local_var->_library_owned = 1;
    return v1_persistent_volume_claim_status_local_var;
}

__attribute__((deprecated)) v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_create(
    list_t *access_modes,
    list_t* allocated_resource_statuses,
    list_t* allocated_resources,
    list_t* capacity,
    list_t *conditions,
    char *current_volume_attributes_class_name,
    v1_modify_volume_status_t *modify_volume_status,
    char *phase
    ) {
    return v1_persistent_volume_claim_status_create_internal (
        access_modes,
        allocated_resource_statuses,
        allocated_resources,
        capacity,
        conditions,
        current_volume_attributes_class_name,
        modify_volume_status,
        phase
        );
}

void v1_persistent_volume_claim_status_free(v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status) {
    if(NULL == v1_persistent_volume_claim_status){
        return ;
    }
    if(v1_persistent_volume_claim_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_persistent_volume_claim_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_persistent_volume_claim_status->access_modes) {
        list_ForEach(listEntry, v1_persistent_volume_claim_status->access_modes) {
            free(listEntry->data);
        }
        list_freeList(v1_persistent_volume_claim_status->access_modes);
        v1_persistent_volume_claim_status->access_modes = NULL;
    }
    if (v1_persistent_volume_claim_status->allocated_resource_statuses) {
        list_ForEach(listEntry, v1_persistent_volume_claim_status->allocated_resource_statuses) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_persistent_volume_claim_status->allocated_resource_statuses);
        v1_persistent_volume_claim_status->allocated_resource_statuses = NULL;
    }
    if (v1_persistent_volume_claim_status->allocated_resources) {
        list_ForEach(listEntry, v1_persistent_volume_claim_status->allocated_resources) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_persistent_volume_claim_status->allocated_resources);
        v1_persistent_volume_claim_status->allocated_resources = NULL;
    }
    if (v1_persistent_volume_claim_status->capacity) {
        list_ForEach(listEntry, v1_persistent_volume_claim_status->capacity) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_persistent_volume_claim_status->capacity);
        v1_persistent_volume_claim_status->capacity = NULL;
    }
    if (v1_persistent_volume_claim_status->conditions) {
        list_ForEach(listEntry, v1_persistent_volume_claim_status->conditions) {
            v1_persistent_volume_claim_condition_free(listEntry->data);
        }
        list_freeList(v1_persistent_volume_claim_status->conditions);
        v1_persistent_volume_claim_status->conditions = NULL;
    }
    if (v1_persistent_volume_claim_status->current_volume_attributes_class_name) {
        free(v1_persistent_volume_claim_status->current_volume_attributes_class_name);
        v1_persistent_volume_claim_status->current_volume_attributes_class_name = NULL;
    }
    if (v1_persistent_volume_claim_status->modify_volume_status) {
        v1_modify_volume_status_free(v1_persistent_volume_claim_status->modify_volume_status);
        v1_persistent_volume_claim_status->modify_volume_status = NULL;
    }
    if (v1_persistent_volume_claim_status->phase) {
        free(v1_persistent_volume_claim_status->phase);
        v1_persistent_volume_claim_status->phase = NULL;
    }
    free(v1_persistent_volume_claim_status);
}

cJSON *v1_persistent_volume_claim_status_convertToJSON(v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_persistent_volume_claim_status->access_modes
    if(v1_persistent_volume_claim_status->access_modes) {
    cJSON *access_modes = cJSON_AddArrayToObject(item, "accessModes");
    if(access_modes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *access_modesListEntry;
    list_ForEach(access_modesListEntry, v1_persistent_volume_claim_status->access_modes) {
    if(cJSON_AddStringToObject(access_modes, "", access_modesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_persistent_volume_claim_status->allocated_resource_statuses
    if(v1_persistent_volume_claim_status->allocated_resource_statuses) {
    cJSON *allocated_resource_statuses = cJSON_AddObjectToObject(item, "allocatedResourceStatuses");
    if(allocated_resource_statuses == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = allocated_resource_statuses;
    listEntry_t *allocated_resource_statusesListEntry;
    if (v1_persistent_volume_claim_status->allocated_resource_statuses) {
    list_ForEach(allocated_resource_statusesListEntry, v1_persistent_volume_claim_status->allocated_resource_statuses) {
        keyValuePair_t *localKeyValue = allocated_resource_statusesListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_persistent_volume_claim_status->allocated_resources
    if(v1_persistent_volume_claim_status->allocated_resources) {
    cJSON *allocated_resources = cJSON_AddObjectToObject(item, "allocatedResources");
    if(allocated_resources == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = allocated_resources;
    listEntry_t *allocated_resourcesListEntry;
    if (v1_persistent_volume_claim_status->allocated_resources) {
    list_ForEach(allocated_resourcesListEntry, v1_persistent_volume_claim_status->allocated_resources) {
        keyValuePair_t *localKeyValue = allocated_resourcesListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_persistent_volume_claim_status->capacity
    if(v1_persistent_volume_claim_status->capacity) {
    cJSON *capacity = cJSON_AddObjectToObject(item, "capacity");
    if(capacity == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = capacity;
    listEntry_t *capacityListEntry;
    if (v1_persistent_volume_claim_status->capacity) {
    list_ForEach(capacityListEntry, v1_persistent_volume_claim_status->capacity) {
        keyValuePair_t *localKeyValue = capacityListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_persistent_volume_claim_status->conditions
    if(v1_persistent_volume_claim_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1_persistent_volume_claim_status->conditions) {
    list_ForEach(conditionsListEntry, v1_persistent_volume_claim_status->conditions) {
    cJSON *itemLocal = v1_persistent_volume_claim_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1_persistent_volume_claim_status->current_volume_attributes_class_name
    if(v1_persistent_volume_claim_status->current_volume_attributes_class_name) {
    if(cJSON_AddStringToObject(item, "currentVolumeAttributesClassName", v1_persistent_volume_claim_status->current_volume_attributes_class_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_claim_status->modify_volume_status
    if(v1_persistent_volume_claim_status->modify_volume_status) {
    cJSON *modify_volume_status_local_JSON = v1_modify_volume_status_convertToJSON(v1_persistent_volume_claim_status->modify_volume_status);
    if(modify_volume_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "modifyVolumeStatus", modify_volume_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_claim_status->phase
    if(v1_persistent_volume_claim_status->phase) {
    if(cJSON_AddStringToObject(item, "phase", v1_persistent_volume_claim_status->phase) == NULL) {
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

v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_parseFromJSON(cJSON *v1_persistent_volume_claim_statusJSON){

    v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_local_var = NULL;

    // define the local list for v1_persistent_volume_claim_status->access_modes
    list_t *access_modesList = NULL;

    // define the local map for v1_persistent_volume_claim_status->allocated_resource_statuses
    list_t *allocated_resource_statusesList = NULL;

    // define the local map for v1_persistent_volume_claim_status->allocated_resources
    list_t *allocated_resourcesList = NULL;

    // define the local map for v1_persistent_volume_claim_status->capacity
    list_t *capacityList = NULL;

    // define the local list for v1_persistent_volume_claim_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1_persistent_volume_claim_status->modify_volume_status
    v1_modify_volume_status_t *modify_volume_status_local_nonprim = NULL;

    // v1_persistent_volume_claim_status->access_modes
    cJSON *access_modes = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "accessModes");
    if (cJSON_IsNull(access_modes)) {
        access_modes = NULL;
    }
    if (access_modes) { 
    cJSON *access_modes_local = NULL;
    if(!cJSON_IsArray(access_modes)) {
        goto end;//primitive container
    }
    access_modesList = list_createList();

    cJSON_ArrayForEach(access_modes_local, access_modes)
    {
        if(!cJSON_IsString(access_modes_local))
        {
            goto end;
        }
        list_addElement(access_modesList , strdup(access_modes_local->valuestring));
    }
    }

    // v1_persistent_volume_claim_status->allocated_resource_statuses
    cJSON *allocated_resource_statuses = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "allocatedResourceStatuses");
    if (cJSON_IsNull(allocated_resource_statuses)) {
        allocated_resource_statuses = NULL;
    }
    if (allocated_resource_statuses) { 
    cJSON *allocated_resource_statuses_local_map = NULL;
    if(!cJSON_IsObject(allocated_resource_statuses) && !cJSON_IsNull(allocated_resource_statuses))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(allocated_resource_statuses))
    {
        allocated_resource_statusesList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(allocated_resource_statuses_local_map, allocated_resource_statuses)
        {
            cJSON *localMapObject = allocated_resource_statuses_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(allocated_resource_statusesList , localMapKeyPair);
        }
    }
    }

    // v1_persistent_volume_claim_status->allocated_resources
    cJSON *allocated_resources = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "allocatedResources");
    if (cJSON_IsNull(allocated_resources)) {
        allocated_resources = NULL;
    }
    if (allocated_resources) { 
    cJSON *allocated_resources_local_map = NULL;
    if(!cJSON_IsObject(allocated_resources) && !cJSON_IsNull(allocated_resources))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(allocated_resources))
    {
        allocated_resourcesList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(allocated_resources_local_map, allocated_resources)
        {
            cJSON *localMapObject = allocated_resources_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(allocated_resourcesList , localMapKeyPair);
        }
    }
    }

    // v1_persistent_volume_claim_status->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "capacity");
    if (cJSON_IsNull(capacity)) {
        capacity = NULL;
    }
    if (capacity) { 
    cJSON *capacity_local_map = NULL;
    if(!cJSON_IsObject(capacity) && !cJSON_IsNull(capacity))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(capacity))
    {
        capacityList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(capacity_local_map, capacity)
        {
            cJSON *localMapObject = capacity_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(capacityList , localMapKeyPair);
        }
    }
    }

    // v1_persistent_volume_claim_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "conditions");
    if (cJSON_IsNull(conditions)) {
        conditions = NULL;
    }
    if (conditions) { 
    cJSON *conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_persistent_volume_claim_condition_t *conditionsItem = v1_persistent_volume_claim_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1_persistent_volume_claim_status->current_volume_attributes_class_name
    cJSON *current_volume_attributes_class_name = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "currentVolumeAttributesClassName");
    if (cJSON_IsNull(current_volume_attributes_class_name)) {
        current_volume_attributes_class_name = NULL;
    }
    if (current_volume_attributes_class_name) { 
    if(!cJSON_IsString(current_volume_attributes_class_name) && !cJSON_IsNull(current_volume_attributes_class_name))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_claim_status->modify_volume_status
    cJSON *modify_volume_status = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "modifyVolumeStatus");
    if (cJSON_IsNull(modify_volume_status)) {
        modify_volume_status = NULL;
    }
    if (modify_volume_status) { 
    modify_volume_status_local_nonprim = v1_modify_volume_status_parseFromJSON(modify_volume_status); //nonprimitive
    }

    // v1_persistent_volume_claim_status->phase
    cJSON *phase = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_claim_statusJSON, "phase");
    if (cJSON_IsNull(phase)) {
        phase = NULL;
    }
    if (phase) { 
    if(!cJSON_IsString(phase) && !cJSON_IsNull(phase))
    {
    goto end; //String
    }
    }


    v1_persistent_volume_claim_status_local_var = v1_persistent_volume_claim_status_create_internal (
        access_modes ? access_modesList : NULL,
        allocated_resource_statuses ? allocated_resource_statusesList : NULL,
        allocated_resources ? allocated_resourcesList : NULL,
        capacity ? capacityList : NULL,
        conditions ? conditionsList : NULL,
        current_volume_attributes_class_name && !cJSON_IsNull(current_volume_attributes_class_name) ? strdup(current_volume_attributes_class_name->valuestring) : NULL,
        modify_volume_status ? modify_volume_status_local_nonprim : NULL,
        phase && !cJSON_IsNull(phase) ? strdup(phase->valuestring) : NULL
        );

    return v1_persistent_volume_claim_status_local_var;
end:
    if (access_modesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, access_modesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(access_modesList);
        access_modesList = NULL;
    }
    if (allocated_resource_statusesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allocated_resource_statusesList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(allocated_resource_statusesList);
        allocated_resource_statusesList = NULL;
    }
    if (allocated_resourcesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allocated_resourcesList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(allocated_resourcesList);
        allocated_resourcesList = NULL;
    }
    if (capacityList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, capacityList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(capacityList);
        capacityList = NULL;
    }
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_persistent_volume_claim_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (modify_volume_status_local_nonprim) {
        v1_modify_volume_status_free(modify_volume_status_local_nonprim);
        modify_volume_status_local_nonprim = NULL;
    }
    return NULL;

}
