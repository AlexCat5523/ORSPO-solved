int is_delimiter(char c, const char *delim) {
    while (*delim != '\0') {
        if (c == *delim) {
            return 1;
        } else {
            delim++;
        }
    }
    return 0;
}


char* strtok(char *string, const char *delim) {
    static char *word = NULL;

    if (*string == '\0') {
        return string;
    }

    if (*string != NULL) {
        word = string;
    }

    while (*string != '\0' && is_delimiter(*string, delim)) {
        string++;
    }

    char* start = *word;

    while (word != '\0') {
        if (is_delimiter(*word, delim)) {
            *word = '\0';
            word++;
            return start;
        }
    }
    return start;
}


int main() {
    
}