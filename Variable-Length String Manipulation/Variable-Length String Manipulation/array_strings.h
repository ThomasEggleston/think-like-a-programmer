typedef char *arrayString;

char characterAt(arrayString s, int pos);

int length(arrayString s);

bool equals(arrayString &s1, arrayString &s2);

void append(arrayString &s, char c);

void concatenate(arrayString &s1, arrayString &s2);

arrayString substring(arrayString &s, int start, int length);

arrayString replaceString(arrayString &source, arrayString target, arrayString replaceText);
