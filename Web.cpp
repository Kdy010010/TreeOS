#include <iostream>
#include <curl/curl.h>
#include "duktape.h"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

static duk_ret_t native_print(duk_context *ctx) {
    std::cout << duk_safe_to_string(ctx, -1) << std::endl;
    return 0;
}

int main() {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        std::string url;
        std::cout << "Enter URL: ";
        std::cin >> url;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        std::string html;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        else {
            std::cout << "HTML Content:\n" << html << std::endl;

            // Initialize JavaScript engine
            duk_context *ctx = duk_create_heap_default();

            // Expose print function to JavaScript
            duk_push_c_function(ctx, native_print, DUK_VARARGS);
            duk_put_global_string(ctx, "print");

            // Evaluate JavaScript code
            const char *jsCode = "print('Hello from JavaScript!');";
            duk_eval_string(ctx, jsCode);

            // Clean up JavaScript engine
            duk_destroy_heap(ctx);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}
