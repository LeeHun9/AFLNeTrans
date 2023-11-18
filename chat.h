#include "klist.h"
#include "kvec.h"
#include "khash.h"
#include <json-c/json.h>

#define PCRE2_CODE_UNIT_WIDTH 8 // Characters are 8 bits
#include <pcre2.h>

#define OPENAI_API_KEY "1"

#define MAX_TOKENS 2048

#define MAX_PROMPT_LENGTH 2048
#define EXAMPLES_PROMPT_LENGTH 400
#define HISTORY_PROMPT_LENGTH 1300


static size_t chat_with_llm_helper(void *contents, size_t size, size_t nmemb, void *userp);
char *chat_with_llm(char *prompt, char *model, int tries, float temperature);
char *construct_prompt_stall(char *protocol_name, char *examples, char *history);
char *extract_stalled_message(char *message, size_t message_len);
char *format_request_message(char *message);