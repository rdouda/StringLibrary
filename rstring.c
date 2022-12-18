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
	return str->data;
}

size_t length(String* str){
	return str->length;
}

bool has_space(String* str){
	return str->allocated - (str->length + 1) > 0;
}

char* add_char(String* str, char c){
	char* new_string = realloc(str->data, (str->length + 2) * sizeof(char));
	new_string[str->length] = c;
	new_string[str->length++] = '\0';
	return new_string;
}

void reallocate(String* str, size_t size){
}

void delete_string(String* str){
	free(str->data);
	free(str);
}

void delete(String* str, size_t start, size_t end) {
	if (start > str->length || end > str->length || start > end) {
		return;
	}
	size_t deleted_len = end - start + 1;
	memmove(str->data + start, str->data + end + 1, str->length - end);
	char* new_string = realloc(str->data, (str->length - deleted_len + 1) * sizeof(char));
	str->data = new_string;
	new_string[str->length - deleted_len] = '\0';
	str->length -= deleted_len;
	str->allocated -= deleted_len + 1;
}
