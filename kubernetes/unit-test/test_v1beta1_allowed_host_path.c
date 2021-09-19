#ifndef v1beta1_allowed_host_path_TEST
#define v1beta1_allowed_host_path_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_allowed_host_path_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_allowed_host_path.h"
v1beta1_allowed_host_path_t* instantiate_v1beta1_allowed_host_path(int include_optional);



v1beta1_allowed_host_path_t* instantiate_v1beta1_allowed_host_path(int include_optional) {
  v1beta1_allowed_host_path_t* v1beta1_allowed_host_path = NULL;
  if (include_optional) {
    v1beta1_allowed_host_path = v1beta1_allowed_host_path_create(
      "0",
      1
    );
  } else {
    v1beta1_allowed_host_path = v1beta1_allowed_host_path_create(
      "0",
      1
    );
  }

  return v1beta1_allowed_host_path;
}


#ifdef v1beta1_allowed_host_path_MAIN

void test_v1beta1_allowed_host_path(int include_optional) {
    v1beta1_allowed_host_path_t* v1beta1_allowed_host_path_1 = instantiate_v1beta1_allowed_host_path(include_optional);

	cJSON* jsonv1beta1_allowed_host_path_1 = v1beta1_allowed_host_path_convertToJSON(v1beta1_allowed_host_path_1);
	printf("v1beta1_allowed_host_path :\n%s\n", cJSON_Print(jsonv1beta1_allowed_host_path_1));
	v1beta1_allowed_host_path_t* v1beta1_allowed_host_path_2 = v1beta1_allowed_host_path_parseFromJSON(jsonv1beta1_allowed_host_path_1);
	cJSON* jsonv1beta1_allowed_host_path_2 = v1beta1_allowed_host_path_convertToJSON(v1beta1_allowed_host_path_2);
	printf("repeating v1beta1_allowed_host_path:\n%s\n", cJSON_Print(jsonv1beta1_allowed_host_path_2));
}

int main() {
  test_v1beta1_allowed_host_path(1);
  test_v1beta1_allowed_host_path(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_allowed_host_path_MAIN
#endif // v1beta1_allowed_host_path_TEST
