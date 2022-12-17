#include "rstring.h"

String* create_string(const char* str)
{
	String *string = malloc(sizeof(string));
	if (str != NULL) {
		size_t length = strlen(str);
		string->allocated = length + 1;
		string->data = (char*)malloc(string->allocated);
		memcpy(string->data, str, length);
		string->data[length] = '\0';
		string->length = length;
		return string;
	}
	string->allocated = 1;
	string->data = (char*)malloc(1);
	string->data[0] = '\0';
	string->length = 0;
	return string;
}

char* get_data(String* str){
	if (str != NULL)
		return str->data;
	return NULL;
}

size_t length(String* str){
	if (str != NULL)
		return str->length;
	return 0;
}

void add_char(String* str, char c){
}

void delete_string(String* str){
	if(str != NULL){
		if(str->data != NULL)
			free(str->data);
		free(str);
	}
}
